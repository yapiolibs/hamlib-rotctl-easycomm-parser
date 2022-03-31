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


bool easycommAzimuthEquals(const EasycommAzimuth *a, const EasycommAzimuth *b)
{
    if(a == NULL && b == NULL)
        return false;

    const float margin = 0.1;
    return (a != NULL && b != NULL) && (a->azimuth <= b->azimuth + margin && a->azimuth >= b->azimuth - margin);
}


bool easycommElevationEquals(const EasycommElevation *a, const EasycommElevation *b)
{
    if(a == NULL && b == NULL)
        return false;

    const float margin = 0.1;
    return (a != NULL && b != NULL) &&
           (a->elevation <= b->elevation + margin && a->elevation >= b->elevation - margin);
}


bool easycommAzimuthElevationEquals(const EasycommAzimuthElevation *a, const EasycommAzimuthElevation *b)
{
    if(a == NULL && b == NULL)
        return false;

    const float margin = 0.1;
    return (a != NULL && b != NULL) &&
           (a->azimuth <= b->azimuth + margin && a->azimuth >= b->azimuth - margin) &&
           (a->elevation <= b->elevation + margin && a->elevation >= b->elevation - margin);
}


bool easycommUplinkFrequencyEquals(const EasycommUplinkFrequency *a, const EasycommUplinkFrequency *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommUplinkFrequency));
}


bool easycommDownlinkFrequencyEquals(const EasycommDownlinkFrequency *a, const EasycommDownlinkFrequency *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommDownlinkFrequency));
}


bool easycommUplinkModeEquals(const EasycommUplinkMode *a, const EasycommUplinkMode *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommUplinkMode));
}


bool easycommDownlinkModeEquals(const EasycommDownlinkMode *a, const EasycommDownlinkMode *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommDownlinkMode));
}


bool easycommUplinkRadioNumberEquals(const EasycommUplinkRadioNumber *a, const EasycommUplinkRadioNumber *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommUplinkRadioNumber));
}


bool easycommDownlinkRadioNumberEquals(const EasycommDownlinkRadioNumber *a, const EasycommDownlinkRadioNumber *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommDownlinkRadioNumber));
}


bool easycommMoveLeftEquals(const EasycommMoveLeft *a, const EasycommMoveLeft *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommMoveLeft));
}


bool easycommMoveRightEquals(const EasycommMoveRight *a, const EasycommMoveRight *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommMoveLeft));
}


bool easycommMoveUpEquals(const EasycommMoveUp *a, const EasycommMoveUp *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommMoveUp));
}


bool easycommMoveDownEquals(const EasycommMoveDown *a, const EasycommMoveDown *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommMoveDown));
}


bool easycommStopAzimuthMoveEquals(const EasycommStopAzimuthMove *a, const EasycommStopAzimuthMove *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommStopAzimuthMove));
}


bool easycommStopElevationMoveEquals(const EasycommStopElevationMove *a, const EasycommStopElevationMove *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommStopElevationMove));
}


bool easycommAcquisitionOfSignalEquals(const EasycommAcquisitionOfSignal *a, const EasycommAcquisitionOfSignal *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommAcquisitionOfSignal));
}


bool easycommLossOfSignalEquals(const EasycommLossOfSignal *a, const EasycommLossOfSignal *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommLossOfSignal));
}


bool easycommSetOutputEquals(const EasycommSetOutput *a, const EasycommSetOutput *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommSetOutput));
}


bool easycommReadInputEquals(const EasycommReadInput *a, const EasycommReadInput *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommReadInput));
}


bool easycommReadAnalogueInputEquals(const EasycommReadAnalogueInput *a, const EasycommReadAnalogueInput *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommReadAnalogueInput));
}


bool easycommSetTimeEquals(const EasycommSetTime *a, const EasycommSetTime *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommSetTime));
}


bool easycommRequestVersionEquals(const EasycommRequestVersion *a, const EasycommRequestVersion *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommRequestVersion));
}


bool easycommVelocityLeftEquals(const EasycommVelocityLeft *a, const EasycommVelocityLeft *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommVelocityLeft));
}


bool easycommVelocityRightEquals(const EasycommVelocityRight *a, const EasycommVelocityRight *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommVelocityRight));
}


bool easycommVelocityUpEquals(const EasycommVelocityUp *a, const EasycommVelocityUp *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommVelocityUp));
}


bool easycommVelocityDownEquals(const EasycommVelocityDown *a, const EasycommVelocityDown *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommVelocityDown));
}


bool easycommReadConfigEquals(const EasycommReadConfig *a, const EasycommReadConfig *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommReadConfig));
}


bool easycommWriteConfigEquals(const EasycommWriteConfig *a, const EasycommWriteConfig *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommWriteConfig));
}


bool easycommGetStatusRegisterEquals(const EasycommGetStatusRegister *a, const EasycommGetStatusRegister *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommGetStatusRegister));
}


bool easycommGetErrorRegisterEquals(const EasycommGetErrorRegister *a, const EasycommGetErrorRegister *b)
{
    return 0 == memcmp(a, b, sizeof(EasycommGetErrorRegister));
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


void easycommAzimuthCopy(const EasycommAzimuth *from, EasycommAzimuth *to)
{
    memcpy(to, from, sizeof(EasycommAzimuth));
}

void easycommElevationCopy(const EasycommElevation *from, EasycommElevation *to)
{
    memcpy(to, from, sizeof(EasycommElevation));
}


void easycommAzimuthElevationCopy(const EasycommAzimuthElevation *from, EasycommAzimuthElevation *to)
{
    memcpy(to, from, sizeof(EasycommAzimuthElevation));
}
