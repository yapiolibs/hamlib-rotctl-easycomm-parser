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
    void easycommAzimuth(EasycommAzimuth *d);
    void easycommGetAzimuth(EasycommGetAzimuth *d);
    void easycommElevation(EasycommElevation *d);
    void easycommGetElevation(EasycommGetElevation *d);
    void easycommGetAzimuthElevation(EasycommGetAzimuthElevation *d);
    void easycommUplinkFrequency(EasycommUplinkFrequency *d);
    void easycommDownlinkFrequency(EasycommDownlinkFrequency *d);
    void easycommUplinkMode(EasycommUplinkMode *d);
    void easycommDownlinkMode(EasycommDownlinkMode *d);
    void easycommUplinkRadioNumber(EasycommUplinkRadioNumber *d);
    void easycommDownlinkRadioNumber(EasycommDownlinkRadioNumber *d);
    void easycommMoveLeft(EasycommMoveLeft *d);
    void easycommMoveRight(EasycommMoveRight *d);
    void easycommMoveUp(EasycommMoveUp *d);
    void easycommMoveDown(EasycommMoveDown *d);
    void easycommStopAzimuthMove(EasycommStopAzimuthMove *d);
    void easycommStopElevationMove(EasycommStopElevationMove *d);
    void easycommAcquisitionOfSignal(EasycommAcquisitionOfSignal *d);
    void easycommLossOfSignal(EasycommLossOfSignal *d);
    void easycommSetOutput(EasycommSetOutput *d);
    void easycommReadInput(EasycommReadInput *d);
    void easycommReadAnalogueInput(EasycommReadAnalogueInput *d);
    void easycommSetTime(EasycommSetTime *d);
    void easycommRequestVersion(EasycommRequestVersion *d);
    void easycommVelocityLeft(EasycommVelocityLeft *d);
    void easycommGetVelocityLeft(EasycommGetVelocityLeft *d);
    void easycommVelocityRight(EasycommVelocityRight *d);
    void easycommGetVelocityRight(EasycommGetVelocityRight *d);
    void easycommVelocityUp(EasycommVelocityUp *d);
    void easycommGetVelocityUp(EasycommGetVelocityUp *d);
    void easycommVelocityDown(EasycommVelocityDown *d);
    void easycommGetVelocityDown(EasycommGetVelocityDown *d);
    void easycommReadConfig(EasycommReadConfig *d);
    void easycommWriteConfig(EasycommWriteConfig *d);
    void easycommGetStatusRegister(EasycommGetStatusRegister *d);
    void easycommGetErrorRegister(EasycommGetErrorRegister *d);
    void easycommReset(EasycommReset *d);
    void easycommPark(EasycommPark *d);

#ifdef __cplusplus
}
#endif
