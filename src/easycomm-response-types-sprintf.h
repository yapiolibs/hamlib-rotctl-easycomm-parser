#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#include <inttypes.h>
#include <stdbool.h>

#include "easycomm-response-types.h"

    void easycommSingleLineSprintf(const EasycommResponseSingleLine *from, char *to);
    void easycommAzimuthSprintf(const EasycommResponseAzimuth *from, char *to);
    void easycommElevationSprintf(const EasycommResponseElevation *from, char *to);
    void easycommAzimuthElevationSprintf(const EasycommResponseAzimuthElevation *from, char *to);
    void easycommUplinkFrequencySprintf(const EasycommResponseUplinkFrequency *from, char *to);
    void easycommDownlinkFrequencySprintf(const EasycommResponseDownlinkFrequency *from, char *to);
    void easycommUplinkModeSprintf(const EasycommResponseUplinkMode *from, char *to);
    void easycommDownlinkModeSprintf(const EasycommResponseDownlinkMode *from, char *to);
    void easycommDownlinkRadioNumberSprintf(const EasycommResponseDownlinkRadioNumber *from, char *to);
    void easycommUplinkRadioNumberSprintf(const EasycommResponseUplinkRadioNumber *from, char *to);
    void easycommReadInputSprintf(const EasycommResponseReadInput *from, char *to);
    void easycommReadAnalogueInputSprintf(const EasycommResponseReadAnalogueInput *from, char *to);
    void easycommRequestVersionSprintf(const EasycommResponseRequestVersion *from, char *to);
    void easycommAlarmSprintf(const EasycommResponseAlarm *from, char *to);
    void easycommVelocityLeftSprintf(const EasycommResponseVelocityLeft *from, char *to);
    void easycommVelocityRightSprintf(const EasycommResponseVelocityRight *from, char *to);
    void easycommVelocityUpSprintf(const EasycommResponseVelocityUp *from, char *to);
    void easycommVelocityDownSprintf(const EasycommResponseVelocityDown *from, char *to);
    void easycommReadConfigSprintf(const EasycommResponseReadConfig *from, char *to);
    void easycommGetStatusRegisterSprintf(const EasycommResponseGetStatusRegister *from, char *to);
    void easycommGetErrorRegisterSprintf(const EasycommResponseGetErrorRegister *from, char *to);

#ifdef __cplusplus
}
#endif