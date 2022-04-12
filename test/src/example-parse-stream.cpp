#if defined(PIO_EXAMPLE_PARSE_STREAM)
#include "example-parse-stream.h"
#include <easycomm-buffered-tokenizer.h>
#include <easycomm-command-callback-handler.h>
#include <easycomm-response-types-ctors.h>
#include <easycomm-response-types-sprintf.h>
#include <easycomm-response-types.h>

// -------------------------------------------------------------------------------------------------

size_t read(char *buffer, size_t buffer_length);
size_t write(const char *buffer, size_t buffer_length);
void commandCallback(const EasycommData *command, void *custom_data);

typedef struct CallbackData
{
    String retained_response{};
    size_t num_commands_pending{ 0 };
} CallbackData;

// -------------------------------------------------------------------------------------------------

char line_buffer[128] = { 0 };       // for read
char line_token_buffer[130] = { 0 }; // for tokenizer state
CallbackData cb_data;
EasycommCommandsCallback cb_handler;
EasycommBufferedTokenizerState line_token_state;

// -------------------------------------------------------------------------------------------------

void setup()
{
    easycommCommandsCallbackCustomDefaultCb(&cb_handler, // callback storage
                                            EasycommParserStandard123, // register cb to all commands defined in standard
                                            commandCallback); // the custom callback to register
    easycommBufferedTokenizerState(&line_token_state);
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
    //   - all commands of one set must be responded within one line
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
        // subsequent reentrant calls with NULL
        line_buffer_ptr = nullptr;


        // if line was received
        if(1 == line_token_state.has_token)
        {
            // remember how many commands are received
            // to retain possible responses so that last response appends '\n'
            cb_data.num_commands_pending = 1;
            for(char *c = line_token_state.token; *c != 0; c++)
                if(*c == ' ')
                    cb_data.num_commands_pending++;

            // tokenize line by spaces and parse each command
            char *save_ptr = nullptr;
            char *word_token = strtok_r(line_token_state.token, " ", &save_ptr);
            while(nullptr != word_token)
            {
                easycommHandleCommand(word_token,  // a potential command to parse
                                      &cb_handler, // registered callbacks for each command type
                                      EasycommParserStandard123, // Easycomm protocol standard
                                      &cb_data);                 // custom data provided to callback
                word_token = strtok_r(nullptr, " ", &save_ptr);
            }

            // mark token as consumed to not block next reentrant line-tokenizer call
            line_token_state.token_consumed = 1;
        }
    }
}

// -------------------------------------------------------------------------------------------------

size_t read(char *buffer, size_t buffer_length) { return 0; }
size_t write(const char *buffer, size_t buffer_length) { return 0; }

// -------------------------------------------------------------------------------------------------

void commandCallback(const EasycommData *command, void *custom_data)
{
    auto *data = (CallbackData *)custom_data;
    if(data->num_commands_pending == 0)
    {
        // "unexpected callback"
    }

    data->num_commands_pending--;
    char string_buffer[128] = { 0 };

    if(EasycommIdReset == command->commandId) {}
    else if(command->commandId == EasycommIdGetAzimuth)
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
    else if(command->commandId == EasycommIdGetStatusRegister)
    {
        // prepare response ...
    }
    else if(command->commandId == EasycommIdGetErrorRegister)
    {
        // prepare response ...
    }
    else if(command->commandId == EasycommIdReadInput)
    {
        // prepare response ...
    }
    else if(command->commandId == EasycommIdReadAnalogueInput)
    {
        // prepare response ...
    }
    else if(command->commandId == EasycommIdRequestVersion)
    {
        // prepare response ...
    }
    else if(command->commandId == EasycommIdReadConfig)
    {
        // prepare response ...
    }
    else
        return;

    // buffer responses
    data->retained_response.concat(string_buffer);

    if(data->num_commands_pending == 0)
    {
        (void)write(data->retained_response.c_str(), data->retained_response.length());
        (void)write("\n", 1);
        data->retained_response = "";
    }
    else
    {
        data->retained_response.concat(" ");
    }
}

#endif
