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
        callbacks->registry[EasycommIdDoReset] = custom_default_cb;
        callbacks->registry[EasycommIdDoPark] = custom_default_cb;
    }

    if(EasycommParserStandard12 == parser_standard || EasycommParserStandard2 == parser_standard ||
       EasycommParserStandard23 == parser_standard || EasycommParserStandard123 == parser_standard)
    {
        callbacks->registry[EasycommIdSingleLine] = custom_default_cb;
        callbacks->registry[EasycommIdSetAzimuth] = custom_default_cb;
        callbacks->registry[EasycommIdGetAzimuth] = custom_default_cb;
        callbacks->registry[EasycommIdSetElevation] = custom_default_cb;
        callbacks->registry[EasycommIdGetElevation] = custom_default_cb;
        callbacks->registry[EasycommIdSetUplinkFrequency] = custom_default_cb;
        callbacks->registry[EasycommIdGetUplinkFrequency] = custom_default_cb;
        callbacks->registry[EasycommIdSetDownlinkFrequency] = custom_default_cb;
        callbacks->registry[EasycommIdGetDownlinkFrequency] = custom_default_cb;
        callbacks->registry[EasycommIdSetUplinkMode] = custom_default_cb;
        callbacks->registry[EasycommIdGetUplinkMode] = custom_default_cb;
        callbacks->registry[EasycommIdSetDownlinkMode] = custom_default_cb;
        callbacks->registry[EasycommIdGetDownlinkMode] = custom_default_cb;
        callbacks->registry[EasycommIdSetUplinkRadio] = custom_default_cb;
        callbacks->registry[EasycommIdGetUplinkRadio] = custom_default_cb;
        callbacks->registry[EasycommIdSetDownlinkRadio] = custom_default_cb;
        callbacks->registry[EasycommIdGetDownlinkRadio] = custom_default_cb;
        callbacks->registry[EasycommIdDoMoveLeft] = custom_default_cb;
        callbacks->registry[EasycommIdDoMoveRight] = custom_default_cb;
        callbacks->registry[EasycommIdDoMoveUp] = custom_default_cb;
        callbacks->registry[EasycommIdDoMoveDown] = custom_default_cb;
        callbacks->registry[EasycommIdDoStopAzimuthMove] = custom_default_cb;
        callbacks->registry[EasycommIdDoStopElevationMove] = custom_default_cb;
        callbacks->registry[EasycommIdAcquisitionOfSignal] = custom_default_cb;
        callbacks->registry[EasycommIdLossOfSignal] = custom_default_cb;
        callbacks->registry[EasycommIdSetDigitalOutput] = custom_default_cb;
        callbacks->registry[EasycommIdGetDigitalInput] = custom_default_cb;
        callbacks->registry[EasycommIdGetAnalogueInput] = custom_default_cb;
        callbacks->registry[EasycommIdSetTime] = custom_default_cb;
        callbacks->registry[EasycommIdGetTime] = custom_default_cb;
        callbacks->registry[EasycommIdGetVersion] = custom_default_cb;
    }

    if(EasycommParserStandard23 == parser_standard || EasycommParserStandard3 == parser_standard ||
       EasycommParserStandard123 == parser_standard)
    {
        callbacks->registry[EasycommIdSetVelocityLeft] = custom_default_cb;
        callbacks->registry[EasycommIdGetVelocityLeft] = custom_default_cb;
        callbacks->registry[EasycommIdSetVelocityRight] = custom_default_cb;
        callbacks->registry[EasycommIdGetVelocityRight] = custom_default_cb;
        callbacks->registry[EasycommIdSetVelocityUp] = custom_default_cb;
        callbacks->registry[EasycommIdGetVelocityUp] = custom_default_cb;
        callbacks->registry[EasycommIdSetVelocityDown] = custom_default_cb;
        callbacks->registry[EasycommIdGetVelocityDown] = custom_default_cb;
        callbacks->registry[EasycommIdSetConfigRegister] = custom_default_cb;
        callbacks->registry[EasycommIdGetConfigRegister] = custom_default_cb;
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
