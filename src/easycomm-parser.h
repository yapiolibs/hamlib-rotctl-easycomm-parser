#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#include "easycomm-parser-types.h"
#include <stdbool.h>

    /**
     * Parses issued commands from host.
     * @param buffer the command string (without newline/carriage return)
     * @param parsed the parsed structure (is touched regardless of return value)
     * @return true on success
     */
    bool easycommParse(const char *buffer, EasycommData *parsed);

#ifdef __cplusplus
}
#endif