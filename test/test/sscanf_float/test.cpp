#ifndef ENV_NATIVE

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
#ifdef ARDUINO_AVR_MEGA2560
    int16_t d = 0;
#else
    int32_t d = 0;
#endif

    uint8_t items = sscanf(buffer, "%s %f %f %s %d", abc, &fn, &fp, def, &d);
    TEST_ASSERT_EQUAL(5, items);
    TEST_ASSERT_EQUAL_STRING("ABC", abc);
    TEST_ASSERT_EQUAL_FLOAT(-123, fn);
    TEST_ASSERT_EQUAL_FLOAT(123.4, fp);
    TEST_ASSERT_EQUAL_STRING("def", def);
    TEST_ASSERT_EQUAL(42, d);
}

#if defined(ARDUINO_AVR_MEGA2560) || defined(ENV_NATIVE)
int main(int argc, char **argv)
#else

void setup() {}

void loop()
#endif
{
    UNITY_BEGIN();
    RUN_TEST(test_sscanf);
    UNITY_END();

#ifdef ARDUINO_AVR_MEGA2560
    return 0;
#endif
}
