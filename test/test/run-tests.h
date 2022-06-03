#pragma once

#if defined(ARDUINO_AVR_MEGA2560) || defined(ENV_NATIVE)
int main(int argc, char **argv) { return tests(); }
#else
void setup() { delay(1000); }
void loop() { tests(); }
#endif
