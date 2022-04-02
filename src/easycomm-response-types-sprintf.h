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
    void easycommResponseAzimuthElevationSprintf(const EasycommResponseAzimuthElevation *from, char *to);
    void easycommResponseUplinkFrequencySprintf(const EasycommResponseUplinkFrequency *from, char *to);
    void easycommResponseDownlinkFrequencySprintf(const EasycommResponseDownlinkFrequency *from, char *to);
    void easycommResponseUplinkModeSprintf(const EasycommResponseUplinkMode *from, char *to);
    void easycommResponseDownlinkModeSprintf(const EasycommResponseDownlinkMode *from, char *to);
    void easycommResponseDownlinkRadioNumberSprintf(const EasycommResponseDownlinkRadioNumber *from, char *to);
    void easycommResponseUplinkRadioNumberSprintf(const EasycommResponseUplinkRadioNumber *from, char *to);
    void easycommResponseReadInputSprintf(const EasycommResponseReadInput *from, char *to);
    void easycommResponseReadAnalogueInputSprintf(const EasycommResponseReadAnalogueInput *from, char *to);
    void easycommResponseRequestVersionSprintf(const EasycommResponseRequestVersion *from, char *to);
    void easycommResponseAlarmSprintf(const EasycommResponseAlarm *from, char *to);
    void easycommResponseVelocityLeftSprintf(const EasycommResponseVelocityLeft *from, char *to);
    void easycommResponseVelocityRightSprintf(const EasycommResponseVelocityRight *from, char *to);
    void easycommResponseVelocityUpSprintf(const EasycommResponseVelocityUp *from, char *to);
    void easycommResponseVelocityDownSprintf(const EasycommResponseVelocityDown *from, char *to);
    void easycommResponseReadConfigSprintf(const EasycommResponseReadConfig *from, char *to);
    void easycommResponseWriteConfigSprintf(const EasycommResponseReadConfig *from, char *to);
    void easycommResponseGetStatusRegisterSprintf(const EasycommResponseGetStatusRegister *from, char *to);
    void easycommResponseGetErrorRegisterSprintf(const EasycommResponseGetErrorRegister *from, char *to);

#ifdef __cplusplus
}
#endif