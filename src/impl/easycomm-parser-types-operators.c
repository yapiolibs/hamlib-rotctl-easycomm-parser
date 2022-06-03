#include "../easycomm-parser-types-operators.h"
#include <stdio.h>
#include <string.h>


// ----- equals (equivalent to ==)


bool easycommDataEquals(const EasycommData *a, const EasycommData *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommData));
}


bool easycommPayloadEquals(const EasycommPayload *a, const EasycommPayload *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommPayload));
}


bool easycommSingleLineEquals(const EasycommSingleLine *a, const EasycommSingleLine *b)
{
    if(a == NULL && b == NULL)
        return false;

    const float margin = 0.1;
    return ((a != NULL && b != NULL) && (a->azimuth <= b->azimuth + margin && a->azimuth >= b->azimuth - margin) &&
            (a->elevation <= b->elevation + margin && a->elevation >= b->elevation - margin) &&
            a->uplinkFrequency.as.uint32 == b->uplinkFrequency.as.uint32 &&
            a->downlinkFrequency.as.uint32 == b->downlinkFrequency.as.uint32 &&
            a->modeDown[0] == b->modeDown[0] && a->modeDown[1] == b->modeDown[1] &&
            a->modeDown[2] == b->modeDown[2] && a->modeUp[0] == b->modeUp[0] &&
            a->modeUp[1] == b->modeUp[1] && a->modeUp[2] == b->modeUp[2]);
}


bool easycommFrequencyEquals(const EasycommFrequency *a, const EasycommFrequency *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommFrequency));
}


bool easycommSetAzimuthEquals(const EasycommSetAzimuth *a, const EasycommSetAzimuth *b)
{
    if(a == NULL && b == NULL)
        return false;

    const float margin = 0.1;
    return (a != NULL && b != NULL) && (a->azimuth <= b->azimuth + margin && a->azimuth >= b->azimuth - margin);
}


bool easycommGetAzimuthEquals(const EasycommGetAzimuth *a, const EasycommGetAzimuth *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommGetAzimuth));
}


bool easycommSetElevationEquals(const EasycommSetElevation *a, const EasycommSetElevation *b)
{
    if(a == NULL && b == NULL)
        return false;

    const float margin = 0.1;
    return (a != NULL && b != NULL) &&
           (a->elevation <= b->elevation + margin && a->elevation >= b->elevation - margin);
}


bool easycommGetElevationEquals(const EasycommGetElevation *a, const EasycommGetElevation *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommGetElevation));
}


bool easycommSetUplinkFrequencyEquals(const EasycommSetUplinkFrequency *a, const EasycommSetUplinkFrequency *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommSetUplinkFrequency));
}


bool easycommSetDownlinkFrequencyEquals(const EasycommSetDownlinkFrequency *a,
                                        const EasycommSetDownlinkFrequency *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommSetDownlinkFrequency));
}


bool easycommSetUplinkModeEquals(const EasycommSetUplinkMode *a, const EasycommSetUplinkMode *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommSetUplinkMode));
}


bool easycommSetDownlinkModeEquals(const EasycommSetDownlinkMode *a, const EasycommSetDownlinkMode *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommSetDownlinkMode));
}


bool easycommSetUplinkRadioNumberEquals(const EasycommSetUplinkRadioNumber *a,
                                        const EasycommSetUplinkRadioNumber *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommSetUplinkRadioNumber));
}


bool easycommSetDownlinkRadioNumberEquals(const EasycommSetDownlinkRadioNumber *a,
                                          const EasycommSetDownlinkRadioNumber *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommSetDownlinkRadioNumber));
}


bool easycommDoMoveLeftEquals(const EasycommDoMoveLeft *a, const EasycommDoMoveLeft *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommDoMoveLeft));
}


bool easycommDoMoveRightEquals(const EasycommDoMoveRight *a, const EasycommDoMoveRight *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommDoMoveLeft));
}


bool easycommDoMoveUpEquals(const EasycommDoMoveUp *a, const EasycommDoMoveUp *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommDoMoveUp));
}


bool easycommDoMoveDownEquals(const EasycommDoMoveDown *a, const EasycommDoMoveDown *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommDoMoveDown));
}


bool easycommDoStopAzimuthMoveEquals(const EasycommDoStopAzimuthMove *a, const EasycommDoStopAzimuthMove *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommDoStopAzimuthMove));
}


bool easycommDoStopElevationMoveEquals(const EasycommDoStopElevationMove *a, const EasycommDoStopElevationMove *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommDoStopElevationMove));
}


bool easycommAcquisitionOfSignalEquals(const EasycommAcquisitionOfSignal *a, const EasycommAcquisitionOfSignal *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommAcquisitionOfSignal));
}


bool easycommLossOfSignalEquals(const EasycommLossOfSignal *a, const EasycommLossOfSignal *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommLossOfSignal));
}


bool easycommSetDigitalOutputEquals(const EasycommSetDigitalOutput *a, const EasycommSetDigitalOutput *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommSetDigitalOutput));
}


bool easycommGetDigitalInputEquals(const EasycommGetDigitalInput *a, const EasycommGetDigitalInput *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommGetDigitalInput));
}


bool easycommGetAnalogueInputEquals(const EasycommGetAnalogueInput *a, const EasycommGetAnalogueInput *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommGetAnalogueInput));
}


bool easycommSetTimeEquals(const EasycommSetTime *a, const EasycommSetTime *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommSetTime));
}


bool easycommGetVersionEquals(const EasycommGetVersion *a, const EasycommGetVersion *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommGetVersion));
}


bool easycommSetVelocityLeftEquals(const EasycommSetVelocityLeft *a, const EasycommSetVelocityLeft *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommSetVelocityLeft));
}


bool easycommGetVelocityLeftEquals(const EasycommGetVelocityLeft *a, const EasycommGetVelocityLeft *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommGetVelocityLeft));
}


bool easycommSetVelocityRightEquals(const EasycommSetVelocityRight *a, const EasycommSetVelocityRight *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommSetVelocityRight));
}


bool easycommGetVelocityRightEquals(const EasycommGetVelocityRight *a, const EasycommGetVelocityRight *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommGetVelocityRight));
}


bool easycommSetVelocityUpEquals(const EasycommSetVelocityUp *a, const EasycommSetVelocityUp *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommSetVelocityUp));
}


bool easycommGetVelocityUpEquals(const EasycommGetVelocityUp *a, const EasycommGetVelocityUp *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommGetVelocityUp));
}


bool easycommSetVelocityDownEquals(const EasycommSetVelocityDown *a, const EasycommSetVelocityDown *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommSetVelocityDown));
}


bool easycommGetVelocityDownEquals(const EasycommGetVelocityDown *a, const EasycommGetVelocityDown *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommGetVelocityDown));
}


bool easycommGetConfigRegisterEquals(const EasycommGetConfigRegister *a, const EasycommGetConfigRegister *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommGetConfigRegister));
}


bool easycommSetConfigRegisterEquals(const EasycommSetConfigRegister *a, const EasycommSetConfigRegister *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommSetConfigRegister));
}


bool easycommGetStatusRegisterEquals(const EasycommGetStatusRegister *a, const EasycommGetStatusRegister *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommGetStatusRegister));
}


bool easycommGetErrorRegisterEquals(const EasycommGetErrorRegister *a, const EasycommGetErrorRegister *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommGetErrorRegister));
}


bool easycommDoResetEquals(const EasycommDoReset *a, const EasycommDoReset *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommDoReset));
}


bool easycommDoParkEquals(const EasycommDoPark *a, const EasycommDoPark *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommDoPark));
}


// ----- copy (equivalent to =, shallow copy)


void easycommDataCopy(const EasycommData *from, EasycommData *to)
{
    memcpy(to, from, sizeof(EasycommData));
}

void easycommPayloadCopy(const EasycommPayload *from, EasycommPayload *to)
{
    memcpy(to, from, sizeof(EasycommPayload));
}

void easycommSingleLineCopy(const EasycommSingleLine *from, EasycommSingleLine *to)
{
    memcpy(to, from, sizeof(EasycommSingleLine));
}


void easycommFrequencyCopy(const EasycommFrequency *from, EasycommFrequency *to)
{
    memcpy(to, from, sizeof(EasycommFrequency));
}


void easycommSetAzimuthCopy(const EasycommSetAzimuth *from, EasycommSetAzimuth *to)
{
    memcpy(to, from, sizeof(EasycommSetAzimuth));
}

void easycommSetElevationCopy(const EasycommSetElevation *from, EasycommSetElevation *to)
{
    memcpy(to, from, sizeof(EasycommSetElevation));
}
