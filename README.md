# hamlib-rotctl-easycomm-parser
Platformio parser library for hamlib rotator control (Easycomm protocol; see
[description](https://github.com/Hamlib/Hamlib/tree/master/rotators/easycomm/easycomm.txt),
[source](https://github.com/Hamlib/Hamlib/tree/master/rotators/easycomm/easycomm.c), and `rotctl --list`).


```ini
# platformio.ini
[env:xxx]
platform = xxx
boboard = xxx
framework = arduino
lib_deps = https://github.com/yapiolibs/hamlib-rotctl-easycomm-parser.git
```

```c
const char *data = "AZ000.1 EL000.0 UP000000000 UUU DN000000000 DDD";
EasycommData result;
if (easycommParse(data, &result)) {...}
```

