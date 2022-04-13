#if defined(PIO_EXAMPLE_PARSE_COMMAND)
#include "example-parse-command.h"
#include <easycomm-parser-types-ctors.h>
#include <easycomm-parser.h>

/**
 * This example aims to show how the line-tokenizer is applied to receive data from rotctl
 * and how to reply to each command that was received in the same line.
 */

// -------------------------------------------------------------------------------------------------

void setup() {}

// -------------------------------------------------------------------------------------------------

void loop()
{
    EasycommData result;

    easycommData(&result);
    if(easycommParseCommand("AZ000.1 EL000.0 UP000000000 UUU DN000000000 DDD", &result, EasycommParserStandard1))
    {
        // standard 1 command was parsed
    }

    easycommData(&result);
    if(easycommParseCommand("AZ100", &result, EasycommParserStandard2))
    {
        // standard 2 command was parsed
    }

    easycommData(&result);
    if(easycommParseCommand("VU50", &result, EasycommParserStandard23))
    {
        // standard 3 command was parsed
    }
}

#endif
