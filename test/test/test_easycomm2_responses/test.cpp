#if !defined(ENV_NATIVE)
#include <Arduino.h>
#endif

#include <easycomm-response-types-ctors.h>
#include <easycomm-response-types-sprintf.h>
#include <easycomm-response-types.h>
#include <stdio.h>
#include <string.h>
#include <unity.h>


void test_response_azimuth_01()
{
    const char *expected_response = "AZ12.4";
    EasycommResponseAzimuth response;
    easycommResponseAzimuth(&response);
    response.azimuth = 12.4;
    char response_str[32];
    easycommResponseAzimuthSprintf(&response, response_str);
    TEST_ASSERT_EQUAL_STRING(expected_response, response_str);
}


void test_response_elevation_01()
{
    const char *expected_response = "EL11.1";
    EasycommResponseElevation response;
    easycommResponseElevation(&response);
    response.elevation = 11.1;
    char response_str[32];
    easycommResponseElevationSprintf(&response, response_str);
    TEST_ASSERT_EQUAL_STRING(expected_response, response_str);
}


void test_response_uplink_frequency_01()
{ /* UplinkFrequency */
    const char *expected_response = "UP876543210";
    EasycommResponseUplinkFrequency response;
    easycommResponseUplinkFrequency(&response);
    response.frequency.as.uint32 = 876543210;
    char response_str[32];
    easycommResponseUplinkFrequencySprintf(&response, response_str);
    TEST_ASSERT_EQUAL_STRING(expected_response, response_str);
}


void test_response_downlink_frequency_01()
{
    const char *expected_response = "DN1030";
    EasycommResponseDownlinkFrequency response;
    easycommResponseDownlinkFrequency(&response);
    response.frequency.as.uint32 = 1030;
    char response_str[32];
    easycommResponseDownlinkFrequencySprintf(&response, response_str);
    TEST_ASSERT_EQUAL_STRING(expected_response, response_str);
}


void test_response_uplink_mode_01()
{
    const char *expected_response = "UMabc";
    EasycommResponseUplinkMode response;
    easycommResponseUplinkMode(&response);
    memcpy(response.mode, "abc", 3);
    char response_str[32];
    easycommResponseUplinkModeSprintf(&response, response_str);
    TEST_ASSERT_EQUAL_STRING(expected_response, response_str);
}


void test_response_downlink_mode_01()
{
    const char *expected_response = "DMfm";
    EasycommResponseDownlinkMode response;
    easycommResponseDownlinkMode(&response);
    memcpy(response.mode, "fm", 2);
    char response_str[32];
    easycommResponseDownlinkModeSprintf(&response, response_str);
    TEST_ASSERT_EQUAL_STRING(expected_response, response_str);
}


void test_response_downlink_radio_number_01()
{
    const char *expected_response = "DR10";
    EasycommResponseDownlinkRadio response;
    easycommResponseDownlinkRadio(&response);
    response.number = 10;
    char response_str[32];
    easycommResponseDownlinkRadioSprintf(&response, response_str);
    TEST_ASSERT_EQUAL_STRING(expected_response, response_str);
}


void test_response_uplink_radio_number_01()
{
    const char *expected_response = "UR12";
    EasycommResponseUplinkRadio response;
    easycommResponseUplinkRadio(&response);
    response.number = 12;
    char response_str[32];
    easycommResponseUplinkRadioSprintf(&response, response_str);
    TEST_ASSERT_EQUAL_STRING(expected_response, response_str);
}


void test_response_digital_input_01()
{
    const char *expected_response = "IP128,1";
    EasycommResponseDigitalInput response;
    easycommResponseDigitalInput(&response);
    response.number = 128;
    response.value = true;
    char response_str[32];
    easycommResponseDigitalInputSprintf(&response, response_str);
    TEST_ASSERT_EQUAL_STRING(expected_response, response_str);
}


void test_response_analogue_input_01()
{
    const char *expected_response = "AN2,256";
    EasycommResponseAnalogueInput response;
    easycommResponseAnalogueInput(&response);
    response.number = 2;
    response.value = 256;
    char response_str[32];
    easycommResponseAnalogueInputSprintf(&response, response_str);
    TEST_ASSERT_EQUAL_STRING(expected_response, response_str);
}


void test_response_version_01()
{
    const char *expected_response = "VE0.16";
    EasycommResponseVersion response;
    easycommResponseVersion(&response);
    response.minor = 16;
    response.major = 0;
    char response_str[32];
    easycommResponseVersionSprintf(&response, response_str);
    TEST_ASSERT_EQUAL_STRING(expected_response, response_str);
}


void test_response_alarm_01()
{
    const char *expected_response = "ALVladolfPutlerBonkers";
    EasycommResponseAlarm response;
    easycommResponseAlarm(&response);
    memcpy(response.message, "VladolfPutlerBonkers", 20);
    char response_str[39];
    easycommResponseAlarmSprintf(&response, response_str);
    TEST_ASSERT_EQUAL_STRING(expected_response, response_str);
}


void test_response_velocity_left_01()
{
    const char *expected_response = "VL9999";
    EasycommResponseVelocityLeft response;
    easycommResponseVelocityLeft(&response);
    response.milliDegSecond = 9999;
    char response_str[32];
    easycommResponseVelocityLeftSprintf(&response, response_str);
    TEST_ASSERT_EQUAL_STRING(expected_response, response_str);
}


void test_response_velocity_right_01()
{
    const char *expected_response = "VR764";
    EasycommResponseVelocityRight response;
    easycommResponseVelocityRight(&response);
    response.milliDegSecond = 764;
    char response_str[32];
    easycommResponseVelocityRightSprintf(&response, response_str);
    TEST_ASSERT_EQUAL_STRING(expected_response, response_str);
}


void test_response_velocity_up_01()
{
    const char *expected_response = "VU123";
    EasycommResponseVelocityUp response;
    easycommResponseVelocityUp(&response);
    response.milliDegSecond = 123;
    char response_str[32];
    easycommResponseVelocityUpSprintf(&response, response_str);
    TEST_ASSERT_EQUAL_STRING(expected_response, response_str);
}


void test_response_velocity_down_01()
{
    const char *expected_response = "VD234";
    EasycommResponseVelocityDown response;
    easycommResponseVelocityDown(&response);
    response.milliDegSecond = 234;
    char response_str[32];
    easycommResponseVelocityDownSprintf(&response, response_str);
    TEST_ASSERT_EQUAL_STRING(expected_response, response_str);
}


int tests()
{
    UNITY_BEGIN();
    RUN_TEST(test_response_azimuth_01);
    RUN_TEST(test_response_elevation_01);
    RUN_TEST(test_response_uplink_frequency_01);
    RUN_TEST(test_response_downlink_frequency_01);
    RUN_TEST(test_response_uplink_mode_01);
    RUN_TEST(test_response_downlink_mode_01);
    RUN_TEST(test_response_uplink_radio_number_01);
    RUN_TEST(test_response_downlink_radio_number_01);
    RUN_TEST(test_response_digital_input_01);
    RUN_TEST(test_response_analogue_input_01);
    RUN_TEST(test_response_version_01);
    RUN_TEST(test_response_alarm_01);
    RUN_TEST(test_response_velocity_left_01);
    RUN_TEST(test_response_velocity_right_01);
    RUN_TEST(test_response_velocity_up_01);
    RUN_TEST(test_response_velocity_down_01);
    return UNITY_END();
}

void setUp() {}

void tearDown() {}

#include "../helpers/run-tests.h"
