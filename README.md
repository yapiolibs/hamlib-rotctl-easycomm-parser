# Hamlib rotctl Easycomm parser
Platformio parser library for hamlib rotator (Easycomm I,II,III) control commands programmed in C for C and C++ projects.

References:
* [library documentation](./src/)
* Easycomm protocol
  * rotctl --list
  * rotctl --model=204 --dump-caps
* Hamlib
  * [protocol description](https://github.com/Hamlib/Hamlib/tree/master/rotators/easycomm/easycomm.txt)
  * [protocol source code](https://github.com/Hamlib/Hamlib/tree/master/rotators/easycomm/easycomm.c)


```ini
# platformio.ini
[env:xxx]
platform  = xxx
boboard   = xxx
framework = arduino
lib_deps  = https://github.com/yapiolibs/hamlib-rotctl-easycomm-parser.git
```

```c
const char *data = "AZ000.1 EL000.0 UP000000000 UUU DN000000000 DDD";
EasycommData result;
if (easycommParse(data, &result)) {...}
```

```c
void testCallback(const EasycommData *command, void *custom_data) { *((bool *)custom_data) = true; }
...
EasycommCommandsCallback cb_handler;
easycommCommandsCallback(&cb_handler, EasycommParserStandard1);
cb_handler.registry[EasycommIdSingleLine] = testCallback;

const char *command = "AZ0.0 EL0.0 UP0 UUU DN0 DDD";
bool custom_data = false;
easycommHandleCommand(command, &cb_handler, EasycommParserStandard1, &custom_data);
```

More examples
* [main.cpp](./test/src/main.cpp)
* [unit tests](./test/test/).

