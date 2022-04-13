# Testing

```bash
# setup
cd hamlib-rotctl-easycomm-parser/test
pio init

# unit tests on desktop
pio test -e native

# unit tests on micro controllers
pio test -e atmelavr             # requries megaatmega2560 board
pio test -e ststm32              # requres blackpill_f401cc board
pio test -e espressif8266        # requires d1_mini board
pio test -e espressif32          # requies esp32doit-devkit-v1 board

# integration test on desktop
pio run -e native -t integration # requires libhamlib-utils installed

# build all targets inclusive examples
pio run

# static code analysis
pio check --fail-on-defect=high --fail-on-defect=medium --fail-on-defect=low
```
