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

INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_uplink_frequency,
                                      EasycommUplinkFrequencyMaxLength,
                                      EasycommParserStandard2,
                                      easycommSetUplinkFrequency,
                                      EasycommIdUplinkFrequency,
                                      setUplinkFrequency)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_downlink_frequency,
                                      EasycommDownlinkFrequencyMaxLength,
                                      EasycommParserStandard2,
                                      easycommSetDownlinkFrequency,
                                      EasycommIdDownlinkFrequency,
                                      setDownlinkFrequency)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_uplink_mode,
                                      EasycommUplinkModeMaxLength,
                                      EasycommParserStandard2,
                                      easycommSetUplinkMode,
                                      EasycommIdUplinkMode,
                                      setUplinkMode)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_downlink_mode,
                                      EasycommDownlinkModeMaxLength,
                                      EasycommParserStandard2,
                                      easycommSetDownlinkMode,
                                      EasycommIdDownlinkMode,
                                      setDownlinkMode)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_uplink_radio,
                                      EasycommUplinkRadioNumberMaxLength,
                                      EasycommParserStandard2,
                                      easycommSetUplinkRadioNumber,
                                      EasycommIdUplinkRadioNumber,
                                      setUplinkRadio)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_downlink_radio,
                                      EasycommDownlinkRadioNumberMaxLength,
                                      EasycommParserStandard2,
                                      easycommSetDownlinkRadioNumber,
                                      EasycommIdDownlinkRadioNumber,
                                      setDownlinkRadio)


void test_parse_uplink_frequency_01()
{
    const char *valid_data = "UP0";
    const char *expected_representation = "UP0";
    EasycommData expected_result;
    easycommSetUplinkFrequency(&expected_result.as.setUplinkFrequency);
    expected_result.as.setUplinkFrequency.frequency.as.uint32 = 0;
    const bool expect_parser_success = true;

    invariant_test_parse_uplink_frequency(valid_data, &expected_result, expected_representation,
                                          expect_parser_success);
}

void test_parse_uplink_frequency_02()
{
    const char *valid_data = "UP999999999";
    const char *expected_representation = "UP999999999";
    EasycommData expected_result;
    easycommSetUplinkFrequency(&expected_result.as.setUplinkFrequency);
    expected_result.as.setUplinkFrequency.frequency.as.uint32 = 999999999;
    const bool expect_parser_success = true;

    invariant_test_parse_uplink_frequency(valid_data, &expected_result, expected_representation,
                                          expect_parser_success);
}


void test_parse_invalid_uplink_frequency_01()
{
    const char *invalid_data = "UP";
    const char *expected_representation = "don't care";
    const EasycommData *dont_care = NULL;
    const bool expect_parser_fail = false;

    invariant_test_parse_uplink_frequency(invalid_data, dont_care, expected_representation, expect_parser_fail);
}


void test_parse_invalid_uplink_frequency_02()
{
    const char *invalid_data = "UP5000000000";
    const char *expected_representation = "don't care";
    const EasycommData *dont_care = NULL;
    const bool expect_parser_fail = false;

    invariant_test_parse_uplink_frequency(invalid_data, dont_care, expected_representation, expect_parser_fail);
}


void test_parse_downlink_frequency_01()
{
    const char *valid_data = "DN0";
    const char *expected_representation = "DN0";
    EasycommData expected_result;
    easycommSetDownlinkFrequency(&expected_result.as.setDownlinkFrequency);
    expected_result.as.setDownlinkFrequency.frequency.as.uint32 = 0;
    const bool expect_parser_success = true;

    invariant_test_parse_downlink_frequency(valid_data, &expected_result, expected_representation,
                                            expect_parser_success);
}

void test_parse_downlink_frequency_02()
{
    const char *valid_data = "DN999999999";
    const char *expected_representation = "DN999999999";
    EasycommData expected_result;
    easycommSetDownlinkFrequency(&expected_result.as.setDownlinkFrequency);
    expected_result.as.setDownlinkFrequency.frequency.as.uint32 = 999999999;
    const bool expect_parser_success = true;

    invariant_test_parse_downlink_frequency(valid_data, &expected_result, expected_representation,
                                            expect_parser_success);
}


void test_parse_invalid_downlink_frequency_01()
{
    const char *invalid_data = "DN";
    const char *expected_representation = "don't care";
    const EasycommData *dont_care = NULL;
    const bool expect_parser_fail = false;

    invariant_test_parse_uplink_frequency(invalid_data, dont_care, expected_representation, expect_parser_fail);
}


void test_parse_invalid_downlink_frequency_02()
{
    const char *invalid_data = "DN5000000000";
    const char *expected_representation = "don't care";
    const EasycommData *dont_care = NULL;
    const bool expect_parser_fail = false;

    invariant_test_parse_uplink_frequency(invalid_data, dont_care, expected_representation, expect_parser_fail);
}


void test_parse_downlink_mode_01()
{
    const char *valid_data = "DMabc";
    const char *expected_representation = "DMabc";
    EasycommData expected_result;
    easycommSetDownlinkMode(&expected_result.as.setDownlinkMode);
    expected_result.as.setDownlinkMode.mode[0] = 'a';
    expected_result.as.setDownlinkMode.mode[1] = 'b';
    expected_result.as.setDownlinkMode.mode[2] = 'c';
    const bool expect_parser_success = true;

    invariant_test_parse_downlink_mode(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_downlink_mode_02()
{
    const char *valid_data = "DMab";
    const char *expected_representation = "DMab";
    EasycommData expected_result;
    easycommSetDownlinkMode(&expected_result.as.setDownlinkMode);
    expected_result.as.setDownlinkMode.mode[0] = 'a';
    expected_result.as.setDownlinkMode.mode[1] = 'b';
    expected_result.as.setDownlinkMode.mode[2] = 0;
    const bool expect_parser_success = true;

    invariant_test_parse_downlink_mode(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_downlink_mode_03()
{
    const char *valid_data = "DMa";
    const char *expected_representation = "DMa";
    EasycommData expected_result;
    easycommSetDownlinkMode(&expected_result.as.setDownlinkMode);
    expected_result.as.setDownlinkMode.mode[0] = 'a';
    expected_result.as.setDownlinkMode.mode[1] = 0;
    expected_result.as.setDownlinkMode.mode[2] = 0;
    const bool expect_parser_success = true;

    invariant_test_parse_downlink_mode(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_invalid_downlink_mode_01()
{
    const char *invalid_data = "DM";
    const char *expected_representation = "don't care";
    const EasycommData *dont_care = NULL;
    const bool expect_parser_fail = false;

    invariant_test_parse_downlink_mode(invalid_data, dont_care, expected_representation, expect_parser_fail);
}


void test_parse_uplink_mode_01()
{
    const char *valid_data = "UMabc";
    const char *expected_representation = "UMabc";
    EasycommData expected_result;
    easycommSetUplinkMode(&expected_result.as.setUplinkMode);
    expected_result.as.setUplinkMode.mode[0] = 'a';
    expected_result.as.setUplinkMode.mode[1] = 'b';
    expected_result.as.setUplinkMode.mode[2] = 'c';
    const bool expect_parser_success = true;

    invariant_test_parse_uplink_mode(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_uplink_mode_02()
{
    const char *valid_data = "UMab";
    const char *expected_representation = "UMab";
    EasycommData expected_result;
    easycommSetUplinkMode(&expected_result.as.setUplinkMode);
    expected_result.as.setUplinkMode.mode[0] = 'a';
    expected_result.as.setUplinkMode.mode[1] = 'b';
    expected_result.as.setUplinkMode.mode[2] = 0;
    const bool expect_parser_success = true;

    invariant_test_parse_uplink_mode(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_uplink_mode_03()
{
    const char *valid_data = "UMa";
    const char *expected_representation = "UMa";
    EasycommData expected_result;
    easycommSetUplinkMode(&expected_result.as.setUplinkMode);
    expected_result.as.setUplinkMode.mode[0] = 'a';
    expected_result.as.setUplinkMode.mode[1] = 0;
    expected_result.as.setUplinkMode.mode[2] = 0;
    const bool expect_parser_success = true;

    invariant_test_parse_uplink_mode(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_invalid_uplink_mode_01()
{
    const char *invalid_data = "UM";
    const char *expected_representation = "don't care";
    const EasycommData *dont_care = NULL;
    const bool expect_parser_fail = false;

    invariant_test_parse_uplink_mode(invalid_data, dont_care, expected_representation, expect_parser_fail);
}


void test_parse_uplink_radio_01()
{
    const char *valid_data = "UR0";
    const char *expected_representation = "UR0";
    EasycommData expected_result;
    easycommSetUplinkRadioNumber(&expected_result.as.setUplinkRadio);
    expected_result.as.setUplinkRadio.number = 0;
    const bool expect_parser_success = true;

    invariant_test_parse_uplink_radio(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_uplink_radio_02()
{
    const char *valid_data = "UR999";
    const char *expected_representation = "UR999";
    EasycommData expected_result;
    easycommSetUplinkRadioNumber(&expected_result.as.setUplinkRadio);
    expected_result.as.setUplinkRadio.number = 999;
    const bool expect_parser_success = true;

    invariant_test_parse_uplink_radio(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_invalid_uplink_radio()
{
    const char *invalid_data = "UR";
    const char *expected_representation = "don't care";
    const EasycommData *dont_care = NULL;
    const bool expect_parser_fail = false;

    invariant_test_parse_uplink_radio(invalid_data, dont_care, expected_representation, expect_parser_fail);
}


void test_parse_downlink_radio_01()
{
    const char *valid_data = "DR0";
    const char *expected_representation = "DR0";
    EasycommData expected_result;
    easycommSetDownlinkRadioNumber(&expected_result.as.setDownlinkRadio);
    expected_result.as.setDownlinkRadio.number = 0;
    const bool expect_parser_success = true;

    invariant_test_parse_downlink_radio(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_downlink_radio_02()
{
    const char *valid_data = "DR031";
    const char *expected_representation = "DR31";
    EasycommData expected_result;
    easycommSetDownlinkRadioNumber(&expected_result.as.setDownlinkRadio);
    expected_result.as.setDownlinkRadio.number = 31;
    const bool expect_parser_success = true;

    invariant_test_parse_downlink_radio(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_invalid_downlink_radio()
{
    const char *invalid_data = "DR";
    const char *expected_representation = "don't care";
    const EasycommData *dont_care = NULL;
    const bool expect_parser_fail = false;

    invariant_test_parse_downlink_radio(invalid_data, dont_care, expected_representation, expect_parser_fail);
}

int tests()
{
    UNITY_BEGIN();
    RUN_TEST(test_parse_uplink_frequency_01);
    RUN_TEST(test_parse_uplink_frequency_02);
    RUN_TEST(test_parse_invalid_uplink_frequency_01);
    RUN_TEST(test_parse_invalid_uplink_frequency_02);
    RUN_TEST(test_parse_downlink_frequency_01);
    RUN_TEST(test_parse_downlink_frequency_02);
    RUN_TEST(test_parse_invalid_downlink_frequency_01);
    RUN_TEST(test_parse_invalid_downlink_frequency_02);
    RUN_TEST(test_parse_downlink_mode_01);
    RUN_TEST(test_parse_downlink_mode_02);
    RUN_TEST(test_parse_downlink_mode_03);
    RUN_TEST(test_parse_invalid_downlink_mode_01);
    RUN_TEST(test_parse_uplink_mode_01);
    RUN_TEST(test_parse_uplink_mode_02);
    RUN_TEST(test_parse_uplink_mode_03);
    RUN_TEST(test_parse_invalid_uplink_mode_01);
    RUN_TEST(test_parse_uplink_radio_01);
    RUN_TEST(test_parse_uplink_radio_02);
    RUN_TEST(test_parse_invalid_uplink_radio);
    RUN_TEST(test_parse_downlink_radio_01);
    RUN_TEST(test_parse_downlink_radio_02);
    RUN_TEST(test_parse_invalid_downlink_radio);
    return UNITY_END();
}

void setUp() {}

void tearDown() {}

#include "../helpers/run-tests.h"