#if !defined(ENV_NATIVE)
#include <Arduino.h>
#endif

#include <easycomm-response-types-ctors.h>
#include <easycomm-response-types-sprintf.h>
#include <easycomm-response-types.h>
#include <stdio.h>
#include <string.h>
#include <unity.h>


void test_response_read_config_01()
{
    const char *expected_response = "CR1,#+!$abc";
    EasycommResponseConfigRegister response;
    easycommResponseConfigRegister(&response);
    response.registerNumber = 1;
    memcpy(response.value.as.str, "#+!$abc", 8);
    char response_str[32];
    easycommResponseConfigRegisterSprintf(&response, response_str);
    TEST_ASSERT_EQUAL_STRING(expected_response, response_str);
}


void test_response_get_status_register_01()
{
    const char *expected_response = "GS2";
    EasycommResponseStatusRegister response;
    easycommResponseStatusRegister(&response);
    response.status = EasycommStatusMoving;
    char response_str[32];
    easycommResponseStatusRegisterSprintf(&response, response_str);
    TEST_ASSERT_EQUAL_STRING(expected_response, response_str);
}


void test_response_get_error_register_01()
{
    const char *expected_response = "GE2";
    EasycommResponseErrorRegister response;
    easycommResponseErrorRegister(&response);
    response.status = EasycommErrorJam;
    char response_str[32];
    easycommResponseErrorRegisterSprintf(&response, response_str);
    TEST_ASSERT_EQUAL_STRING(expected_response, response_str);
}

int tests()
{
    UNITY_BEGIN();
    RUN_TEST(test_response_read_config_01);
    RUN_TEST(test_response_get_status_register_01);
    RUN_TEST(test_response_get_error_register_01);
    return UNITY_END();
}

void setUp() {}

void tearDown() {}

#include "../helpers/run-tests.h"
