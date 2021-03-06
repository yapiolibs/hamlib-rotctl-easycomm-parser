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

INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_read_config,
                                      EasycommGetConfigRegisterMaxLength,
                                      EasycommParserStandard3,
                                      easycommGetConfigRegister,
                                      EasycommIdGetConfigRegister,
                                      getConfigRegister)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_write_config,
                                      EasycommSetConfigRegisterMaxLength,
                                      EasycommParserStandard3,
                                      easycommSetConfigRegister,
                                      EasycommIdSetConfigRegister,
                                      setConfigRegister)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_get_status_register,
                                      EasycommGetStatusRegisterLength,
                                      EasycommParserStandard3,
                                      easycommGetStatusRegister,
                                      EasycommIdGetStatusRegister,
                                      getStatusRegister)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_get_error_register,
                                      EasycommGetErrorRegisterLength,
                                      EasycommParserStandard3,
                                      easycommGetErrorRegister,
                                      EasycommIdGetErrorRegister,
                                      getErrorRegister)


void test_parse_get_config_register()
{
    const char *valid_data = "CR123";
    const char *expected_representation = "CR123";
    EasycommData expected_result;
    easycommGetConfigRegister(&expected_result.as.getConfigRegister);
    expected_result.as.getConfigRegister.registerNumber = 123;
    const bool expect_parser_success = true;

    invariant_test_parse_read_config(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_set_config_register()
{
    const char *valid_data = "CW123,0815";
    const char *expected_representation = "CW123,0815";
    EasycommData expected_result;
    easycommSetConfigRegister(&expected_result.as.setConfigRegister);
    expected_result.as.setConfigRegister.registerNumber = 123;
    memcpy(expected_result.as.setConfigRegister.value.as.str, "0815", 4);
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

int tests()
{
    UNITY_BEGIN();
    RUN_TEST(test_parse_get_config_register);
    RUN_TEST(test_parse_set_config_register);
    RUN_TEST(test_parse_get_status_register);
    RUN_TEST(test_parse_get_error_register);
    return UNITY_END();
}

void setUp() {}

void tearDown() {}

#include "../helpers/run-tests.h"
