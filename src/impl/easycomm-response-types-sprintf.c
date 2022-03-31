#include "../easycomm-response-types-sprintf.h"
#include <stdio.h>
#include <string.h>


void easycommResponseSingleLineSprintf(const EasycommResponseSingleLine *from, char *to)
{
    sprintf(to,
#ifdef ARDUINO_AVR_MEGA2560
            "AZ%05.1f EL%05.1f UP%09lu %c%c%c DN%09lu %c%c%c",
#else
            "AZ%.1f EL%.1f UP%u %c%c%c DN%u %c%c%c",
#endif
            from->azimuth, from->elevation, from->uplinkFrequency.as.uint32, from->modeUp[0],
            from->modeUp[1], from->modeUp[2], from->downlinkFrequency.as.uint32, from->modeDown[0],
            from->modeDown[1], from->modeDown[2]);
}


void easycommResponseAzimuthSprintf(const EasycommResponseAzimuth *from, char *to)
{
    sprintf(to, "AZ%.1f", from->azimuth);
}


void easycommResponseElevationSprintf(const EasycommResponseElevation *from, char *to)
{
    sprintf(to, "EL%.1f", from->elevation);
}


void easycommResponseAzimuthElevationSprintf(const EasycommResponseAzimuthElevation *from, char *to)
{
    sprintf(to, "AZ%.1f EL%.1f", from->azimuth, from->elevation);
}


void easycommResponseUplinkFrequencySprintf(const EasycommResponseUplinkFrequency *from, char *to)
{
#ifdef ARDUINO_AVR_MEGA2560
    sprintf(to, "UP%lu", from->frequency.as.uint32);
#else
    sprintf(to, "UP%u", from->frequency.as.uint32);
#endif
}


void easycommResponseDownlinkFrequencySprintf(const EasycommResponseDownlinkFrequency *from, char *to)
{
#ifdef ARDUINO_AVR_MEGA2560
    sprintf(to, "DN%09ld", from->frequency.as.uint32);
#else
    sprintf(to, "DN%u", from->frequency.as.uint32);
#endif
}


void easycommResponseUplinkModeSprintf(const EasycommResponseUplinkMode *from, char *to)
{
    sprintf(to, "UM%c%c%c", from->mode[0], from->mode[1], from->mode[2]);
}


void easycommResponseDownlinkModeSprintf(const EasycommResponseDownlinkMode *from, char *to)
{
    sprintf(to, "DM%c%c%c", from->mode[0], from->mode[1], from->mode[2]);
}


void easycommResponseDownlinkRadioNumberSprintf(const EasycommResponseDownlinkRadioNumber *from, char *to)
{
    sprintf(to, "DR%u", from->number);
}


void easycommResponseUplinkRadioNumberSprintf(const EasycommResponseUplinkRadioNumber *from, char *to)
{
    sprintf(to, "UR%u", from->number);
}


void easycommResponseReadInputSprintf(const EasycommResponseReadInput *from, char *to)
{
    sprintf(to, "IP%u,%u", from->number, from->value);
}


void easycommResponseReadAnalogueInputSprintf(const EasycommResponseReadAnalogueInput *from, char *to)
{
    sprintf(to, "AN%u,%u", from->number, from->value);
}


void easycommResponseRequestVersionSprintf(const EasycommResponseRequestVersion *from, char *to)
{
    sprintf(to, "VE%u.%u", from->major, from->minor);
}


void easycommResponseAlarmSprintf(const EasycommResponseAlarm *from, char *to)
{
    sprintf(to, "AL%s", from->message);
}


void easycommResponseVelocityLeftSprintf(const EasycommResponseVelocityLeft *from, char *to)
{
    sprintf(to, "VL%u", from->milliDegSecond);
}


void easycommResponseVelocityRightSprintf(const EasycommResponseVelocityRight *from, char *to)
{
    sprintf(to, "VR%u", from->milliDegSecond);
}


void easycommResponseVelocityUpSprintf(const EasycommResponseVelocityUp *from, char *to)
{
    sprintf(to, "VU%u", from->milliDegSecond);
}

void easycommResponseVelocityDownSprintf(const EasycommResponseVelocityDown *from, char *to)
{
    sprintf(to, "VD%u", from->milliDegSecond);
}


void easycommResponseReadConfigSprintf(const EasycommResponseReadConfig *from, char *to)
{
#ifdef ARDUINO_AVR_MEGA2560
    sprintf(to, "CR%u,%ld", from->registerNumber, from->value.as.int32);
#else
    sprintf(to, "CR%u,%d", from->registerNumber, from->value.as.int32);
#endif
}


void easycommResponseGetStatusRegisterSprintf(const EasycommResponseGetStatusRegister *from, char *to)
{
    sprintf(to, "GS%u", from->status);
}


void easycommResponseGetErrorRegisterSprintf(const EasycommResponseGetErrorRegister *from, char *to)
{
    sprintf(to, "GE%u", from->status);
}