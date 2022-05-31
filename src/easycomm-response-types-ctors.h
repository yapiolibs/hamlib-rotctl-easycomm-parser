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
    void easycommResponseDigitalInput(EasycommResponseDigitalInput *d);
    void easycommResponseAnalogueInput(EasycommResponseAnalogueInput *d);
    void easycommResponseVersion(EasycommResponseVersion *d);
    void easycommResponseAlarm(EasycommResponseAlarm *d);
    void easycommResponseVelocityLeft(EasycommResponseVelocityLeft *d);
    void easycommResponseVelocityRight(EasycommResponseVelocityRight *d);
    void easycommResponseVelocityUp(EasycommResponseVelocityUp *d);
    void easycommResponseVelocityDown(EasycommResponseVelocityDown *d);
    void easycommResponseConfigRegister(EasycommResponseConfigRegister *d);
    void easycommResponseStatusRegister(EasycommResponseStatusRegister *d);
    void easycommResponseErrorRegister(EasycommResponseErrorRegister *d);

#ifdef __cplusplus
}
#endif
