# Hamlib rotctl Easycomm parser
Platformio parser library for hamlib rotator (Easycomm I,II,III) control commands.

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

More examples [here](./test/test/).

