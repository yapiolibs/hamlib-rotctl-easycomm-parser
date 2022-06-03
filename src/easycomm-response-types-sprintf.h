#pragma once
#ifdef __cplusplus
extern "C"
{
#endif

#include <inttypes.h>
#include <stdbool.h>

#include "easycomm-response-types.h"

    void easycommResponseSingleLineSprintf(const EasycommResponseSingleLine *from, char *to);
    void easycommResponseAzimuthSprintf(const EasycommResponseAzimuth *from, char *to);
    void easycommResponseElevationSprintf(const EasycommResponseElevation *from, char *to);
    void easycommResponseUplinkFrequencySprintf(const EasycommResponseUplinkFrequency *from, char *to);
    void easycommResponseDownlinkFrequencySprintf(const EasycommResponseDownlinkFrequency *from, char *to);
    void easycommResponseUplinkModeSprintf(const EasycommResponseUplinkMode *from, char *to);
    void easycommResponseDownlinkModeSprintf(const EasycommResponseDownlinkMode *from, char *to);
    void easycommResponseDownlinkRadioSprintf(const EasycommResponseDownlinkRadio *from, char *to);
    void easycommResponseUplinkRadioSprintf(const EasycommResponseUplinkRadio *from, char *to);
    void easycommResponseDigitalInputSprintf(const EasycommResponseDigitalInput *from, char *to);
    void easycommResponseAnalogueInputSprintf(const EasycommResponseAnalogueInput *from, char *to);
    void easycommResponseVersionSprintf(const EasycommResponseVersion *from, char *to);
    void easycommResponseTimeSprintf(const EasycommResponseTime *from, char *to);
    void easycommResponseAlarmSprintf(const EasycommResponseAlarm *from, char *to);
    void easycommResponseVelocityLeftSprintf(const EasycommResponseVelocityLeft *from, char *to);
    void easycommResponseVelocityRightSprintf(const EasycommResponseVelocityRight *from, char *to);
    void easycommResponseVelocityUpSprintf(const EasycommResponseVelocityUp *from, char *to);
    void easycommResponseVelocityDownSprintf(const EasycommResponseVelocityDown *from, char *to);
    void easycommResponseConfigRegisterSprintf(const EasycommResponseConfigRegister *from, char *to);
    void easycommResponseStatusRegisterSprintf(const EasycommResponseStatusRegister *from, char *to);
    void easycommResponseErrorRegisterSprintf(const EasycommResponseErrorRegister *from, char *to);

#ifdef __cplusplus
}
#endif
