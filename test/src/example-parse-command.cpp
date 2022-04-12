#if defined(PIO_EXAMPLE_PARSE_COMMAND)
#include "example-parse-command.h"
#include <easycomm-parser.h>

void setup() {}

void loop()
{
    const char *data = "AZ000.1 EL000.0 UP000000000 UUU DN000000000 DDD";
    EasycommData result;

    if(easycommParseCommand(data, &result, EasycommParserStandard1))
    {
        // command was parsed
    }
}

#endif
