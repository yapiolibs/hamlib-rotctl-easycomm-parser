#include "../easycomm-parser.h"
#include "command-parsers.h"

#include <string.h>

typedef bool (*ParserPredicateFunction)(const char *);
typedef bool (*CommandReaderFunction)(const char *, EasycommData *);
typedef bool (*EasycommParseStandardFunction)(const char *, EasycommData *);

typedef struct CommandParser
{
    ParserPredicateFunction isCommand;
    CommandReaderFunction parseCommand;
} CommandParser;

#include <stdio.h>
static bool invokeCommandParsers(const char *buffer, CommandParser *parsers, EasycommData *result)
{
    CommandParser *command_parser = parsers;
    while(command_parser != NULL)
    {
        if(command_parser->isCommand(buffer))
        {
            if(false == command_parser->parseCommand(buffer, result))
            {
                result->commandId = EasycommIdInvalid;
                return false;
            }
            return true;
        }
        command_parser++;
    }
    return false;
}


static bool easycommParse1(const char *buffer, EasycommData *parsed)
{
    static CommandParser parsers[] = {
        { .isCommand = isEasycomm1SingleLine, .parseCommand = readEasycomm1SingleLine },
        { .isCommand = isEasycommReset, .parseCommand = readEasycommReset },
        { .isCommand = isEasycommPark, .parseCommand = readEasycommPark },
        { .isCommand = fallbackPredicate, .parseCommand = fallbackParser },
        { .isCommand = NULL, .parseCommand = NULL },
    };

    return invokeCommandParsers(buffer, parsers, parsed);
}

static bool easycommParse2(const char *buffer, EasycommData *parsed)
{
    static CommandParser parsers[] = {
        { .isCommand = isEasycomm2GetAzimuthElevation, .parseCommand = readEasycomm2GetAzimuthElevation },
        { .isCommand = isEasycomm2Azimuth, .parseCommand = readEasycomm2Azimuth },
        { .isCommand = isEasycomm2GetAzimuth, .parseCommand = readEasycomm2GetAzimuth },
        { .isCommand = isEasycomm2Elevation, .parseCommand = readEasycomm2Elevation },
        { .isCommand = isEasycomm2GetElevation, .parseCommand = readEasycomm2GetElevation },
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
        { .isCommand = fallbackPredicate, .parseCommand = fallbackParser },
        { .isCommand = NULL, .parseCommand = NULL },
    };

    return invokeCommandParsers(buffer, parsers, parsed);
}

static bool easycommParse3(const char *buffer, EasycommData *parsed)
{
    static CommandParser parsers[] = {
        { .isCommand = isEasycomm3VelocityLeft, .parseCommand = readEasycomm3VelocityLeft },
        { .isCommand = isEasycomm3GetVelocityLeft, .parseCommand = readEasycomm3GetVelocityLeft },
        { .isCommand = isEasycomm3VelocityRight, .parseCommand = readEasycomm3VelocityRight },
        { .isCommand = isEasycomm3GetVelocityRight, .parseCommand = readEasycomm3GetVelocityRight },
        { .isCommand = isEasycomm3VelocityUp, .parseCommand = readEasycomm3VelocityUp },
        { .isCommand = isEasycomm3GetVelocityUp, .parseCommand = readEasycomm3GetVelocityUp },
        { .isCommand = isEasycomm3VelocityDown, .parseCommand = readEasycomm3VelocityDown },
        { .isCommand = isEasycomm3GetVelocityDown, .parseCommand = readEasycomm3GetVelocityDown },
        { .isCommand = isEasycomm3ReadConfig, .parseCommand = readEasycomm3ReadConfig },
        { .isCommand = isEasycomm3WriteConfig, .parseCommand = readEasycomm3WriteConfig },
        { .isCommand = isEasycomm3GetStatusRegister, .parseCommand = readEasycomm3GetStatusRegister },
        { .isCommand = isEasycomm3GetErrorRegister, .parseCommand = readEasycomm3GetErrorRegister },
        { .isCommand = fallbackPredicate, .parseCommand = fallbackParser },
        { .isCommand = NULL, .parseCommand = NULL },
    };

    return invokeCommandParsers(buffer, parsers, parsed);
}


static bool easycommParse12(const char *buffer, EasycommData *parsed)
{
    if(easycommParse1(buffer, parsed))
        return true;
    else
        return easycommParse2(buffer, parsed);
}


static bool easycommParse23(const char *buffer, EasycommData *parsed)
{
    if(easycommParse2(buffer, parsed))
        return true;
    else
        return easycommParse3(buffer, parsed);
}


static bool easycommParse123(const char *buffer, EasycommData *parsed)
{
    if(easycommParse1(buffer, parsed))
        return true;
    else if(easycommParse2(buffer, parsed))
        return true;
    else
        return easycommParse3(buffer, parsed);
}


bool easycommParse(const char *buffer, EasycommData *parsed, EasycommParserStandard parser_standard)
{
    static EasycommParseStandardFunction standards[] = {
        easycommParse1, easycommParse12, easycommParse123,
        easycommParse2, easycommParse23, easycommParse3,
    };
    return standards[parser_standard](buffer, parsed);
}
