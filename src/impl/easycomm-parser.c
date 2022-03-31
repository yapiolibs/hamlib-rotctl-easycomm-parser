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
    static CommandParser parsers[32] = {
        { .isCommand = isEasycomm1SingleLine, .parseCommand = readEasycomm1SingleLine },
        { .isCommand = isEasycomm2Azimuth, .parseCommand = readEasycomm2Azimuth },
        { .isCommand = isEasycomm2Elevation, .parseCommand = readEasycomm2Elevation },
        { .isCommand = isEasycomm2AzimuthElevation, .parseCommand = readEasycomm2AzimuthElevation },
        { .isCommand = isEasycomm2ElevationAzimuth, .parseCommand = readEasycomm2ElevationAzimuth },
        { .isCommand = isEasycomm2UplinkFrequency, .parseCommand = readEasycomm2UplinkFrequency },
        { .isCommand = isEasycomm2DownlinkFrequency, .parseCommand = readEasycomm2DownlinkFrequency },
        { .isCommand = isEasycomm2UplinkMode, .parseCommand = readEasycomm2UplinkMode },
        { .isCommand = isEasycomm2DownlinkMode, .parseCommand = readEasycomm2DownlinkMode },
        { .isCommand = isEasycomm2UplinkRadioNumber, .parseCommand = readEasycomm2UplinkRadioNumber },
        { .isCommand = isEasycomm2DownlinkRadioNumber, .parseCommand = readEasycomm2DownlinkRadioNumber },
        { .isCommand = isEasycomm2MoveLeft, .parseCommand = readEasycomm2MoveLeft },
        { .isCommand = isEasycomm2MoveRight, .parseCommand = readEasycomm2MoveRight },
        { .isCommand = isEasycomm2MoveUp, .parseCommand = readEasycomm2MoveUp },
        { .isCommand = isEasycomm2MoveDown, .parseCommand = readEasycomm2MoveDown },
        { .isCommand = isEasycomm2StopAzimuthMove, .parseCommand = readEasycomm2StopAzimuthMove },
        { .isCommand = isEasycomm2StopElevationMove, .parseCommand = readEasycomm2StopElevationMove },
        { .isCommand = isEasycomm2AcquisitionOfSignal, .parseCommand = readEasycomm2AcquisitionOfSignal },
        { .isCommand = isEasycomm2LossOfSignal, .parseCommand = readEasycomm2LossOfSignal },
        { .isCommand = isEasycomm2SetOutput, .parseCommand = readEasycomm2SetOutput },
        { .isCommand = isEasycomm2ReadInput, .parseCommand = readEasycomm2ReadInput },
        { .isCommand = isEasycomm2ReadAnalogueInput, .parseCommand = readEasycomm2ReadAnalogueInput },
        { .isCommand = isEasycomm2SetTime, .parseCommand = readEasycomm2SetTime },
        { .isCommand = isEasycomm2RequestVersion, .parseCommand = readEasycomm2RequestVersion },
        { .isCommand = isEasycomm3VelocityLeft, .parseCommand = readEasycomm3VelocityLeft },
        { .isCommand = isEasycomm3VelocityRight, .parseCommand = readEasycomm3VelocityRight },
        { .isCommand = isEasycomm3VelocityUp, .parseCommand = readEasycomm3VelocityUp },
        { .isCommand = isEasycomm3VelocityDown, .parseCommand = readEasycomm3VelocityDown },
        { .isCommand = isEasycomm3ReadConfig, .parseCommand = readEasycomm3ReadConfig },
        { .isCommand = isEasycomm3WriteConfig, .parseCommand = readEasycomm3WriteConfig },
        { .isCommand = isEasycomm3GetStatusRegister, .parseCommand = readEasycomm3GetStatusRegister },
        { .isCommand = isEasycomm3GetErrorRegister, .parseCommand = readEasycomm3GetErrorRegister },
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
