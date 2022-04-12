#include "../easycomm-command-callback-handler.h"

#include <stdio.h>
#include <string.h> // size_t


void defaultCallback(const EasycommData *command, void *custom_data) {}


void easycommCommandsCallback(EasycommCommandsCallback *callbacks, EasycommParserStandard parser_standard)
{
    easycommCommandsCallbackCustomDefaultCb(callbacks, parser_standard, defaultCallback);
}


void easycommCommandsCallbackCustomDefaultCb(EasycommCommandsCallback *callbacks,
                                             EasycommParserStandard parser_standard,
                                             EasycommCommandCallback custom_default_cb)
{
    if(NULL == callbacks)
        return;

    for(size_t i = 0; i < EasycommIdsCount; i++)
        callbacks->registry[i] = NULL;

    callbacks->registry[EasycommIdInvalid] = custom_default_cb;

    if(EasycommParserStandard1 == parser_standard || EasycommParserStandard12 == parser_standard ||
       EasycommParserStandard123 == parser_standard)
    {
        callbacks->registry[EasycommIdSingleLine] = custom_default_cb;
        callbacks->registry[EasycommIdReset] = custom_default_cb;
        callbacks->registry[EasycommIdPark] = custom_default_cb;
    }

    if(EasycommParserStandard12 == parser_standard || EasycommParserStandard2 == parser_standard ||
       EasycommParserStandard23 == parser_standard || EasycommParserStandard123 == parser_standard)
    {
        callbacks->registry[EasycommIdSingleLine] = custom_default_cb;
        callbacks->registry[EasycommIdGetAzimuth] = custom_default_cb;
        callbacks->registry[EasycommIdAzimuth] = custom_default_cb;
        callbacks->registry[EasycommIdElevation] = custom_default_cb;
        callbacks->registry[EasycommIdGetElevation] = custom_default_cb;
        callbacks->registry[EasycommIdUplinkFrequency] = custom_default_cb;
        callbacks->registry[EasycommIdDownlinkFrequency] = custom_default_cb;
        callbacks->registry[EasycommIdUplinkMode] = custom_default_cb;
        callbacks->registry[EasycommIdDownlinkMode] = custom_default_cb;
        callbacks->registry[EasycommIdUplinkRadioNumber] = custom_default_cb;
        callbacks->registry[EasycommIdDownlinkRadioNumber] = custom_default_cb;
        callbacks->registry[EasycommIdMoveLeft] = custom_default_cb;
        callbacks->registry[EasycommIdMoveRight] = custom_default_cb;
        callbacks->registry[EasycommIdMoveUp] = custom_default_cb;
        callbacks->registry[EasycommIdMoveDown] = custom_default_cb;
        callbacks->registry[EasycommIdStopAzimuthMove] = custom_default_cb;
        callbacks->registry[EasycommIdStopElevationMove] = custom_default_cb;
        callbacks->registry[EasycommIdAcquisitionOfSignal] = custom_default_cb;
        callbacks->registry[EasycommIdLossOfSignal] = custom_default_cb;
        callbacks->registry[EasycommIdSetOutput] = custom_default_cb;
        callbacks->registry[EasycommIdReadInput] = custom_default_cb;
        callbacks->registry[EasycommIdReadAnalogueInput] = custom_default_cb;
        callbacks->registry[EasycommIdSetTime] = custom_default_cb;
        callbacks->registry[EasycommIdRequestVersion] = custom_default_cb;
    }

    if(EasycommParserStandard23 == parser_standard || EasycommParserStandard3 == parser_standard ||
       EasycommParserStandard123 == parser_standard)
    {
        callbacks->registry[EasycommIdVelocityLeft] = custom_default_cb;
        callbacks->registry[EasycommIdGetVelocityLeft] = custom_default_cb;
        callbacks->registry[EasycommIdVelocityRight] = custom_default_cb;
        callbacks->registry[EasycommIdGetVelocityRight] = custom_default_cb;
        callbacks->registry[EasycommIdVelocityUp] = custom_default_cb;
        callbacks->registry[EasycommIdGetVelocityUp] = custom_default_cb;
        callbacks->registry[EasycommIdVelocityDown] = custom_default_cb;
        callbacks->registry[EasycommIdGetVelocityDown] = custom_default_cb;
        callbacks->registry[EasycommIdReadConfig] = custom_default_cb;
        callbacks->registry[EasycommIdWriteConfig] = custom_default_cb;
        callbacks->registry[EasycommIdGetStatusRegister] = custom_default_cb;
        callbacks->registry[EasycommIdGetErrorRegister] = custom_default_cb;
    }
}


bool easycommHandleCommand(const char *buffer,
                           EasycommCommandsCallback *registry,
                           EasycommParserStandard parser_standard,
                           void *custom_data)
{
    EasycommData command;
    if(easycommParseCommand(buffer, &command, parser_standard))
    {
        if(NULL == registry)
            return false;

        EasycommCommandCallback callback = registry->registry[command.commandId];
        if(NULL != callback)
        {
            callback(&command, custom_data);
            return true;
        }
    }
    return false;
}
