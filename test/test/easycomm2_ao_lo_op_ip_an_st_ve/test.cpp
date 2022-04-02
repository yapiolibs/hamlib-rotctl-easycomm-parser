#ifndef ENV_NATIVE

#include <Arduino.h>

#endif

#include "../common.h"
#include <easycomm-parser-types-ctors.h>
#include <easycomm-parser-types-operators.h>
#include <easycomm-parser-types-sprintf.h>
#include <easycomm-parser.h>
#include <stdio.h>
#include <string.h>
#include <unity.h>

INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_acquition_of_signal,
                                      EasycommAcquisitionOfSignalLength,
                                      EasycommParserStandard2,
                                      easycommAcquisitionOfSignal,
                                      EasycommIdAcquisitionOfSignal,
                                      acquisitionOfSignal)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_loss_of_signal,
                                      EasycommLossOfSignalLength,
                                      EasycommParserStandard2,
                                      easycommLossOfSignal,
                                      EasycommIdLossOfSignal,
                                      lossOfSignal)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_set_output,
                                      EasycommSetOutputMaxLength,
                                      EasycommParserStandard2,
                                      easycommSetOutput,
                                      EasycommIdSetOutput,
                                      setOutput)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_read_input,
                                      EasycommReadInputMaxLength,
                                      EasycommParserStandard2,
                                      easycommReadInput,
                                      EasycommIdReadInput,
                                      readInput)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_read_analogue_input,
                                      EasycommReadAnalogueInputMaxLength,
                                      EasycommParserStandard2,
                                      easycommReadAnalogueInput,
                                      EasycommIdReadAnalogueInput,
                                      readAnalogueInput)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_set_time,
                                      EasycommSetTimeMaxLength,
                                      EasycommParserStandard2,
                                      easycommSetTime,
                                      EasycommIdSetTime,
                                      setTime)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_request_version,
                                      EasycommRequestVersionLength,
                                      EasycommParserStandard2,
                                      easycommRequestVersion,
                                      EasycommIdRequestVersion,
                                      requestVersion)


void test_parse_acquisition_of_signal()
{
    const char *valid_data = "AO";
    const char *expected_representation = "AO";
    EasycommData expected_result;
    easycommAcquisitionOfSignal(&expected_result.as.acquisitionOfSignal);
    const bool expect_parser_success = true;

    invariant_test_parse_acquition_of_signal(valid_data, &expected_result, expected_representation,
                                             expect_parser_success);
}


void test_parse_loss_of_signal()
{
    const char *valid_data = "LO";
    const char *expected_representation = "LO";
    EasycommData expected_result;
    easycommLossOfSignal(&expected_result.as.lossOfSignal);
    const bool expect_parser_success = true;

    invariant_test_parse_loss_of_signal(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_set_output_01()
{
    const char *valid_data = "OP01,2";
    const char *expected_representation = "OP1,1";
    EasycommData expected_result;
    easycommSetOutput(&expected_result.as.setOutput);
    expected_result.as.setOutput.number = 1;
    expected_result.as.setOutput.value = true;
    const bool expect_parser_success = true;

    invariant_test_parse_set_output(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_set_output_02()
{
    const char *valid_data = "OP002,0";
    const char *expected_representation = "OP2,0";
    EasycommData expected_result;
    easycommSetOutput(&expected_result.as.setOutput);
    expected_result.as.setOutput.number = 2;
    const bool expect_parser_success = true;

    invariant_test_parse_set_output(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_read_input_01()
{
    const char *valid_data = "IP13";
    const char *expected_representation = "IP13";
    EasycommData expected_result;
    easycommReadInput(&expected_result.as.readInput);
    expected_result.as.readInput.number = 13;
    const bool expect_parser_success = true;

    invariant_test_parse_read_input(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_read_input_02()
{
    const char *valid_data = "IP002";
    const char *expected_representation = "IP2";
    EasycommData expected_result;
    easycommReadInput(&expected_result.as.readInput);
    expected_result.as.readInput.number = 2;
    const bool expect_parser_success = true;

    invariant_test_parse_read_input(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_read_analogue_input_01()
{
    const char *valid_data = "AN13";
    const char *expected_representation = "AN13";
    EasycommData expected_result;
    easycommReadAnalogueInput(&expected_result.as.readAnalogueInput);
    expected_result.as.readInput.number = 13;
    const bool expect_parser_success = true;

    invariant_test_parse_read_analogue_input(valid_data, &expected_result, expected_representation,
                                             expect_parser_success);
}


void test_parse_read_analogue_input_02()
{
    const char *valid_data = "AN000";
    const char *expected_representation = "AN0";
    EasycommData expected_result;
    easycommReadAnalogueInput(&expected_result.as.readAnalogueInput);
    expected_result.as.readAnalogueInput.number = 0;
    const bool expect_parser_success = true;

    invariant_test_parse_read_analogue_input(valid_data, &expected_result, expected_representation,
                                             expect_parser_success);
}


void test_parse_set_time_01()
{
    const char *valid_data = "ST11:22:33:44:55:66";
    const char *expected_representation = "ST11:22:33:44:55:66";
    EasycommData expected_result;
    easycommSetTime(&expected_result.as.setTime);
    expected_result.as.setTime.year = 11;
    expected_result.as.setTime.month = 22;
    expected_result.as.setTime.day = 33;
    expected_result.as.setTime.hour = 44;
    expected_result.as.setTime.minute = 55;
    expected_result.as.setTime.second = 66;
    const bool expect_parser_success = true;

    invariant_test_parse_set_time(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_set_time_02()
{
    const char *valid_data = "ST01:02:03:04:05:06";
    const char *expected_representation = "ST01:02:03:04:05:06";
    EasycommData expected_result;
    easycommSetTime(&expected_result.as.setTime);
    expected_result.as.setTime.year = 1;
    expected_result.as.setTime.month = 2;
    expected_result.as.setTime.day = 3;
    expected_result.as.setTime.hour = 4;
    expected_result.as.setTime.minute = 5;
    expected_result.as.setTime.second = 6;
    const bool expect_parser_success = true;

    invariant_test_parse_set_time(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_set_time_03()
{
    const char *valid_data = "ST1:2:3:4:5:6";
    const char *expected_representation = "ST01:02:03:04:05:06";
    EasycommData expected_result;
    easycommSetTime(&expected_result.as.setTime);
    expected_result.as.setTime.year = 1;
    expected_result.as.setTime.month = 2;
    expected_result.as.setTime.day = 3;
    expected_result.as.setTime.hour = 4;
    expected_result.as.setTime.minute = 5;
    expected_result.as.setTime.second = 6;
    const bool expect_parser_success = true;

    invariant_test_parse_set_time(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_request_version()
{
    const char *valid_data = "VE";
    const char *expected_representation = "VE";
    EasycommData expected_result;
    easycommRequestVersion(&expected_result.as.requestVersion);
    const bool expect_parser_success = true;

    invariant_test_parse_request_version(valid_data, &expected_result, expected_representation, expect_parser_success);
}


#if defined(ARDUINO_AVR_MEGA2560) || defined(ENV_NATIVE)
int main(int argc, char **argv)
#else

void setup() {}

void loop()
#endif
{
    UNITY_BEGIN();

    RUN_TEST(test_parse_acquisition_of_signal);
    RUN_TEST(test_parse_loss_of_signal);

    RUN_TEST(test_parse_set_output_01);
    RUN_TEST(test_parse_set_output_02);

    RUN_TEST(test_parse_read_input_01);
    RUN_TEST(test_parse_read_input_02);

    RUN_TEST(test_parse_read_analogue_input_01);
    RUN_TEST(test_parse_read_analogue_input_02);

    RUN_TEST(test_parse_set_time_01);
    RUN_TEST(test_parse_set_time_02);
    RUN_TEST(test_parse_set_time_03);

    RUN_TEST(test_parse_request_version);

    UNITY_END();
#ifdef ARDUINO_AVR_MEGA2560
    return 0;
#endif
}
