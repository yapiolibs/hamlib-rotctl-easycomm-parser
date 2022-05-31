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

INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_move_left,
                                      EasycommMoveLeftLength,
                                      EasycommParserStandard2,
                                      easycommDoMoveLeft,
                                      EasycommIdMoveLeft,
                                      doMoveLeft)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_move_right,
                                      EasycommMoveRightLength,
                                      EasycommParserStandard2,
                                      easycommDoMoveRight,
                                      EasycommIdMoveRight,
                                      doMoveRight)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_move_up,
                                      EasycommMoveUpLength,
                                      EasycommParserStandard2,
                                      easycommDoMoveUp,
                                      EasycommIdMoveUp,
                                      doMoveUp)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_move_down,
                                      EasycommMoveDownLength,
                                      EasycommParserStandard2,
                                      easycommDoMoveDown,
                                      EasycommIdMoveDown,
                                      doMoveDown)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_stop_azimuth_move,
                                      EasycommStopAzimuthMoveLength,
                                      EasycommParserStandard2,
                                      easycommDoStopAzimuthMove,
                                      EasycommIdStopAzimuthMove,
                                      doStopAzimuthMove)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_stop_elevation_move,
                                      EasycommStopElevationMoveLength,
                                      EasycommParserStandard2,
                                      easycommDoStopElevationMove,
                                      EasycommIdStopElevationMove,
                                      doStopElevationMove)


void test_parse_move_left()
{
    const char *valid_data = "ML";
    const char *expected_representation = "ML";
    EasycommData expected_result;
    easycommDoMoveLeft(&expected_result.as.doMoveLeft);
    const bool expect_parser_success = true;

    invariant_test_parse_move_left(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_move_right()
{
    const char *valid_data = "MR";
    const char *expected_representation = "MR";
    EasycommData expected_result;
    easycommDoMoveRight(&expected_result.as.doMoveRight);
    const bool expect_parser_success = true;

    invariant_test_parse_move_right(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_move_up()
{
    const char *valid_data = "MU";
    const char *expected_representation = "MU";
    EasycommData expected_result;
    easycommDoMoveUp(&expected_result.as.doMoveUp);
    const bool expect_parser_success = true;

    invariant_test_parse_move_up(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_move_down()
{
    const char *valid_data = "MD";
    const char *expected_representation = "MD";
    EasycommData expected_result;
    easycommDoMoveDown(&expected_result.as.doMoveDown);
    const bool expect_parser_success = true;

    invariant_test_parse_move_down(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_stop_azimuth_move()
{
    const char *valid_data = "SA";
    const char *expected_representation = "SA";
    EasycommData expected_result;
    easycommDoStopAzimuthMove(&expected_result.as.doStopAzimuthMove);
    const bool expect_parser_success = true;

    invariant_test_parse_stop_azimuth_move(valid_data, &expected_result, expected_representation,
                                           expect_parser_success);
}


void test_parse_stop_elevation_move()
{
    const char *valid_data = "SE";
    const char *expected_representation = "SE";
    EasycommData expected_result;
    easycommDoStopElevationMove(&expected_result.as.doStopElevationMove);
    const bool expect_parser_success = true;

    invariant_test_parse_stop_elevation_move(valid_data, &expected_result, expected_representation,
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
    RUN_TEST(test_parse_move_left);
    RUN_TEST(test_parse_move_right);
    RUN_TEST(test_parse_move_up);
    RUN_TEST(test_parse_move_down);
    RUN_TEST(test_parse_stop_azimuth_move);
    RUN_TEST(test_parse_stop_elevation_move);
    UNITY_END();
#ifdef ARDUINO_AVR_MEGA2560
    return 0;
#endif
}
