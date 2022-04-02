# Testing

```bash
cd hamlib-rotctl-easycomm-parser/test
pio init

# unit test on desktop
pio test -e native

# unit test on micro controllers
pio test -e megaatmega2560
pio test -e d1_mini
pio test -e esp_wroom_32

# integration test on desktop (requires rotctl/hamlib installed)
pio run -e native_integration_test
```
