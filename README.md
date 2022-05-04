# [Hamlib](https://github.com/Hamlib/Hamlib) rotctl [Easycomm](https://github.com/Hamlib/Hamlib/tree/master/rotators/easycomm) parser

A PlatformmIO parser library for Hamlib rotator control commands.
- Parses the string-based protocol as described by Easycomm standards I, II or III.
  - from string to C-struct (reception)
  - from C-struct to string (response)
- Programmed with less dependencies in C for C and C++ projects.
- Requires float support for `scanf` and `printf`.

[![PlatformIO Registry](https://badges.registry.platformio.org/packages/rubienr/library/HamlibRotctlEasycommParser.svg)](https://registry.platformio.org/libraries/rubienr/HamlibRotctlEasycommParser)

[**Integrate in project:**](https://github.com/yapiolibs/hamlib-rotctl-easycomm-parser/blob/main/test/platformio.ini)
```ini
# platformio.ini
[env:xxx]
platform  = xxx # one of ["native", "atmelavr", "ststm32", "espressiv8266", "espressif32"]
board     = xxx
framework = arduino
lib_deps  = rubienr/HamlibRotctlEasycommParser
# some platforms require folat support for scanf/printf to be explicitely enabled
build_flags =
    # if platfrom is atmelavr:
    # -Wl,-u,vfscanf,-lscanf_flt,-u,vfprintf,-lprintf_flt
    # if platform is ststm32:
    # -Wl,-u_scanf_float,-u_printf_float
```

[**Parse a single command:**](https://github.com/yapiolibs/hamlib-rotctl-easycomm-parser/blob/main/test/src/example-parse-command.cpp)
```c
void setup() {}

void loop()
{
    EasycommData result;

    easycommData(&result);
    if(easycommParseCommand("AZ000.1 EL000.0 UP000000000 UUU DN000000000 DDD", &result, EasycommParserStandard1))
    {
        // standard 1 command was parsed
    }

    easycommData(&result);
    if(easycommParseCommand("AZ100", &result, EasycommParserStandard2))
    {
        // standard 2 command was parsed
    }

    easycommData(&result);
    if(easycommParseCommand("VU50", &result, EasycommParserStandard23))
    {
        // standard 3 command was parsed
    }
}
```

[**Parse with callback:**](https://github.com/yapiolibs/hamlib-rotctl-easycomm-parser/blob/main/test/src/example-parse-with-callback.cpp)
```c
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
    cb_handler.registry[EasycommIdAzimuth] = customCallback;

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
```

**Parse from stream:** [see full example](https://github.com/yapiolibs/hamlib-rotctl-easycomm-parser/blob/main/test/src/example-parse-stream.cpp)

**More examples:**

* [native-integration-test-program.cpp](https://github.com/yapiolibs/hamlib-rotctl-easycomm-parser/blob/main/test/src/native-integration-test-program.cpp)
* [unit tests](https://github.com/yapiolibs/hamlib-rotctl-easycomm-parser/blob/main/test/test/)

**References:**

* [Command reference](https://github.com/yapiolibs/hamlib-rotctl-easycomm-parser/tree/main/src/)
* Easycomm protocol
  * rotctl --list
  * rotctl --model=204 --dump-caps
* Hamlib
  * [protocol description](https://github.com/Hamlib/Hamlib/tree/master/rotators/easycomm/easycomm.txt)
  * [protocol source](https://github.com/Hamlib/Hamlib/tree/master/rotators/easycomm/easycomm.c)


**Checks**

[![pio-run.yaml](https://github.com/yapiolibs/hamlib-rotctl-easycomm-parser/actions/workflows/pio-run.yaml/badge.svg)](https://github.com/yapiolibs/hamlib-rotctl-easycomm-parser/actions/workflows/pio-run.yaml)<br />
[![pio-check.yaml](https://github.com/yapiolibs/hamlib-rotctl-easycomm-parser/actions/workflows/pio-check.yaml/badge.svg)](https://github.com/yapiolibs/hamlib-rotctl-easycomm-parser/actions/workflows/pio-check.yaml)<br />
[![unit-tests.yaml](https://github.com/yapiolibs/hamlib-rotctl-easycomm-parser/actions/workflows/unit-tests.yaml/badge.svg)](https://github.com/yapiolibs/hamlib-rotctl-easycomm-parser/actions/workflows/unit-tests.yaml)<br />
[![integration-tests-hamlib3x.yaml](https://github.com/yapiolibs/hamlib-rotctl-easycomm-parser/actions/workflows/integration-tests-hamlib3x.yaml/badge.svg)](https://github.com/yapiolibs/hamlib-rotctl-easycomm-parser/actions/workflows/integration-tests-hamlib3x.yaml)<br />
[![integration-tests-hamlib4x.yaml](https://github.com/yapiolibs/hamlib-rotctl-easycomm-parser/actions/workflows/integration-tests-hamlib4x.yaml/badge.svg)](https://github.com/yapiolibs/hamlib-rotctl-easycomm-parser/actions/workflows/integration-tests-hamlib4x.yaml)<br />
[![codeql-analysis.yml](https://github.com/yapiolibs/hamlib-rotctl-easycomm-parser/actions/workflows/codeql-analysis.yaml/badge.svg)](https://github.com/yapiolibs/hamlib-rotctl-easycomm-parser/actions/workflows/codeql-analysis.yaml)<br />
