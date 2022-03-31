#ifndef ENV_NATIVE

#include <Arduino.h>

#endif

#include <easycomm-parser-types-ctors.h>
#include <easycomm-parser-types-operators.h>
#include <easycomm-parser-types-sprintf.h>
#include <easycomm-parser.h>
#include <stdio.h>
#include <string.h>
#include <unity.h>

void invariant_test_parse_uplink_frequency(const char *data,
                                           const EasycommData *expected,
                                           const char *expected_representation,
                                           bool expect_parser_success)
{
    EasycommData parsed;
    bool is_parsed = easycommParse(data, &parsed);
    char data_as_string[EasycommUplinkFrequencyMaxLength + 1] = { 0 };

    if(expect_parser_success)
    {
        if(is_parsed)
        {
            TEST_ASSERT_EQUAL(EasycommIdUplinkFrequency, parsed.commandId);
            easycommUplinkFrequencySprintf(&parsed.as.uplinkFrequency, data_as_string);
            TEST_ASSERT_EQUAL_STRING(expected_representation, data_as_string);

            TEST_ASSERT_TRUE(easycommUplinkFrequencyEquals(&parsed.as.uplinkFrequency, &expected->as.uplinkFrequency));
        }
        else
        {
            TEST_FAIL_MESSAGE("failed to parse");
        }
    }
    else
    {
        if(is_parsed)
        {
            easycommUplinkFrequencySprintf(&parsed.as.uplinkFrequency, data_as_string);
            TEST_ASSERT_EQUAL_STRING(expected_representation, data_as_string);
        }
        TEST_ASSERT_EQUAL(EasycommIdInvalid, parsed.commandId);
        TEST_ASSERT_FALSE(is_parsed);
    }
}


void invariant_test_parse_downlink_frequency(const char *data,
                                             const EasycommData *expected,
                                             const char *expected_representation,
                                             bool expect_parser_success)
{
    EasycommData parsed;
    bool is_parsed = easycommParse(data, &parsed);
    char data_as_string[EasycommDownlinkFrequencyMaxLength + 1] = { 0 };

    if(expect_parser_success)
    {
        if(is_parsed)
        {
            TEST_ASSERT_EQUAL(EasycommIdDownlinkFrequency, parsed.commandId);
            easycommDownlinkFrequencySprintf(&parsed.as.downlinkFrequency, data_as_string);
            TEST_ASSERT_EQUAL_STRING(expected_representation, data_as_string);

            TEST_ASSERT_TRUE(easycommDownlinkFrequencyEquals(&parsed.as.downlinkFrequency,
                                                             &expected->as.downlinkFrequency));
        }
        else
        {
            TEST_FAIL_MESSAGE("failed to parse");
        }
    }
    else
    {
        if(is_parsed)
        {
            easycommDownlinkFrequencySprintf(&parsed.as.downlinkFrequency, data_as_string);
            TEST_ASSERT_EQUAL_STRING(expected_representation, data_as_string);
        }
        TEST_ASSERT_EQUAL(EasycommIdInvalid, parsed.commandId);
        TEST_ASSERT_FALSE(is_parsed);
    }
}


void invariant_test_parse_uplink_mode(const char *data,
                                      const EasycommData *expected,
                                      const char *expected_representation,
                                      bool expect_parser_success)
{
    EasycommData parsed;
    bool is_parsed = easycommParse(data, &parsed);
    char data_as_string[EasycommUplinkModeMaxLength + 1] = { 0 };

    if(expect_parser_success)
    {
        if(is_parsed)
        {
            TEST_ASSERT_EQUAL(EasycommIdUplinkMode, parsed.commandId);
            easycommUplinkModeSprintf(&parsed.as.uplinkMode, data_as_string);
            TEST_ASSERT_EQUAL_STRING(expected_representation, data_as_string);

            TEST_ASSERT_TRUE(easycommUplinkModeEquals(&parsed.as.uplinkMode, &expected->as.uplinkMode));
        }
        else
        {
            TEST_FAIL_MESSAGE("failed to parse");
        }
    }
    else
    {
        if(is_parsed)
        {
            easycommUplinkModeSprintf(&parsed.as.uplinkMode, data_as_string);
            TEST_ASSERT_EQUAL_STRING(expected_representation, data_as_string);
        }
        TEST_ASSERT_EQUAL(EasycommIdInvalid, parsed.commandId);
        TEST_ASSERT_FALSE(is_parsed);
    }
}


void invariant_test_parse_downlink_mode(const char *data,
                                        const EasycommData *expected,
                                        const char *expected_representation,
                                        bool expect_parser_success)
{
    EasycommData parsed;
    bool is_parsed = easycommParse(data, &parsed);
    char data_as_string[EasycommDownlinkModeMaxLength + 1] = { 0 };

    if(expect_parser_success)
    {
        if(is_parsed)
        {
            TEST_ASSERT_EQUAL(EasycommIdDownlinkMode, parsed.commandId);
            easycommDownlinkModeSprintf(&parsed.as.downlinkMode, data_as_string);
            TEST_ASSERT_EQUAL_STRING(expected_representation, data_as_string);

            TEST_ASSERT_TRUE(easycommDownlinkModeEquals(&parsed.as.downlinkMode, &expected->as.downlinkMode));
        }
        else
        {
            TEST_FAIL_MESSAGE("failed to parse");
        }
    }
    else
    {
        if(is_parsed)
        {
            easycommDownlinkModeSprintf(&parsed.as.downlinkMode, data_as_string);
            TEST_ASSERT_EQUAL_STRING(expected_representation, data_as_string);
        }
        TEST_ASSERT_EQUAL(EasycommIdInvalid, parsed.commandId);
        TEST_ASSERT_FALSE(is_parsed);
    }
}


void invariant_test_parse_uplink_radio(const char *data,
                                       const EasycommData *expected,
                                       const char *expected_representation,
                                       bool expect_parser_success)
{
    EasycommData parsed;
    bool is_parsed = easycommParse(data, &parsed);
    char data_as_string[EasycommUplinkRadioNumberMaxLength + 1] = { 0 };

    if(expect_parser_success)
    {
        if(is_parsed)
        {
            TEST_ASSERT_EQUAL(EasycommIdUplinkRadioNumber, parsed.commandId);
            easycommUplinkRadioNumberSprintf(&parsed.as.uplinkRadio, data_as_string);
            TEST_ASSERT_EQUAL_STRING(expected_representation, data_as_string);

            TEST_ASSERT_TRUE(easycommUplinkRadioNumberEquals(&parsed.as.uplinkRadio, &expected->as.uplinkRadio));
        }
        else
        {
            TEST_FAIL_MESSAGE("failed to parse");
        }
    }
    else
    {
        if(is_parsed)
        {
            easycommUplinkRadioNumberSprintf(&parsed.as.uplinkRadio, data_as_string);
            TEST_ASSERT_EQUAL_STRING(expected_representation, data_as_string);
        }
        TEST_ASSERT_EQUAL(EasycommIdInvalid, parsed.commandId);
        TEST_ASSERT_FALSE(is_parsed);
    }
}


void invariant_test_parse_downlink_radio(const char *data,
                                         const EasycommData *expected,
                                         const char *expected_representation,
                                         bool expect_parser_success)
{
    EasycommData parsed;
    bool is_parsed = easycommParse(data, &parsed);
    char data_as_string[EasycommDownlinkRadioNumberMaxLength + 1] = { 0 };

    if(expect_parser_success)
    {
        if(is_parsed)
        {
            TEST_ASSERT_EQUAL(EasycommIdDownlinkRadioNumber, parsed.commandId);
            easycommDownlinkRadioNumberSprintf(&parsed.as.downlinkRadio, data_as_string);
            TEST_ASSERT_EQUAL_STRING(expected_representation, data_as_string);

            TEST_ASSERT_TRUE(easycommDownlinkRadioNumberEquals(&parsed.as.downlinkRadio,
                                                               &expected->as.downlinkRadio));
        }
        else
        {
            TEST_FAIL_MESSAGE("failed to parse");
        }
    }
    else
    {
        if(is_parsed)
        {
            easycommDownlinkRadioNumberSprintf(&parsed.as.downlinkRadio, data_as_string);
            TEST_ASSERT_EQUAL_STRING(expected_representation, data_as_string);
        }
        TEST_ASSERT_EQUAL(EasycommIdInvalid, parsed.commandId);
        TEST_ASSERT_FALSE(is_parsed);
    }
}


void test_parse_uplink_frequency_01()
{
    const char *valid_data = "UP0";
    const char *expected_representation = "UP0";
    EasycommData expected_result;
    easycommUplinkFrequency(&expected_result.as.uplinkFrequency);
    expected_result.as.uplinkFrequency.frequency.as.uint32 = 0;
    const bool expect_parser_success = true;

    invariant_test_parse_uplink_frequency(valid_data, &expected_result, expected_representation,
                                          expect_parser_success);
}

void test_parse_uplink_frequency_02()
{
    const char *valid_data = "UP999999999";
    const char *expected_representation = "UP999999999";
    EasycommData expected_result;
    easycommUplinkFrequency(&expected_result.as.uplinkFrequency);
    expected_result.as.uplinkFrequency.frequency.as.uint32 = 999999999;
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
    easycommDownlinkFrequency(&expected_result.as.downlinkFrequency);
    expected_result.as.downlinkFrequency.frequency.as.uint32 = 0;
    const bool expect_parser_success = true;

    invariant_test_parse_downlink_frequency(valid_data, &expected_result, expected_representation,
                                            expect_parser_success);
}

void test_parse_downlink_frequency_02()
{
    const char *valid_data = "DN999999999";
    const char *expected_representation = "DN999999999";
    EasycommData expected_result;
    easycommDownlinkFrequency(&expected_result.as.downlinkFrequency);
    expected_result.as.downlinkFrequency.frequency.as.uint32 = 999999999;
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
    easycommDownlinkMode(&expected_result.as.downlinkMode);
    expected_result.as.downlinkMode.mode[0] = 'a';
    expected_result.as.downlinkMode.mode[1] = 'b';
    expected_result.as.downlinkMode.mode[2] = 'c';
    const bool expect_parser_success = true;

    invariant_test_parse_downlink_mode(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_downlink_mode_02()
{
    const char *valid_data = "DMab";
    const char *expected_representation = "DMab";
    EasycommData expected_result;
    easycommDownlinkMode(&expected_result.as.downlinkMode);
    expected_result.as.downlinkMode.mode[0] = 'a';
    expected_result.as.downlinkMode.mode[1] = 'b';
    expected_result.as.downlinkMode.mode[2] = 0;
    const bool expect_parser_success = true;

    invariant_test_parse_downlink_mode(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_downlink_mode_03()
{
    const char *valid_data = "DMa";
    const char *expected_representation = "DMa";
    EasycommData expected_result;
    easycommDownlinkMode(&expected_result.as.downlinkMode);
    expected_result.as.downlinkMode.mode[0] = 'a';
    expected_result.as.downlinkMode.mode[1] = 0;
    expected_result.as.downlinkMode.mode[2] = 0;
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
    easycommUplinkMode(&expected_result.as.uplinkMode);
    expected_result.as.uplinkMode.mode[0] = 'a';
    expected_result.as.uplinkMode.mode[1] = 'b';
    expected_result.as.uplinkMode.mode[2] = 'c';
    const bool expect_parser_success = true;

    invariant_test_parse_uplink_mode(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_uplink_mode_02()
{
    const char *valid_data = "UMab";
    const char *expected_representation = "UMab";
    EasycommData expected_result;
    easycommUplinkMode(&expected_result.as.uplinkMode);
    expected_result.as.uplinkMode.mode[0] = 'a';
    expected_result.as.uplinkMode.mode[1] = 'b';
    expected_result.as.uplinkMode.mode[2] = 0;
    const bool expect_parser_success = true;

    invariant_test_parse_uplink_mode(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_uplink_mode_03()
{
    const char *valid_data = "UMa";
    const char *expected_representation = "UMa";
    EasycommData expected_result;
    easycommUplinkMode(&expected_result.as.uplinkMode);
    expected_result.as.uplinkMode.mode[0] = 'a';
    expected_result.as.uplinkMode.mode[1] = 0;
    expected_result.as.uplinkMode.mode[2] = 0;
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
    easycommUplinkRadioNumber(&expected_result.as.uplinkRadio);
    expected_result.as.uplinkRadio.number = 0;
    const bool expect_parser_success = true;

    invariant_test_parse_uplink_radio(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_uplink_radio_02()
{
    const char *valid_data = "UR999";
    const char *expected_representation = "UR999";
    EasycommData expected_result;
    easycommUplinkRadioNumber(&expected_result.as.uplinkRadio);
    expected_result.as.uplinkRadio.number = 999;
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
    easycommDownlinkRadioNumber(&expected_result.as.downlinkRadio);
    expected_result.as.downlinkRadio.number = 0;
    const bool expect_parser_success = true;

    invariant_test_parse_downlink_radio(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_downlink_radio_02()
{
    const char *valid_data = "DR031";
    const char *expected_representation = "DR31";
    EasycommData expected_result;
    easycommDownlinkRadioNumber(&expected_result.as.downlinkRadio);
    expected_result.as.downlinkRadio.number = 31;
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


#if defined(ARDUINO_AVR_MEGA2560) || defined(ENV_NATIVE)
int main(int argc, char **argv)
#else

void setup() {}

void loop()
#endif
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

    UNITY_END();
#ifdef ARDUINO_AVR_MEGA2560
    return 0;
#endif
}
