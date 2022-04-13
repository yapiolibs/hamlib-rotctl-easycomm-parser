#if defined(PIO_EXAMPLE_PARSE_STREAM)
#include "example-parse-stream.h"
#include <easycomm-buffered-tokenizer.h>
#include <easycomm-command-callback-handler.h>
#include <easycomm-response-types-ctors.h>
#include <easycomm-response-types-sprintf.h>
#include <easycomm-response-types.h>

/**
 * This example aims to show how the line-tokenizer is applied to receive data from rotctl
 * and how to reply to each command that was received in the same line.
 */

// -------------------------------------------------------------------------------------------------

// custom data for each callback
typedef struct CallbackData
{
    String retained_response{};
    size_t num_commands_pending{ 0 };
} CallbackData;

// -------------------------------------------------------------------------------------------------

size_t read(char *buffer, size_t buffer_length);                      // read from serial stub
size_t write(const char *buffer, size_t buffer_length);               // write to serial stub
void commandCallback(const EasycommData *command, void *custom_data); // custom callback for each command

// -------------------------------------------------------------------------------------------------

char line_buffer[128] = { 0 };                   // for reading input
CallbackData cb_data;                            // custom data for all callbacks
EasycommCommandsCallback cb_handler;             // callback registry for each command
EasycommBufferedTokenizerState line_token_state; // state for buffered line tokenizer
char line_token_buffer[130] = { 0 };             // line tokenizer buffer

// -------------------------------------------------------------------------------------------------

void setup()
{
    easycommCommandsCallbackCustomDefaultCb(&cb_handler, // callback registry
                                            EasycommParserStandard123, // register CB to all commands defined in standard 1, 2 and 3
                                            commandCallback); // a custom callback to register

    easycommBufferedTokenizerState(&line_token_state); // ctor
    // bind a buffer to tokenizer state
    easycommBufferedTokenizerStateSetBuffers(&line_token_state, line_token_buffer, sizeof(line_token_buffer));
}

// -------------------------------------------------------------------------------------------------

void loop()
{
    // when receiving from rotctl:
    //   - a line is terminated by: '\r' or '\n' or '\r\n' or '\n\r' (dont make assumptions)
    //     from now on termed as :eol:
    //   - duplicate subsequent ' ' may occur; as regex: \s+
    //   - leading and trailing ' '* may occur; as regex: \s*
    //   - a command (:cmd:) is a char sequence without spaces; as regex: \S+
    //   - multiple commands are \s* separated; example: (\s*:cmd\s*:)+
    //   - a set of 1 to N commands ends with :eol: - example: (\s*:cmd\s*:)+:eol:
    size_t read_len = read(line_buffer, sizeof(line_buffer));

    // when responding to rotctl:
    //   - all commands in one set must be responded within one line terminated by '\n'
    //   - the response order should be the same as the command order

    char *line_buffer_ptr = line_buffer;
    // easycommBufferedTokenizerStrtok() is reentrand and
    //   - reads from stream until :eol:
    //   - trims \s+ to \s
    //   - removes leading/trailing \s+ from :cmd:
    //   - removes :eol:
    // the result is: :cmd:(\s:cmd:)*
    while(easycommBufferedTokenizerStrtok(&line_token_state, line_buffer_ptr, read_len))
    {
        // subsequent reentrant calls provide NULL instead of line_buffer pointer
        line_buffer_ptr = nullptr;

        // if a line was completed
        if(1 == line_token_state.has_token)
        {
            // remember how many commands are received
            // to retain possible responses so that the last response appends '\n'
            cb_data.num_commands_pending = 1;
            for(char *c = line_token_state.token; *c != 0; c++)
                if(*c == ' ')
                    cb_data.num_commands_pending++;

            // tokenize line by spaces and parse each token/command
            char *save_ptr{ nullptr };
            char *word_token = strtok_r(line_token_state.token, " ", &save_ptr);
            while(nullptr != word_token)
            {
                easycommHandleCommand(word_token,                // a potential command to parse
                                      &cb_handler,               // registry of CBs for each command
                                      EasycommParserStandard123, // Easycomm protocol standard to consider
                                      &cb_data);                 // custom data provided to all CBs
                word_token = strtok_r(nullptr, " ", &save_ptr);
            }

            // mark line as consumed to not block subsequent reentrant line-tokenizer calls
            line_token_state.token_consumed = 1;
        }
    }
}

// -------------------------------------------------------------------------------------------------

size_t read(char *buffer, size_t buffer_length) { return 0; }
size_t write(const char *buffer, size_t buffer_length) { return 0; }

// -------------------------------------------------------------------------------------------------

// A naive callback example: all commands pass this CB.
// 1. for each command/callback, decrement the pending counter
// 2. prepare responses for commands where a response is expected
// 3. retain responses until the last the last command (counter == 0) and append '\n'
void commandCallback(const EasycommData *command, void *custom_data)
{
    auto *data = (CallbackData *)custom_data;
    if(data->num_commands_pending == 0)
    {
        // unexpected callback
        return;
    }

    data->num_commands_pending--;
    char string_buffer[128] = { 0 };

    if(command->commandId == EasycommIdGetAzimuth)
    {
        // requested current azimuth, prepare response
        EasycommResponseAzimuth az;
        easycommResponseAzimuth(&az);
        az.azimuth = 11;
        easycommResponseAzimuthSprintf(&az, string_buffer);
    }
    else if(command->commandId == EasycommIdGetElevation)
    { // prepare response ...
    }
    // other commands ...
    else if(command->commandId == EasycommIdReset)
    { // no response expected
    }
    // further commands ...
    else
        return;

    // retain response
    data->retained_response.concat(string_buffer);

    // last command was interpreted
    if(data->num_commands_pending == 0)
    {
        (void)write(data->retained_response.c_str(), data->retained_response.length());
        (void)write("\n", 1);
        data->retained_response = "";
    }
    else
    // other commands will follow
    {
        data->retained_response.concat(" ");
    }
}

#endif
