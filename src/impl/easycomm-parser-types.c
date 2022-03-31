#include "../easycomm-parser-types.h"
#include <stdio.h>
#include <string.h>


// ----- contructors


void easycommData(EasycommData *d)
{
    memset(d, 0, sizeof(EasycommData));
    d->commandId = EasycommIdInvalid;
}


void easycommPayload(EasycommPayload *d)
{
    memset(d, 0, sizeof(EasycommPayload));
    d->commandId = EasycommIdInvalid;
}


void easycommSingleLine(EasycommSingleLine *d)
{
    memset(d, 0, sizeof(EasycommSingleLine));
    d->commandId = EasycommIdSingleLine;
}


void easycommFrequency(EasycommFrequency *d) { memset(d, 0, sizeof(EasycommFrequency)); }


void easycommAzimuth(EasycommAzimuth *d)
{
    memset(d, 0, sizeof(EasycommAzimuth));
    d->commandId = EasycommIdAzimuth;
}


void easycommElevation(EasycommElevation *d)
{
    memset(d, 0, sizeof(EasycommElevation));
    d->commandId = EasycommIdElevation;
}


void easycommAzimuthElevation(EasycommAzimuthElevation *d)
{
    memset(d, 0, sizeof(EasycommAzimuthElevation));
    d->commandId = EasycommIdAzimuthElevation;
}


void easycommUplinkFrequency(EasycommUplinkFrequency *d)
{
    memset(d, 0, sizeof(EasycommUplinkFrequency));
    d->commandId = EasycommIdUplinkFrequency;
}


void easycommDownlinkFrequency(EasycommDownlinkFrequency *d)
{
    memset(d, 0, sizeof(EasycommDownlinkFrequency));
    d->commandId = EasycommIdDownlinkFrequency;
}


void easycommUplinkMode(EasycommUplinkMode *d)
{
    memset(d, 0, sizeof(EasycommUplinkMode));
    d->commandId = EasycommIdUplinkMode;
}


void easycommDownlinkMode(EasycommDownlinkMode *d)
{
    memset(d, 0, sizeof(EasycommDownlinkMode));
    d->commandId = EasycommIdDownlinkMode;
}


void easycommUplinkRadioNumber(EasycommUplinkRadioNumber *d)
{
    memset(d, 0, sizeof(EasycommUplinkRadioNumber));
    d->commandId = EasycommIdUplinkRadioNumber;
}


void easycommDownlinkRadioNumber(EasycommDownlinkRadioNumber *d)
{
    memset(d, 0, sizeof(EasycommDownlinkRadioNumber));
    d->commandId = EasycommIdDownlinkRadioNumber;
}


void easycommMoveLeft(EasycommMoveLeft *d)
{
    memset(d, 0, sizeof(EasycommMoveLeft));
    d->commandId = EasycommIdMoveLeft;
}


void easycommMoveRight(EasycommMoveRight *d)
{
    memset(d, 0, sizeof(EasycommMoveRight));
    d->commandId = EasycommIdMoveRight;
}


void easycommMoveUp(EasycommMoveUp *d)
{
    memset(d, 0, sizeof(EasycommMoveUp));
    d->commandId = EasycommIdMoveUp;
}


void easycommMoveDown(EasycommMoveDown *d)
{
    memset(d, 0, sizeof(EasycommMoveDown));
    d->commandId = EasycommIdMoveDown;
}


void easycommStopAzimuthMove(EasycommStopAzimuthMove *d)
{
    memset(d, 0, sizeof(EasycommStopAzimuthMove));
    d->commandId = EasycommIdStopAzimuthMove;
}


void easycommStopElevationMove(EasycommStopElevationMove *d)
{
    memset(d, 0, sizeof(EasycommStopElevationMove));
    d->commandId = EasycommIdStopElevationMove;
}


void easycommAcquisitionOfSignal(EasycommAcquisitionOfSignal *d)
{
    memset(d, 0, sizeof(EasycommAcquisitionOfSignal));
    d->commandId = EasycommIdAcquisitionOfSignal;
}


void easycommLossOfSignal(EasycommLossOfSignal *d)
{
    memset(d, 0, sizeof(EasycommLossOfSignal));
    d->commandId = EasycommIdLossOfSignal;
}


void easycommSetOutput(EasycommSetOutput *d)
{
    memset(d, 0, sizeof(EasycommSetOutput));
    d->commandId = EasycommIdSetOutput;
}


void easycommReadInput(EasycommReadInput *d)
{
    memset(d, 0, sizeof(EasycommReadInput));
    d->commandId = EasycommIdReadInput;
}


void easycommReadAnalogueInput(EasycommReadAnalogueInput *d)
{
    memset(d, 0, sizeof(EasycommReadAnalogueInput));
    d->commandId = EasycommIdReadAnalogueInput;
}


void easycommSetTime(EasycommSetTime *d)
{
    memset(d, 0, sizeof(EasycommSetTime));
    d->commandId = EasycommIdSetTime;
}


void easycommRequestVersion(EasycommRequestVersion *d)
{
    memset(d, 0, sizeof(EasycommRequestVersion));
    d->commandId = EasycommIdRequestVersion;
}


void easycommVelocityLeft(EasycommVelocityLeft *d)
{
    memset(d, 0, sizeof(EasycommVelocityLeft));
    d->commandId = EasycommIdVelocityLeft;
}


void easycommVelocityRight(EasycommVelocityRight *d)
{
    memset(d, 0, sizeof(EasycommVelocityRight));
    d->commandId = EasycommIdVelocityRight;
}


void easycommVelocityUp(EasycommVelocityUp *d)
{
    memset(d, 0, sizeof(EasycommVelocityUp));
    d->commandId = EasycommIdVelocityUp;
}


void easycommVelocityDown(EasycommVelocityDown *d)
{
    memset(d, 0, sizeof(EasycommVelocityDown));
    d->commandId = EasycommIdVelocityDown;
}


void easycommReadConfig(EasycommReadConfig *d)
{
    memset(d, 0, sizeof(EasycommReadConfig));
    d->commandId = EasycommIdReadConfig;
}


void easycommWriteConfig(EasycommWriteConfig *d)
{
    memset(d, 0, sizeof(EasycommWriteConfig));
    d->commandId = EasycommIdWriteConfig;
}


void easycommGetStatusRegister(EasycommGetStatusRegister *d)
{
    memset(d, 0, sizeof(EasycommGetStatusRegister));
    d->commandId = EasycommIdGetStatusRegister;
}


void easycommGetErrorRegister(EasycommGetErrorRegister *d)
{
    memset(d, 0, sizeof(EasycommGetErrorRegister));
    d->commandId = EasycommIdGetErrorRegister;
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


// ----- command to string conversions


void easycommSingleLineSprintf(const EasycommSingleLine *from, char *to)
{
    sprintf(to,
#ifdef ARDUINO_AVR_MEGA2560
            "AZ%05.1f EL%05.1f UP%09lu %c%c%c DN%09lu %c%c%c",
#else
            "AZ%05.1f EL%05.1f UP%09u %c%c%c DN%09u %c%c%c",
#endif
            from->azimuth, from->elevation, from->uplinkFrequency.as.uint32, from->modeUp[0],
            from->modeUp[1], from->modeUp[2], from->downlinkFrequency.as.uint32, from->modeDown[0],
            from->modeDown[1], from->modeDown[2]);
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

void easycommUplinkFrequencySprintf(const EasycommUplinkFrequency *from, char *to)
{
#ifdef ARDUINO_AVR_MEGA2560
    sprintf(to, "UP%09ld", from->frequency.as.uint32);
#else
    sprintf(to, "UP%09d", from->frequency.as.uint32);
#endif
}


void easycommDownlinkFrequencySprintf(const EasycommDownlinkFrequency *from, char *to)
{
#ifdef ARDUINO_AVR_MEGA2560
    sprintf(to, "DN%09ld", from->frequency.as.uint32);
#else
    sprintf(to, "DN%09d", from->frequency.as.uint32);
#endif
}


void easycommUplinkModeSprintf(const EasycommUplinkMode *from, char *to)
{
    sprintf(to, "UM%c%c%c", from->mode[0], from->mode[1], from->mode[2]);
}


void easycommDownlinkModeSprintf(const EasycommDownlinkMode *from, char *to)
{
    sprintf(to, "DM%c%c%c", from->mode[0], from->mode[1], from->mode[2]);
}


void easycommUplinkRadioNumberSprintf(const EasycommUplinkRadioNumber *from, char *to)
{
    sprintf(to, "UR%03d", from->number);
}


void easycommDownlinkRadioNumberSprintf(const EasycommDownlinkRadioNumber *from, char *to)
{
    sprintf(to, "DR%03d", from->number);
}


void easycommMoveLeftSprintf(const EasycommMoveLeft *from, char *to) { sprintf(to, "ML"); }


void easycommMoveRightSprintf(const EasycommMoveRight *from, char *to) { sprintf(to, "MR"); }


void easycommMoveUpSprintf(const EasycommMoveUp *from, char *to) { sprintf(to, "MU"); }


void easycommMoveDownSprintf(const EasycommMoveDown *from, char *to) { sprintf(to, "MD"); }


void easycommStopAzimuthMoveSprintf(const EasycommStopAzimuthMove *from, char *to)
{
    sprintf(to, "SA");
}


void easycommStopElevationMoveSprintf(const EasycommStopElevationMove *from, char *to)
{
    sprintf(to, "SE");
}


void easycommAcquisitionOfSignalSprintf(const EasycommAcquisitionOfSignal *from, char *to)
{
    sprintf(to, "AOS");
}


void easycommLossOfSignalSprintf(const EasycommLossOfSignal *from, char *to) { sprintf(to, "LOS"); }


void easycommSetOutputSprintf(const EasycommSetOutput *from, char *to)
{
    sprintf(to, "OP%03d", from->number);
}


void easycommReadInputSprintf(const EasycommReadInput *from, char *to)
{
    sprintf(to, "IP%03d", from->number);
}


void easycommReadAnalogueInputSprintf(const EasycommReadAnalogueInput *from, char *to)
{
    sprintf(to, "AN%03d", from->number);
}


void easycommSetTimeSprintf(const EasycommSetTime *from, char *to)
{
    sprintf(to, "ST%02d:%02d:%02d:%02d:%02d:%02d", from->year, from->month, from->day, from->hour,
            from->minute, from->second);
}


void easycommRequestVersionSprintf(const EasycommRequestVersion *from, char *to)
{
    sprintf(to, "VE");
}


void easycommVelocityLeftSprintf(const EasycommVelocityLeft *from, char *to)
{
    sprintf(to, "VL%09d", from->milliDegSecond);
}


void easycommVelocityRightSprintf(const EasycommVelocityRight *from, char *to)
{
    sprintf(to, "VR%09d", from->milliDegSecond);
}


void easycommVelocityUpSprintf(const EasycommVelocityUp *from, char *to)
{
    sprintf(to, "VU%09d", from->milliDegSecond);
}


void easycommVelocityDownSprintf(const EasycommVelocityDown *from, char *to)
{
    sprintf(to, "VD%09d", from->milliDegSecond);
}


void easycommReadConfigSprintf(const EasycommReadConfig *from, char *to)
{
    sprintf(to, "CR%03d", from->registerNumber);
}


void easycommWriteConfigSprintf(const EasycommWriteConfig *from, char *to)
{
    sprintf(to, "CW%03d", from->registerNumber);
}


void easycommGetStatusRegisterSprintf(const EasycommGetStatusRegister *from, char *to)
{
    sprintf(to, "GS");
}


void easycommGetErrorRegisterSprintf(const EasycommGetErrorRegister *from, char *to)
{
    sprintf(to, "GE");
}
