#if !defined(ENV_NATIVE)
#include <Arduino.h>
#endif

#include <easycomm-buffered-tokenizer.h>
#include <stdio.h>
#include <unity.h>


static bool verifyExpectedTokens(const char *expected_tokens[],
                                 size_t expected_num_tokens,
                                 char *text,
                                 size_t text_len,
                                 EasycommBufferedTokenizerState &state)
{
    /*
        if(expected_num_tokens > 1)
            printf("expected %zu token(s) are:\n", expected_num_tokens);
        for(size_t token_idx = 0; token_idx < expected_num_tokens; token_idx++)
        {
            printf("  token #%zu: \"%s\"\n", token_idx, expected_tokens[token_idx]);
        }
    */
    size_t num_tokens_found = 0;
    bool found_tokens_differ = false;

    char *text_ptr = text;
    while(easycommBufferedTokenizerStrtok(&state, text_ptr, text_len))
    {
        text_ptr = nullptr;
        TEST_ASSERT_EQUAL(0, state.buffer_overflow);
        if(1 == state.has_token)
        {
            if(num_tokens_found <= expected_num_tokens)
            {
                if(0 != strcmp(expected_tokens[num_tokens_found], state.token))
                {
                    // printf("  ERROR found token #%zu: expected token \"%s\" differs from found "
                    // "\"%s\"\n",
                    //       num_tokens_found, expected_tokens[num_tokens_found], state.token);
                    found_tokens_differ = true;
                }
                else
                {
                    // printf("  OK    found token #%zu: expected token \"%s\" same as found \"%s\"\n",
                    //        num_tokens_found, expected_tokens[num_tokens_found], state.token);
                }
            }
            else
            {
                // printf("  ERROR found token #%zu: unexpected token \"%s\"\n", num_tokens_found,
                //        state.token);
                found_tokens_differ = true;
            }

            num_tokens_found++;
            state.token_consumed = 1;
        }
    }

    // printf("expected %zu token(s), found %zu\n", expected_num_tokens, num_tokens_found);
    return !found_tokens_differ && (expected_num_tokens == num_tokens_found);
}


void test_buffered_tokenizer_single_token_one_word_01()
{
    EasycommBufferedTokenizerState state;
    easycommBufferedTokenizerState(&state);
    char token_buffer[128] = { 0 };
    easycommBufferedTokenizerStateSetBuffers(&state, token_buffer, sizeof(token_buffer));

    char text[] = "asdf";
    size_t text_len = strlen(text);
    const char *expected_tokens[] = {};

    TEST_ASSERT_EQUAL(0, state.buffer_overflow);
    TEST_ASSERT_TRUE(verifyExpectedTokens(expected_tokens, 0, text, text_len, state));
}


void test_buffered_tokenizer_single_token_one_word_02()
{
    EasycommBufferedTokenizerState state;
    easycommBufferedTokenizerState(&state);
    char token_buffer[128] = { 0 };
    easycommBufferedTokenizerStateSetBuffers(&state, token_buffer, sizeof(token_buffer));

    char text[] = "asdf\n";
    size_t text_len = strlen(text);
    const char *expected_tokens[] = { "asdf" };

    TEST_ASSERT_EQUAL(0, state.buffer_overflow);
    TEST_ASSERT_TRUE(verifyExpectedTokens(expected_tokens, 1, text, text_len, state));
}


void test_buffered_tokenizer_single_token_one_word_03()
{
    EasycommBufferedTokenizerState state;
    easycommBufferedTokenizerState(&state);
    char token_buffer[128] = { 0 };

    char text[] = "asdf \n";
    const char *expected_tokens[] = { "asdf" };

    size_t text_len = strlen(text);
    easycommBufferedTokenizerStateSetBuffers(&state, token_buffer, sizeof(token_buffer));

    TEST_ASSERT_EQUAL(0, state.buffer_overflow);
    TEST_ASSERT_TRUE(verifyExpectedTokens(expected_tokens, 1, text, text_len, state));
}


void test_buffered_tokenizer_single_token_one_word_04()
{
    EasycommBufferedTokenizerState state;
    easycommBufferedTokenizerState(&state);
    char token_buffer[128] = { 0 };

    char text[] = "asdf  \n";
    const char *expected_tokens[] = { "asdf" };

    size_t text_len = strlen(text);
    easycommBufferedTokenizerStateSetBuffers(&state, token_buffer, sizeof(token_buffer));

    TEST_ASSERT_EQUAL(0, state.buffer_overflow);
    TEST_ASSERT_TRUE(verifyExpectedTokens(expected_tokens, 1, text, text_len, state));
}


void test_buffered_tokenizer_single_token_one_word_05()
{
    EasycommBufferedTokenizerState state;
    easycommBufferedTokenizerState(&state);
    char token_buffer[128] = { 0 };
    easycommBufferedTokenizerStateSetBuffers(&state, token_buffer, sizeof(token_buffer));

    char text[] = " asdf\n";
    size_t text_len = strlen(text);
    const char *expected_tokens[] = { "asdf" };

    TEST_ASSERT_EQUAL(0, state.buffer_overflow);
    TEST_ASSERT_TRUE(verifyExpectedTokens(expected_tokens, 1, text, text_len, state));
}


void test_buffered_tokenizer_single_token_one_word_06()
{
    EasycommBufferedTokenizerState state;
    easycommBufferedTokenizerState(&state);
    char token_buffer[128] = { 0 };
    easycommBufferedTokenizerStateSetBuffers(&state, token_buffer, sizeof(token_buffer));

    char text[] = "  asdf\n";
    size_t text_len = strlen(text);
    const char *expected_tokens[] = { "asdf" };

    TEST_ASSERT_EQUAL(0, state.buffer_overflow);
    TEST_ASSERT_TRUE(verifyExpectedTokens(expected_tokens, 1, text, text_len, state));
}


void test_buffered_tokenizer_single_token_one_word_07()
{
    EasycommBufferedTokenizerState state;
    easycommBufferedTokenizerState(&state);
    char token_buffer[128] = { 0 };
    easycommBufferedTokenizerStateSetBuffers(&state, token_buffer, sizeof(token_buffer));

    char text[] = " asdf\r\n";
    size_t text_len = strlen(text);
    const char *expected_tokens[] = { "asdf" };

    TEST_ASSERT_EQUAL(0, state.buffer_overflow);
    TEST_ASSERT_TRUE(verifyExpectedTokens(expected_tokens, 1, text, text_len, state));
}

void test_buffered_tokenizer_single_token_one_word_08()
{
    EasycommBufferedTokenizerState state;
    easycommBufferedTokenizerState(&state);
    char token_buffer[128] = { 0 };
    easycommBufferedTokenizerStateSetBuffers(&state, token_buffer, sizeof(token_buffer));

    char text[] = "\r\n asdf\r\n";
    size_t text_len = strlen(text);
    const char *expected_tokens[] = { "asdf" };


    TEST_ASSERT_EQUAL(0, state.buffer_overflow);
    TEST_ASSERT_TRUE(verifyExpectedTokens(expected_tokens, 1, text, text_len, state));
}


void test_buffered_tokenizer_single_token_one_word_09()
{
    EasycommBufferedTokenizerState state;
    easycommBufferedTokenizerState(&state);
    char token_buffer[128] = { 0 };
    easycommBufferedTokenizerStateSetBuffers(&state, token_buffer, sizeof(token_buffer));

    char text[] = "  \r\n asdf \r\n";
    size_t text_len = strlen(text);
    const char *expected_tokens[] = { "asdf" };

    TEST_ASSERT_EQUAL(0, state.buffer_overflow);
    TEST_ASSERT_TRUE(verifyExpectedTokens(expected_tokens, 1, text, text_len, state));
}


void test_buffered_tokenizer_single_token_one_word_10()
{
    EasycommBufferedTokenizerState state;
    easycommBufferedTokenizerState(&state);
    char token_buffer[128] = { 0 };
    easycommBufferedTokenizerStateSetBuffers(&state, token_buffer, sizeof(token_buffer));

    char text[] = "  \n\r\n\n\n\r\r\n asdf \r\r\r\n\n";
    size_t text_len = strlen(text);
    const char *expected_tokens[] = { "asdf" };

    TEST_ASSERT_EQUAL(0, state.buffer_overflow);
    TEST_ASSERT_TRUE(verifyExpectedTokens(expected_tokens, 1, text, text_len, state));
}


void test_buffered_tokenizer_single_token_multiple_words_01()
{
    EasycommBufferedTokenizerState state;
    easycommBufferedTokenizerState(&state);
    char token_buffer[128] = { 0 };

    char text[] = "  asdf   ghi   \n";
    easycommBufferedTokenizerStateSetBuffers(&state, token_buffer, sizeof(token_buffer));
    size_t text_len = strlen(text);
    const char *expected_tokens[] = { "asdf ghi" };

    TEST_ASSERT_EQUAL(0, state.buffer_overflow);
    TEST_ASSERT_TRUE(verifyExpectedTokens(expected_tokens, 1, text, text_len, state));
}


void test_buffered_tokenizer_single_token_multiple_words_02()
{
    EasycommBufferedTokenizerState state;
    easycommBufferedTokenizerState(&state);
    char token_buffer[128] = { 0 };
    easycommBufferedTokenizerStateSetBuffers(&state, token_buffer, sizeof(token_buffer));

    char text[] = "  asdf,13   ghi,14,15  abc1235  uvw#125 \n";
    size_t text_len = strlen(text);
    const char *expected_tokens[] = { "asdf,13 ghi,14,15 abc1235 uvw#125" };

    TEST_ASSERT_EQUAL(0, state.buffer_overflow);
    TEST_ASSERT_TRUE(verifyExpectedTokens(expected_tokens, 1, text, text_len, state));
}


void test_buffered_tokenizer_multiple_token_multiple_words_01()
{
    EasycommBufferedTokenizerState state;
    easycommBufferedTokenizerState(&state);
    char token_buffer[128] = { 0 };
    easycommBufferedTokenizerStateSetBuffers(&state, token_buffer, sizeof(token_buffer));

    char text[] = "asdf ghi\njkl mno\n";
    size_t text_len = strlen(text);
    const char *expected_tokens[] = { "asdf ghi", "jkl mno" };

    TEST_ASSERT_EQUAL(0, state.buffer_overflow);
    TEST_ASSERT_TRUE(verifyExpectedTokens(expected_tokens, 2, text, text_len, state));
}


void test_buffered_tokenizer_multiple_token_multiple_words_02()
{
    EasycommBufferedTokenizerState state;
    easycommBufferedTokenizerState(&state);
    char token_buffer[128] = { 0 };
    easycommBufferedTokenizerStateSetBuffers(&state, token_buffer, sizeof(token_buffer));

    char text[] = "  asdf   ghi   \n   jkl    mno  \n";
    size_t text_len = strlen(text);
    const char *expected_tokens[] = { "asdf ghi", "jkl mno" };

    TEST_ASSERT_TRUE(verifyExpectedTokens(expected_tokens, 2, text, text_len, state));
    TEST_ASSERT_EQUAL(0, state.buffer_overflow);
}


void test_buffered_tokenizer_multiple_token_multiple_words_03()
{
    EasycommBufferedTokenizerState state;
    easycommBufferedTokenizerState(&state);
    char token_buffer[128] = { 0 };
    easycommBufferedTokenizerStateSetBuffers(&state, token_buffer, sizeof(token_buffer));

    char text[] = " x\n asdf ghi \r \n jkl mno \r\n qwer \r\n";
    size_t text_len = strlen(text);
    const char *expected_tokens[] = { "x", "asdf ghi", "jkl mno", "qwer" };

    TEST_ASSERT_EQUAL(0, state.buffer_overflow);
    TEST_ASSERT_TRUE(verifyExpectedTokens(expected_tokens, 4, text, text_len, state));
}


void test_buffered_tokenizer_multiple_token_with_pending_token_01()
{
    EasycommBufferedTokenizerState state;
    easycommBufferedTokenizerState(&state);
    char token_buffer[128] = { 0 };
    easycommBufferedTokenizerStateSetBuffers(&state, token_buffer, sizeof(token_buffer));

    char text1[] = "aaa\nbbb\nccc";
    size_t text1_len = strlen(text1);
    const char *expected_tokens1[] = { "aaa", "bbb" };

    TEST_ASSERT_EQUAL(0, state.buffer_overflow);
    TEST_ASSERT_TRUE(verifyExpectedTokens(expected_tokens1, 2, text1, text1_len, state));

    char text2[] = "ddd\neee\n";
    size_t text2_len = strlen(text2);
    const char *expected_tokens2[] = { "cccddd", "eee" };

    TEST_ASSERT_EQUAL(0, state.buffer_overflow);
    TEST_ASSERT_TRUE(verifyExpectedTokens(expected_tokens2, 2, text2, text2_len, state));
}


void test_buffered_tokenizer_multiple_token_with_pending_token_02()
{
    EasycommBufferedTokenizerState state;
    easycommBufferedTokenizerState(&state);
    char token_buffer[128] = { 0 };
    easycommBufferedTokenizerStateSetBuffers(&state, token_buffer, sizeof(token_buffer));

    char text1[] = "aaa\nbbb\nccc";
    size_t text1_len = strlen(text1);
    const char *expected_tokens1[] = { "aaa", "bbb" };

    TEST_ASSERT_EQUAL(0, state.buffer_overflow);
    TEST_ASSERT_TRUE(verifyExpectedTokens(expected_tokens1, 2, text1, text1_len, state));

    char text2[] = "\n";
    size_t text2_len = strlen(text2);
    const char *expected_tokens2[] = { "ccc" };

    TEST_ASSERT_EQUAL(0, state.buffer_overflow);
    TEST_ASSERT_TRUE(verifyExpectedTokens(expected_tokens2, 1, text2, text2_len, state));
}


void test_buffered_tokenizer_multiple_token_with_pending_token_03()
{
    EasycommBufferedTokenizerState state;
    easycommBufferedTokenizerState(&state);
    char token_buffer[128] = { 0 };
    easycommBufferedTokenizerStateSetBuffers(&state, token_buffer, sizeof(token_buffer));

    char text1[] = "aaa\nbbb\nccc";
    size_t text1_len = strlen(text1);
    const char *expected_tokens1[] = { "aaa", "bbb" };

    TEST_ASSERT_EQUAL(0, state.buffer_overflow);
    TEST_ASSERT_TRUE(verifyExpectedTokens(expected_tokens1, 2, text1, text1_len, state));

    char text2[] = "ddd\neee";
    size_t text2_len = strlen(text2);
    const char *expected_tokens2[] = { "cccddd" };

    TEST_ASSERT_EQUAL(0, state.buffer_overflow);
    TEST_ASSERT_TRUE(verifyExpectedTokens(expected_tokens2, 1, text2, text2_len, state));
}


void test_buffered_tokenizer_multiple_token_with_pending_token_04()
{
    EasycommBufferedTokenizerState state;
    easycommBufferedTokenizerState(&state);
    char token_buffer[128] = { 0 };
    easycommBufferedTokenizerStateSetBuffers(&state, token_buffer, sizeof(token_buffer));

    char text1[] = "aaa\rbbb\rccc";
    size_t text1_len = strlen(text1);
    const char *expected_tokens1[] = { "aaa", "bbb" };

    TEST_ASSERT_EQUAL(0, state.buffer_overflow);
    TEST_ASSERT_TRUE(verifyExpectedTokens(expected_tokens1, 2, text1, text1_len, state));

    char text2[] = "ddd\reee";
    size_t text2_len = strlen(text2);
    const char *expected_tokens2[] = { "cccddd" };

    TEST_ASSERT_EQUAL(0, state.buffer_overflow);
    TEST_ASSERT_TRUE(verifyExpectedTokens(expected_tokens2, 1, text2, text2_len, state));
}


int tests()
{
    UNITY_BEGIN();
    RUN_TEST(test_buffered_tokenizer_single_token_one_word_01);
    RUN_TEST(test_buffered_tokenizer_single_token_one_word_02);
    RUN_TEST(test_buffered_tokenizer_single_token_one_word_03);
    RUN_TEST(test_buffered_tokenizer_single_token_one_word_04);
    RUN_TEST(test_buffered_tokenizer_single_token_one_word_05);
    RUN_TEST(test_buffered_tokenizer_single_token_one_word_06);
    RUN_TEST(test_buffered_tokenizer_single_token_one_word_07);
    RUN_TEST(test_buffered_tokenizer_single_token_one_word_08);
    RUN_TEST(test_buffered_tokenizer_single_token_one_word_09);
    RUN_TEST(test_buffered_tokenizer_single_token_one_word_10);
    RUN_TEST(test_buffered_tokenizer_single_token_multiple_words_01);
    RUN_TEST(test_buffered_tokenizer_single_token_multiple_words_02);
    RUN_TEST(test_buffered_tokenizer_multiple_token_multiple_words_01);
    RUN_TEST(test_buffered_tokenizer_multiple_token_multiple_words_02);
    RUN_TEST(test_buffered_tokenizer_multiple_token_multiple_words_03);
    RUN_TEST(test_buffered_tokenizer_multiple_token_with_pending_token_01);
    RUN_TEST(test_buffered_tokenizer_multiple_token_with_pending_token_02);
    RUN_TEST(test_buffered_tokenizer_multiple_token_with_pending_token_03);
    RUN_TEST(test_buffered_tokenizer_multiple_token_with_pending_token_04);
    return UNITY_END();
}

void setUp() {}

void tearDown() {}

#include "../helpers/run-tests.h"
