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
        { .isCommand = isEasycomm1SingleLine, .parseCommand = parseEasycomm1SingleLine },
        { .isCommand = isEasycommDoReset, .parseCommand = parseEasycommDoReset },
        { .isCommand = isEasycommDoPark, .parseCommand = parseEasycommDoPark },
        { .isCommand = fallbackPredicate, .parseCommand = fallbackParser },
        { .isCommand = NULL, .parseCommand = NULL },
    };

    return invokeCommandParsers(buffer, parsers, parsed);
}

static bool easycommParse2(const char *buffer, EasycommData *parsed)
{
    static CommandParser parsers[] = {
        { .isCommand = isEasycomm2SetAzimuth, .parseCommand = parseEasycomm2SetAzimuth },
        { .isCommand = isEasycomm2GetAzimuth, .parseCommand = parseEasycomm2GetAzimuth },
        { .isCommand = isEasycomm2SetElevation, .parseCommand = parseEasycomm2SetElevation },
        { .isCommand = isEasycomm2GetElevation, .parseCommand = parseEasycomm2GetElevation },
        { .isCommand = isEasycomm2SetUplinkFrequency, .parseCommand = parseEasycomm2SetUplinkFrequency },
        { .isCommand = isEasycomm2SetDownlinkFrequency, .parseCommand = parseEasycomm2SetDownlinkFrequency },
        { .isCommand = isEasycomm2SetUplinkMode, .parseCommand = parseEasycomm2SetUplinkMode },
        { .isCommand = isEasycomm2SetDownlinkMode, .parseCommand = parseEasycomm2SetDownlinkMode },
        { .isCommand = isEasycomm2SetUplinkRadioNumber, .parseCommand = parseEasycomm2SetUplinkRadioNumber },
        { .isCommand = isEasycomm2SetDownlinkRadioNumber, .parseCommand = parseEasycomm2SetDownlinkRadioNumber },
        { .isCommand = isEasycomm2DoMoveLeft, .parseCommand = parseEasycomm2DoMoveLeft },
        { .isCommand = isEasycomm2DoMoveRight, .parseCommand = parseEasycomm2DoMoveRight },
        { .isCommand = isEasycomm2DoMoveUp, .parseCommand = parseEasycomm2DoMoveUp },
        { .isCommand = isEasycomm2DoMoveDown, .parseCommand = parseEasycomm2DoMoveDown },
        { .isCommand = isEasycomm2DoStopAzimuthMove, .parseCommand = parseEasycomm2DoStopAzimuthMove },
        { .isCommand = isEasycomm2DoStopElevationMove, .parseCommand = parseEasycomm2DoStopElevationMove },
        { .isCommand = isEasycomm2AcquisitionOfSignal, .parseCommand = parseEasycomm2AcquisitionOfSignal },
        { .isCommand = isEasycomm2LossOfSignal, .parseCommand = parseEasycomm2LossOfSignal },
        { .isCommand = isEasycomm2SetDigitalOutput, .parseCommand = parseEasycomm2SetDigitalOutput },
        { .isCommand = isEasycomm2GetDigitalInput, .parseCommand = parseEasycomm2GetDigitalInput },
        { .isCommand = isEasycomm2GetAnalogueInput, .parseCommand = parseEasycomm2GetAnalogueInput },
        { .isCommand = isEasycomm2SetTime, .parseCommand = parseEasycomm2SetTime },
        { .isCommand = isEasycomm2GetVersion, .parseCommand = parseEasycomm2GetVersion },
        { .isCommand = fallbackPredicate, .parseCommand = fallbackParser },
        { .isCommand = NULL, .parseCommand = NULL },
    };

    return invokeCommandParsers(buffer, parsers, parsed);
}

static bool easycommParse3(const char *buffer, EasycommData *parsed)
{
    static CommandParser parsers[] = {
        { .isCommand = isEasycomm3SetVelocityLeft, .parseCommand = parseEasycomm3SetVelocityLeft },
        { .isCommand = isEasycomm3GetVelocityLeft, .parseCommand = parseEasycomm3GetVelocityLeft },
        { .isCommand = isEasycomm3SetVelocityRight, .parseCommand = parseEasycomm3SetVelocityRight },
        { .isCommand = isEasycomm3GetVelocityRight, .parseCommand = parseEasycomm3GetVelocityRight },
        { .isCommand = isEasycomm3SetVelocityUp, .parseCommand = parseEasycomm3SetVelocityUp },
        { .isCommand = isEasycomm3GetVelocityUp, .parseCommand = parseEasycomm3GetVelocityUp },
        { .isCommand = isEasycomm3SetVelocityDown, .parseCommand = parseEasycomm3SetVelocityDown },
        { .isCommand = isEasycomm3GetVelocityDown, .parseCommand = parseEasycomm3GetVelocityDown },
        { .isCommand = isEasycomm3GetConfigRegister, .parseCommand = parseEasycomm3GetConfigRegister },
        { .isCommand = isEasycomm3SetConfigRegister, .parseCommand = parseEasycomm3SetConfigRegister },
        { .isCommand = isEasycomm3GetStatusRegister, .parseCommand = parseEasycomm3GetStatusRegister },
        { .isCommand = isEasycomm3GetErrorRegister, .parseCommand = parseEasycomm3GetErrorRegister },
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


bool easycommParseCommand(const char *buffer, EasycommData *parsed, EasycommParserStandard parser_standard)
{
    static EasycommParseStandardFunction standards[] = {
        easycommParse1, easycommParse12, easycommParse123,
        easycommParse2, easycommParse23, easycommParse3,
    };
    return standards[parser_standard](buffer, parsed);
}
