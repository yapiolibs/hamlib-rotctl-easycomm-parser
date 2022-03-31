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

void invariant_test_parse_read_config(const char *data,
                                      const EasycommData *expected,
                                      const char *expected_representation,
                                      bool expect_parser_success)
{
    EasycommData parsed;
    bool is_parsed = easycommParse(data, &parsed);
    char data_as_string[EasycommReadConfigMaxLength + 1] = { 0 };

    if(expect_parser_success)
    {
        if(is_parsed)
        {
            TEST_ASSERT_EQUAL(EasycommIdReadConfig, parsed.commandId);
            easycommReadConfigSprintf(&parsed.as.readConfig, data_as_string);
            TEST_ASSERT_EQUAL_STRING(expected_representation, data_as_string);
            TEST_ASSERT_TRUE(easycommReadConfigEquals(&parsed.as.readConfig, &expected->as.readConfig));
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
            easycommReadConfigSprintf(&parsed.as.readConfig, data_as_string);
            TEST_ASSERT_EQUAL_STRING(expected_representation, data_as_string);
        }
        TEST_ASSERT_EQUAL(EasycommIdInvalid, parsed.commandId);
        TEST_ASSERT_FALSE(is_parsed);
    }
}


void invariant_test_parse_write_config(const char *data,
                                       const EasycommData *expected,
                                       const char *expected_representation,
                                       bool expect_parser_success)
{
    EasycommData parsed;
    bool is_parsed = easycommParse(data, &parsed);
    char data_as_string[EasycommWriteConfigMaxLength + 1] = { 0 };

    if(expect_parser_success)
    {
        if(is_parsed)
        {
            TEST_ASSERT_EQUAL(EasycommIdWriteConfig, parsed.commandId);
            easycommWriteConfigSprintf(&parsed.as.writeConfig, data_as_string);
            TEST_ASSERT_EQUAL_STRING(expected_representation, data_as_string);
            TEST_ASSERT_TRUE(easycommWriteConfigEquals(&parsed.as.writeConfig, &expected->as.writeConfig));
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
            easycommWriteConfigSprintf(&parsed.as.writeConfig, data_as_string);
            TEST_ASSERT_EQUAL_STRING(expected_representation, data_as_string);
        }
        TEST_ASSERT_EQUAL(EasycommIdInvalid, parsed.commandId);
        TEST_ASSERT_FALSE(is_parsed);
    }
}


void invariant_test_parse_get_status_register(const char *data,
                                              const EasycommData *expected,
                                              const char *expected_representation,
                                              bool expect_parser_success)
{
    EasycommData parsed;
    bool is_parsed = easycommParse(data, &parsed);
    char data_as_string[EasycommGetStatusRegisterLength + 1] = { 0 };

    if(expect_parser_success)
    {
        if(is_parsed)
        {
            TEST_ASSERT_EQUAL(EasycommIdGetStatusRegister, parsed.commandId);
            easycommGetStatusRegisterSprintf(&parsed.as.getStatusRegister, data_as_string);
            TEST_ASSERT_EQUAL_STRING(expected_representation, data_as_string);

            TEST_ASSERT_TRUE(easycommGetStatusRegisterEquals(&parsed.as.getStatusRegister,
                                                             &expected->as.getStatusRegister));
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
            easycommGetStatusRegisterSprintf(&parsed.as.getStatusRegister, data_as_string);
            TEST_ASSERT_EQUAL_STRING(expected_representation, data_as_string);
        }
        TEST_ASSERT_EQUAL(EasycommIdInvalid, parsed.commandId);
        TEST_ASSERT_FALSE(is_parsed);
    }
}


void invariant_test_parse_get_error_register(const char *data,
                                             const EasycommData *expected,
                                             const char *expected_representation,
                                             bool expect_parser_success)
{
    EasycommData parsed;
    bool is_parsed = easycommParse(data, &parsed);
    char data_as_string[EasycommGetErrorRegisterLength + 1] = { 0 };

    if(expect_parser_success)
    {
        if(is_parsed)
        {
            TEST_ASSERT_EQUAL(EasycommIdGetErrorRegister, parsed.commandId);
            easycommGetErrorRegisterSprintf(&parsed.as.getErrorRegister, data_as_string);
            TEST_ASSERT_EQUAL_STRING(expected_representation, data_as_string);

            TEST_ASSERT_TRUE(easycommGetErrorRegisterEquals(&parsed.as.getErrorRegister,
                                                            &expected->as.getErrorRegister));
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
            easycommGetErrorRegisterSprintf(&parsed.as.getErrorRegister, data_as_string);
            TEST_ASSERT_EQUAL_STRING(expected_representation, data_as_string);
        }
        TEST_ASSERT_EQUAL(EasycommIdInvalid, parsed.commandId);
        TEST_ASSERT_FALSE(is_parsed);
    }
}


void test_parse_read_config()
{
    const char *valid_data = "CR123";
    const char *expected_representation = "CR123";
    EasycommData expected_result;
    easycommReadConfig(&expected_result.as.readConfig);
    expected_result.as.readConfig.registerNumber = 123;
    const bool expect_parser_success = true;

    invariant_test_parse_read_config(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_write_config()
{
    const char *valid_data = "CW123,0815";
    const char *expected_representation = "CW123,815";
    EasycommData expected_result;
    easycommWriteConfig(&expected_result.as.writeConfig);
    expected_result.as.writeConfig.registerNumber = 123;
    expected_result.as.writeConfig.value.as.int32 = 815;
    const bool expect_parser_success = true;

    invariant_test_parse_write_config(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_get_status_register()
{
    const char *valid_data = "GS";
    const char *expected_representation = "GS";
    EasycommData expected_result;
    easycommGetStatusRegister(&expected_result.as.getStatusRegister);
    const bool expect_parser_success = true;

    invariant_test_parse_get_status_register(valid_data, &expected_result, expected_representation,
                                             expect_parser_success);
}


void test_parse_get_error_register()
{
    const char *valid_data = "GE";
    const char *expected_representation = "GE";
    EasycommData expected_result;
    easycommGetErrorRegister(&expected_result.as.getErrorRegister);
    const bool expect_parser_success = true;

    invariant_test_parse_get_error_register(valid_data, &expected_result, expected_representation,
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

    RUN_TEST(test_parse_read_config);
    RUN_TEST(test_parse_write_config);
    RUN_TEST(test_parse_get_status_register);
    RUN_TEST(test_parse_get_error_register);

    UNITY_END();
#ifdef ARDUINO_AVR_MEGA2560
    return 0;
#endif
}
