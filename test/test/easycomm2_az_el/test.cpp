#if !defined(ENV_NATIVE)
#include <Arduino.h>
#endif

#include "../common-parse-command.h"
#include <easycomm-parser-types-ctors.h>
#include <easycomm-parser-types-operators.h>
#include <easycomm-parser-types-sprintf.h>
#include <easycomm-parser.h>
#include <string.h>
#include <unity.h>


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_azimuth,
                                      EasycommAzimuthMaxLength,
                                      EasycommParserStandard2,
                                      easycommAzimuth,
                                      EasycommIdAzimuth,
                                      azimuth)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_elevation,
                                      EasycommElevationMaxLength,
                                      EasycommParserStandard2,
                                      easycommElevation,
                                      EasycommIdElevation,
                                      elevation)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_get_azimuth,
                                      EasycommGetAzimuthLength,
                                      EasycommParserStandard2,
                                      easycommGetAzimuth,
                                      EasycommIdGetAzimuth,
                                      getAzimuth)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_get_elevation,
                                      EasycommGetElevationLength,
                                      EasycommParserStandard2,
                                      easycommGetElevation,
                                      EasycommIdGetElevation,
                                      getElevation)


void test_parse_azimuth_01()
{
    const char *valid_data = "AZ213.4";
    const char *expected_representation = "AZ213.4";
    EasycommData expected_result;
    easycommAzimuth(&expected_result.as.azimuth);
    expected_result.as.azimuth.azimuth = 213.4;
    const bool expect_parser_success = true;

    invariant_test_parse_azimuth(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_azimuth_02()
{
    const char *valid_data = "AZ1.1";
    const char *expected_representation = "AZ1.1";
    EasycommData expected_result;
    easycommAzimuth(&expected_result.as.azimuth);
    expected_result.as.azimuth.azimuth = 1.1;
    const bool expect_parser_success = true;

    invariant_test_parse_azimuth(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_azimuth_03()
{
    const char *valid_data = "AZ000.1";
    const char *expected_representation = "AZ0.1";
    EasycommData expected_result;
    easycommAzimuth(&expected_result.as.azimuth);
    expected_result.as.azimuth.azimuth = 0.1;
    const bool expect_parser_success = true;

    invariant_test_parse_azimuth(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_azimuth_04()
{
    const char *valid_data = "AZ.1233";
    const char *expected_representation = "AZ0.1";
    EasycommData expected_result;
    easycommAzimuth(&expected_result.as.azimuth);
    expected_result.as.azimuth.azimuth = 0.1;
    const bool expect_parser_success = true;

    invariant_test_parse_azimuth(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_unexpected_azimuth()
{
    const char *valid_data = "AZ-0.4";
    const char *expected_representation = "AZ-0.4";
    EasycommData expected_result;
    easycommAzimuth(&expected_result.as.azimuth);
    expected_result.as.azimuth.azimuth = -0.4;
    const bool expect_parser_success = true;

    invariant_test_parse_azimuth(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_elevation_01()
{
    const char *valid_data = "EL213.4";
    const char *expected_representation = "EL213.4";
    EasycommData expected_result;
    easycommElevation(&expected_result.as.elevation);
    expected_result.as.elevation.elevation = 213.4;
    const bool expect_parser_success = true;

    invariant_test_parse_elevation(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_elevation_02()
{
    const char *valid_data = "EL1.1";
    const char *expected_representation = "EL1.1";
    EasycommData expected_result;
    easycommElevation(&expected_result.as.elevation);
    expected_result.as.elevation.elevation = 1.1;
    const bool expect_parser_success = true;

    invariant_test_parse_elevation(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_elevation_03()
{
    const char *valid_data = "EL00099";
    const char *expected_representation = "EL99.0";
    EasycommData expected_result;
    easycommElevation(&expected_result.as.elevation);
    expected_result.as.elevation.elevation = 99;
    const bool expect_parser_success = true;

    invariant_test_parse_elevation(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_unexpected_elevation()
{
    const char *valid_data = "EL-0.4";
    const char *expected_representation = "EL-0.4";
    EasycommData expected_result;
    easycommElevation(&expected_result.as.elevation);
    expected_result.as.elevation.elevation = -0.4;
    const bool expect_parser_success = true;

    invariant_test_parse_elevation(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_get_azimuth_01()
{
    const char *valid_data = "AZ";
    const char *expected_representation = "AZ";
    EasycommData expected_result;
    easycommGetAzimuth(&expected_result.as.getAzimuth);
    const bool expect_parser_success = true;

    invariant_test_parse_get_azimuth(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_get_elevation_01()
{
    const char *valid_data = "EL";
    const char *expected_representation = "EL";
    EasycommData expected_result;
    easycommGetElevation(&expected_result.as.getElevation);
    const bool expect_parser_success = true;

    invariant_test_parse_get_elevation(valid_data, &expected_result, expected_representation, expect_parser_success);
}


#if defined(ARDUINO_AVR_MEGA2560) || defined(ENV_NATIVE)
int main(int argc, char **argv)
#else

void setup() {}

void loop()
#endif
{
    UNITY_BEGIN();
    RUN_TEST(test_parse_azimuth_01);
    RUN_TEST(test_parse_azimuth_02);
    RUN_TEST(test_parse_azimuth_03);
    RUN_TEST(test_parse_azimuth_04);
    RUN_TEST(test_parse_unexpected_azimuth);
    RUN_TEST(test_parse_elevation_01);
    RUN_TEST(test_parse_elevation_02);
    RUN_TEST(test_parse_elevation_03);
    RUN_TEST(test_parse_unexpected_elevation);
    RUN_TEST(test_parse_get_azimuth_01);
    RUN_TEST(test_parse_get_elevation_01);
    UNITY_END();
#ifdef ARDUINO_AVR_MEGA2560
    return 0;
#endif
}
