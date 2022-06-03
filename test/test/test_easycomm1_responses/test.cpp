#if !defined(ENV_NATIVE)
#include <Arduino.h>
#endif

#include <easycomm-response-types-ctors.h>
#include <easycomm-response-types-sprintf.h>
#include <easycomm-response-types.h>
#include <stdio.h>
#include <string.h>
#include <unity.h>


void test_response_single_line_01()
{
    const char *expected_response = "AZ0.0 EL0.0 UP0 upm DN0 dnm";
    EasycommResponseSingleLine response;
    easycommResponseSingleLine(&response);
    memcpy(response.modeUp, "upm", 3);
    memcpy(response.modeDown, "dnm", 3);
    char response_str[32];
    easycommResponseSingleLineSprintf(&response, response_str);
    TEST_ASSERT_EQUAL_STRING(expected_response, response_str);
}


void test_response_single_line_02()
{
    const char *expected_response = "AZ10.0 EL11.0 UP12 x DN13 y";
    EasycommResponseSingleLine response;
    easycommResponseSingleLine(&response);
    response.azimuth = 10;
    response.elevation = 11;
    response.uplinkFrequency.as.uint32 = 12;
    response.downlinkFrequency.as.uint32 = 13;
    memcpy(response.modeUp, "x", 1);
    memcpy(response.modeDown, "y", 1);
    char response_str[32];
    easycommResponseSingleLineSprintf(&response, response_str);
    TEST_ASSERT_EQUAL_STRING(expected_response, response_str);
}


int tests()
{
    UNITY_BEGIN();
    RUN_TEST(test_response_single_line_01);
    RUN_TEST(test_response_single_line_02);
    return UNITY_END();
}

void setUp() {}

void tearDown() {}

#include "../helpers/run-tests.h"
