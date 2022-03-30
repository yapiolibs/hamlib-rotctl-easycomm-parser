#ifdef ENV_NATIVE
#include <easycomm-parser.h>
#else
#undef ARDUINO_ARCH_ESP8266

#include <Arduino.h>
#include <easycomm-parser.h>

#endif

bool parse() {
    const char *data = "AZ000.1 EL000.0 UP000000000 UUU DN000000000 DDD";
    EasycommData result;
    return easycommParse(data, &result);
}

#ifdef ENV_NATIVE
int main() {
    return (parse()) ? 0 : 1;
}

#else

void setup() {}


void loop() {
    parse();
}

#endif