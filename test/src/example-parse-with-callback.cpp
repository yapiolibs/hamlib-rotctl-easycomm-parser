#if defined(PIO_EXAMPLE_PARSE_WITH_CALLBACK)
#include "example-parse-with-callback.h"
#include <easycomm-command-callback-handler.h>

void commandCallback(const EasycommData *command, void *custom_data)
{
    *((bool *)custom_data) = true;
}

void setup() {}

void loop()
{
    EasycommCommandsCallback cb_handler;
    easycommCommandsCallback(&cb_handler, EasycommParserStandard1);
    cb_handler.registry[EasycommIdSingleLine] = commandCallback;
    const char *command = "AZ0.0 EL0.0 UP0 UUU DN0 DDD";

    bool is_command_callback_invoked = false;
    bool is_callback_invoked =
    easycommHandleCommand(command, &cb_handler, EasycommParserStandard1, &is_command_callback_invoked);

    if(is_command_callback_invoked)
    {
        // command callback was invoked
    }
    else if(is_callback_invoked)
    {
        // dummy callback was invoked
    }
}

#endif
