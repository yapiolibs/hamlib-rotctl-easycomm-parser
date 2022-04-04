#if !defined(ENV_NATIVE)
#include <Arduino.h>
#endif
#include <easycomm-command-callback-handler.h>
#include <easycomm-parser.h>


bool parser_example()
{
    const char *data = "AZ000.1 EL000.0 UP000000000 UUU DN000000000 DDD";
    EasycommData result;
    return easycommParse(data, &result, EasycommParserStandard1);
}


void testCallback(const EasycommData *command, void *custom_data) { *((bool *)custom_data) = true; }


bool callback_example()
{
    EasycommCommandsCallback cb_handler;
    easycommCommandsCallback(&cb_handler, EasycommParserStandard1);
    cb_handler.registry[EasycommIdSingleLine] = testCallback;
    const char *command = "AZ0.0 EL0.0 UP0 UUU DN0 DDD";

    bool is_test_callback_invoked = false;
    bool is_callback_invoked =
    easycommHandleCommand(command, &cb_handler, EasycommParserStandard1, &is_test_callback_invoked);
    return true == is_test_callback_invoked && true == is_callback_invoked;
}


#if defined(ENV_NATIVE)

#include <easycomm-command-callback-handler.h>
#include <easycomm-parser-types-sprintf.h>
#include <easycomm-response-types-ctors.h>
#include <easycomm-response-types-sprintf.h>
#include <easycomm-response-types.h>
#include <errno.h>
#include <fcntl.h>
#include <iostream>
#include <string.h>
#include <sys/select.h>
#include <unistd.h>

/**
 * Test program that runs natively for integration testing.
 * Reads input from a file descriptor to feed the parser with rotctl genrated data.
 * Prints the parsed command to stdout or "<invalid>" if cannot parse.
 *
 * Workflow:
 *   1. create a virtual device:
 *      socat -d -d pty,raw,echo=0,link=/tmp/easycomm-host-side pty,raw,echo=0,link=/tmp/easycomm-controller-side
 *
 *   2. start rotctl:
 *      rotctl --model=204 --rot-file=/tmp/easycomm-host-side -vvvvv
 *
 *   3. start test program (build with `pio run -e native`):
 *      pio run -e native
 *      .pio/build/native/program /tmp/easycomm-controller-side
 *
 *   4. send commands by rotctl and verify the output of the test program
 *      "R" or "\reset" causes the test program to finish
 */

typedef struct CallbackData
{
    int serial_fd;
} CallbackData;

void printCommandCallback(const EasycommData *command, void *custom_data)
{
    CallbackData *data = (CallbackData *)custom_data;
    char string_buffer[128] = { 0 };

    easycommDataSprintf(command, string_buffer);
    printf("received: >%s<\n", string_buffer);

    if(EasycommIdReset == command->commandId)
    {
        exit(0);
    }
    else if(command->commandId == EasycommIdGetAzimuth)
    {
        EasycommResponseAzimuth az;
        easycommResponseAzimuth(&az);
        az.azimuth = 123.4;
        easycommResponseAzimuthSprintf(&az, string_buffer);
    }
    else if(command->commandId == EasycommIdGetElevation)
    {
        EasycommResponseElevation el;
        easycommResponseElevation(&el);
        el.elevation = -12.3;
        easycommResponseElevationSprintf(&el, string_buffer);
    }
    else if(command->commandId == EasycommIdGetAzimuthElevation)
    {
        EasycommResponseAzimuthElevation azel;
        easycommResponseAzimuthElevation(&azel);
        azel.elevation = 1;
        azel.azimuth = 2;
        easycommResponseAzimuthElevationSprintf(&azel, string_buffer);
    }
    else if(command->commandId == EasycommIdGetStatusRegister)
    {
        EasycommResponseGetStatusRegister gs;
        easycommResponseGetStatusRegister(&gs);
        gs.status = EasycommStatusMoving;
        easycommResponseGetStatusRegisterSprintf(&gs, string_buffer);
    }
    else if(command->commandId == EasycommIdGetErrorRegister)
    {
        EasycommResponseGetErrorRegister ge;
        easycommResponseGetErrorRegister(&ge);
        ge.status = EasycommErrorSensor;
        easycommResponseGetErrorRegisterSprintf(&ge, string_buffer);
    }
    else if(command->commandId == EasycommIdReadInput)
    {
        EasycommResponseReadInput ip;
        easycommResponseReadInput(&ip);
        ip.number = 1;
        ip.value = true;
        easycommResponseReadInputSprintf(&ip, string_buffer);
    }
    else if(command->commandId == EasycommIdReadAnalogueInput)
    {
        EasycommResponseReadAnalogueInput an;
        easycommResponseReadAnalogueInput(&an);
        an.number = 1;
        an.value = 42;
        easycommResponseReadAnalogueInputSprintf(&an, string_buffer);
    }
    else if(command->commandId == EasycommIdRequestVersion)
    {
        EasycommResponseRequestVersion ve;
        easycommResponseRequestVersion(&ve);
        ve.major = 0;
        ve.minor = 1;
        easycommResponseRequestVersionSprintf(&ve, string_buffer);
    }
    else if(command->commandId == EasycommIdReadConfig)
    {
        EasycommResponseReadConfig cr;
        easycommResponseReadConfig(&cr);
        cr.registerNumber = 1;
        memcpy(&cr.value.as.str, "asdf", 4);
        easycommResponseReadConfigSprintf(&cr, string_buffer);
    }
    else
        return;

    printf("response: >%s<\n", string_buffer);
    write(data->serial_fd, string_buffer, strlen(string_buffer)); // rotctl expects response
    write(data->serial_fd, "\n", 1);
}


int main(int argc, char **argv)
{
    if(argc < 2)
        return 1;

    char *device_path = argv[1];


    int serial_fd = open(device_path, O_RDWR);
    if(serial_fd < 0)
    {
        printf("failed to open device: %s (error %d)", strerror(errno), errno);
        return 1;
    }

    char line_buffer[256] = { 0 };
    fd_set read_fds;
    fd_set exception_fds;

    CallbackData cb_data;
    cb_data.serial_fd = serial_fd;
    EasycommCommandsCallback cb_handler;
    easycommCommandsCallbackCustomDefaultCb(&cb_handler, EasycommParserStandard123, printCommandCallback);

    while(true)
    {
        memset(line_buffer, 0, sizeof(line_buffer));
        FD_SET(serial_fd, &read_fds);
        FD_SET(serial_fd, &exception_fds);

        if(0 > select(serial_fd + 1, &read_fds, nullptr, &exception_fds, nullptr))
        {
            printf("error: device not ready\n");
            return 1;
        }

        if(0 < read(serial_fd, &line_buffer, sizeof(line_buffer)))
        {
            // cleanup and trim trailing '\r' '\n' and ' '
            *strchrnul(line_buffer, '\r') = 0;
            *strchrnul(line_buffer, '\n') = 0;
            for(char *c = line_buffer + strlen(line_buffer) - 1; c != line_buffer; c--)
            {
                if(*c == ' ')
                    *c = 0;
                else
                    break;
            }

            // TODO workaround messy responses from rotctl:
            //   - "AZ EL " expects the response in one line "AZxxx Elxxx\n"
            //     not as documented "AZxxx\n" and "ELxxx\n" so it cannot be handled as two
            //     separate commands "AZ" "EL". it must be one "AZ EL" command.
            //   - "SA SE " can be handled as two ' ' separated commands but this contradicts
            //     "AZ EL " above
            //  idea:
            //    - read until '\n'
            //    - tokenize N-commands
            //    - try handle all N
            //    - retain transmission until last N is handled or an error occurs
            // char *token = strtok(line_buffer, " ");
            // while(nullptr != token)
            {
                // printf("xxx %s\n", token);
                // easycommHandleCommand(token, &cb_handler, EasycommParserStandard123, &cb_data);
                easycommHandleCommand(line_buffer, &cb_handler, EasycommParserStandard123, &cb_data);
                // token = strtok(nullptr, " ");
            }
        }
    }

    close(serial_fd);
    return 0;
}

#else

void setup() {}

void loop()
{
    // parser_example();
    callback_example();
}

#endif
