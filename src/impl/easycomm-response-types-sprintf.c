#include "../easycomm-response-types-sprintf.h"
#include <stdio.h>
#include <string.h>


void easycommResponseSingleLineSprintf(const EasycommResponseSingleLine *from, char *to)
{
    sprintf(to,
#if defined(ARDUINO_ARCH_AVR) || defined(ARDUINO_ARCH_STM32)
            "AZ%.1f EL%.1f UP%lu %s DN%lu %s",
#elif defined(ARDUINO_ARCH_ESP8266) || defined(ARDUINO_ARCH_ESP32)
            "AZ%.1f EL%.1f UP%u %s DN%u %s",
#else // assume native platform
            "AZ%.1f EL%.1f UP%u %s DN%u %s",
#endif
            from->azimuth, from->elevation, from->uplinkFrequency.as.uint32, from->modeUp,
            from->downlinkFrequency.as.uint32, from->modeDown);
}


void easycommResponseAzimuthSprintf(const EasycommResponseAzimuth *from, char *to)
{
    sprintf(to, "AZ%.1f", from->azimuth);
}


void easycommResponseElevationSprintf(const EasycommResponseElevation *from, char *to)
{
    sprintf(to, "EL%.1f", from->elevation);
}


void easycommResponseUplinkFrequencySprintf(const EasycommResponseUplinkFrequency *from, char *to)
{
#if defined(ARDUINO_ARCH_AVR) || defined(ARDUINO_ARCH_STM32)
    sprintf(to, "UP%lu", from->frequency.as.uint32);
#elif defined(ARDUINO_ARCH_ESP8266) || defined(ARDUINO_ARCH_ESP32)
    sprintf(to, "UP%u", from->frequency.as.uint32);
#else // assume native platform
    sprintf(to, "UP%u", from->frequency.as.uint32);
#endif
}


void easycommResponseDownlinkFrequencySprintf(const EasycommResponseDownlinkFrequency *from, char *to)
{
#if defined(ARDUINO_ARCH_AVR) || defined(ARDUINO_ARCH_STM32)
    sprintf(to, "DN%ld", from->frequency.as.uint32);
#elif defined(ARDUINO_ARCH_ESP8266) || defined(ARDUINO_ARCH_ESP32)
    sprintf(to, "DN%u", from->frequency.as.uint32);
#else // assume native platform
    sprintf(to, "DN%u", from->frequency.as.uint32);
#endif
}


void easycommResponseUplinkModeSprintf(const EasycommResponseUplinkMode *from, char *to)
{
    sprintf(to, "UM%s", from->mode);
}


void easycommResponseDownlinkModeSprintf(const EasycommResponseDownlinkMode *from, char *to)
{
    sprintf(to, "DM%s", from->mode);
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
    sprintf(to, "CR%u,%s", from->registerNumber, from->value.as.str);
}


void easycommResponseGetStatusRegisterSprintf(const EasycommResponseGetStatusRegister *from, char *to)
{
    sprintf(to, "GS%u", from->status);
}


void easycommResponseGetErrorRegisterSprintf(const EasycommResponseGetErrorRegister *from, char *to)
{
    sprintf(to, "GE%u", from->status);
}
