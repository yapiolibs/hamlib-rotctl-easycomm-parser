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

INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_move_left,
                                      EasycommDoMoveLeftLength,
                                      EasycommParserStandard2,
                                      easycommDoMoveLeft,
                                      EasycommIdDoMoveLeft,
                                      doMoveLeft)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_move_right,
                                      EasycommDoMoveRightLength,
                                      EasycommParserStandard2,
                                      easycommDoMoveRight,
                                      EasycommIdDoMoveRight,
                                      doMoveRight)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_move_up,
                                      EasycommDoMoveUpLength,
                                      EasycommParserStandard2,
                                      easycommDoMoveUp,
                                      EasycommIdDoMoveUp,
                                      doMoveUp)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_move_down,
                                      EasycommDoMoveDownLength,
                                      EasycommParserStandard2,
                                      easycommDoMoveDown,
                                      EasycommIdDoMoveDown,
                                      doMoveDown)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_stop_azimuth_move,
                                      EasycommDoStopAzimuthMoveLength,
                                      EasycommParserStandard2,
                                      easycommDoStopAzimuthMove,
                                      EasycommIdDoStopAzimuthMove,
                                      doStopAzimuthMove)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_stop_elevation_move,
                                      EasycommDoStopElevationMoveLength,
                                      EasycommParserStandard2,
                                      easycommDoStopElevationMove,
                                      EasycommIdDoStopElevationMove,
                                      doStopElevationMove)


void test_parse_do_move_left()
{
    const char *valid_data = "ML";
    const char *expected_representation = "ML";
    EasycommData expected_result;
    easycommDoMoveLeft(&expected_result.as.doMoveLeft);
    const bool expect_parser_success = true;

    invariant_test_parse_move_left(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_do_move_right()
{
    const char *valid_data = "MR";
    const char *expected_representation = "MR";
    EasycommData expected_result;
    easycommDoMoveRight(&expected_result.as.doMoveRight);
    const bool expect_parser_success = true;

    invariant_test_parse_move_right(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_do_move_up()
{
    const char *valid_data = "MU";
    const char *expected_representation = "MU";
    EasycommData expected_result;
    easycommDoMoveUp(&expected_result.as.doMoveUp);
    const bool expect_parser_success = true;

    invariant_test_parse_move_up(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_do_move_down()
{
    const char *valid_data = "MD";
    const char *expected_representation = "MD";
    EasycommData expected_result;
    easycommDoMoveDown(&expected_result.as.doMoveDown);
    const bool expect_parser_success = true;

    invariant_test_parse_move_down(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_do_stop_azimuth_move()
{
    const char *valid_data = "SA";
    const char *expected_representation = "SA";
    EasycommData expected_result;
    easycommDoStopAzimuthMove(&expected_result.as.doStopAzimuthMove);
    const bool expect_parser_success = true;

    invariant_test_parse_stop_azimuth_move(valid_data, &expected_result, expected_representation,
                                           expect_parser_success);
}


void test_parse_do_stop_elevation_move()
{
    const char *valid_data = "SE";
    const char *expected_representation = "SE";
    EasycommData expected_result;
    easycommDoStopElevationMove(&expected_result.as.doStopElevationMove);
    const bool expect_parser_success = true;

    invariant_test_parse_stop_elevation_move(valid_data, &expected_result, expected_representation,
                                             expect_parser_success);
}

int tests()
{
    UNITY_BEGIN();
    RUN_TEST(test_parse_do_move_left);
    RUN_TEST(test_parse_do_move_right);
    RUN_TEST(test_parse_do_move_up);
    RUN_TEST(test_parse_do_move_down);
    RUN_TEST(test_parse_do_stop_azimuth_move);
    RUN_TEST(test_parse_do_stop_elevation_move);
    return UNITY_END();
}

void setUp() {}

void tearDown() {}

#include "../helpers/run-tests.h"
