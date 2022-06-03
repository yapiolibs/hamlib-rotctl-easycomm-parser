#if defined(PIO_EXAMPLE_PARSE_WITH_CALLBACK)
#include "example-parse-with-callback.h"
#include <easycomm-command-callback-handler.h>

void customCallback(const EasycommData *command, void *custom_data)
{
    *((bool *)custom_data) = true;
}

void setup() {}

void loop()
{
    // registry for possible callbacks (CB) for each command; CBs may be nullptr
    EasycommCommandsCallback cb_handler;

    // register empty SB stubs for all commands described in standard 2
    easycommCommandsCallback(&cb_handler, EasycommParserStandard2);

    // override a specific CB
    cb_handler.registry[EasycommIdSetAzimuth] = customCallback;

    bool some_cb_invoked = { false };
    bool custom_cb_invoked = { false };

    some_cb_invoked = easycommHandleCommand("EL100.1", &cb_handler, EasycommParserStandard2, &custom_cb_invoked);
    // custom_cb_invoked == false because customCallback(...) was regitered for AZ but not EL
    // command some_cb_invoked == true because a default empty CB was called for EL command

    some_cb_invoked = easycommHandleCommand("AZ100.1", &cb_handler, EasycommParserStandard2, &custom_cb_invoked);
    // custom_cb_invoked == true
    // some_cb_invoked == true

    some_cb_invoked = easycommHandleCommand("VU", &cb_handler, EasycommParserStandard3, &custom_cb_invoked);
    // custom_cb_invoked == false
    // some_cb_invoked == false because VU is a standard 3 command but CBs are registered only for standard 2

    // suppress unused variable warnings
    (void)custom_cb_invoked;
    (void)some_cb_invoked;
}

#endif
