#ifndef ENV_NATIVE

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


void test_response_downlink_radioNumber_01()
{
    const char *expected_response = "DR10";
    EasycommResponseDownlinkRadioNumber response;
    easycommResponseDownlinkRadioNumber(&response);
    response.number = 10;
    char response_str[32];
    easycommResponseDownlinkRadioNumberSprintf(&response, response_str);
    TEST_ASSERT_EQUAL_STRING(expected_response, response_str);
}


void test_response_uplink_radioNumber_01()
{
    const char *expected_response = "UR12";
    EasycommResponseUplinkRadioNumber response;
    easycommResponseUplinkRadioNumber(&response);
    response.number = 12;
    char response_str[32];
    easycommResponseUplinkRadioNumberSprintf(&response, response_str);
    TEST_ASSERT_EQUAL_STRING(expected_response, response_str);
}


void test_response_read_input_01()
{
    const char *expected_response = "IP128,1";
    EasycommResponseReadInput response;
    easycommResponseReadInput(&response);
    response.number = 128;
    response.value = true;
    char response_str[32];
    easycommResponseReadInputSprintf(&response, response_str);
    TEST_ASSERT_EQUAL_STRING(expected_response, response_str);
}


void test_response_read_analogue_input_01()
{
    const char *expected_response = "AN2,256";
    EasycommResponseReadAnalogueInput response;
    easycommResponseReadAnalogueInput(&response);
    response.number = 2;
    response.value = 256;
    char response_str[32];
    easycommResponseReadAnalogueInputSprintf(&response, response_str);
    TEST_ASSERT_EQUAL_STRING(expected_response, response_str);
}


void test_response_request_version_01()
{
    const char *expected_response = "VE0.16";
    EasycommResponseRequestVersion response;
    easycommResponseRequestVersion(&response);
    response.minor = 16;
    response.major = 0;
    char response_str[32];
    easycommResponseRequestVersionSprintf(&response, response_str);
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


void test_response_read_config_01()
{
    const char *expected_response = "CR1,#+!$abc";
    EasycommResponseReadConfig response;
    easycommResponseReadConfig(&response);
    response.registerNumber = 1;
    memcpy(response.value.as.str, "#+!$abc", 8);
    char response_str[32];
    easycommResponseReadConfigSprintf(&response, response_str);
    TEST_ASSERT_EQUAL_STRING(expected_response, response_str);
}


void test_response_get_status_register_01()
{
    const char *expected_response = "GS2";
    EasycommResponseGetStatusRegister response;
    easycommResponseGetStatusRegister(&response);
    response.status = EasycommStatusMoving;
    char response_str[32];
    easycommResponseGetStatusRegisterSprintf(&response, response_str);
    TEST_ASSERT_EQUAL_STRING(expected_response, response_str);
}


void test_response_get_error_register_01()
{
    const char *expected_response = "GE2";
    EasycommResponseGetErrorRegister response;
    easycommResponseGetErrorRegister(&response);
    response.status = EasycommErrorJam;
    char response_str[32];
    easycommResponseGetErrorRegisterSprintf(&response, response_str);
    TEST_ASSERT_EQUAL_STRING(expected_response, response_str);
}


#if defined(ARDUINO_AVR_MEGA2560) || defined(ENV_NATIVE)
int main(int argc, char **argv)
#else

void setup() {}

void loop()
#endif
{
    UNITY_BEGIN();

    RUN_TEST(test_response_single_line_01);
    RUN_TEST(test_response_single_line_02);
    RUN_TEST(test_response_azimuth_01);
    RUN_TEST(test_response_elevation_01);
    RUN_TEST(test_response_uplink_frequency_01);
    RUN_TEST(test_response_downlink_frequency_01);
    RUN_TEST(test_response_uplink_mode_01);
    RUN_TEST(test_response_downlink_mode_01);
    RUN_TEST(test_response_uplink_radioNumber_01);
    RUN_TEST(test_response_downlink_radioNumber_01);
    RUN_TEST(test_response_read_input_01);
    RUN_TEST(test_response_read_analogue_input_01);
    RUN_TEST(test_response_request_version_01);
    RUN_TEST(test_response_alarm_01);
    RUN_TEST(test_response_velocity_left_01);
    RUN_TEST(test_response_velocity_right_01);
    RUN_TEST(test_response_velocity_up_01);
    RUN_TEST(test_response_velocity_down_01);
    RUN_TEST(test_response_read_config_01);
    RUN_TEST(test_response_get_status_register_01);
    RUN_TEST(test_response_get_error_register_01);

    UNITY_END();
#ifdef ARDUINO_AVR_MEGA2560
    return 0;
#endif
}
