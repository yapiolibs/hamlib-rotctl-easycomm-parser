#if !defined(ENV_NATIVE)
#include <Arduino.h>
#endif

#include <stdio.h>
#include <string.h>
#include <unity.h>

void test_sscanf()
{
    // may require: build_flags += -Wl,-u,vfscanf,-lscanf_flt,-u,vfprintf,-lprintf_flt
    char buffer[] = "ABC -123 123.4 def 42", abc[4] = { 0 }, def[4] = { 0 };
    float fn = 0, fp = 0;
    int32_t d = 0;

    uint8_t items = sscanf(buffer,
#if defined(ARDUINO_AVR_MEGA2560) || defined(ARDUINO_ARCH_STM32)
                           "%s %f %f %s %ld", // int32_t on stm32f4 is long int
#elif defined(ARDUINO_ARCH_ESP8266) || defined(ARDUINO_ARCH_ESP32)
                           "%s %f %f %s %d",
#else // assume native platform
                           "%s %f %f %s %d",
#endif
                           abc, &fn, &fp, def, &d);
    TEST_ASSERT_EQUAL(5, items);
    TEST_ASSERT_EQUAL_STRING("ABC", abc);
    TEST_ASSERT_EQUAL_FLOAT(-123, fn);
    TEST_ASSERT_EQUAL_FLOAT(123.4, fp);
    TEST_ASSERT_EQUAL_STRING("def", def);
    TEST_ASSERT_EQUAL(42, d);
}

int tests()
{
    UNITY_BEGIN();
    RUN_TEST(test_sscanf);
    return UNITY_END();
}

void setUp() {}

void tearDown() {}

#include "../run-tests.h"
