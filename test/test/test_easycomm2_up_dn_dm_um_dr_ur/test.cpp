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

INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_set_uplink_frequency,
                                      EasycommSetUplinkFrequencyMaxLength,
                                      EasycommParserStandard2,
                                      easycommSetUplinkFrequency,
                                      EasycommIdSetUplinkFrequency,
                                      setUplinkFrequency)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_get_uplink_frequency,
                                      EasycommGetUplinkFrequencyLength,
                                      EasycommParserStandard2,
                                      easycommGetUplinkFrequency,
                                      EasycommIdGetUplinkFrequency,
                                      getUplinkFrequency)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_set_downlink_frequency,
                                      EasycommSetDownlinkFrequencyMaxLength,
                                      EasycommParserStandard2,
                                      easycommSetDownlinkFrequency,
                                      EasycommIdSetDownlinkFrequency,
                                      setDownlinkFrequency)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_get_downlink_frequency,
                                      EasycommGetDownlinkFrequencyLength,
                                      EasycommParserStandard2,
                                      easycommGetDownlinkFrequency,
                                      EasycommIdGetDownlinkFrequency,
                                      getDownlinkFrequency)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_set_uplink_mode,
                                      EasycommSetUplinkModeMaxLength,
                                      EasycommParserStandard2,
                                      easycommSetUplinkMode,
                                      EasycommIdSetUplinkMode,
                                      setUplinkMode)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_get_uplink_mode,
                                      EasycommGetUplinkModeLength,
                                      EasycommParserStandard2,
                                      easycommGetUplinkMode,
                                      EasycommIdGetUplinkMode,
                                      getUplinkMode)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_set_downlink_mode,
                                      EasycommSetDownlinkModeMaxLength,
                                      EasycommParserStandard2,
                                      easycommSetDownlinkMode,
                                      EasycommIdSetDownlinkMode,
                                      setDownlinkMode)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_get_downlink_mode,
                                      EasycommGetDownlinkModeLength,
                                      EasycommParserStandard2,
                                      easycommGetDownlinkMode,
                                      EasycommIdGetDownlinkMode,
                                      getDownlinkMode)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_set_uplink_radio,
                                      EasycommSetUplinkRadioMaxLength,
                                      EasycommParserStandard2,
                                      easycommSetUplinkRadio,
                                      EasycommIdSetUplinkRadio,
                                      setUplinkRadio)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_get_uplink_radio,
                                      EasycommGetUplinkRadioLength,
                                      EasycommParserStandard2,
                                      easycommGetUplinkRadio,
                                      EasycommIdGetUplinkRadio,
                                      getUplinkRadio)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_set_downlink_radio,
                                      EasycommSetDownlinkRadioMaxLength,
                                      EasycommParserStandard2,
                                      easycommSetDownlinkRadio,
                                      EasycommIdSetDownlinkRadio,
                                      setDownlinkRadio)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_get_downlink_radio,
                                      EasycommGetDownlinkRadioLength,
                                      EasycommParserStandard2,
                                      easycommGetDownlinkRadio,
                                      EasycommIdGetDownlinkRadio,
                                      getDownlinkRadio)


void test_parse_set_uplink_frequency_01()
{
    const char *valid_data = "UP0";
    const char *expected_representation = "UP0";
    EasycommData expected_result;
    easycommSetUplinkFrequency(&expected_result.as.setUplinkFrequency);
    expected_result.as.setUplinkFrequency.frequency.as.uint32 = 0;
    const bool expect_parser_success = true;

    invariant_test_parse_set_uplink_frequency(valid_data, &expected_result, expected_representation,
                                              expect_parser_success);
}

void test_parse_set_uplink_frequency_02()
{
    const char *valid_data = "UP999999999";
    const char *expected_representation = "UP999999999";
    EasycommData expected_result;
    easycommSetUplinkFrequency(&expected_result.as.setUplinkFrequency);
    expected_result.as.setUplinkFrequency.frequency.as.uint32 = 999999999;
    const bool expect_parser_success = true;

    invariant_test_parse_set_uplink_frequency(valid_data, &expected_result, expected_representation,
                                              expect_parser_success);
}


void test_parse_get_uplink_frequency_01()
{
    const char *valid_data = "UP";
    const char *expected_representation = "UP";
    EasycommData expected_result;
    easycommGetUplinkFrequency(&expected_result.as.getUplinkFrequency);
    const bool expect_parser_success = true;

    invariant_test_parse_get_uplink_frequency(valid_data, &expected_result, expected_representation,
                                              expect_parser_success);
}


void test_parse_get_uplink_frequency_02()
{
    const char *invalid_data = "UP5000000000";
    const char *expected_representation = "don't care";
    const EasycommData *dont_care = NULL;
    const bool expect_parser_fail = false;

    invariant_test_parse_set_uplink_frequency(invalid_data, dont_care, expected_representation, expect_parser_fail);
}


void test_parse_set_downlink_frequency_01()
{
    const char *valid_data = "DN0";
    const char *expected_representation = "DN0";
    EasycommData expected_result;
    easycommSetDownlinkFrequency(&expected_result.as.setDownlinkFrequency);
    expected_result.as.setDownlinkFrequency.frequency.as.uint32 = 0;
    const bool expect_parser_success = true;

    invariant_test_parse_set_downlink_frequency(valid_data, &expected_result,
                                                expected_representation, expect_parser_success);
}

void test_parse_set_downlink_frequency_02()
{
    const char *valid_data = "DN999999999";
    const char *expected_representation = "DN999999999";
    EasycommData expected_result;
    easycommSetDownlinkFrequency(&expected_result.as.setDownlinkFrequency);
    expected_result.as.setDownlinkFrequency.frequency.as.uint32 = 999999999;
    const bool expect_parser_success = true;

    invariant_test_parse_set_downlink_frequency(valid_data, &expected_result,
                                                expected_representation, expect_parser_success);
}


void test_parse_get_downlink_frequency_01()
{
    const char *valid_data = "DN";
    const char *expected_representation = "DN";
    EasycommData expected_result;
    easycommGetDownlinkFrequency(&expected_result.as.getDownlinkFrequency);
    const bool expect_parser_success = true;

    invariant_test_parse_get_downlink_frequency(valid_data, &expected_result,
                                                expected_representation, expect_parser_success);
}


void test_parse_invalid_set_downlink_frequency_02()
{
    const char *invalid_data = "DN5000000000";
    const char *expected_representation = "don't care";
    const EasycommData *dont_care = NULL;
    const bool expect_parser_fail = false;

    invariant_test_parse_set_downlink_frequency(invalid_data, dont_care, expected_representation, expect_parser_fail);
}


void test_parse_set_downlink_mode_01()
{
    const char *valid_data = "DMabc";
    const char *expected_representation = "DMabc";
    EasycommData expected_result;
    easycommSetDownlinkMode(&expected_result.as.setDownlinkMode);
    expected_result.as.setDownlinkMode.mode[0] = 'a';
    expected_result.as.setDownlinkMode.mode[1] = 'b';
    expected_result.as.setDownlinkMode.mode[2] = 'c';
    const bool expect_parser_success = true;

    invariant_test_parse_set_downlink_mode(valid_data, &expected_result, expected_representation,
                                           expect_parser_success);
}


void test_parse_set_downlink_mode_02()
{
    const char *valid_data = "DMab";
    const char *expected_representation = "DMab";
    EasycommData expected_result;
    easycommSetDownlinkMode(&expected_result.as.setDownlinkMode);
    expected_result.as.setDownlinkMode.mode[0] = 'a';
    expected_result.as.setDownlinkMode.mode[1] = 'b';
    expected_result.as.setDownlinkMode.mode[2] = 0;
    const bool expect_parser_success = true;

    invariant_test_parse_set_downlink_mode(valid_data, &expected_result, expected_representation,
                                           expect_parser_success);
}


void test_parse_set_downlink_mode_03()
{
    const char *valid_data = "DMa";
    const char *expected_representation = "DMa";
    EasycommData expected_result;
    easycommSetDownlinkMode(&expected_result.as.setDownlinkMode);
    expected_result.as.setDownlinkMode.mode[0] = 'a';
    expected_result.as.setDownlinkMode.mode[1] = 0;
    expected_result.as.setDownlinkMode.mode[2] = 0;
    const bool expect_parser_success = true;

    invariant_test_parse_set_downlink_mode(valid_data, &expected_result, expected_representation,
                                           expect_parser_success);
}


void test_parse_get_downlink_mode_01()
{
    const char *valid_data = "DM";
    const char *expected_representation = "DM";
    EasycommData expected_result;
    easycommGetDownlinkMode(&expected_result.as.getDownlinkMode);
    const bool expect_parser_success = true;

    invariant_test_parse_get_downlink_mode(valid_data, &expected_result, expected_representation,
                                           expect_parser_success);
}


void test_parse_set_uplink_mode_01()
{
    const char *valid_data = "UMabc";
    const char *expected_representation = "UMabc";
    EasycommData expected_result;
    easycommSetUplinkMode(&expected_result.as.setUplinkMode);
    expected_result.as.setUplinkMode.mode[0] = 'a';
    expected_result.as.setUplinkMode.mode[1] = 'b';
    expected_result.as.setUplinkMode.mode[2] = 'c';
    const bool expect_parser_success = true;

    invariant_test_parse_set_uplink_mode(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_set_uplink_mode_02()
{
    const char *valid_data = "UMab";
    const char *expected_representation = "UMab";
    EasycommData expected_result;
    easycommSetUplinkMode(&expected_result.as.setUplinkMode);
    expected_result.as.setUplinkMode.mode[0] = 'a';
    expected_result.as.setUplinkMode.mode[1] = 'b';
    expected_result.as.setUplinkMode.mode[2] = 0;
    const bool expect_parser_success = true;

    invariant_test_parse_set_uplink_mode(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_set_uplink_mode_03()
{
    const char *valid_data = "UMa";
    const char *expected_representation = "UMa";
    EasycommData expected_result;
    easycommSetUplinkMode(&expected_result.as.setUplinkMode);
    expected_result.as.setUplinkMode.mode[0] = 'a';
    expected_result.as.setUplinkMode.mode[1] = 0;
    expected_result.as.setUplinkMode.mode[2] = 0;
    const bool expect_parser_success = true;

    invariant_test_parse_set_uplink_mode(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_get_uplink_mode_01()
{
    const char *invalid_data = "UM";
    const char *expected_representation = "UM";
    EasycommData expected_result;
    easycommGetUplinkMode(&expected_result.as.getUplinkMode);
    const bool expect_parser_success = true;

    invariant_test_parse_get_uplink_mode(invalid_data, &expected_result, expected_representation,
                                         expect_parser_success);
}


void test_parse_set_uplink_radio_01()
{
    const char *valid_data = "UR0";
    const char *expected_representation = "UR0";
    EasycommData expected_result;
    easycommSetUplinkRadio(&expected_result.as.setUplinkRadio);
    expected_result.as.setUplinkRadio.number = 0;
    const bool expect_parser_success = true;

    invariant_test_parse_set_uplink_radio(valid_data, &expected_result, expected_representation,
                                          expect_parser_success);
}


void test_parse_set_uplink_radio_02()
{
    const char *valid_data = "UR999";
    const char *expected_representation = "UR999";
    EasycommData expected_result;
    easycommSetUplinkRadio(&expected_result.as.setUplinkRadio);
    expected_result.as.setUplinkRadio.number = 999;
    const bool expect_parser_success = true;

    invariant_test_parse_set_uplink_radio(valid_data, &expected_result, expected_representation,
                                          expect_parser_success);
}


void test_parse_get_uplink_radio_01()
{
    const char *valid_data = "UR";
    const char *expected_representation = "UR";
    EasycommData expected_result;
    easycommGetUplinkRadio(&expected_result.as.getUplinkRadio);
    const bool expect_parser_success = true;

    invariant_test_parse_get_uplink_radio(valid_data, &expected_result, expected_representation,
                                          expect_parser_success);
}


void test_parse_set_downlink_radio_01()
{
    const char *valid_data = "DR0";
    const char *expected_representation = "DR0";
    EasycommData expected_result;
    easycommSetDownlinkRadio(&expected_result.as.setDownlinkRadio);
    expected_result.as.setDownlinkRadio.number = 0;
    const bool expect_parser_success = true;

    invariant_test_parse_set_downlink_radio(valid_data, &expected_result, expected_representation,
                                            expect_parser_success);
}


void test_parse_set_downlink_radio_02()
{
    const char *valid_data = "DR031";
    const char *expected_representation = "DR31";
    EasycommData expected_result;
    easycommSetDownlinkRadio(&expected_result.as.setDownlinkRadio);
    expected_result.as.setDownlinkRadio.number = 31;
    const bool expect_parser_success = true;

    invariant_test_parse_set_downlink_radio(valid_data, &expected_result, expected_representation,
                                            expect_parser_success);
}


void test_parse_get_downlink_radio_01()
{
    const char *valid_data = "DR";
    const char *expected_representation = "DR";
    EasycommData expected_result;
    easycommGetDownlinkRadio(&expected_result.as.getDownlinkRadio);
    const bool expect_parser_success = true;

    invariant_test_parse_get_downlink_radio(valid_data, &expected_result, expected_representation,
                                            expect_parser_success);
}

int tests()
{
    UNITY_BEGIN();
    RUN_TEST(test_parse_set_uplink_frequency_01);
    RUN_TEST(test_parse_set_uplink_frequency_02);
    RUN_TEST(test_parse_get_uplink_frequency_01);
    RUN_TEST(test_parse_get_uplink_frequency_02);
    RUN_TEST(test_parse_set_downlink_frequency_01);
    RUN_TEST(test_parse_set_downlink_frequency_02);
    RUN_TEST(test_parse_get_downlink_frequency_01);
    RUN_TEST(test_parse_invalid_set_downlink_frequency_02);
    RUN_TEST(test_parse_set_downlink_mode_01);
    RUN_TEST(test_parse_set_downlink_mode_02);
    RUN_TEST(test_parse_set_downlink_mode_03);
    RUN_TEST(test_parse_get_downlink_mode_01);
    RUN_TEST(test_parse_set_uplink_mode_01);
    RUN_TEST(test_parse_set_uplink_mode_02);
    RUN_TEST(test_parse_set_uplink_mode_03);
    RUN_TEST(test_parse_get_uplink_mode_01);
    RUN_TEST(test_parse_set_uplink_radio_01);
    RUN_TEST(test_parse_set_uplink_radio_02);
    RUN_TEST(test_parse_get_uplink_radio_01);
    RUN_TEST(test_parse_set_downlink_radio_01);
    RUN_TEST(test_parse_set_downlink_radio_02);
    RUN_TEST(test_parse_get_downlink_radio_01);
    return UNITY_END();
}

void setUp() {}

void tearDown() {}

#include "../helpers/run-tests.h"
