# Hamlib rotctl Easycomm parser
Platformio parser library for hamlib rotator (Easycomm I,II,III) control commands programmed in C for C and C++ projects.


**Integrate in project:**
```ini
# platformio.ini
[env:xxx]
platform  = xxx # one of ["native", "atmelavr", "ststm32", "espressiv8266", "espressif32"]
board     = xxx
framework = arduino
lib_deps  = https://github.com/yapiolibs/hamlib-rotctl-easycomm-parser.git
```

[**Parse a single command:**](https://github.com/yapiolibs/hamlib-rotctl-easycomm-parser/blob/main/test/src/example-parse-command.cpp)
```c
#include <easycomm-parser.h>

void setup() {}

void loop()
{
    const char *data = "AZ000.1 EL000.0 UP000000000 UUU DN000000000 DDD";
    EasycommData result;

    if(easycommParseCommand(data, &result, EasycommParserStandard1))
    {
        // command was parsed
    }
}
```

[**Parse with callback:**](https://github.com/yapiolibs/hamlib-rotctl-easycomm-parser/blob/main/test/src/example-parse-with-callback.cpp)
```c
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
```

**Parse from stream:** [see full example](https://github.com/yapiolibs/hamlib-rotctl-easycomm-parser/blob/main/test/src/example-parse-stream.cpp).

**More examples:**

* [native-integration-test-program.cpp](https://github.com/yapiolibs/hamlib-rotctl-easycomm-parser/blob/main/test/src/native-integration-test-program.cpp)
* [unit tests](https://github.com/yapiolibs/hamlib-rotctl-easycomm-parser/blob/main/test/test/)

**References:**

* [library documentation](./src/)
* Easycomm protocol
  * rotctl --list
  * rotctl --model=204 --dump-caps
* Hamlib
  * [protocol description](https://github.com/Hamlib/Hamlib/tree/master/rotators/easycomm/easycomm.txt)
  * [protocol source code](https://github.com/Hamlib/Hamlib/tree/master/rotators/easycomm/easycomm.c)


**Checks**

[![pio-run.yaml](https://github.com/yapiolibs/hamlib-rotctl-easycomm-parser/actions/workflows/pio-run.yaml/badge.svg)](https://github.com/yapiolibs/hamlib-rotctl-easycomm-parser/actions/workflows/pio-run.yaml)<br />
[![pio-check.yaml](https://github.com/yapiolibs/hamlib-rotctl-easycomm-parser/actions/workflows/pio-check.yaml/badge.svg)](https://github.com/yapiolibs/hamlib-rotctl-easycomm-parser/actions/workflows/pio-check.yaml)<br />
[![unit-tests.yaml](https://github.com/yapiolibs/hamlib-rotctl-easycomm-parser/actions/workflows/unit-tests.yaml/badge.svg)](https://github.com/yapiolibs/hamlib-rotctl-easycomm-parser/actions/workflows/unit-tests.yaml)<br />
[![integration-tests-hamlib3x.yaml](https://github.com/yapiolibs/hamlib-rotctl-easycomm-parser/actions/workflows/integration-tests-hamlib3x.yaml/badge.svg)](https://github.com/yapiolibs/hamlib-rotctl-easycomm-parser/actions/workflows/integration-tests-hamlib3x.yaml)<br />
[![integration-tests-hamlib4x.yaml](https://github.com/yapiolibs/hamlib-rotctl-easycomm-parser/actions/workflows/integration-tests-hamlib4x.yaml/badge.svg)](https://github.com/yapiolibs/hamlib-rotctl-easycomm-parser/actions/workflows/integration-tests-hamlib4x.yaml)<br />
[![codeql-analysis.yml](https://github.com/yapiolibs/hamlib-rotctl-easycomm-parser/actions/workflows/codeql-analysis.yaml/badge.svg)](https://github.com/yapiolibs/hamlib-rotctl-easycomm-parser/actions/workflows/codeql-analysis.yaml)<br />
