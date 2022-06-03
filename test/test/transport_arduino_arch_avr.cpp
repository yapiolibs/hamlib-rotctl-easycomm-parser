#if defined(ARDUINO_ARCH_AVR)
#include <Arduino.h>

extern "C" void unittest_uart_begin() { Serial.begin(115200, SERIAL_8N1); }
extern "C" void unittest_uart_putchar(char c) { Serial.write(c); }
extern "C" void unittest_uart_flush() { Serial.flush(); }
extern "C" void unittest_uart_end() { Serial.end(); }

#endif
