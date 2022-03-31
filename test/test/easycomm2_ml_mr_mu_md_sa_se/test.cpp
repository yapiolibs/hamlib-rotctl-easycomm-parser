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

void invariant_test_parse_move_left(const char *data,
                                    const EasycommData *expected,
                                    const char *expected_representation,
                                    bool expect_parser_success)
{
    EasycommData parsed;
    bool is_parsed = easycommParse(data, &parsed);
    char data_as_string[EasycommMoveLeftLength + 1] = { 0 };

    if(expect_parser_success)
    {
        if(is_parsed)
        {
            TEST_ASSERT_EQUAL(EasycommIdMoveLeft, parsed.commandId);
            easycommMoveLeftSprintf(&parsed.as.moveLeft, data_as_string);
            TEST_ASSERT_EQUAL_STRING(expected_representation, data_as_string);

            TEST_ASSERT_TRUE(easycommMoveLeftEquals(&parsed.as.moveLeft, &expected->as.moveLeft));
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
            easycommMoveLeftSprintf(&parsed.as.moveLeft, data_as_string);
            TEST_ASSERT_EQUAL_STRING(expected_representation, data_as_string);
        }
        TEST_ASSERT_EQUAL(EasycommIdInvalid, parsed.commandId);
        TEST_ASSERT_FALSE(is_parsed);
    }
}


void invariant_test_parse_move_right(const char *data,
                                     const EasycommData *expected,
                                     const char *expected_representation,
                                     bool expect_parser_success)
{
    EasycommData parsed;
    bool is_parsed = easycommParse(data, &parsed);
    char data_as_string[EasycommMoveRightLength + 1] = { 0 };

    if(expect_parser_success)
    {
        if(is_parsed)
        {
            TEST_ASSERT_EQUAL(EasycommIdMoveRight, parsed.commandId);
            easycommMoveRightSprintf(&parsed.as.moveRight, data_as_string);
            TEST_ASSERT_EQUAL_STRING(expected_representation, data_as_string);

            TEST_ASSERT_TRUE(easycommMoveRightEquals(&parsed.as.moveRight, &expected->as.moveRight));
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
            easycommMoveRightSprintf(&parsed.as.moveRight, data_as_string);
            TEST_ASSERT_EQUAL_STRING(expected_representation, data_as_string);
        }
        TEST_ASSERT_EQUAL(EasycommIdInvalid, parsed.commandId);
        TEST_ASSERT_FALSE(is_parsed);
    }
}


void invariant_test_parse_move_up(const char *data,
                                  const EasycommData *expected,
                                  const char *expected_representation,
                                  bool expect_parser_success)
{
    EasycommData parsed;
    bool is_parsed = easycommParse(data, &parsed);
    char data_as_string[EasycommMoveUpLength + 1] = { 0 };

    if(expect_parser_success)
    {
        if(is_parsed)
        {
            TEST_ASSERT_EQUAL(EasycommIdMoveUp, parsed.commandId);
            easycommMoveUpSprintf(&parsed.as.moveUp, data_as_string);
            TEST_ASSERT_EQUAL_STRING(expected_representation, data_as_string);

            TEST_ASSERT_TRUE(easycommMoveUpEquals(&parsed.as.moveUp, &expected->as.moveUp));
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
            easycommMoveUpSprintf(&parsed.as.moveUp, data_as_string);
            TEST_ASSERT_EQUAL_STRING(expected_representation, data_as_string);
        }
        TEST_ASSERT_EQUAL(EasycommIdInvalid, parsed.commandId);
        TEST_ASSERT_FALSE(is_parsed);
    }
}


void invariant_test_parse_move_down(const char *data,
                                    const EasycommData *expected,
                                    const char *expected_representation,
                                    bool expect_parser_success)
{
    EasycommData parsed;
    bool is_parsed = easycommParse(data, &parsed);
    char data_as_string[EasycommMoveDownLength + 1] = { 0 };

    if(expect_parser_success)
    {
        if(is_parsed)
        {
            TEST_ASSERT_EQUAL(EasycommIdMoveDown, parsed.commandId);
            easycommMoveDownSprintf(&parsed.as.moveDown, data_as_string);
            TEST_ASSERT_EQUAL_STRING(expected_representation, data_as_string);

            TEST_ASSERT_TRUE(easycommMoveDownEquals(&parsed.as.moveDown, &expected->as.moveDown));
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
            easycommMoveDownSprintf(&parsed.as.moveDown, data_as_string);
            TEST_ASSERT_EQUAL_STRING(expected_representation, data_as_string);
        }
        TEST_ASSERT_EQUAL(EasycommIdInvalid, parsed.commandId);
        TEST_ASSERT_FALSE(is_parsed);
    }
}


void invariant_test_parse_stop_azimuth_move(const char *data,
                                            const EasycommData *expected,
                                            const char *expected_representation,
                                            bool expect_parser_success)
{
    EasycommData parsed;
    bool is_parsed = easycommParse(data, &parsed);
    char data_as_string[EasycommStopAzimuthMoveLength + 1] = { 0 };

    if(expect_parser_success)
    {
        if(is_parsed)
        {
            TEST_ASSERT_EQUAL(EasycommIdStopAzimuthMove, parsed.commandId);
            easycommStopAzimuthMoveSprintf(&parsed.as.stopAzimuthMove, data_as_string);
            TEST_ASSERT_EQUAL_STRING(expected_representation, data_as_string);

            TEST_ASSERT_TRUE(easycommStopAzimuthMoveEquals(&parsed.as.stopAzimuthMove, &expected->as.stopAzimuthMove));
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
            easycommStopAzimuthMoveSprintf(&parsed.as.stopAzimuthMove, data_as_string);
            TEST_ASSERT_EQUAL_STRING(expected_representation, data_as_string);
        }
        TEST_ASSERT_EQUAL(EasycommIdInvalid, parsed.commandId);
        TEST_ASSERT_FALSE(is_parsed);
    }
}


void invariant_test_parse_stop_elevation_move(const char *data,
                                              const EasycommData *expected,
                                              const char *expected_representation,
                                              bool expect_parser_success)
{
    EasycommData parsed;
    bool is_parsed = easycommParse(data, &parsed);
    char data_as_string[EasycommStopElevationMoveLength + 1] = { 0 };

    if(expect_parser_success)
    {
        if(is_parsed)
        {
            TEST_ASSERT_EQUAL(EasycommIdStopElevationMove, parsed.commandId);
            easycommStopElevationMoveSprintf(&parsed.as.stopElevationMove, data_as_string);
            TEST_ASSERT_EQUAL_STRING(expected_representation, data_as_string);

            TEST_ASSERT_TRUE(easycommStopElevationMoveEquals(&parsed.as.stopElevationMove,
                                                             &expected->as.stopElevationMove));
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
            easycommStopElevationMoveSprintf(&parsed.as.stopElevationMove, data_as_string);
            TEST_ASSERT_EQUAL_STRING(expected_representation, data_as_string);
        }
        TEST_ASSERT_EQUAL(EasycommIdInvalid, parsed.commandId);
        TEST_ASSERT_FALSE(is_parsed);
    }
}


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
