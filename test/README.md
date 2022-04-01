# Usnittests

```bash
cd hamlib-rotctl-easycomm-parser/test
pio init

# test on desktop
pio test -e native

# test on micro controllers
pio test -e megaatmega2560
pio test -e d1_mini
pio test -e esp_wroom_32

# build all supported platforms
pio run
```
