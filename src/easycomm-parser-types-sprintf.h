#pragma once
#ifdef __cplusplus
extern "C"
{
#endif
#include <inttypes.h>
#include <stdbool.h>

#include "easycomm-parser-types.h"

    void easycommInvalidSprintf(const EasycommData *from, char *to);
    void easycommSingleLineSprintf(const EasycommSingleLine *from, char *to);
    void easycommSetAzimuthSprintf(const EasycommSetAzimuth *from, char *to);
    void easycommGetAzimuthSprintf(const EasycommGetAzimuth *from, char *to);
    void easycommSetElevationSprintf(const EasycommSetElevation *from, char *to);
    void easycommGetElevationSprintf(const EasycommGetElevation *from, char *to);
    void easycommSetUplinkFrequencySprintf(const EasycommSetUplinkFrequency *from, char *to);
    void easycommSetDownlinkFrequencySprintf(const EasycommSetDownlinkFrequency *from, char *to);
    void easycommSetUplinkModeSprintf(const EasycommSetUplinkMode *from, char *to);
    void easycommSetDownlinkModeSprintf(const EasycommSetDownlinkMode *from, char *to);
    void easycommSetUplinkRadioNumberSprintf(const EasycommSetUplinkRadioNumber *from, char *to);
    void easycommSetDownlinkRadioNumberSprintf(const EasycommSetDownlinkRadioNumber *from, char *to);
    void easycommDoMoveLeftSprintf(const EasycommDoMoveLeft *from, char *to);
    void easycommDoMoveRightSprintf(const EasycommDoMoveRight *from, char *to);
    void easycommDoMoveUpSprintf(const EasycommDoMoveUp *from, char *to);
    void easycommDoMoveDownSprintf(const EasycommDoMoveDown *from, char *to);
    void easycommDoStopAzimuthMoveSprintf(const EasycommDoStopAzimuthMove *from, char *to);
    void easycommDoStopElevationMoveSprintf(const EasycommDoStopElevationMove *from, char *to);
    void easycommAcquisitionOfSignalSprintf(const EasycommAcquisitionOfSignal *from, char *to);
    void easycommLossOfSignalSprintf(const EasycommLossOfSignal *from, char *to);
    void easycommSetDigitalOutputSprintf(const EasycommSetDigitalOutput *from, char *to);
    void easycommGetDigitalInputSprintf(const EasycommGetDigitalInput *from, char *to);
    void easycommGetAnalogueInputSprintf(const EasycommGetAnalogueInput *from, char *to);
    void easycommSetTimeSprintf(const EasycommSetTime *from, char *to);
    void easycommGetVersionSprintf(const EasycommGetVersion *from, char *to);
    void easycommSetVelocityLeftSprintf(const EasycommSetVelocityLeft *from, char *to);
    void easycommGetVelocityLeftSprintf(const EasycommGetVelocityLeft *from, char *to);
    void easycommSetVelocityRightSprintf(const EasycommSetVelocityRight *from, char *to);
    void easycommGetVelocityRightSprintf(const EasycommGetVelocityRight *from, char *to);
    void easycommSetVelocityUpSprintf(const EasycommSetVelocityUp *from, char *to);
    void easycommGetVelocityUpSprintf(const EasycommGetVelocityUp *from, char *to);
    void easycommSetVelocityDownSprintf(const EasycommSetVelocityDown *from, char *to);
    void easycommGetVelocityDownSprintf(const EasycommGetVelocityDown *from, char *to);
    void easycommGetConfigRegisterSprintf(const EasycommGetConfigRegister *from, char *to);
    void easycommSetConfigRegisterSprintf(const EasycommSetConfigRegister *from, char *to);
    void easycommGetStatusRegisterSprintf(const EasycommGetStatusRegister *from, char *to);
    void easycommGetErrorRegisterSprintf(const EasycommGetErrorRegister *from, char *to);
    void easycommDataSprintf(const EasycommData *from, char *to);
    void easycommDoResetSprintf(const EasycommDoReset *from, char *to);
    void easycommDoParkSprintf(const EasycommDoPark *from, char *to);

#ifdef __cplusplus
}
#endif
