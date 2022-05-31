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
    bool easycommSetAzimuthEquals(const EasycommSetAzimuth *a, const EasycommSetAzimuth *b);
    bool easycommGetAzimuthEquals(const EasycommGetAzimuth *a, const EasycommGetAzimuth *b);
    bool easycommSetElevationEquals(const EasycommSetElevation *a, const EasycommSetElevation *b);
    bool easycommGetElevationEquals(const EasycommGetElevation *a, const EasycommGetElevation *b);
    bool easycommSetUplinkFrequencyEquals(const EasycommSetUplinkFrequency *a,
                                          const EasycommSetUplinkFrequency *b);
    bool easycommSetDownlinkFrequencyEquals(const EasycommSetDownlinkFrequency *a,
                                            const EasycommSetDownlinkFrequency *b);
    bool easycommSetUplinkModeEquals(const EasycommSetUplinkMode *a, const EasycommSetUplinkMode *b);
    bool easycommSetDownlinkModeEquals(const EasycommSetDownlinkMode *a, const EasycommSetDownlinkMode *b);
    bool easycommSetUplinkRadioNumberEquals(const EasycommSetUplinkRadioNumber *a,
                                            const EasycommSetUplinkRadioNumber *b);
    bool easycommSetDownlinkRadioNumberEquals(const EasycommSetDownlinkRadioNumber *a,
                                              const EasycommSetDownlinkRadioNumber *b);
    bool easycommDoMoveLeftEquals(const EasycommDoMoveLeft *a, const EasycommDoMoveLeft *b);
    bool easycommDoMoveRightEquals(const EasycommDoMoveRight *a, const EasycommDoMoveRight *b);
    bool easycommDoMoveUpEquals(const EasycommDoMoveUp *a, const EasycommDoMoveUp *b);
    bool easycommDoMoveDownEquals(const EasycommDoMoveDown *a, const EasycommDoMoveDown *b);
    bool easycommDoStopAzimuthMoveEquals(const EasycommDoStopAzimuthMove *a, const EasycommDoStopAzimuthMove *b);
    bool easycommDoStopElevationMoveEquals(const EasycommDoStopElevationMove *a,
                                           const EasycommDoStopElevationMove *b);
    bool easycommAcquisitionOfSignalEquals(const EasycommAcquisitionOfSignal *a,
                                           const EasycommAcquisitionOfSignal *b);
    bool easycommLossOfSignalEquals(const EasycommLossOfSignal *a, const EasycommLossOfSignal *b);
    bool easycommSetDigitalOutputEquals(const EasycommSetDigitalOutput *a, const EasycommSetDigitalOutput *b);
    bool easycommGetDigitalInputEquals(const EasycommGetDigitalInput *a, const EasycommGetDigitalInput *b);
    bool easycommGetAnalogueInputEquals(const EasycommGetAnalogueInput *a, const EasycommGetAnalogueInput *b);
    bool easycommSetTimeEquals(const EasycommSetTime *a, const EasycommSetTime *b);
    bool easycommGetVersionEquals(const EasycommGetVersion *a, const EasycommGetVersion *b);
    bool easycommSetVelocityLeftEquals(const EasycommSetVelocityLeft *a, const EasycommSetVelocityLeft *b);
    bool easycommGetVelocityLeftEquals(const EasycommGetVelocityLeft *a, const EasycommGetVelocityLeft *b);
    bool easycommSetVelocityRightEquals(const EasycommSetVelocityRight *a, const EasycommSetVelocityRight *b);
    bool easycommGetVelocityRightEquals(const EasycommGetVelocityRight *a, const EasycommGetVelocityRight *b);
    bool easycommSetVelocityUpEquals(const EasycommSetVelocityUp *a, const EasycommSetVelocityUp *b);
    bool easycommGetVelocityUpEquals(const EasycommGetVelocityUp *a, const EasycommGetVelocityUp *b);
    bool easycommSetVelocityDownEquals(const EasycommSetVelocityDown *a, const EasycommSetVelocityDown *b);
    bool easycommGetVelocityDownEquals(const EasycommGetVelocityDown *a, const EasycommGetVelocityDown *b);
    bool easycommGetConfigRegisterEquals(const EasycommGetConfigRegister *a, const EasycommGetConfigRegister *b);
    bool easycommSetConfigRegisterEquals(const EasycommSetConfigRegister *a, const EasycommSetConfigRegister *b);
    bool easycommGetStatusRegisterEquals(const EasycommGetStatusRegister *a, const EasycommGetStatusRegister *b);
    bool easycommGetErrorRegisterEquals(const EasycommGetErrorRegister *a, const EasycommGetErrorRegister *b);
    bool easycommDoResetEquals(const EasycommDoReset *a, const EasycommDoReset *b);
    bool easycommDoParkEquals(const EasycommDoPark *a, const EasycommDoPark *b);

    // ----- copy (equivalent to =, shallow copy)

    void easycommDataCopy(const EasycommData *from, EasycommData *to);
    void easycommPayloadCopy(const EasycommPayload *from, EasycommPayload *to);
    void easycommSingleLineCopy(const EasycommSingleLine *from, EasycommSingleLine *to);
    void easycommFrequencyCopy(const EasycommFrequency *from, EasycommFrequency *to);
    void easycommSetAzimuthCopy(const EasycommSetAzimuth *from, EasycommSetAzimuth *to);
    void easycommSetElevationCopy(const EasycommSetElevation *from, EasycommSetElevation *to);


#ifdef __cplusplus
}
#endif
