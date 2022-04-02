#include "../easycomm-response-types-ctors.h"
#include <stdio.h>
#include <string.h>


void easycommResponseSingleLine(EasycommResponseSingleLine *d)
{
    memset(d, 0, sizeof(EasycommResponseSingleLine));
}


void easycommResponseAzimuth(EasycommResponseAzimuth *d)
{
    memset(d, 0, sizeof(EasycommResponseAzimuth));
}


void easycommResponseElevation(EasycommResponseElevation *d)
{
    memset(d, 0, sizeof(EasycommResponseElevation));
}


void easycommResponseAzimuthElevation(EasycommResponseAzimuthElevation *d)
{
    memset(d, 0, sizeof(EasycommResponseElevation));
}


void easycommResponseUplinkFrequency(EasycommResponseUplinkFrequency *d)
{
    memset(d, 0, sizeof(EasycommResponseUplinkFrequency));
}


void easycommResponseDownlinkFrequency(EasycommResponseDownlinkFrequency *d)
{
    memset(d, 0, sizeof(EasycommResponseDownlinkFrequency));
}


void easycommResponseUplinkMode(EasycommResponseUplinkMode *d)
{
    memset(d, 0, sizeof(EasycommResponseUplinkMode));
}


void easycommResponseDownlinkMode(EasycommResponseDownlinkMode *d)
{
    memset(d, 0, sizeof(EasycommResponseDownlinkMode));
}


void easycommResponseDownlinkRadioNumber(EasycommResponseDownlinkRadioNumber *d)
{
    memset(d, 0, sizeof(EasycommResponseDownlinkRadioNumber));
}


void easycommResponseUplinkRadioNumber(EasycommResponseUplinkRadioNumber *d)
{
    memset(d, 0, sizeof(EasycommResponseUplinkRadioNumber));
}


void easycommResponseReadInput(EasycommResponseReadInput *d)
{
    memset(d, 0, sizeof(EasycommResponseReadInput));
}


void easycommResponseReadAnalogueInput(EasycommResponseReadAnalogueInput *d)
{
    memset(d, 0, sizeof(EasycommResponseReadAnalogueInput));
}


void easycommResponseRequestVersion(EasycommResponseRequestVersion *d)
{
    memset(d, 0, sizeof(EasycommResponseRequestVersion));
}


void easycommResponseAlarm(EasycommResponseAlarm *d)
{
    memset(d, 0, sizeof(EasycommResponseAlarm));
}


void easycommResponseVelocityLeft(EasycommResponseVelocityLeft *d)
{
    memset(d, 0, sizeof(EasycommResponseVelocityLeft));
}


void easycommResponseVelocityRight(EasycommResponseVelocityRight *d)
{
    memset(d, 0, sizeof(EasycommResponseVelocityRight));
}


void easycommResponseVelocityUp(EasycommResponseVelocityUp *d)
{
    memset(d, 0, sizeof(EasycommResponseVelocityUp));
}


void easycommResponseVelocityDown(EasycommResponseVelocityDown *d)
{
    memset(d, 0, sizeof(EasycommResponseVelocityDown));
}


void easycommResponseReadConfig(EasycommResponseReadConfig *d)
{
    memset(d, 0, sizeof(EasycommResponseReadConfig));
}


void easycommResponseGetStatusRegister(EasycommResponseGetStatusRegister *d)
{
    memset(d, 0, sizeof(EasycommResponseGetStatusRegister));
}


void easycommResponseGetErrorRegister(EasycommResponseGetErrorRegister *d)
{
    memset(d, 0, sizeof(EasycommResponseGetErrorRegister));
}
