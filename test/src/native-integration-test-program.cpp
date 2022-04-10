#if defined(ENV_NATIVE)
#include <easycomm-command-callback-handler.h>
#include <easycomm-parser-types-sprintf.h>
#include <easycomm-response-types-ctors.h>
#include <easycomm-response-types-sprintf.h>
#include <easycomm-response-types.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sys/select.h>
#include <sys/stat.h>
#include <sys/types.h>
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
    // TODO remove need of buffering in retained_response
    std::string retained_response;
    size_t num_commands_pending;
    int serial_fd;
} CallbackData;


static void printCommandCallback(const EasycommData *command, void *custom_data)
{
    CallbackData *data = (CallbackData *)custom_data;
    if(data->num_commands_pending == 0)
    {
        printf("unexpected number of commands");
        exit(1);
    }

    data->num_commands_pending--;
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
        az.azimuth = 11;
        easycommResponseAzimuthSprintf(&az, string_buffer);
    }
    else if(command->commandId == EasycommIdGetElevation)
    {
        EasycommResponseElevation el;
        easycommResponseElevation(&el);
        el.elevation = 12;
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

    if(data->num_commands_pending == 0)
    {
        data->retained_response.append(string_buffer);
        printf("response: >%s<\n", data->retained_response.c_str());
        (void)write(data->serial_fd, data->retained_response.c_str(), data->retained_response.length());
        (void)write(data->serial_fd, "\n", 1);
        data->retained_response.clear();
    }
    else
    {
        data->retained_response.append(string_buffer);
        data->retained_response.append(" ");
    }
}


int main(int argc, const char **argv)
{
    if(argc < 2)
        return 1;

    const char *device_path = argv[1];

    int serial_fd = open(device_path, O_RDWR);
    if(serial_fd < 0)
    {
        printf("failed to open device %s: %s (error %d)", device_path, strerror(errno), errno);
        return 1;
    }

    fd_set read_fds;
    fd_set exception_fds;

    CallbackData cb_data;
    cb_data.serial_fd = serial_fd;
    EasycommCommandsCallback cb_handler;
    easycommCommandsCallbackCustomDefaultCb(&cb_handler, EasycommParserStandard123, printCommandCallback);

    while(true)
    {
        char line_buffer[256] = { 0 };
        FD_SET(serial_fd, &read_fds);
        FD_SET(serial_fd, &exception_fds);

        if(0 > select(serial_fd + 1, &read_fds, nullptr, &exception_fds, nullptr))
        {
            printf("error: device not ready\n");
            return 1;
        }

        // assume line buffered read: a read will include '\n'
        if(0 < read(serial_fd, &line_buffer, sizeof(line_buffer)))
        {
            // assume each command is space separated or ends with newline
            // assume rotctl expects exactly one answer for all commands in each line (due to timout)

            // cleanup and trim trailing '\r' '\n' and ' ' from rotctl
            *strchrnul(line_buffer, '\r') = 0;
            *strchrnul(line_buffer, '\n') = 0;
            for(char *c = line_buffer + strlen(line_buffer) - 1; c != line_buffer; c--)
            {
                if(*c == ' ')
                    *c = 0;
                else
                    break;
            }

            // remember how many responses are to be retained; last response sends '\n'
            cb_data.num_commands_pending = 1;
            for(char *c = line_buffer; *c != 0; c++)
            {
                if(*c == ' ')
                    cb_data.num_commands_pending++;
            }

            char *token = strtok(line_buffer, " ");
            while(nullptr != token)
            {
                easycommHandleCommand(token, &cb_handler, EasycommParserStandard123, &cb_data);
                token = strtok(nullptr, " ");
            }
        }
    }

    close(serial_fd);
    return 0;
}
#endif
