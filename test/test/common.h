#pragma once
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


#define INVARIANT_TEST_PARSE_EASYCOMM_COMMAND(fx_name, str_buffer_len, parser_standard,                  \
                                              cmd_operators_prefix, cmd_enum_id, data_union_member_name) \
    void fx_name(const char *data, const EasycommData *expected,                                         \
                 const char *expected_representation, bool expect_parser_success)                        \
    {                                                                                                    \
        EasycommData parsed;                                                                             \
        bool is_parsed = easycommParse(data, &parsed, parser_standard);                                  \
        char data_as_string[str_buffer_len + 1] = { 0 };                                                 \
                                                                                                         \
        if(expect_parser_success)                                                                        \
        {                                                                                                \
            if(is_parsed)                                                                                \
            {                                                                                            \
                TEST_ASSERT_EQUAL(cmd_enum_id, parsed.commandId);                                        \
                cmd_operators_prefix##Sprintf(&parsed.as.data_union_member_name, data_as_string);        \
                TEST_ASSERT_EQUAL_STRING(expected_representation, data_as_string);                       \
                TEST_ASSERT_TRUE(cmd_operators_prefix##Equals(&parsed.as.data_union_member_name,         \
                                                              &expected->as.data_union_member_name));    \
            }                                                                                            \
            else                                                                                         \
            {                                                                                            \
                TEST_FAIL_MESSAGE("failed to parse");                                                    \
            }                                                                                            \
        }                                                                                                \
        else                                                                                             \
        {                                                                                                \
            if(is_parsed)                                                                                \
            {                                                                                            \
                cmd_operators_prefix##Sprintf(&parsed.as.data_union_member_name, data_as_string);        \
                TEST_ASSERT_EQUAL_STRING(expected_representation, data_as_string);                       \
            }                                                                                            \
            TEST_ASSERT_EQUAL(EasycommIdInvalid, parsed.commandId);                                      \
            TEST_ASSERT_FALSE(is_parsed);                                                                \
        }                                                                                                \
    }
