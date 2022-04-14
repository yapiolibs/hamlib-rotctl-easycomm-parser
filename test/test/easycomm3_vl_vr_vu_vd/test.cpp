#if !defined(ENV_NATIVE)
#include <Arduino.h>
#endif

#include "../common-parse-command.h"
#include <easycomm-parser-types-ctors.h>
#include <easycomm-parser-types-operators.h>
#include <easycomm-parser-types-sprintf.h>
#include <easycomm-parser.h>
#include <string.h>
#include <unity.h>


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_velocity_left,
                                      EasycommVelocityLeftMaxLength,
                                      EasycommParserStandard3,
                                      easycommVelocityLeft,
                                      EasycommIdVelocityLeft,
                                      velocityLeft)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_velocity_right,
                                      EasycommVelocityRightMaxLength,
                                      EasycommParserStandard3,
                                      easycommVelocityRight,
                                      EasycommIdVelocityRight,
                                      velocityRight)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_velocity_up,
                                      EasycommVelocityUpMaxLength,
                                      EasycommParserStandard3,
                                      easycommVelocityUp,
                                      EasycommIdVelocityUp,
                                      velocityUp)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_velocity_down,
                                      EasycommVelocityDownMaxLength,
                                      EasycommParserStandard3,
                                      easycommVelocityDown,
                                      EasycommIdVelocityDown,
                                      velocityDown)


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


#if defined(ARDUINO_AVR_MEGA2560) || defined(ENV_NATIVE)
int main(int argc, char **argv)
#else

void setup() {}

void loop()
#endif
{
#if !defined(ARDUINO_AVR_MEGA2560) && !defined(ENV_NATIVE)
    delay(1000);
#endif
    UNITY_BEGIN();
    RUN_TEST(test_parse_velocity_left);
    RUN_TEST(test_parse_velocity_right);
    RUN_TEST(test_parse_velocity_up);
    RUN_TEST(test_parse_velocity_down);
    RUN_TEST(test_parse_get_velocity_left);
    RUN_TEST(test_parse_get_velocity_right);
    RUN_TEST(test_parse_get_velocity_up);
    RUN_TEST(test_parse_get_velocity_down);
    UNITY_END();
#ifdef ARDUINO_AVR_MEGA2560
    return 0;
#endif
}
