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
    d->commandId = EasycommIdSetAzimuth;
}

void easycommGetAzimuth(EasycommGetAzimuth *d)
{
    memset(d, 0, sizeof(EasycommGetAzimuth));
    d->commandId = EasycommIdGetAzimuth;
}


void easycommSetElevation(EasycommSetElevation *d)
{
    memset(d, 0, sizeof(EasycommSetElevation));
    d->commandId = EasycommIdSetElevation;
}


void easycommGetElevation(EasycommGetElevation *d)
{
    memset(d, 0, sizeof(EasycommGetElevation));
    d->commandId = EasycommIdGetElevation;
}


void easycommSetUplinkFrequency(EasycommSetUplinkFrequency *d)
{
    memset(d, 0, sizeof(EasycommSetUplinkFrequency));
    d->commandId = EasycommIdSetUplinkFrequency;
}


void easycommGetUplinkFrequency(EasycommGetUplinkFrequency *d)
{
    memset(d, 0, sizeof(EasycommGetUplinkFrequency));
    d->commandId = EasycommIdGetUplinkFrequency;
}


void easycommSetDownlinkFrequency(EasycommSetDownlinkFrequency *d)
{
    memset(d, 0, sizeof(EasycommSetDownlinkFrequency));
    d->commandId = EasycommIdSetDownlinkFrequency;
}


void easycommGetDownlinkFrequency(EasycommGetDownlinkFrequency *d)
{
    memset(d, 0, sizeof(EasycommGetDownlinkFrequency));
    d->commandId = EasycommIdGetDownlinkFrequency;
}


void easycommSetUplinkMode(EasycommSetUplinkMode *d)
{
    memset(d, 0, sizeof(EasycommSetUplinkMode));
    d->commandId = EasycommIdSetUplinkMode;
}


void easycommGetUplinkMode(EasycommGetUplinkMode *d)
{
    memset(d, 0, sizeof(EasycommGetUplinkMode));
    d->commandId = EasycommIdGetUplinkMode;
}


void easycommSetDownlinkMode(EasycommSetDownlinkMode *d)
{
    memset(d, 0, sizeof(EasycommSetDownlinkMode));
    d->commandId = EasycommIdSetDownlinkMode;
}


void easycommGetDownlinkMode(EasycommGetDownlinkMode *d)
{
    memset(d, 0, sizeof(EasycommGetDownlinkMode));
    d->commandId = EasycommIdGetDownlinkMode;
}


void easycommSetUplinkRadio(EasycommSetUplinkRadio *d)
{
    memset(d, 0, sizeof(EasycommSetUplinkRadio));
    d->commandId = EasycommIdSetUplinkRadio;
}


void easycommGetUplinkRadio(EasycommGetUplinkRadio *d)
{
    memset(d, 0, sizeof(EasycommGetUplinkRadio));
    d->commandId = EasycommIdGetUplinkRadio;
}


void easycommSetDownlinkRadio(EasycommSetDownlinkRadio *d)
{
    memset(d, 0, sizeof(EasycommSetDownlinkRadio));
    d->commandId = EasycommIdSetDownlinkRadio;
}


void easycommGetDownlinkRadio(EasycommGetDownlinkRadio *d)
{
    memset(d, 0, sizeof(EasycommGetDownlinkRadio));
    d->commandId = EasycommIdGetDownlinkRadio;
}


void easycommDoMoveLeft(EasycommDoMoveLeft *d)
{
    memset(d, 0, sizeof(EasycommDoMoveLeft));
    d->commandId = EasycommIdDoMoveLeft;
}


void easycommDoMoveRight(EasycommDoMoveRight *d)
{
    memset(d, 0, sizeof(EasycommDoMoveRight));
    d->commandId = EasycommIdDoMoveRight;
}


void easycommDoMoveUp(EasycommDoMoveUp *d)
{
    memset(d, 0, sizeof(EasycommDoMoveUp));
    d->commandId = EasycommIdDoMoveUp;
}


void easycommDoMoveDown(EasycommDoMoveDown *d)
{
    memset(d, 0, sizeof(EasycommDoMoveDown));
    d->commandId = EasycommIdDoMoveDown;
}


void easycommDoStopAzimuthMove(EasycommDoStopAzimuthMove *d)
{
    memset(d, 0, sizeof(EasycommDoStopAzimuthMove));
    d->commandId = EasycommIdDoStopAzimuthMove;
}


void easycommDoStopElevationMove(EasycommDoStopElevationMove *d)
{
    memset(d, 0, sizeof(EasycommDoStopElevationMove));
    d->commandId = EasycommIdDoStopElevationMove;
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
    d->commandId = EasycommIdSetDigitalOutput;
}


void easycommGetDigitalInput(EasycommGetDigitalInput *d)
{
    memset(d, 0, sizeof(EasycommGetDigitalInput));
    d->commandId = EasycommIdGetDigitalInput;
}


void easycommGetAnalogueInput(EasycommGetAnalogueInput *d)
{
    memset(d, 0, sizeof(EasycommGetAnalogueInput));
    d->commandId = EasycommIdGetAnalogueInput;
}


void easycommSetTime(EasycommSetTime *d)
{
    memset(d, 0, sizeof(EasycommSetTime));
    d->commandId = EasycommIdSetTime;
}


void easycommGetTime(EasycommGetTime *d)
{
    memset(d, 0, sizeof(EasycommGetTime));
    d->commandId = EasycommIdGetTime;
}


void easycommGetVersion(EasycommGetVersion *d)
{
    memset(d, 0, sizeof(EasycommGetVersion));
    d->commandId = EasycommIdGetVersion;
}


void easycommSetVelocityLeft(EasycommSetVelocityLeft *d)
{
    memset(d, 0, sizeof(EasycommSetVelocityLeft));
    d->commandId = EasycommIdSetVelocityLeft;
}

void easycommGetVelocityLeft(EasycommGetVelocityLeft *d)
{
    memset(d, 0, sizeof(EasycommGetVelocityLeft));
    d->commandId = EasycommIdGetVelocityLeft;
}


void easycommSetVelocityRight(EasycommSetVelocityRight *d)
{
    memset(d, 0, sizeof(EasycommSetVelocityRight));
    d->commandId = EasycommIdSetVelocityRight;
}


void easycommGetVelocityRight(EasycommGetVelocityRight *d)
{
    memset(d, 0, sizeof(EasycommGetVelocityRight));
    d->commandId = EasycommIdGetVelocityRight;
}


void easycommSetVelocityUp(EasycommSetVelocityUp *d)
{
    memset(d, 0, sizeof(EasycommSetVelocityUp));
    d->commandId = EasycommIdSetVelocityUp;
}


void easycommGetVelocityUp(EasycommGetVelocityUp *d)
{
    memset(d, 0, sizeof(EasycommGetVelocityUp));
    d->commandId = EasycommIdGetVelocityUp;
}


void easycommSetVelocityDown(EasycommSetVelocityDown *d)
{
    memset(d, 0, sizeof(EasycommSetVelocityDown));
    d->commandId = EasycommIdSetVelocityDown;
}


void easycommGetVelocityDown(EasycommGetVelocityDown *d)
{
    memset(d, 0, sizeof(EasycommGetVelocityDown));
    d->commandId = EasycommIdGetVelocityDown;
}


void easycommGetConfigRegister(EasycommGetConfigRegister *d)
{
    memset(d, 0, sizeof(EasycommGetConfigRegister));
    d->commandId = EasycommIdGetConfigRegister;
}


void easycommSetConfigRegister(EasycommSetConfigRegister *d)
{
    memset(d, 0, sizeof(EasycommSetConfigRegister));
    d->commandId = EasycommIdSetConfigRegister;
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
    d->commandId = EasycommIdDoReset;
}


void easycommDoPark(EasycommDoPark *d)
{
    memset(d, 0, sizeof(EasycommDoPark));
    d->commandId = EasycommIdDoPark;
}
