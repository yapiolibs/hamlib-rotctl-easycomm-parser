#include "../easycomm-parser-types-ctors.h"
#include <stdio.h>
#include <string.h>


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
