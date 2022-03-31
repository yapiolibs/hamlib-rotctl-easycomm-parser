#pragma once

#ifdef __cplusplus
extern "C"
{
#endif
/**
 * Easycomm 1, 2 and 3 references:
 * - description https://github.com/Hamlib/Hamlib/blob/master/rotators/easycomm/easycomm.txt
 * - implementation details https://github.com/Hamlib/Hamlib/blob/master/rotators/easycomm/easycomm.c
 */
#include <inttypes.h>
#include <stdbool.h>

#include "easycomm-parser-types.h"

    void easycommSingleLineSprintf(const EasycommSingleLine *from, char *to);
    void easycommAzimuthSprintf(const EasycommAzimuth *from, char *to);
    void easycommElevationSprintf(const EasycommElevation *from, char *to);
    void easycommAzimuthElevationSprintf(const EasycommAzimuthElevation *from, char *to);
    void easycommUplinkFrequencySprintf(const EasycommUplinkFrequency *from, char *to);
    void easycommDownlinkFrequencySprintf(const EasycommDownlinkFrequency *from, char *to);
    void easycommUplinkModeSprintf(const EasycommUplinkMode *from, char *to);
    void easycommDownlinkModeSprintf(const EasycommDownlinkMode *from, char *to);
    void easycommUplinkRadioNumberSprintf(const EasycommUplinkRadioNumber *from, char *to);
    void easycommDownlinkRadioNumberSprintf(const EasycommDownlinkRadioNumber *from, char *to);
    void easycommMoveLeftSprintf(const EasycommMoveLeft *from, char *to);
    void easycommMoveRightSprintf(const EasycommMoveRight *from, char *to);
    void easycommMoveUpSprintf(const EasycommMoveUp *from, char *to);
    void easycommMoveDownSprintf(const EasycommMoveDown *from, char *to);
    void easycommStopAzimuthMoveSprintf(const EasycommStopAzimuthMove *from, char *to);
    void easycommStopElevationMoveSprintf(const EasycommStopElevationMove *from, char *to);
    void easycommAcquisitionOfSignalSprintf(const EasycommAcquisitionOfSignal *from, char *to);
    void easycommLossOfSignalSprintf(const EasycommLossOfSignal *from, char *to);
    void easycommSetOutputSprintf(const EasycommSetOutput *from, char *to);
    void easycommReadInputSprintf(const EasycommReadInput *from, char *to);
    void easycommReadAnalogueInputSprintf(const EasycommReadAnalogueInput *from, char *to);
    void easycommSetTimeSprintf(const EasycommSetTime *from, char *to);
    void easycommRequestVersionSprintf(const EasycommRequestVersion *from, char *to);
    void easycommVelocityLeftSprintf(const EasycommVelocityLeft *from, char *to);
    void easycommVelocityRightSprintf(const EasycommVelocityRight *from, char *to);
    void easycommVelocityUpSprintf(const EasycommVelocityUp *from, char *to);
    void easycommVelocityDownSprintf(const EasycommVelocityDown *from, char *to);
    void easycommReadConfigSprintf(const EasycommReadConfig *from, char *to);
    void easycommWriteConfigSprintf(const EasycommWriteConfig *from, char *to);
    void easycommGetStatusRegisterSprintf(const EasycommGetStatusRegister *from, char *to);
    void easycommGetErrorRegisterSprintf(const EasycommGetErrorRegister *from, char *to);


#ifdef __cplusplus
}
#endif