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

void invariant_test_parse_velocity_left(const char *data,
                                        const EasycommData *expected,
                                        const char *expected_representation,
                                        bool expect_parser_success)
{
    EasycommData parsed;
    bool is_parsed = easycommParse(data, &parsed);
    char data_as_string[EasycommVelocityLeftMaxLength + 1] = { 0 };

    if(expect_parser_success)
    {
        if(is_parsed)
        {
            TEST_ASSERT_EQUAL(EasycommIdVelocityLeft, parsed.commandId);
            easycommVelocityLeftSprintf(&parsed.as.velocityLeft, data_as_string);
            TEST_ASSERT_EQUAL_STRING(expected_representation, data_as_string);

            TEST_ASSERT_TRUE(easycommVelocityLeftEquals(&parsed.as.velocityLeft, &expected->as.velocityLeft));
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
            easycommVelocityLeftSprintf(&parsed.as.velocityLeft, data_as_string);
            TEST_ASSERT_EQUAL_STRING(expected_representation, data_as_string);
        }
        TEST_ASSERT_EQUAL(EasycommIdInvalid, parsed.commandId);
        TEST_ASSERT_FALSE(is_parsed);
    }
}


void invariant_test_parse_velocity_right(const char *data,
                                         const EasycommData *expected,
                                         const char *expected_representation,
                                         bool expect_parser_success)
{
    EasycommData parsed;
    bool is_parsed = easycommParse(data, &parsed);
    char data_as_string[EasycommVelocityRightMaxLength + 1] = { 0 };

    if(expect_parser_success)
    {
        if(is_parsed)
        {
            TEST_ASSERT_EQUAL(EasycommIdVelocityRight, parsed.commandId);
            easycommVelocityRightSprintf(&parsed.as.velocityRight, data_as_string);
            TEST_ASSERT_EQUAL_STRING(expected_representation, data_as_string);

            TEST_ASSERT_TRUE(easycommVelocityRightEquals(&parsed.as.velocityRight, &expected->as.velocityRight));
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
            easycommVelocityRightSprintf(&parsed.as.velocityRight, data_as_string);
            TEST_ASSERT_EQUAL_STRING(expected_representation, data_as_string);
        }
        TEST_ASSERT_EQUAL(EasycommIdInvalid, parsed.commandId);
        TEST_ASSERT_FALSE(is_parsed);
    }
}


void invariant_test_parse_velocity_up(const char *data,
                                      const EasycommData *expected,
                                      const char *expected_representation,
                                      bool expect_parser_success)
{
    EasycommData parsed;
    bool is_parsed = easycommParse(data, &parsed);
    char data_as_string[EasycommVelocityUpMaxLength + 1] = { 0 };

    if(expect_parser_success)
    {
        if(is_parsed)
        {
            TEST_ASSERT_EQUAL(EasycommIdVelocityUp, parsed.commandId);
            easycommVelocityUpSprintf(&parsed.as.velocityUp, data_as_string);
            TEST_ASSERT_EQUAL_STRING(expected_representation, data_as_string);

            TEST_ASSERT_TRUE(easycommVelocityUpEquals(&parsed.as.velocityUp, &expected->as.velocityUp));
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
            easycommVelocityUpSprintf(&parsed.as.velocityUp, data_as_string);
            TEST_ASSERT_EQUAL_STRING(expected_representation, data_as_string);
        }
        TEST_ASSERT_EQUAL(EasycommIdInvalid, parsed.commandId);
        TEST_ASSERT_FALSE(is_parsed);
    }
}


void invariant_test_parse_velocity_down(const char *data,
                                        const EasycommData *expected,
                                        const char *expected_representation,
                                        bool expect_parser_success)
{
    EasycommData parsed;
    bool is_parsed = easycommParse(data, &parsed);
    char data_as_string[EasycommVelocityDownMaxLength + 1] = { 0 };

    if(expect_parser_success)
    {
        if(is_parsed)
        {
            TEST_ASSERT_EQUAL(EasycommIdVelocityDown, parsed.commandId);
            easycommVelocityDownSprintf(&parsed.as.velocityDown, data_as_string);
            TEST_ASSERT_EQUAL_STRING(expected_representation, data_as_string);

            TEST_ASSERT_TRUE(easycommVelocityDownEquals(&parsed.as.velocityDown, &expected->as.velocityDown));
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
            easycommVelocityDownSprintf(&parsed.as.velocityDown, data_as_string);
            TEST_ASSERT_EQUAL_STRING(expected_representation, data_as_string);
        }
        TEST_ASSERT_EQUAL(EasycommIdInvalid, parsed.commandId);
        TEST_ASSERT_FALSE(is_parsed);
    }
}


void test_parse_velocity_left()
{
    const char *valid_data = "VL00123";
    const char *expected_representation = "VL123";
    EasycommData expected_result;
    easycommVelocityLeft(&expected_result.as.velocityLeft);
    expected_result.as.velocityLeft.milliDegSecond = 123;
    const bool expect_parser_success = true;

    invariant_test_parse_velocity_left(valid_data, &expected_result, expected_representation, expect_parser_success);
}

void test_parse_velocity_right()
{
    const char *valid_data = "VR00123";
    const char *expected_representation = "VR123";
    EasycommData expected_result;
    easycommVelocityRight(&expected_result.as.velocityRight);
    expected_result.as.velocityRight.milliDegSecond = 123;
    const bool expect_parser_success = true;

    invariant_test_parse_velocity_right(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_velocity_up()
{
    const char *valid_data = "VU00123";
    const char *expected_representation = "VU123";
    EasycommData expected_result;
    easycommVelocityUp(&expected_result.as.velocityUp);
    expected_result.as.velocityUp.milliDegSecond = 123;
    const bool expect_parser_success = true;

    invariant_test_parse_velocity_up(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_velocity_down()
{
    const char *valid_data = "VD00123";
    const char *expected_representation = "VD123";
    EasycommData expected_result;
    easycommVelocityDown(&expected_result.as.velocityDown);
    expected_result.as.velocityDown.milliDegSecond = 123;
    const bool expect_parser_success = true;

    invariant_test_parse_velocity_down(valid_data, &expected_result, expected_representation, expect_parser_success);
}


#if defined(ARDUINO_AVR_MEGA2560) || defined(ENV_NATIVE)
int main(int argc, char **argv)
#else

void setup() {}

void loop()
#endif
{
    UNITY_BEGIN();

    RUN_TEST(test_parse_velocity_left);
    RUN_TEST(test_parse_velocity_right);
    RUN_TEST(test_parse_velocity_up);
    RUN_TEST(test_parse_velocity_down);

    UNITY_END();
#ifdef ARDUINO_AVR_MEGA2560
    return 0;
#endif
}
