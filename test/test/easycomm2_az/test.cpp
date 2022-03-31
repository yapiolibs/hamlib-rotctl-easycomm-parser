#ifndef ENV_NATIVE

#include <Arduino.h>

#endif

#include <easycomm-parser-types-ctors.h>
#include <easycomm-parser-types-operators.h>
#include <easycomm-parser-types-ssprintf.h>
#include <easycomm-parser.h>
#include <stdio.h>
#include <string.h>
#include <unity.h>

void invariant_test_parse_azimuth_elevation(const char *data,
                                            const EasycommData *expected,
                                            const char *expected_representation,
                                            bool expect_parser_success)
{
    EasycommData parsed;
    bool is_parsed = easycommParse(data, &parsed);

    if(expect_parser_success)
    {
        if(is_parsed)
        {
            TEST_ASSERT_EQUAL(EasycommIdAzimuth, parsed.commandId);

            char parsed_to_string[EasycommAzimuthMaxLength + 1] = { 0 };
            easycommAzimuthSprintf(&parsed.as.azimuth, parsed_to_string);
            TEST_ASSERT_EQUAL_STRING(expected_representation, parsed_to_string);

            TEST_ASSERT_TRUE(easycommAzimuthEquals(&parsed.as.azimuth, &expected->as.azimuth));
        }
        else
        {
            TEST_FAIL_MESSAGE("failed to parse");
        }
    }
    else
    {
        TEST_ASSERT_FALSE(is_parsed);
    }
}


void test_parse_azimuth_01()
{
    const char *valid_data = "AZ213.4";
    const char *expected_representation = "AZ213.4";
    EasycommData expected_result;
    easycommAzimuth(&expected_result.as.azimuth);
    expected_result.as.azimuth.azimuth = 213.4;
    const bool expect_parser_success = true;

    invariant_test_parse_azimuth_elevation(valid_data, &expected_result, expected_representation,
                                           expect_parser_success);
}

void test_parse_azimuth_02()
{
    const char *valid_data = "AZ1.1";
    const char *expected_representation = "AZ001.1";
    EasycommData expected_result;
    easycommAzimuth(&expected_result.as.azimuth);
    expected_result.as.azimuth.azimuth = 1.1;
    const bool expect_parser_success = true;

    invariant_test_parse_azimuth_elevation(valid_data, &expected_result, expected_representation,
                                           expect_parser_success);
}

void test_parse_unexpected_azimuth()
{
    const char *valid_data = "AZ-0.4";
    const char *expected_representation = "AZ-00.4";
    EasycommData expected_result;
    easycommAzimuth(&expected_result.as.azimuth);
    expected_result.as.azimuth.azimuth = -0.4;
    const bool expect_parser_success = true;

    invariant_test_parse_azimuth_elevation(valid_data, &expected_result, expected_representation,
                                           expect_parser_success);
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
    RUN_TEST(test_parse_unexpected_azimuth);
    UNITY_END();

#ifdef ARDUINO_AVR_MEGA2560
    return 0;
#endif
}
