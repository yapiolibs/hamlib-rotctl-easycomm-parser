#pragma once
#ifdef __cplusplus
extern "C"
{
#endif

#include "easycomm-parser-types.h"

    // ----- equals (equivalent to ==)

    bool easycommDataEquals(const EasycommData *a, const EasycommData *b);
    bool easycommPayloadEquals(const EasycommPayload *a, const EasycommPayload *b);
    bool easycommSingleLineEquals(const EasycommSingleLine *a, const EasycommSingleLine *b);
    bool easycommFrequencyEquals(const EasycommFrequency *a, const EasycommFrequency *b);
    bool easycommAzimuthEquals(const EasycommAzimuth *a, const EasycommAzimuth *b);
    bool easycommGetAzimuthEquals(const EasycommGetAzimuth *a, const EasycommGetAzimuth *b);
    bool easycommElevationEquals(const EasycommElevation *a, const EasycommElevation *b);
    bool easycommGetElevationEquals(const EasycommGetElevation *a, const EasycommGetElevation *b);
    bool easycommUplinkFrequencyEquals(const EasycommUplinkFrequency *a, const EasycommUplinkFrequency *b);
    bool easycommDownlinkFrequencyEquals(const EasycommDownlinkFrequency *a, const EasycommDownlinkFrequency *b);
    bool easycommUplinkModeEquals(const EasycommUplinkMode *a, const EasycommUplinkMode *b);
    bool easycommDownlinkModeEquals(const EasycommDownlinkMode *a, const EasycommDownlinkMode *b);
    bool easycommUplinkRadioNumberEquals(const EasycommUplinkRadioNumber *a, const EasycommUplinkRadioNumber *b);
    bool easycommDownlinkRadioNumberEquals(const EasycommDownlinkRadioNumber *a,
                                           const EasycommDownlinkRadioNumber *b);
    bool easycommMoveLeftEquals(const EasycommMoveLeft *a, const EasycommMoveLeft *b);
    bool easycommMoveRightEquals(const EasycommMoveRight *a, const EasycommMoveRight *b);
    bool easycommMoveUpEquals(const EasycommMoveUp *a, const EasycommMoveUp *b);
    bool easycommMoveDownEquals(const EasycommMoveDown *a, const EasycommMoveDown *b);
    bool easycommStopAzimuthMoveEquals(const EasycommStopAzimuthMove *a, const EasycommStopAzimuthMove *b);
    bool easycommStopElevationMoveEquals(const EasycommStopElevationMove *a, const EasycommStopElevationMove *b);
    bool easycommAcquisitionOfSignalEquals(const EasycommAcquisitionOfSignal *a,
                                           const EasycommAcquisitionOfSignal *b);
    bool easycommLossOfSignalEquals(const EasycommLossOfSignal *a, const EasycommLossOfSignal *b);
    bool easycommSetOutputEquals(const EasycommSetOutput *a, const EasycommSetOutput *b);
    bool easycommReadInputEquals(const EasycommReadInput *a, const EasycommReadInput *b);
    bool easycommReadAnalogueInputEquals(const EasycommReadAnalogueInput *a, const EasycommReadAnalogueInput *b);
    bool easycommSetTimeEquals(const EasycommSetTime *a, const EasycommSetTime *b);
    bool easycommRequestVersionEquals(const EasycommRequestVersion *a, const EasycommRequestVersion *b);
    bool easycommVelocityLeftEquals(const EasycommVelocityLeft *a, const EasycommVelocityLeft *b);
    bool easycommGetVelocityLeftEquals(const EasycommGetVelocityLeft *a, const EasycommGetVelocityLeft *b);
    bool easycommVelocityRightEquals(const EasycommVelocityRight *a, const EasycommVelocityRight *b);
    bool easycommGetVelocityRightEquals(const EasycommGetVelocityRight *a, const EasycommGetVelocityRight *b);
    bool easycommVelocityUpEquals(const EasycommVelocityUp *a, const EasycommVelocityUp *b);
    bool easycommGetVelocityUpEquals(const EasycommGetVelocityUp *a, const EasycommGetVelocityUp *b);
    bool easycommVelocityDownEquals(const EasycommVelocityDown *a, const EasycommVelocityDown *b);
    bool easycommGetVelocityDownEquals(const EasycommGetVelocityDown *a, const EasycommGetVelocityDown *b);
    bool easycommReadConfigEquals(const EasycommReadConfig *a, const EasycommReadConfig *b);
    bool easycommWriteConfigEquals(const EasycommWriteConfig *a, const EasycommWriteConfig *b);
    bool easycommGetStatusRegisterEquals(const EasycommGetStatusRegister *a, const EasycommGetStatusRegister *b);
    bool easycommGetErrorRegisterEquals(const EasycommGetErrorRegister *a, const EasycommGetErrorRegister *b);
    bool easycommResetEquals(const EasycommReset *a, const EasycommReset *b);
    bool easycommParkEquals(const EasycommPark *a, const EasycommPark *b);

    // ----- copy (equivalent to =, shallow copy)

    void easycommDataCopy(const EasycommData *from, EasycommData *to);
    void easycommPayloadCopy(const EasycommPayload *from, EasycommPayload *to);
    void easycommSingleLineCopy(const EasycommSingleLine *from, EasycommSingleLine *to);
    void easycommFrequencyCopy(const EasycommFrequency *from, EasycommFrequency *to);
    void easycommAzimuthCopy(const EasycommAzimuth *from, EasycommAzimuth *to);
    void easycommElevationCopy(const EasycommElevation *from, EasycommElevation *to);


#ifdef __cplusplus
}
#endif
