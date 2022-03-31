#include "../easycomm-response-types-sprintf.h"
#include <stdio.h>
#include <string.h>


void easycommSingleLineSprintf(const EasycommResponseSingleLine *from, char *to)
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


void easycommAzimuthSprintf(const EasycommResponseAzimuth *from, char *to)
{
    sprintf(to, "AZ%05.1f", from->azimuth);
}


void easycommElevationSprintf(const EasycommResponseElevation *from, char *to)
{
    sprintf(to, "EL%05.1f", from->elevation);
}


void easycommAzimuthElevationSprintf(const EasycommResponseAzimuthElevation *from, char *to)
{
    sprintf(to, "AZ%05.1f EL%05.1f", from->azimuth, from->elevation);
}


void easycommUplinkFrequencySprintf(const EasycommResponseUplinkFrequency *from, char *to)
{
#ifdef ARDUINO_AVR_MEGA2560
    sprintf(to, "UP%09ld", from->frequency.as.uint32);
#else
    sprintf(to, "UP%09d", from->frequency.as.uint32);
#endif
}


void easycommDownlinkFrequencySprintf(const EasycommResponseDownlinkFrequency *from, char *to)
{
#ifdef ARDUINO_AVR_MEGA2560
    sprintf(to, "DN%09ld", from->frequency.as.uint32);
#else
    sprintf(to, "DN%09d", from->frequency.as.uint32);
#endif
}


void easycommUplinkModeSprintf(const EasycommResponseUplinkMode *from, char *to)
{
    sprintf(to, "UM%c%c%c", from->mode[0], from->mode[1], from->mode[2]);
}


void easycommDownlinkModeSprintf(const EasycommResponseDownlinkMode *from, char *to)
{
    sprintf(to, "DM%c%c%c", from->mode[0], from->mode[1], from->mode[2]);
}


void easycommDownlinkRadioNumberSprintf(const EasycommResponseDownlinkRadioNumber *from, char *to)
{
    sprintf(to, "DR%03d", from->number);
}


void easycommUplinkRadioNumberSprintf(const EasycommResponseUplinkRadioNumber *from, char *to)
{
    sprintf(to, "UR%03d", from->number);
}


void easycommReadInputSprintf(const EasycommResponseReadInput *from, char *to)
{
    sprintf(to, "IP%03d,%06d", from->number, from->value);
}


void easycommReadAnalogueInputSprintf(const EasycommResponseReadAnalogueInput *from, char *to)
{
    sprintf(to, "AN%03d,%06d", from->number, from->value);
}


void easycommRequestVersionSprintf(const EasycommResponseRequestVersion *from, char *to)
{
    sprintf(to, "VE%d.%d", from->major, from->minor);
}


void easycommAlarmSprintf(const EasycommResponseAlarm *from, char *to)
{
    sprintf(to, "AL%s", from->message);
}


void easycommVelocityLeftSprintf(const EasycommResponseVelocityLeft *from, char *to)
{
    sprintf(to, "VL%05d", from->milliDegSecond);
}


void easycommVelocityRightSprintf(const EasycommResponseVelocityRight *from, char *to)
{
    sprintf(to, "VR%05d", from->milliDegSecond);
}


void easycommVelocityUpSprintf(const EasycommResponseVelocityUp *from, char *to)
{
    sprintf(to, "VU%05d", from->milliDegSecond);
}

void easycommVelocityDownSprintf(const EasycommResponseVelocityDown *from, char *to)
{
    sprintf(to, "VD%05d", from->milliDegSecond);
}


void easycommReadConfigSprintf(const EasycommResponseReadConfig *from, char *to)
{
    sprintf(to, "XX%03d,%s", from->registerNumber, from->registerValue);
}


void easycommGetStatusRegisterSprintf(const EasycommResponseGetStatusRegister *from, char *to)
{
    sprintf(to, "GS%d", from->status);
}


void easycommGetErrorRegisterSprintf(const EasycommResponseGetErrorRegister *from, char *to)
{
    sprintf(to, "GE%d", from->status);
}
