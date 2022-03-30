#include "../easycomm-parser-types.h"
#include <stdio.h>
#include <string.h>


// ----- contructors


void easycommData(EasycommData *d)
{
    memset(d, 0, sizeof(EasycommData));
    d->commandId = EasycommInvalidId;
}


void easycommPayload(EasycommPayload *d)
{
    memset(d, 0, sizeof(EasycommPayload));
    d->commandId = EasycommInvalidId;
}


void easycommSingleLine(EasycommSingleLine *d)
{
    memset(d, 0, sizeof(EasycommSingleLine));
    d->commandId = EasycommSingleLineId;
}


void easycommFrequency(EasycommFrequency *d) { memset(d, 0, sizeof(EasycommFrequency)); }


void easycommAzimuth(EasycommAzimuth *d)
{
    memset(d, 0, sizeof(EasycommAzimuth));
    d->commandId = EasycommAzimuthId;
}


void easycommElevation(EasycommElevation *d)
{
    memset(d, 0, sizeof(EasycommElevation));
    d->commandId = EasycommElevationId;
}


void easycommAzimuthElevation(EasycommAzimuthElevation *d)
{
    memset(d, 0, sizeof(EasycommAzimuthElevation));
    d->commandId = EasycommAzimuthElevationId;
}


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
            a->uplink_frequency.as.uint32 == b->uplink_frequency.as.uint32 &&
            a->downlink_frequency.as.uint32 == b->downlink_frequency.as.uint32 &&
            a->mode_down[0] == b->mode_down[0] && a->mode_down[1] == b->mode_down[1] &&
            a->mode_down[2] == b->mode_down[2] && a->mode_up[0] == b->mode_up[0] &&
            a->mode_up[1] == b->mode_up[1] && a->mode_up[2] == b->mode_up[2]);
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


// ----- command to string conversions


void easycommSingleLineSprintf(const EasycommSingleLine *from, char *to)
{
    sprintf(to,
#ifdef ARDUINO_AVR_MEGA2560
            "AZ%05.1f EL%05.1f UP%09lu %c%c%c DN%09lu %c%c%c",
#else
            "AZ%05.1f EL%05.1f UP%09u %c%c%c DN%09u %c%c%c",
#endif
            from->azimuth, from->elevation, from->uplink_frequency.as.uint32, from->mode_up[0],
            from->mode_up[1], from->mode_up[2], from->downlink_frequency.as.uint32,
            from->mode_down[0], from->mode_down[1], from->mode_down[2]);
}


void easycommAzimuthSprintf(const EasycommAzimuth *from, char *to)
{
    sprintf(to, "AZ%05.1f", from->azimuth);
}


void easycommElevationSprintf(const EasycommElevation *from, char *to)
{
    sprintf(to, "EL%05.1f", from->elevation);
}


void easycommAzimuthElevationSprintf(const EasycommAzimuthElevation *from, char *to)
{
    sprintf(to, "AZ%05.1f EL%05.1f", from->azimuth, from->elevation);
}