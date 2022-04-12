#pragma once
#ifdef __cplusplus
extern "C"
{
#endif

#include "easycomm-response-types.h"

    void easycommResponseSingleLine(EasycommResponseSingleLine *d);
    void easycommResponseAzimuth(EasycommResponseAzimuth *d);
    void easycommResponseElevation(EasycommResponseElevation *d);
    void easycommResponseUplinkFrequency(EasycommResponseUplinkFrequency *d);
    void easycommResponseDownlinkFrequency(EasycommResponseDownlinkFrequency *d);
    void easycommResponseUplinkMode(EasycommResponseUplinkMode *d);
    void easycommResponseDownlinkMode(EasycommResponseDownlinkMode *d);
    void easycommResponseDownlinkRadioNumber(EasycommResponseDownlinkRadioNumber *d);
    void easycommResponseUplinkRadioNumber(EasycommResponseUplinkRadioNumber *d);
    void easycommResponseReadInput(EasycommResponseReadInput *d);
    void easycommResponseReadAnalogueInput(EasycommResponseReadAnalogueInput *d);
    void easycommResponseRequestVersion(EasycommResponseRequestVersion *d);
    void easycommResponseAlarm(EasycommResponseAlarm *d);
    void easycommResponseVelocityLeft(EasycommResponseVelocityLeft *d);
    void easycommResponseVelocityRight(EasycommResponseVelocityRight *d);
    void easycommResponseVelocityUp(EasycommResponseVelocityUp *d);
    void easycommResponseVelocityDown(EasycommResponseVelocityDown *d);
    void easycommResponseReadConfig(EasycommResponseReadConfig *d);
    void easycommResponseGetStatusRegister(EasycommResponseGetStatusRegister *d);
    void easycommResponseGetErrorRegister(EasycommResponseGetErrorRegister *d);

#ifdef __cplusplus
}
#endif
