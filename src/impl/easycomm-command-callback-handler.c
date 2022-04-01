#include "../easycomm-command-callback-handler.h"

#include <stdio.h>
#include <string.h> // size_t


void defaultCallback(const EasycommData *command, void *custom_data) {}


void easycommCommandsCallback(EasycommCommandsCallback *callbacks, EasycommParserStandard parser_standard)
{
    if(NULL == callbacks)
        return;

    for(size_t i = 0; i < EasycommIdsCount; i++)
        callbacks->registry[i] = NULL;

    callbacks->registry[EasycommIdInvalid] = defaultCallback;

    if(EasycommParserStandard1 == parser_standard || EasycommParserStandard12 == parser_standard ||
       EasycommParserStandard123 == parser_standard)
    {
        callbacks->registry[EasycommIdSingleLine] = defaultCallback;
    }

    if(EasycommParserStandard12 == parser_standard || EasycommParserStandard2 == parser_standard ||
       EasycommParserStandard23 == parser_standard || EasycommParserStandard123 == parser_standard)
    {
        callbacks->registry[EasycommIdSingleLine] = defaultCallback;
        callbacks->registry[EasycommIdAzimuth] = defaultCallback;
        callbacks->registry[EasycommIdElevation] = defaultCallback;
        callbacks->registry[EasycommIdUplinkFrequency] = defaultCallback;
        callbacks->registry[EasycommIdDownlinkFrequency] = defaultCallback;
        callbacks->registry[EasycommIdUplinkMode] = defaultCallback;
        callbacks->registry[EasycommIdDownlinkMode] = defaultCallback;
        callbacks->registry[EasycommIdUplinkRadioNumber] = defaultCallback;
        callbacks->registry[EasycommIdDownlinkRadioNumber] = defaultCallback;
        callbacks->registry[EasycommIdMoveLeft] = defaultCallback;
        callbacks->registry[EasycommIdMoveRight] = defaultCallback;
        callbacks->registry[EasycommIdMoveUp] = defaultCallback;
        callbacks->registry[EasycommIdMoveDown] = defaultCallback;
        callbacks->registry[EasycommIdStopAzimuthMove] = defaultCallback;
        callbacks->registry[EasycommIdStopElevationMove] = defaultCallback;
        callbacks->registry[EasycommIdAcquisitionOfSignal] = defaultCallback;
        callbacks->registry[EasycommIdLossOfSignal] = defaultCallback;
        callbacks->registry[EasycommIdSetOutput] = defaultCallback;
        callbacks->registry[EasycommIdReadInput] = defaultCallback;
        callbacks->registry[EasycommIdReadAnalogueInput] = defaultCallback;
        callbacks->registry[EasycommIdSetTime] = defaultCallback;
        callbacks->registry[EasycommIdRequestVersion] = defaultCallback;
    }

    if(EasycommParserStandard23 == parser_standard || EasycommParserStandard3 == parser_standard ||
       EasycommParserStandard123 == parser_standard)
    {
        callbacks->registry[EasycommIdVelocityLeft] = defaultCallback;
        callbacks->registry[EasycommIdVelocityRight] = defaultCallback;
        callbacks->registry[EasycommIdVelocityUp] = defaultCallback;
        callbacks->registry[EasycommIdVelocityDown] = defaultCallback;
        callbacks->registry[EasycommIdReadConfig] = defaultCallback;
        callbacks->registry[EasycommIdWriteConfig] = defaultCallback;
        callbacks->registry[EasycommIdGetStatusRegister] = defaultCallback;
        callbacks->registry[EasycommIdGetErrorRegister] = defaultCallback;
    }
}


bool easycommHandleCommand(const char *buffer,
                           EasycommCommandsCallback *registry,
                           EasycommParserStandard parser_standard,
                           void *custom_data)
{
    EasycommData command;
    if(easycommParse(buffer, &command, parser_standard))
    {
        EasycommCommandCallback callback = registry->registry[command.commandId];
        if(NULL != callback)
        {
            callback(&command, custom_data);
            return true;
        }
    }
    return false;
}