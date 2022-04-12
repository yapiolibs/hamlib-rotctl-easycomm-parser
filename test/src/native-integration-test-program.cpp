#if defined(ENV_NATIVE)
#include <easycomm-buffered-tokenizer.h>
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
    std::string retained_response{};
    size_t num_commands_pending{ 0 };
    int serial_fd{ -1 };
    FILE *log_file{ nullptr };
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
    fprintf(data->log_file, "      parsed: >%s<\n", string_buffer);

    if(EasycommIdReset == command->commandId)
    {
        if(0 != close(data->serial_fd))
        {
            fprintf(data->log_file, "failed to close serial device; %s (error %d)", strerror(errno), errno);
        }
        fprintf(data->log_file, "<< exit  PID=%d\n", getpid());
        fflush(data->log_file);
        fclose(data->log_file);
        fflush(stdout);
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
        fprintf(data->log_file, "      response: >%s<\n", data->retained_response.c_str());
        printf("response: >%s<\n", data->retained_response.c_str());
        (void)write(data->serial_fd, data->retained_response.c_str(), data->retained_response.length());
        (void)write(data->serial_fd, "\n", 1);
        fflush(data->log_file);
        fflush(stdout);
        data->retained_response.clear();
    }
    else
    {
        data->retained_response.append(string_buffer);
        data->retained_response.append(" ");
    }
}

extern const char *__progname;

int main(int argc, const char **argv)
{
    CallbackData cb_data;

    { // open log file
        char log_file_name[128] = { 0 };
        sprintf(log_file_name, "%s.log", __progname);
        cb_data.log_file = fopen(log_file_name, "a");
        if(nullptr == cb_data.log_file)
        {
            printf("failed to open logfile: \"%s\"", log_file_name);
            fflush(stdout);
            return 1;
        }
        fprintf(cb_data.log_file, ">> start PID=%d\n", getpid());
        fflush(cb_data.log_file);
    }

    if(argc < 2) // check cli arguments
    {
        printf("not enough arguments provided: serial device path missing\n");
        fprintf(cb_data.log_file, "not enough arguments provided: serial device path missing\n");
        fflush(stdout);
        fflush(cb_data.log_file);
        fclose(cb_data.log_file);
        return 1;
    }

    { // open serial device
        const char *device_path = argv[1];
        cb_data.serial_fd = open(device_path, O_RDWR);
        for(int8_t retries = 16; (retries > 0) && (cb_data.serial_fd < 0); retries--)
        {
            timeval timeout{ .tv_sec = 0, .tv_usec = 125 * 1000 };
            select(0, nullptr, nullptr, nullptr, &timeout);
            cb_data.serial_fd = open(device_path, O_RDWR);
            if(cb_data.serial_fd < 0)
            {
                printf("failed to open device %s: %s (error %d), retries: %d", device_path,
                       strerror(errno), errno, retries);
                fprintf(cb_data.log_file, "failed to open device %s: %s (error %d), retries: %d",
                        device_path, strerror(errno), errno, retries);
            }
        }

        if(cb_data.serial_fd < 0)
        {
            printf("failed to open device %s: %s (error %d)", device_path, strerror(errno), errno);
            fprintf(cb_data.log_file, "failed to open device %s: %s (error %d)", device_path,
                    strerror(errno), errno);
            fflush(stdout);
            fflush(cb_data.log_file);
            fclose(cb_data.log_file);
            return 1;
        }
    }


    EasycommCommandsCallback cb_handler;
    easycommCommandsCallbackCustomDefaultCb(&cb_handler, EasycommParserStandard123, printCommandCallback);

    EasycommBufferedTokenizerState line_token_state;
    easycommBufferedTokenizerState(&line_token_state);
    char line_token_buffer[128] = { 0 };
    easycommBufferedTokenizerStateSetBuffers(&line_token_state, line_token_buffer, sizeof(line_token_buffer));

    while(true) // read bytes from serial device
    {
        char line_buffer[256] = { 0 };
        fd_set read_fds;
        fd_set exception_fds;
        FD_SET(cb_data.serial_fd, &read_fds);
        FD_SET(cb_data.serial_fd, &exception_fds);

        fprintf(cb_data.log_file, "  waiting ...\n");
        if(0 > select(cb_data.serial_fd + 1, &read_fds, nullptr, &exception_fds, nullptr))
        {
            printf("error: device not ready: %s (error %d)\n", strerror(errno), errno);
            fprintf(cb_data.log_file, "error: device not ready: %s (error %d)\n", strerror(errno), errno);
        }

        // assume:
        //   - a read may contain multiple lines of 1 to N commands
        //   - a line terminates with '\n' or "\r\n"
        //   - a line may have leading/trailing ' ' around '\n' or "\r\n"
        //   - multiple commands in a line are separated by one or multiple ' '
        ssize_t read_len = read(cb_data.serial_fd, &line_buffer[0], sizeof(line_buffer));
        if(0 > read_len)
        {
            printf("error: failed to read stdin: %s (error %d)\n", strerror(errno), errno);
            fprintf(cb_data.log_file, "error: failed to read stdin: %s (error %d)\n", strerror(errno), errno);
            fflush(stdout);
            fflush(cb_data.log_file);
            fclose(cb_data.log_file);
            return 1;
        }
        else if(0 == read_len)
        {
            printf("error: unexpected read of 0 bytes\n");
            fprintf(cb_data.log_file, "error: unexpected read of 0 bytes\n");
            fflush(stdout);
            fflush(cb_data.log_file);
            fclose(cb_data.log_file);
            return 1;
        }
        else
        { // tokenize lines
            fprintf(cb_data.log_file, "  received >%s<\n", line_buffer);
            fflush(cb_data.log_file);

            // assume:
            //   - each command is space separated or ends with newline
            //   - due to rx-timeout rotctl expects exactly one answer for all commands in
            //     each line until '\n'r

            char *line_buffer_ptr = line_buffer;
            while(easycommBufferedTokenizerStrtok(&line_token_state, line_buffer_ptr, read_len))
            {
                line_buffer_ptr = nullptr;
                if(1 == line_token_state.has_token)
                {
                    // remember how many responses are to be retained; last response appends '\n'
                    cb_data.num_commands_pending = 1;
                    for(char *c = line_token_state.token; *c != 0; c++)
                        if(*c == ' ')
                            cb_data.num_commands_pending++;

                    char *save_ptr = nullptr;
                    char *word_token = strtok_r(line_token_state.token, " ", &save_ptr);
                    while(nullptr != word_token) // tokenize words
                    {
                        fprintf(cb_data.log_file, "    token >%s<, pending %zu\n", word_token,
                                cb_data.num_commands_pending);
                        easycommHandleCommand(word_token, &cb_handler, EasycommParserStandard123, &cb_data);
                        word_token = strtok_r(nullptr, " ", &save_ptr);
                    }
                    fprintf(cb_data.log_file, "  pending %zu\n", cb_data.num_commands_pending);

                    line_token_state.token_consumed = 1;
                }
            }
        }
    }
    return 0;
}
#endif
