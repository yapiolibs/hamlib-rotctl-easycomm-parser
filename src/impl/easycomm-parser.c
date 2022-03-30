#include "../easycomm-parser.h"
#include "command-parsers.h"

#include <string.h>

typedef bool (*ParserPredicate)(const char *);
typedef bool (*CommandReader)(const char *, EasycommData *);

typedef struct CommandParser
{
    ParserPredicate isCommand;
    CommandReader parseCommand;
} CommandParser;

bool easycommParse(const char *buffer, EasycommData *parsed)
{
    static CommandParser parsers[5] = {
        { .isCommand = isEasycomm1SingleLine, .parseCommand = readEasycomm1SingleLine },
        { .isCommand = isEasycomm2Azimuth, .parseCommand = readEasycomm2Azimuth },
        { .isCommand = isEasycomm2Elevation, .parseCommand = readEasycomm2Elevation },
        { .isCommand = isEasycomm2AzimuthElevation, .parseCommand = readEasycomm2AzimuthElevation },
        { .isCommand = isEasycomm2ElevationAzimuth, .parseCommand = readEasycomm2ElevationAzimuth },
    };

    for(size_t i = sizeof(parsers) / sizeof(CommandParser); i > 0; i--)
    {
        if(parsers[i - 1].isCommand(buffer))
        {
            return parsers[i - 1].parseCommand(buffer, parsed);
        }
    }

    return false;
}
