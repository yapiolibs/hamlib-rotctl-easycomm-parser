#include "../easycomm-buffered-tokenizer.h"
#include <stdio.h>


static char getLastBufferedCharOrNul(const EasycommBufferedTokenizerState *state)
{
    if(NULL == state->_token_end)
        return 0;
    return *state->_token_end;
}


static bool isBufferEmpty(const EasycommBufferedTokenizerState *state)
{
    return NULL == state->_token_end;
}


static bool incrementBoundaryPtr(EasycommBufferedTokenizerState *state)
{
    if(NULL == state->_token_end)
    {
        state->_token_end = state->token;
        return true;
    }
    // leave space for at least one 0 character
    else if(state->_token_end >= state->_token_buffer_end - 1 - 1)
    {
        return false;
    }
    else
    {
        state->_token_end++;
        return true;
    }
}

static void clearTokenBuffer(EasycommBufferedTokenizerState *state)
{
    *state->token = 0;
    state->_token_end = NULL;
}

/**
 * @return less than 0 on buffer overflow, 0 if character consumed (even if ignored), greater than 0 on '\n'
 */
static int8_t putCharToBuffer(EasycommBufferedTokenizerState *state, char ch)
{
    // handle ' '
    if(' ' == ch)
    {
        if(' ' == getLastBufferedCharOrNul(state)) // ignore subsequent ' '
        {
            return 0;
        }
        else if(isBufferEmpty(state)) // ignore leading ' '
        {
            return 0;
        }
        else // consume ' '
        {
            if(false == incrementBoundaryPtr(state))
                return -1;
            *state->_token_end = ch;
            *(state->_token_end + 1) = 0;
            return 0;
        }
    }

    // handle '\r'
    else if('\r' == ch) // ignore irrelevant '\r' for $ compatibility
    {
        // TODO report behaviour:
        //   '\r' must also trigger end of token since rotctl seems to not send '\n' when
        //   the 'w' command is used.
        //   example:
        //     Rotator command: "w AZ123.4 EL-12.3 UP1234 upm DN1235 dnm"
        //     transmits "w AZ123.4 EL-12.3 UP1234 upm DN1235 dnm\r"
        //     expected_
        //       "w AZ123.4 EL-12.3 UP1234 upm DN1235 dnm\r\n" or
        //       "w AZ123.4 EL-12.3 UP1234 upm DN1235 dnm\n"
        return 1;
    }

    // handle '\n'
    else if('\n' == ch) // found end of token
    {
        return 1;
    }

    // handle any other character
    else
    {
        if(false == incrementBoundaryPtr(state))
            return -1;
        *state->_token_end = ch;
        *(state->_token_end + 1) = 0;
        return 0;
    }
}


void easycommBufferedTokenizerState(EasycommBufferedTokenizerState *state)
{
    memset(state, 0, sizeof(EasycommBufferedTokenizerState));
}


void easycommBufferedTokenizerStateSetBuffers(EasycommBufferedTokenizerState *state, char *token_buffer, size_t token_buffer_size)
{
    state->token = token_buffer;
    state->_token_end = NULL;
    state->_token_buffer_end = token_buffer + token_buffer_size;
}


bool easycommBufferedTokenizerStrtok(EasycommBufferedTokenizerState *state, char *char_sequence, size_t char_sequence_len)
{
    if(1 == state->has_token && 1 == state->token_consumed)
    {
        state->token_consumed = 0;
        state->has_token = 0;
        clearTokenBuffer(state);
    }

    if(1 == state->has_token)
        return true;

    if(1 == state->buffer_overflow)
        return false;

    // new data resets the reentrant information
    if(char_sequence != NULL)
    {
        state->_save_ptr = char_sequence;
        state->_save_ptr_len = char_sequence_len;
        state->_save_ptr_idx = 0;
    }

    for(; state->_save_ptr_idx < state->_save_ptr_len; state->_save_ptr_idx++)
    {
        int8_t consume_status = putCharToBuffer(state, state->_save_ptr[state->_save_ptr_idx]);

        if(consume_status < 0) // error: buffer overflow
        {
            state->buffer_overflow = 1;
            return false;
        }
        else if(consume_status == 0) // consumed char
        {
        }
        else // if (consume_status > 0 ) // found end of token
        {
            if(state->_token_end == NULL)
            {
                state->_save_ptr_idx++;
                return true;
            }
            if(*state->_token_end == ' ')
                *state->_token_end = 0;
            state->has_token = 1;

            state->_save_ptr_idx++;
            return true;
        }
    }
    return false;
}
