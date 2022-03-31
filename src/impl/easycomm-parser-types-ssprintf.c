#include "../easycomm-parser-types-ssprintf.h"
#include <stdio.h>
#include <string.h>


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
