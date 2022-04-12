#pragma once
#ifdef __cplusplus
extern "C"
{
#endif
#include <inttypes.h>
#include <stdbool.h>
#include <string.h> // size_t

    typedef struct EasycommBufferedTokenizerState
    {
        // output: points at start of next token; token is valid if .has_token == 1
        char *token;

        // private: points constantly to end of .token buffer
        char *_token_buffer_end;

        // private: points at last written token char or NULL if buffer is empty
        char *_token_end;

        // private: reentrant information
        char *_save_ptr;
        size_t _save_ptr_idx;
        size_t _save_ptr_len;

        // output: 1 if token buffer contains a valid token, 0 otherwise
        uint8_t has_token : 1;

        // intput: set the flag to 1 to consume the token (if .has_token == 1)
        uint8_t token_consumed : 1;

        // output: 1 indicates a buffer overflow, 0 normal operation
        // example: multiple calls with new input data do not contain the delimiter '\n' and fill up the buffer
        // consequence: once the flag is set, the state is inconsistent and not recoverable
        uint8_t buffer_overflow : 1;
    } EasycommBufferedTokenizerState;

    /**
     * Default constructor.
     * @param state
     */
    void easycommBufferedTokenizerState(EasycommBufferedTokenizerState *state);

    /**
     * Bind a buffer to the tokenizer state.
     * @param state
     * @param token_buffer pointer to buffer to bind
     * @param token_buffer_size length of buffer
     */
    void easycommBufferedTokenizerStateSetBuffers(EasycommBufferedTokenizerState *state,
                                                  char *token_buffer,
                                                  size_t token_buffer_size);

    /**
     * Takes a char sequence and provides tokens delimited by '\n'.
     *
     * This function is reentrant. A call identifies the first token (if any).
     * A subsequent call identifies the next token (if any) and so forth.
     * The function must be called respectively to consume all tokens before new data is provided.
     * Until all tokens are consumed and the input is not exhausted the `char_sequence` must not be
     * modified.
     * A call with new data appends to the last token buffer.
     * To reset the tokenizer re-construct the EasycommBufferedTokenizerState with its default
     * constructor.
     *
     * Tokens are trimmed left/right from whitespaces, have multiple whitespaces removed,
     * do not contain '\r' or '\n' and are 0 terminated.
     *
     * Usage:
     *   1. On the first call `char_sequence` must point to a character sequence to tokenize.
     *   2. While return is `true` subsequent calls must occur with `char_sequence == NULL`
     *      until no more tokens are found. Before each call clear the flag: `state->has_token = 0`.
     *   3. On the next call `char_sequence` must point again to a character sequence.
     *      If `char_sequence == NULL` then buffer_size is ignored.
     *
     * If buffer_overflow is indicated, then the result inclusive the whole state is invalid and
     * not recoverable.
     *
     * @param state input and output argument
     * @param char_sequence the string to tokenize; non null terminated character sequence
     * @param char_sequence_len length of char_sequence
     * @return true: the char_sequence is not exhausted or a pending token is to be consumed
     *         false: the char_sequence is exhausted or an error occurred
     */
    bool easycommBufferedTokenizerStrtok(EasycommBufferedTokenizerState *state, char *char_sequence, size_t char_sequence_len);

#ifdef __cplusplus
}
#endif
