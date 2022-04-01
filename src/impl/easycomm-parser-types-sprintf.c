#include "../easycomm-parser-types-sprintf.h"
#include <stdio.h>
#include <string.h>


void easycommSingleLineSprintf(const EasycommSingleLine *from, char *to)
{
    sprintf(to,
#ifdef ARDUINO_AVR_MEGA2560
            "AZ%.1f EL%.1f UP%lu %c%c%c DN%lu %c%c%c",
#else
            "AZ%.1f EL%.1f UP%u %c%c%c DN%u %c%c%c",
#endif
            from->azimuth, from->elevation, from->uplinkFrequency.as.uint32, from->modeUp[0],
            from->modeUp[1], from->modeUp[2], from->downlinkFrequency.as.uint32, from->modeDown[0],
            from->modeDown[1], from->modeDown[2]);
}


void easycommAzimuthSprintf(const EasycommAzimuth *from, char *to)
{
    sprintf(to, "AZ%.1f", from->azimuth);
}


void easycommElevationSprintf(const EasycommElevation *from, char *to)
{
    sprintf(to, "EL%.1f", from->elevation);
}


void easycommUplinkFrequencySprintf(const EasycommUplinkFrequency *from, char *to)
{
#ifdef ARDUINO_AVR_MEGA2560
    sprintf(to, "UP%lu", from->frequency.as.uint32);
#else
    sprintf(to, "UP%u", from->frequency.as.uint32);
#endif
}


void easycommDownlinkFrequencySprintf(const EasycommDownlinkFrequency *from, char *to)
{
#ifdef ARDUINO_AVR_MEGA2560
    sprintf(to, "DN%lu", from->frequency.as.uint32);
#else
    sprintf(to, "DN%u", from->frequency.as.uint32);
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
    sprintf(to, "UR%u", from->number);
}


void easycommDownlinkRadioNumberSprintf(const EasycommDownlinkRadioNumber *from, char *to)
{
    sprintf(to, "DR%u", from->number);
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
    sprintf(to, "AO");
}


void easycommLossOfSignalSprintf(const EasycommLossOfSignal *from, char *to) { sprintf(to, "LO"); }


void easycommSetOutputSprintf(const EasycommSetOutput *from, char *to)
{
    sprintf(to, "OP%u,%u", from->number, from->value);
}


void easycommReadInputSprintf(const EasycommReadInput *from, char *to)
{
    sprintf(to, "IP%u", from->number);
}


void easycommReadAnalogueInputSprintf(const EasycommReadAnalogueInput *from, char *to)
{
    sprintf(to, "AN%u", from->number);
}


void easycommSetTimeSprintf(const EasycommSetTime *from, char *to)
{
    sprintf(to, "ST%02u:%02u:%02u:%02u:%02u:%02u", from->year, from->month, from->day, from->hour,
            from->minute, from->second);
}


void easycommRequestVersionSprintf(const EasycommRequestVersion *from, char *to)
{
    sprintf(to, "VE");
}


void easycommVelocityLeftSprintf(const EasycommVelocityLeft *from, char *to)
{
    sprintf(to, "VL%u", from->milliDegSecond);
}


void easycommVelocityRightSprintf(const EasycommVelocityRight *from, char *to)
{
    sprintf(to, "VR%u", from->milliDegSecond);
}


void easycommVelocityUpSprintf(const EasycommVelocityUp *from, char *to)
{
    sprintf(to, "VU%u", from->milliDegSecond);
}


void easycommVelocityDownSprintf(const EasycommVelocityDown *from, char *to)
{
    sprintf(to, "VD%u", from->milliDegSecond);
}


void easycommReadConfigSprintf(const EasycommReadConfig *from, char *to)
{
    sprintf(to, "CR%u", from->registerNumber);
}


void easycommWriteConfigSprintf(const EasycommWriteConfig *from, char *to)
{
    sprintf(to, "CW%u,%s", from->registerNumber, from->value.as.str);
}


void easycommGetStatusRegisterSprintf(const EasycommGetStatusRegister *from, char *to)
{
    sprintf(to, "GS");
}


void easycommGetErrorRegisterSprintf(const EasycommGetErrorRegister *from, char *to)
{
    sprintf(to, "GE");
}
