# Testing

```bash
# unit tests on developer PC
pio test -e native

# unit tests on micro controllers
pio test -e atmelavr             # requires megaatmega2560 board to be connected
pio test -e ststm32              # requires blackpill_f401cc board to be connected
pio test -e espressif8266        # requires d1_mini board to be connected
pio test -e espressif32          # requires esp32doit-devkit-v1 board to be connected

# integration test on desktop
pio run -e native -t integration # requires libhamlib-utils installed

# build all targets inclusive examples (exclusive unit tests)
pio run

# static code analysis
pio check --fail-on-defect=high --fail-on-defect=medium --fail-on-defect=low

# setup for IDE (clion example)
cd hamlib-rotctl-easycomm-parser/test
pio init --ide clion
```
