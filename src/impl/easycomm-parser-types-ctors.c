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


void easycommSetAzimuth(EasycommSetAzimuth *d)
{
    memset(d, 0, sizeof(EasycommSetAzimuth));
    d->commandId = EasycommIdAzimuth;
}

void easycommGetAzimuth(EasycommGetAzimuth *d)
{
    memset(d, 0, sizeof(EasycommGetAzimuth));
    d->commandId = EasycommIdGetAzimuth;
}


void easycommSetElevation(EasycommSetElevation *d)
{
    memset(d, 0, sizeof(EasycommSetElevation));
    d->commandId = EasycommIdElevation;
}


void easycommGetElevation(EasycommGetElevation *d)
{
    memset(d, 0, sizeof(EasycommGetElevation));
    d->commandId = EasycommIdGetElevation;
}


void easycommSetUplinkFrequency(EasycommSetUplinkFrequency *d)
{
    memset(d, 0, sizeof(EasycommSetUplinkFrequency));
    d->commandId = EasycommIdUplinkFrequency;
}


void easycommSetDownlinkFrequency(EasycommSetDownlinkFrequency *d)
{
    memset(d, 0, sizeof(EasycommSetDownlinkFrequency));
    d->commandId = EasycommIdDownlinkFrequency;
}


void easycommSetUplinkMode(EasycommSetUplinkMode *d)
{
    memset(d, 0, sizeof(EasycommSetUplinkMode));
    d->commandId = EasycommIdUplinkMode;
}


void easycommSetDownlinkMode(EasycommSetDownlinkMode *d)
{
    memset(d, 0, sizeof(EasycommSetDownlinkMode));
    d->commandId = EasycommIdDownlinkMode;
}


void easycommSetUplinkRadioNumber(EasycommSetUplinkRadioNumber *d)
{
    memset(d, 0, sizeof(EasycommSetUplinkRadioNumber));
    d->commandId = EasycommIdUplinkRadioNumber;
}


void easycommSetDownlinkRadioNumber(EasycommSetDownlinkRadioNumber *d)
{
    memset(d, 0, sizeof(EasycommSetDownlinkRadioNumber));
    d->commandId = EasycommIdDownlinkRadioNumber;
}


void easycommDoMoveLeft(EasycommDoMoveLeft *d)
{
    memset(d, 0, sizeof(EasycommDoMoveLeft));
    d->commandId = EasycommIdMoveLeft;
}


void easycommDoMoveRight(EasycommDoMoveRight *d)
{
    memset(d, 0, sizeof(EasycommDoMoveRight));
    d->commandId = EasycommIdMoveRight;
}


void easycommDoMoveUp(EasycommDoMoveUp *d)
{
    memset(d, 0, sizeof(EasycommDoMoveUp));
    d->commandId = EasycommIdMoveUp;
}


void easycommDoMoveDown(EasycommDoMoveDown *d)
{
    memset(d, 0, sizeof(EasycommDoMoveDown));
    d->commandId = EasycommIdMoveDown;
}


void easycommDoStopAzimuthMove(EasycommDoStopAzimuthMove *d)
{
    memset(d, 0, sizeof(EasycommDoStopAzimuthMove));
    d->commandId = EasycommIdStopAzimuthMove;
}


void easycommDoStopElevationMove(EasycommDoStopElevationMove *d)
{
    memset(d, 0, sizeof(EasycommDoStopElevationMove));
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


void easycommSetDigitalOutput(EasycommSetDigitalOutput *d)
{
    memset(d, 0, sizeof(EasycommSetDigitalOutput));
    d->commandId = EasycommIdSetOutput;
}


void easycommGetDigitalInput(EasycommGetDigitalInput *d)
{
    memset(d, 0, sizeof(EasycommGetDigitalInput));
    d->commandId = EasycommIdReadInput;
}


void easycommGetAnalogueInput(EasycommGetAnalogueInput *d)
{
    memset(d, 0, sizeof(EasycommGetAnalogueInput));
    d->commandId = EasycommIdReadAnalogueInput;
}


void easycommSetTime(EasycommSetTime *d)
{
    memset(d, 0, sizeof(EasycommSetTime));
    d->commandId = EasycommIdSetTime;
}


void easycommGetVersion(EasycommGetVersion *d)
{
    memset(d, 0, sizeof(EasycommGetVersion));
    d->commandId = EasycommIdRequestVersion;
}


void easycommSetVelocityLeft(EasycommSetVelocityLeft *d)
{
    memset(d, 0, sizeof(EasycommSetVelocityLeft));
    d->commandId = EasycommIdVelocityLeft;
}

void easycommGetVelocityLeft(EasycommGetVelocityLeft *d)
{
    memset(d, 0, sizeof(EasycommGetVelocityLeft));
    d->commandId = EasycommIdGetVelocityLeft;
}


void easycommSetVelocityRight(EasycommSetVelocityRight *d)
{
    memset(d, 0, sizeof(EasycommSetVelocityRight));
    d->commandId = EasycommIdVelocityRight;
}


void easycommGetVelocityRight(EasycommGetVelocityRight *d)
{
    memset(d, 0, sizeof(EasycommGetVelocityRight));
    d->commandId = EasycommIdGetVelocityRight;
}


void easycommSetVelocityUp(EasycommSetVelocityUp *d)
{
    memset(d, 0, sizeof(EasycommSetVelocityUp));
    d->commandId = EasycommIdVelocityUp;
}


void easycommGetVelocityUp(EasycommGetVelocityUp *d)
{
    memset(d, 0, sizeof(EasycommGetVelocityUp));
    d->commandId = EasycommIdGetVelocityUp;
}


void easycommSetVelocityDown(EasycommSetVelocityDown *d)
{
    memset(d, 0, sizeof(EasycommSetVelocityDown));
    d->commandId = EasycommIdVelocityDown;
}


void easycommGetVelocityDown(EasycommGetVelocityDown *d)
{
    memset(d, 0, sizeof(EasycommGetVelocityDown));
    d->commandId = EasycommIdGetVelocityDown;
}


void easycommGetConfigRegister(EasycommGetConfigRegister *d)
{
    memset(d, 0, sizeof(EasycommGetConfigRegister));
    d->commandId = EasycommIdReadConfig;
}


void easycommSetConfigRegister(EasycommSetConfigRegister *d)
{
    memset(d, 0, sizeof(EasycommSetConfigRegister));
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


void easycommDoReset(EasycommDoReset *d)
{
    memset(d, 0, sizeof(EasycommDoReset));
    d->commandId = EasycommIdReset;
}


void easycommDoPark(EasycommDoPark *d)
{
    memset(d, 0, sizeof(EasycommDoPark));
    d->commandId = EasycommIdPark;
}
