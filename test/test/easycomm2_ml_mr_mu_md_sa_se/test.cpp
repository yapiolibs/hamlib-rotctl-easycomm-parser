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
                                      easycommMoveLeft,
                                      EasycommIdMoveLeft,
                                      moveLeft)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_move_right,
                                      EasycommMoveRightLength,
                                      EasycommParserStandard2,
                                      easycommMoveRight,
                                      EasycommIdMoveRight,
                                      moveRight)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_move_up,
                                      EasycommMoveUpLength,
                                      EasycommParserStandard2,
                                      easycommMoveUp,
                                      EasycommIdMoveUp,
                                      moveUp)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_move_down,
                                      EasycommMoveDownLength,
                                      EasycommParserStandard2,
                                      easycommMoveDown,
                                      EasycommIdMoveDown,
                                      moveDown)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_stop_azimuth_move,
                                      EasycommStopAzimuthMoveLength,
                                      EasycommParserStandard2,
                                      easycommStopAzimuthMove,
                                      EasycommIdStopAzimuthMove,
                                      stopAzimuthMove)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_stop_elevation_move,
                                      EasycommStopElevationMoveLength,
                                      EasycommParserStandard2,
                                      easycommStopElevationMove,
                                      EasycommIdStopElevationMove,
                                      stopElevationMove)


void test_parse_move_left()
{
    const char *valid_data = "ML";
    const char *expected_representation = "ML";
    EasycommData expected_result;
    easycommMoveLeft(&expected_result.as.moveLeft);
    const bool expect_parser_success = true;

    invariant_test_parse_move_left(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_move_right()
{
    const char *valid_data = "MR";
    const char *expected_representation = "MR";
    EasycommData expected_result;
    easycommMoveRight(&expected_result.as.moveRight);
    const bool expect_parser_success = true;

    invariant_test_parse_move_right(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_move_up()
{
    const char *valid_data = "MU";
    const char *expected_representation = "MU";
    EasycommData expected_result;
    easycommMoveUp(&expected_result.as.moveUp);
    const bool expect_parser_success = true;

    invariant_test_parse_move_up(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_move_down()
{
    const char *valid_data = "MD";
    const char *expected_representation = "MD";
    EasycommData expected_result;
    easycommMoveDown(&expected_result.as.moveDown);
    const bool expect_parser_success = true;

    invariant_test_parse_move_down(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_stop_azimuth_move()
{
    const char *valid_data = "SA";
    const char *expected_representation = "SA";
    EasycommData expected_result;
    easycommStopAzimuthMove(&expected_result.as.stopAzimuthMove);
    const bool expect_parser_success = true;

    invariant_test_parse_stop_azimuth_move(valid_data, &expected_result, expected_representation,
                                           expect_parser_success);
}


void test_parse_stop_elevation_move()
{
    const char *valid_data = "SE";
    const char *expected_representation = "SE";
    EasycommData expected_result;
    easycommStopElevationMove(&expected_result.as.stopElevationMove);
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
