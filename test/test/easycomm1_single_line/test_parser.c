#include <unity.h>
#include <easycomm-parser.h>

#include <string.h>
#include <stdio.h>

void printEasycommSingleLine(const EasycommSingleLine *data) {
    char buffer[48];
    easycommSingleLineSprintf(data, buffer);
    printf("%s", buffer);
}

void invariant_test_parse_Easycomm1SingleLine(const char *data,
                                              const EasycommData *expected,
                                              bool expect_parser_success) {
    EasycommData parsed;
    easycommData(&parsed);
    bool is_parsed = easycommParse(data, &parsed);

    printf("parsing:  %s\n", data);
    printf("parsed:   ");
    printEasycommSingleLine(&parsed.as.singleLine);
    printf("\n");
    if (expected != NULL) {
        printf("expected: ");
        printEasycommSingleLine(&expected->as.singleLine);
        printf("\n");
    }

    if (expect_parser_success) {
        if (is_parsed) {
            TEST_ASSERT_EQUAL(EasycommIdSingleLine, parsed.commandId);
            TEST_ASSERT_TRUE(easycommSingleLineEquals(&parsed.as.singleLine, &expected->as.singleLine));
        } else {
            TEST_FAIL_MESSAGE("failed to parse");
        }
    } else {
        TEST_ASSERT_FALSE(is_parsed);
    }
}


void test_parse_azimuth_01() {
    const char *valid_data = "AZ123.4 EL000.0 UP000000000 UUU DN000000000 DDD";
    EasycommData expected_result;
    easycommData(&expected_result);
    expected_result.as.singleLine.azimuth = 123.4f;
    memcpy(&expected_result.as.singleLine.mode_up, "UUU", 3);
    memcpy(&expected_result.as.singleLine.mode_down, "DDD", 3);
    expected_result.commandId = EasycommIdSingleLine;
    const bool expect_parser_success = true;

    invariant_test_parse_Easycomm1SingleLine(valid_data,
                                             &expected_result,
                                             expect_parser_success);
}

void test_parse_azimuth_02() {
    const char *valid_data = "AZ000.1 EL000.0 UP000000000 UUU DN000000000 DDD";
    EasycommData expected_result;
    easycommData(&expected_result);
    expected_result.as.singleLine.azimuth = 0.1f;
    memcpy(&expected_result.as.singleLine.mode_up, "UUU", 3);
    memcpy(&expected_result.as.singleLine.mode_down, "DDD", 3);
    expected_result.commandId = EasycommIdSingleLine;
    const bool expect_parser_success = true;

    invariant_test_parse_Easycomm1SingleLine(valid_data,
                                             &expected_result,
                                             expect_parser_success);
}

void test_parse_elevation() {
    const char *valid_data = "AZ000.0 EL213.4 UP000000000 UUU DN000000000 DDD";
    EasycommData expected_result;
    easycommData(&expected_result);
    expected_result.as.singleLine.elevation = 213.4f;
    memcpy(&expected_result.as.singleLine.mode_up, "UUU", 3);
    memcpy(&expected_result.as.singleLine.mode_down, "DDD", 3);
    expected_result.commandId = EasycommIdSingleLine;
    const bool expect_parser_success = true;

    invariant_test_parse_Easycomm1SingleLine(valid_data,
                                             &expected_result,
                                             expect_parser_success);
}

void test_parse_uplink_frequency() {
    const char *valid_data = "AZ000.0 EL000.0 UP999999999 UUU DN000000000 DDD";
    EasycommData expected_result;
    easycommData(&expected_result);
    expected_result.as.singleLine.uplink_frequency.as.uint32 = 999999999;
    memcpy(&expected_result.as.singleLine.mode_up, "UUU", 3);
    memcpy(&expected_result.as.singleLine.mode_down, "DDD", 3);
    expected_result.commandId = EasycommIdSingleLine;
    const bool expect_parser_success = true;

    invariant_test_parse_Easycomm1SingleLine(valid_data,
                                             &expected_result,
                                             expect_parser_success);
}


void test_parse_downlink_frequency() {
    const char *valid_data = "AZ000.0 EL000.0 UP000000000 UUU DN999999999 DDD";
    EasycommData expected_result;
    easycommData(&expected_result);
    expected_result.as.singleLine.downlink_frequency.as.uint32 = 999999999;
    memcpy(&expected_result.as.singleLine.mode_up, "UUU", 3);
    memcpy(&expected_result.as.singleLine.mode_down, "DDD", 3);
    expected_result.commandId = EasycommIdSingleLine;
    const bool expect_parser_success = true;

    invariant_test_parse_Easycomm1SingleLine(valid_data,
                                             &expected_result,
                                             expect_parser_success);
}

void test_parse_uplink_mode() {
    const char *valid_data = "AZ000.0 EL000.0 UP000000000 ABC DN000000000 DDD";
    EasycommData expected_result;
    easycommData(&expected_result);
    memcpy(&expected_result.as.singleLine.mode_up, "ABC", 3);
    memcpy(&expected_result.as.singleLine.mode_down, "DDD", 3);
    expected_result.commandId = EasycommIdSingleLine;
    const bool expect_parser_success = true;

    invariant_test_parse_Easycomm1SingleLine(valid_data,
                                             &expected_result,
                                             expect_parser_success);
}

void test_parse_downlink_mode() {
    const char *valid_data = "AZ000.0 EL000.0 UP000000000 UUU DN000000000 DEF";
    EasycommData expected_result;
    easycommData(&expected_result);
    memcpy(&expected_result.as.singleLine.mode_up, "UUU", 3);
    memcpy(&expected_result.as.singleLine.mode_down, "DEF", 3);
    expected_result.commandId = EasycommIdSingleLine;
    const bool expect_parser_success = true;

    invariant_test_parse_Easycomm1SingleLine(valid_data,
                                             &expected_result,
                                             expect_parser_success);
}

void test_parse_invalid_azimuth() {
    const char *invalid_data = "AZ123.45 EL000.0 UP000000000 UUU DN000000000 DDD";
    const EasycommData *dont_care = NULL;
    const bool expect_parser_fail = false;

    invariant_test_parse_Easycomm1SingleLine(invalid_data,
                                             dont_care,
                                             expect_parser_fail);
}

void test_parse_invalid_elevation() {
    const char *invalid_data = "AZ000.0 EL0359 UP000000000 UUU DN000000000 DDD";
    const EasycommData *dont_care = NULL;
    const bool expect_parser_fail = false;

    invariant_test_parse_Easycomm1SingleLine(invalid_data,
                                             dont_care,
                                             expect_parser_fail);
}

void test_parse_invalid_uplink_mode() {
    const char *invalid_data = "AZ000.0 EL000.0 UP10 UUUU DN000000000 DDD";
    const EasycommData *dont_care = NULL;
    const bool expect_parser_fail = false;

    invariant_test_parse_Easycomm1SingleLine(invalid_data,
                                             dont_care,
                                             expect_parser_fail);
}

void test_parse_invalid_downlink_mode() {
    const char *invalid_data = "AZ000.0 EL000.0 UP10 UUU DN000000000 DD";
    const EasycommData *dont_care = NULL;
    const bool expect_parser_fail = false;

    invariant_test_parse_Easycomm1SingleLine(invalid_data,
                                             dont_care,
                                             expect_parser_fail);
}

void test_parse_invalid_uplink_frequency() {
    const char *invalid_data = "AZ000.0 EL000.0 UP10 UUU DN000000000 DDD";
    const EasycommData *dont_care = NULL;
    const bool expect_parser_fail = false;

    invariant_test_parse_Easycomm1SingleLine(invalid_data,
                                             dont_care,
                                             expect_parser_fail);
}

int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_parse_azimuth_01);
    RUN_TEST(test_parse_azimuth_02);
    RUN_TEST(test_parse_elevation);
    RUN_TEST(test_parse_uplink_frequency);
    RUN_TEST(test_parse_downlink_frequency);
    RUN_TEST(test_parse_uplink_mode);
    RUN_TEST(test_parse_downlink_mode);
    RUN_TEST(test_parse_invalid_azimuth);
    RUN_TEST(test_parse_invalid_elevation);
    RUN_TEST(test_parse_invalid_uplink_mode);
    RUN_TEST(test_parse_invalid_downlink_mode);
    RUN_TEST(test_parse_invalid_uplink_frequency);
    UNITY_END();
    return 0;
}

