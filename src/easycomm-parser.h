#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#include "easycomm-parser-types.h"
#include <stdbool.h>

    /**
     * notes: do not
     * - change enum order
     * - assign values to enum items
     */
    typedef enum EasycommParserStandard
    {
        EasycommParserStandard1,   // standard 1 only
        EasycommParserStandard12,  // standard 1 and 2
        EasycommParserStandard2,   // standard 2 only, 1 excluded
        EasycommParserStandard23,  // standard 2 and 3, 1 excluded
        EasycommParserStandard3,   // standard 3 only, 1 and 2 excluded
        EasycommParserStandard123, // standard 1, 2 and 3
    } EasycommParserStandard;

    /**
     * Parses issued commands from host
     * @param buffer the command string (null terminated without newline/carriage return)
     * @param protocol_standard Easycomm standard: to intercept
     * @param parsed the parsed structure (assume the struct touched in any case regardless of return value)
     * @return true on success
     */
    bool easycommParse(const char *buffer, EasycommData *parsed, EasycommParserStandard protocol_standard);

#ifdef __cplusplus
}
#endif