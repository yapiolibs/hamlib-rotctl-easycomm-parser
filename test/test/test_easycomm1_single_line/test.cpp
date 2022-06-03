#if !defined(ENV_NATIVE)
#include <Arduino.h>
#endif

#include "../helpers/common-parse-command.h"
#include <easycomm-parser-types-ctors.h>
#include <easycomm-parser-types-operators.h>
#include <easycomm-parser-types-sprintf.h>
#include <easycomm-parser.h>
#include <string.h>
#include <unity.h>


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_single_line,
                                      EasycommSingleLineMaxLength,
                                      EasycommParserStandard1,
                                      easycommSingleLine,
                                      EasycommIdSingleLine,
                                      singleLine)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_reset,
                                      EasycommResetLength,
                                      EasycommParserStandard1,
                                      easycommDoReset,
                                      EasycommIdReset,
                                      doReset)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_park,
                                      EasycommParkLength,
                                      EasycommParserStandard1,
                                      easycommDoPark,
                                      EasycommIdPark,
                                      doPark)

void test_parse_elevation_01()
{
    const char *valid_data = "AZ0.0 EL0.0 UP0 UUU DN0 DDD";
    const char *expected_representation = "AZ0.0 EL0.0 UP0 UUU DN0 DDD";
    EasycommData expected_result;
    easycommSingleLine(&expected_result.as.singleLine);
    memcpy(&expected_result.as.singleLine.modeUp, "UUU", 3);
    memcpy(&expected_result.as.singleLine.modeDown, "DDD", 3);
    const bool expect_parser_success = true;

    invariant_test_parse_single_line(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_elevation_02()
{
    const char *valid_data = "AZ000.1 EL000.0 UP000000000 UUU DN000000000 DDD";
    const char *expected_representation = "AZ0.1 EL0.0 UP0 UUU DN0 DDD";
    EasycommData expected_result;
    easycommSingleLine(&expected_result.as.singleLine);
    expected_result.as.singleLine.azimuth = 0.1f;
    memcpy(&expected_result.as.singleLine.modeUp, "UUU", 3);
    memcpy(&expected_result.as.singleLine.modeDown, "DDD", 3);
    const bool expect_parser_success = true;

    invariant_test_parse_single_line(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_elevation_03()
{
    const char *valid_data = "AZ123.4 EL000.0 UP000000000 UUU DN000000000 DDD";
    const char *expected_representation = "AZ123.4 EL0.0 UP0 UUU DN0 DDD";
    EasycommData expected_result;
    easycommSingleLine(&expected_result.as.singleLine);
    expected_result.as.singleLine.azimuth = 123.4f;
    memcpy(&expected_result.as.singleLine.modeUp, "UUU", 3);
    memcpy(&expected_result.as.singleLine.modeDown, "DDD", 3);
    const bool expect_parser_success = true;

    invariant_test_parse_single_line(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_elevation()
{
    const char *valid_data = "AZ000.0 EL977.3 UP000000000 UUU DN000000000 DDD";
    const char *expected_representation = "AZ0.0 EL977.3 UP0 UUU DN0 DDD";
    EasycommData expected_result;
    easycommSingleLine(&expected_result.as.singleLine);
    expected_result.as.singleLine.elevation = 977.3f;
    memcpy(&expected_result.as.singleLine.modeUp, "UUU", 3);
    memcpy(&expected_result.as.singleLine.modeDown, "DDD", 3);
    const bool expect_parser_success = true;

    invariant_test_parse_single_line(valid_data, &expected_result, expected_representation, expect_parser_success);
}

void test_parse_uplink_frequency()
{
    const char *valid_data = "AZ000.0 EL000.0 UP999999999 UUU DN000000000 DDD";
    const char *expected_representation = "AZ0.0 EL0.0 UP999999999 UUU DN0 DDD";
    EasycommData expected_result;
    easycommSingleLine(&expected_result.as.singleLine);
    expected_result.as.singleLine.uplinkFrequency.as.uint32 = 999999999;
    memcpy(&expected_result.as.singleLine.modeUp, "UUU", 3);
    memcpy(&expected_result.as.singleLine.modeDown, "DDD", 3);
    const bool expect_parser_success = true;

    invariant_test_parse_single_line(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_downlink_frequency()
{
    const char *valid_data = "AZ000.0 EL000.0 UP000000000 UUU DN999999999 DDD";
    const char *expected_representation = "AZ0.0 EL0.0 UP0 UUU DN999999999 DDD";
    EasycommData expected_result;
    easycommSingleLine(&expected_result.as.singleLine);
    expected_result.as.singleLine.downlinkFrequency.as.uint32 = 999999999;
    memcpy(&expected_result.as.singleLine.modeUp, "UUU", 3);
    memcpy(&expected_result.as.singleLine.modeDown, "DDD", 3);
    const bool expect_parser_success = true;

    invariant_test_parse_single_line(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_uplink_mode()
{
    const char *valid_data = "AZ000.0 EL000.0 UP000000000 ABC DN000000000 DDD";
    const char *expected_representation = "AZ0.0 EL0.0 UP0 ABC DN0 DDD";
    EasycommData expected_result;
    easycommSingleLine(&expected_result.as.singleLine);
    memcpy(&expected_result.as.singleLine.modeUp, "ABC", 3);
    memcpy(&expected_result.as.singleLine.modeDown, "DDD", 3);
    const bool expect_parser_success = true;

    invariant_test_parse_single_line(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_downlink_mode()
{
    const char *valid_data = "AZ000.0 EL000.0 UP000000000 UUU DN000000000 DEF";
    const char *expected_representation = "AZ0.0 EL0.0 UP0 UUU DN0 DEF";
    EasycommData expected_result;
    easycommSingleLine(&expected_result.as.singleLine);
    memcpy(&expected_result.as.singleLine.modeUp, "UUU", 3);
    memcpy(&expected_result.as.singleLine.modeDown, "DEF", 3);
    const bool expect_parser_success = true;

    invariant_test_parse_single_line(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_invalid_azimuth()
{
    const char *invalid_data = "AZ123.45 EL000.0 UP000000000 UUU DN000000000 DDD";
    const char *expected_representation = "don't care";
    const EasycommData *dont_care = NULL;
    const bool expect_parser_fail = false;

    invariant_test_parse_single_line(invalid_data, dont_care, expected_representation, expect_parser_fail);
}


void test_parse_unexpected_elevation()
{
    const char *invalid_data = "AZ000.0 EL0359 UP000000000 UUU DN000000000 DDD";
    const char *expected_representation = "AZ0.0 EL359.0 UP0 UUU DN0 DDD";
    EasycommData expected_result;
    easycommSingleLine(&expected_result.as.singleLine);
    expected_result.as.singleLine.elevation = 359;
    memcpy(&expected_result.as.singleLine.modeUp, "UUU", 3);
    memcpy(&expected_result.as.singleLine.modeDown, "DDD", 3);
    const bool expect_parser_success = true;

    invariant_test_parse_single_line(invalid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_trimmed_uplink_mode()
{
    const char *invalid_data = "AZ000.0 EL000.0 UP10 UUUU DN000000000 DDD";
    const char *expected_representation = "AZ0.0 EL0.0 UP10 UUU DN0 DDD";
    EasycommData expected_result;
    easycommSingleLine(&expected_result.as.singleLine);
    expected_result.as.singleLine.uplinkFrequency.as.uint32 = 10;
    memcpy(&expected_result.as.singleLine.modeUp, "UUU", 3);
    memcpy(&expected_result.as.singleLine.modeDown, "DDD", 3);
    const bool expect_parser_success = true;

    invariant_test_parse_single_line(invalid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_short_downlink_mode()
{
    const char *data = "AZ000.0 EL000.0 UP10 UUU DN000000000 DD";
    const char *expected_representation = "AZ0.0 EL0.0 UP10 UUU DN0 DD";
    EasycommData expected_result;
    easycommSingleLine(&expected_result.as.singleLine);
    expected_result.as.singleLine.uplinkFrequency.as.uint32 = 10;
    memcpy(&expected_result.as.singleLine.modeUp, "UUU", 3);
    memcpy(&expected_result.as.singleLine.modeDown, "DD", 2);
    const bool expect_parser_success = true;

    invariant_test_parse_single_line(data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_unexpected_uplink_frequency()
{
    const char *invalid_data = "AZ000.0 EL000.0 UP10 UUU DN000000000 DDD";
    const char *expected_representation = "AZ0.0 EL0.0 UP10 UUU DN0 DDD";
    EasycommData expected_result;
    easycommSingleLine(&expected_result.as.singleLine);
    expected_result.as.singleLine.uplinkFrequency.as.uint32 = 10;
    memcpy(&expected_result.as.singleLine.modeUp, "UUU", 3);
    memcpy(&expected_result.as.singleLine.modeDown, "DDD", 3);
    const bool expect_parser_success = true;

    invariant_test_parse_single_line(invalid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_reset()
{
    const char *valid_data = "RESET";
    const char *expected_representation = "RESET";
    EasycommData expected_result;
    easycommDoReset(&expected_result.as.doReset);
    const bool expect_parser_success = true;

    invariant_test_parse_reset(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_park()
{
    const char *valid_data = "PARK";
    const char *expected_representation = "PARK";
    EasycommData expected_result;
    easycommDoPark(&expected_result.as.doPark);
    const bool expect_parser_success = true;

    invariant_test_parse_park(valid_data, &expected_result, expected_representation, expect_parser_success);
}

int tests()
{
    UNITY_BEGIN();
    RUN_TEST(test_parse_elevation_01);
    RUN_TEST(test_parse_elevation_02);
    RUN_TEST(test_parse_elevation_03);
    RUN_TEST(test_parse_elevation);
    RUN_TEST(test_parse_uplink_frequency);
    RUN_TEST(test_parse_downlink_frequency);
    RUN_TEST(test_parse_uplink_mode);
    RUN_TEST(test_parse_downlink_mode);
    RUN_TEST(test_parse_invalid_azimuth);
    RUN_TEST(test_parse_unexpected_elevation);
    RUN_TEST(test_parse_trimmed_uplink_mode);
    RUN_TEST(test_parse_short_downlink_mode);
    RUN_TEST(test_parse_unexpected_uplink_frequency);
    RUN_TEST(test_parse_reset);
    RUN_TEST(test_parse_park);
    return UNITY_END();
}

void setUp() {}

void tearDown() {}

#include "../helpers/run-tests.h"
