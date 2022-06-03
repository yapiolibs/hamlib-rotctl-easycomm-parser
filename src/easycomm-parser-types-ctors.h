#pragma once
#ifdef __cplusplus
extern "C"
{
#endif

#include "easycomm-parser-types.h"

    void easycommData(EasycommData *d);
    void easycommPayload(EasycommPayload *d);
    void easycommSingleLine(EasycommSingleLine *d);
    void easycommFrequency(EasycommFrequency *d);
    void easycommSetAzimuth(EasycommSetAzimuth *d);
    void easycommGetAzimuth(EasycommGetAzimuth *d);
    void easycommSetElevation(EasycommSetElevation *d);
    void easycommGetElevation(EasycommGetElevation *d);
    void easycommSetUplinkFrequency(EasycommSetUplinkFrequency *d);
    void easycommSetDownlinkFrequency(EasycommSetDownlinkFrequency *d);
    void easycommSetUplinkMode(EasycommSetUplinkMode *d);
    void easycommSetDownlinkMode(EasycommSetDownlinkMode *d);
    void easycommSetUplinkRadioNumber(EasycommSetUplinkRadioNumber *d);
    void easycommSetDownlinkRadioNumber(EasycommSetDownlinkRadioNumber *d);
    void easycommDoMoveLeft(EasycommDoMoveLeft *d);
    void easycommDoMoveRight(EasycommDoMoveRight *d);
    void easycommDoMoveUp(EasycommDoMoveUp *d);
    void easycommDoMoveDown(EasycommDoMoveDown *d);
    void easycommDoStopAzimuthMove(EasycommDoStopAzimuthMove *d);
    void easycommDoStopElevationMove(EasycommDoStopElevationMove *d);
    void easycommAcquisitionOfSignal(EasycommAcquisitionOfSignal *d);
    void easycommLossOfSignal(EasycommLossOfSignal *d);
    void easycommSetDigitalOutput(EasycommSetDigitalOutput *d);
    void easycommGetDigitalInput(EasycommGetDigitalInput *d);
    void easycommGetAnalogueInput(EasycommGetAnalogueInput *d);
    void easycommSetTime(EasycommSetTime *d);
    void easycommGetVersion(EasycommGetVersion *d);
    void easycommSetVelocityLeft(EasycommSetVelocityLeft *d);
    void easycommGetVelocityLeft(EasycommGetVelocityLeft *d);
    void easycommSetVelocityRight(EasycommSetVelocityRight *d);
    void easycommGetVelocityRight(EasycommGetVelocityRight *d);
    void easycommSetVelocityUp(EasycommSetVelocityUp *d);
    void easycommGetVelocityUp(EasycommGetVelocityUp *d);
    void easycommSetVelocityDown(EasycommSetVelocityDown *d);
    void easycommGetVelocityDown(EasycommGetVelocityDown *d);
    void easycommGetConfigRegister(EasycommGetConfigRegister *d);
    void easycommSetConfigRegister(EasycommSetConfigRegister *d);
    void easycommGetStatusRegister(EasycommGetStatusRegister *d);
    void easycommGetErrorRegister(EasycommGetErrorRegister *d);
    void easycommDoReset(EasycommDoReset *d);
    void easycommDoPark(EasycommDoPark *d);

#ifdef __cplusplus
}
#endif
