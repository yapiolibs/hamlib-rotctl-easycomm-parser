#if defined(ENV_NATIVE)
#include "native-integration-test-program.h"
#else
#include <Arduino.h>
#include <easycomm-command-callback-handler.h>
#include <easycomm-parser.h>

bool parser_example()
{
    const char *data = "AZ000.1 EL000.0 UP000000000 UUU DN000000000 DDD";
    EasycommData result;
    return easycommParse(data, &result, EasycommParserStandard1);
}


void testCallback(const EasycommData *command, void *custom_data) { *((bool *)custom_data) = true; }


bool pase_with_callback_example()
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

void setup() {}

void loop()
{
    // parser_example();
    pase_with_callback_example();
}

#endif
