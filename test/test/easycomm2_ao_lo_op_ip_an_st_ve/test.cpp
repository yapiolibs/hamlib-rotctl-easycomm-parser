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

void setUp() {}

void tearDown() {}

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
                                      easycommSetDigitalOutput,
                                      EasycommIdSetOutput,
                                      setDigitalOutput)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_read_input,
                                      EasycommReadInputMaxLength,
                                      EasycommParserStandard2,
                                      easycommGetDitigalInput,
                                      EasycommIdReadInput,
                                      getDigitalInput)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_read_analogue_input,
                                      EasycommReadAnalogueInputMaxLength,
                                      EasycommParserStandard2,
                                      easycommGetAnalogueInput,
                                      EasycommIdReadAnalogueInput,
                                      getAnalogueInput)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_set_time,
                                      EasycommSetTimeMaxLength,
                                      EasycommParserStandard2,
                                      easycommSetTime,
                                      EasycommIdSetTime,
                                      setTime)


INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(invariant_test_parse_request_version,
                                      EasycommRequestVersionLength,
                                      EasycommParserStandard2,
                                      easycommGetVersion,
                                      EasycommIdRequestVersion,
                                      getVersion)


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
    easycommSetDigitalOutput(&expected_result.as.setDigitalOutput);
    expected_result.as.setDigitalOutput.number = 1;
    expected_result.as.setDigitalOutput.value = true;
    const bool expect_parser_success = true;

    invariant_test_parse_set_output(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_set_output_02()
{
    const char *valid_data = "OP002,0";
    const char *expected_representation = "OP2,0";
    EasycommData expected_result;
    easycommSetDigitalOutput(&expected_result.as.setDigitalOutput);
    expected_result.as.setDigitalOutput.number = 2;
    const bool expect_parser_success = true;

    invariant_test_parse_set_output(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_read_input_01()
{
    const char *valid_data = "IP13";
    const char *expected_representation = "IP13";
    EasycommData expected_result;
    easycommGetDigitalInput(&expected_result.as.getDigitalInput);
    expected_result.as.getDigitalInput.number = 13;
    const bool expect_parser_success = true;

    invariant_test_parse_read_input(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_read_input_02()
{
    const char *valid_data = "IP002";
    const char *expected_representation = "IP2";
    EasycommData expected_result;
    easycommGetDigitalInput(&expected_result.as.getDigitalInput);
    expected_result.as.getDigitalInput.number = 2;
    const bool expect_parser_success = true;

    invariant_test_parse_read_input(valid_data, &expected_result, expected_representation, expect_parser_success);
}


void test_parse_read_analogue_input_01()
{
    const char *valid_data = "AN13";
    const char *expected_representation = "AN13";
    EasycommData expected_result;
    easycommGetAnalogueInput(&expected_result.as.getAnalogueInput);
    expected_result.as.getAnalogueInput.number = 13;
    const bool expect_parser_success = true;

    invariant_test_parse_read_analogue_input(valid_data, &expected_result, expected_representation,
                                             expect_parser_success);
}


void test_parse_read_analogue_input_02()
{
    const char *valid_data = "AN000";
    const char *expected_representation = "AN0";
    EasycommData expected_result;
    easycommGetAnalogueInput(&expected_result.as.getAnalogueInput);
    expected_result.as.getAnalogueInput.number = 0;
    const bool expect_parser_success = true;

    invariant_test_parse_read_analogue_input(valid_data, &expected_result, expected_representation,
                                             expect_parser_success);
}


void test_parse_set_time_string()
{
    // issue: https://github.com/yapiolibs/hamlib-rotctl-easycomm-parser/issues/4
    // buffer examples: "STyy:MM:dd:hh:mm:ss"
    EasycommSetTime timeStamp;

    size_t items = sscanf("ST11:22:33:44:55:66",
#if defined(ARDUINO_ARCH_AVR)
                          "ST%hhu:%hhu:%hhu:%hhu:%hhu:%hhu",
#elif defined(ARDUINO_ARCH_STM32)
                          "ST%hhu:%hhu:%hhu:%hhu:%hhu:%hhu",
#elif defined(ARDUINO_ARCH_ESP8266) || defined(ARDUINO_ARCH_ESP32)
                          "ST%hhu:%hhu:%hhu:%hhu:%hhu:%hhu",
#else // assume native platform
                          "ST%hhu:%hhu:%hhu:%hhu:%hhu:%hhu",
#endif
                          &timeStamp.year, &timeStamp.month, &timeStamp.day, &timeStamp.hour,
                          &timeStamp.minute, &timeStamp.second);

    TEST_ASSERT_EQUAL(6, items);
    TEST_ASSERT_EQUAL(11, timeStamp.year);
    TEST_ASSERT_EQUAL(22, timeStamp.month);
    TEST_ASSERT_EQUAL(33, timeStamp.day);
    TEST_ASSERT_EQUAL(44, timeStamp.hour);
    TEST_ASSERT_EQUAL(55, timeStamp.minute);
    TEST_ASSERT_EQUAL(66, timeStamp.second);
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
    easycommGetVersion(&expected_result.as.getVersion);
    const bool expect_parser_success = true;

    invariant_test_parse_request_version(valid_data, &expected_result, expected_representation, expect_parser_success);
}

int run_tests()
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
    RUN_TEST(test_parse_set_time_string);
    RUN_TEST(test_parse_set_time_01);
    RUN_TEST(test_parse_set_time_02);
    RUN_TEST(test_parse_set_time_03);
    RUN_TEST(test_parse_request_version);
    return UNITY_END();
}

int main(int argc, char **argv) { return run_tests(); }

#if defined(ARDUINO_AVR_MEGA2560) || defined(ENV_NATIVE)
int main(int argc, char **argv)
#else
void loop() {}

void setup()
#endif
{
#if !defined(ARDUINO_AVR_MEGA2560) && !defined(ENV_NATIVE)
    delay(1000);
#endif

#if defined(ARDUINO_AVR_MEGA2560) || defined(ENV_NATIVE)
    return run_tests();
#else
    run_tests();
#endif
}
