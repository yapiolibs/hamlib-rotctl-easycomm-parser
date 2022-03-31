#ifndef ENV_NATIVE

#include <Arduino.h>

#endif

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
            TEST_ASSERT_EQUAL(EasycommIdElevation, parsed.commandId);

            char parsed_to_string[EasycommElevationMaxLength + 1] = { 0 };
            easycommElevationSprintf(&parsed.as.elevation, parsed_to_string);
            TEST_ASSERT_EQUAL_STRING(expected_representation, parsed_to_string);

            TEST_ASSERT_TRUE(easycommElevationEquals(&parsed.as.elevation, &expected->as.elevation));
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


void test_parse_elevation_01()
{
    const char *valid_data = "EL213.4";
    const char *expected_representation = "EL213.4";
    EasycommData expected_result;
    easycommElevation(&expected_result.as.elevation);
    expected_result.as.elevation.elevation = 213.4;
    const bool expect_parser_success = true;

    invariant_test_parse_azimuth_elevation(valid_data, &expected_result, expected_representation,
                                           expect_parser_success);
}

void test_parse_elevation_02()
{
    const char *valid_data = "EL1.1";
    const char *expected_representation = "EL001.1";
    EasycommData expected_result;
    easycommElevation(&expected_result.as.elevation);
    expected_result.as.elevation.elevation = 1.1;
    const bool expect_parser_success = true;

    invariant_test_parse_azimuth_elevation(valid_data, &expected_result, expected_representation,
                                           expect_parser_success);
}

void test_parse_unexpected_elevation()
{
    const char *valid_data = "EL-0.4";
    const char *expected_representation = "EL-00.4";
    EasycommData expected_result;
    easycommElevation(&expected_result.as.elevation);
    expected_result.as.elevation.elevation = -0.4;
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
    RUN_TEST(test_parse_elevation_01);
    RUN_TEST(test_parse_elevation_02);
    RUN_TEST(test_parse_unexpected_elevation);
    UNITY_END();

#ifdef ARDUINO_AVR_MEGA2560
    return 0;
#endif
}
