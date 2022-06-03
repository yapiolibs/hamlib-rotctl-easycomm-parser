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


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_velocity_left,
                                      EasycommSetVelocityLeftMaxLength,
                                      EasycommParserStandard3,
                                      easycommSetVelocityLeft,
                                      EasycommIdSetVelocityLeft,
                                      setVelocityLeft)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_velocity_right,
                                      EasycommSetVelocityRightMaxLength,
                                      EasycommParserStandard3,
                                      easycommSetVelocityRight,
                                      EasycommIdSetVelocityRight,
                                      setVelocityRight)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_velocity_up,
                                      EasycommSetVelocityUpMaxLength,
                                      EasycommParserStandard3,
                                      easycommSetVelocityUp,
                                      EasycommIdSetVelocityUp,
                                      setVelocityUp)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_velocity_down,
                                      EasycommSetVelocityDownMaxLength,
                                      EasycommParserStandard3,
                                      easycommSetVelocityDown,
                                      EasycommIdSetVelocityDown,
                                      setVelocityDown)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_get_velocity_left,
                                      EasycommGetVelocityLeftLength,
                                      EasycommParserStandard3,
                                      easycommGetVelocityLeft,
                                      EasycommIdGetVelocityLeft,
                                      getVelocityLeft)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_get_velocity_right,
                                      EasycommGetVelocityRightLength,
                                      EasycommParserStandard3,
                                      easycommGetVelocityRight,
                                      EasycommIdGetVelocityRight,
                                      getVelocityRight)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_get_velocity_up,
                                      EasycommGetVelocityUpLength,
                                      EasycommParserStandard3,
                                      easycommGetVelocityUp,
                                      EasycommIdGetVelocityUp,
                                      getVelocityUp)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_get_velocity_down,
                                      EasycommGetVelocityDownLength,
                                      EasycommParserStandard3,
                                      easycommGetVelocityDown,
                                      EasycommIdGetVelocityDown,
                                      getVelocityDown)

void test_parse_set_velocity_left()
{
    const char *valid_data = "VL00123";
    const char *expected_representation = "VL123";
    EasycommData expected_result;
    easycommSetVelocityLeft(&expected_result.as.setVelocityLeft);
    expected_result.as.setVelocityLeft.milliDegSecond = 123;
    const bool expect_parser_success = true;

    invariant_test_parse_velocity_left(valid_data, &expected_result, expected_representation, expect_parser_success);
}

void test_parse_set_velocity_right()
{
    const char *valid_data = "VR00123";
    const char *expected_representation = "VR123";
    EasycommData expected_result;
    easycommSetVelocityRight(&expected_result.as.setVelocityRight);
    expected_result.as.setVelocityRight.milliDegSecond = 123;
    const bool expect_parser_success = true;

    invariant_test_parse_velocity_right(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_set_velocity_up()
{
    const char *valid_data = "VU00123";
    const char *expected_representation = "VU123";
    EasycommData expected_result;
    easycommSetVelocityUp(&expected_result.as.setVelocityUp);
    expected_result.as.setVelocityUp.milliDegSecond = 123;
    const bool expect_parser_success = true;

    invariant_test_parse_velocity_up(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_set_velocity_down()
{
    const char *valid_data = "VD00123";
    const char *expected_representation = "VD123";
    EasycommData expected_result;
    easycommSetVelocityDown(&expected_result.as.setVelocityDown);
    expected_result.as.setVelocityDown.milliDegSecond = 123;
    const bool expect_parser_success = true;

    invariant_test_parse_velocity_down(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_get_velocity_left()
{
    const char *valid_data = "VL";
    const char *expected_representation = "VL";
    EasycommData expected_result;
    easycommGetVelocityLeft(&expected_result.as.getVelocityLeft);
    const bool expect_parser_success = true;

    invariant_test_parse_get_velocity_left(valid_data, &expected_result, expected_representation,
                                           expect_parser_success);
}

void test_parse_get_velocity_right()
{
    const char *valid_data = "VR";
    const char *expected_representation = "VR";
    EasycommData expected_result;
    easycommGetVelocityRight(&expected_result.as.getVelocityRight);
    const bool expect_parser_success = true;

    invariant_test_parse_get_velocity_right(valid_data, &expected_result, expected_representation,
                                            expect_parser_success);
}


void test_parse_get_velocity_up()
{
    const char *valid_data = "VU";
    const char *expected_representation = "VU";
    EasycommData expected_result;
    easycommGetVelocityUp(&expected_result.as.getVelocityUp);
    const bool expect_parser_success = true;

    invariant_test_parse_get_velocity_up(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_get_velocity_down()
{
    const char *valid_data = "VD";
    const char *expected_representation = "VD";
    EasycommData expected_result;
    easycommGetVelocityDown(&expected_result.as.getVelocityDown);
    const bool expect_parser_success = true;

    invariant_test_parse_get_velocity_down(valid_data, &expected_result, expected_representation,
                                           expect_parser_success);
}

int tests()
{
    UNITY_BEGIN();
    RUN_TEST(test_parse_set_velocity_left);
    RUN_TEST(test_parse_set_velocity_right);
    RUN_TEST(test_parse_set_velocity_up);
    RUN_TEST(test_parse_set_velocity_down);
    RUN_TEST(test_parse_get_velocity_left);
    RUN_TEST(test_parse_get_velocity_right);
    RUN_TEST(test_parse_get_velocity_up);
    RUN_TEST(test_parse_get_velocity_down);
    return UNITY_END();
}

void setUp() {}

void tearDown() {}

#include "../helpers/run-tests.h"
