#include "../easycomm-parser-types-sprintf.h"
#include <stdio.h>
#include <string.h>

void easycommInvalidSprintf(const EasycommData *from, char *to) { sprintf(to, "<invalid>"); }

void easycommSingleLineSprintf(const EasycommSingleLine *from, char *to)
{
    sprintf(to,
#if defined(ARDUINO_ARCH_AVR)
            "AZ%.1f EL%.1f UP%lu %c%c%c DN%lu %c%c%c",
#elif defined(ARDUINO_ARCH_STM32)
            "AZ%.1f EL%.1f UP%lu %c%c%c DN%lu %c%c%c",
#elif defined(ARDUINO_ARCH_ESP8266)
            "AZ%.1f EL%.1f UP%u %c%c%c DN%u %c%c%c",
#elif defined(ARDUINO_ARCH_ESP32)
            "AZ%.1f EL%.1f UP%u %c%c%c DN%u %c%c%c",
#else // assume native platform
            "AZ%.1f EL%.1f UP%u %c%c%c DN%u %c%c%c",
#endif
            from->azimuth, from->elevation, from->uplinkFrequency.as.uint32, from->modeUp[0],
            from->modeUp[1], from->modeUp[2], from->downlinkFrequency.as.uint32, from->modeDown[0],
            from->modeDown[1], from->modeDown[2]);
}


void easycommSetAzimuthSprintf(const EasycommSetAzimuth *from, char *to)
{
    sprintf(to, "AZ%.1f", from->azimuth);
}


void easycommGetAzimuthSprintf(const EasycommGetAzimuth *from, char *to) { sprintf(to, "AZ"); }


void easycommSetElevationSprintf(const EasycommSetElevation *from, char *to)
{
    sprintf(to, "EL%.1f", from->elevation);
}


void easycommGetElevationSprintf(const EasycommGetElevation *from, char *to) { sprintf(to, "EL"); }


void easycommSetUplinkFrequencySprintf(const EasycommSetUplinkFrequency *from, char *to)
{
#if defined(ARDUINO_ARCH_AVR)
    sprintf(to, "UP%lu", from->frequency.as.uint32);
#elif defined(ARDUINO_ARCH_STM32)
    sprintf(to, "UP%lu", from->frequency.as.uint32);
#elif defined(ARDUINO_ARCH_ESP8266)
    sprintf(to, "UP%u", from->frequency.as.uint32);
#elif defined(ARDUINO_ARCH_ESP32)
    sprintf(to, "UP%u", from->frequency.as.uint32);
#else // assume native platform
    sprintf(to, "UP%u", from->frequency.as.uint32);
#endif
}


void easycommGetUplinkFrequencySprintf(const EasycommGetUplinkFrequency *from, char *to)
{
    sprintf(to, "UP");
}


void easycommSetDownlinkFrequencySprintf(const EasycommSetDownlinkFrequency *from, char *to)
{
#if defined(ARDUINO_ARCH_AVR)
    sprintf(to, "DN%lu", from->frequency.as.uint32);
#elif defined(ARDUINO_ARCH_STM32)
    sprintf(to, "DN%lu", from->frequency.as.uint32);
#elif defined(ARDUINO_ARCH_ESP8266)
    sprintf(to, "DN%u", from->frequency.as.uint32);
#elif defined(ARDUINO_ARCH_ESP32)
    sprintf(to, "DN%u", from->frequency.as.uint32);
#else // assume native platform
    sprintf(to, "DN%u", from->frequency.as.uint32);
#endif
}


void easycommGetDownlinkFrequencySprintf(const EasycommGetDownlinkFrequency *from, char *to)
{
    sprintf(to, "DN");
}


void easycommSetUplinkModeSprintf(const EasycommSetUplinkMode *from, char *to)
{
    sprintf(to, "UM%c%c%c", from->mode[0], from->mode[1], from->mode[2]);
}


void easycommGetUplinkModeSprintf(const EasycommGetUplinkMode *from, char *to)
{
    sprintf(to, "UM");
}


void easycommSetDownlinkModeSprintf(const EasycommSetDownlinkMode *from, char *to)
{
    sprintf(to, "DM%c%c%c", from->mode[0], from->mode[1], from->mode[2]);
}


void easycommGetDownlinkModeSprintf(const EasycommGetDownlinkMode *from, char *to)
{
    sprintf(to, "DM");
}


void easycommSetUplinkRadioSprintf(const EasycommSetUplinkRadio *from, char *to)
{
    sprintf(to, "UR%u", from->number);
}


void easycommGetUplinkRadioSprintf(const EasycommGetUplinkRadio *from, char *to)
{
    sprintf(to, "UR");
}


void easycommSetDownlinkRadioSprintf(const EasycommSetDownlinkRadio *from, char *to)
{
    sprintf(to, "DR%u", from->number);
}

void easycommGetDownlinkRadioSprintf(const EasycommGetDownlinkRadio *from, char *to)
{
    sprintf(to, "DR");
}


void easycommDoMoveLeftSprintf(const EasycommDoMoveLeft *from, char *to) { sprintf(to, "ML"); }


void easycommDoMoveRightSprintf(const EasycommDoMoveRight *from, char *to) { sprintf(to, "MR"); }


void easycommDoMoveUpSprintf(const EasycommDoMoveUp *from, char *to) { sprintf(to, "MU"); }


void easycommDoMoveDownSprintf(const EasycommDoMoveDown *from, char *to) { sprintf(to, "MD"); }


void easycommDoStopAzimuthMoveSprintf(const EasycommDoStopAzimuthMove *from, char *to)
{
    sprintf(to, "SA");
}


void easycommDoStopElevationMoveSprintf(const EasycommDoStopElevationMove *from, char *to)
{
    sprintf(to, "SE");
}


void easycommAcquisitionOfSignalSprintf(const EasycommAcquisitionOfSignal *from, char *to)
{
    sprintf(to, "AO");
}


void easycommLossOfSignalSprintf(const EasycommLossOfSignal *from, char *to) { sprintf(to, "LO"); }


void easycommSetDigitalOutputSprintf(const EasycommSetDigitalOutput *from, char *to)
{
    sprintf(to, "OP%u,%u", from->number, from->value);
}


void easycommGetDigitalInputSprintf(const EasycommGetDigitalInput *from, char *to)
{
    sprintf(to, "IP%u", from->number);
}


void easycommGetAnalogueInputSprintf(const EasycommGetAnalogueInput *from, char *to)
{
    sprintf(to, "AN%u", from->number);
}


void easycommSetTimeSprintf(const EasycommSetTime *from, char *to)
{
    sprintf(to, "ST%02u:%02u:%02u:%02u:%02u:%02u", from->year, from->month, from->day, from->hour,
            from->minute, from->second);
}


void easycommGetTimeSprintf(const EasycommGetTime *from, char *to) { sprintf(to, "ST"); }


void easycommGetVersionSprintf(const EasycommGetVersion *from, char *to) { sprintf(to, "VE"); }


void easycommSetVelocityLeftSprintf(const EasycommSetVelocityLeft *from, char *to)
{
    sprintf(to, "VL%u", from->milliDegSecond);
}


void easycommGetVelocityLeftSprintf(const EasycommGetVelocityLeft *from, char *to)
{
    sprintf(to, "VL");
}


void easycommSetVelocityRightSprintf(const EasycommSetVelocityRight *from, char *to)
{
    sprintf(to, "VR%u", from->milliDegSecond);
}


void easycommGetVelocityRightSprintf(const EasycommGetVelocityRight *from, char *to)
{
    sprintf(to, "VR");
}


void easycommSetVelocityUpSprintf(const EasycommSetVelocityUp *from, char *to)
{
    sprintf(to, "VU%u", from->milliDegSecond);
}


void easycommGetVelocityUpSprintf(const EasycommGetVelocityUp *from, char *to)
{
    sprintf(to, "VU");
}


void easycommSetVelocityDownSprintf(const EasycommSetVelocityDown *from, char *to)
{
    sprintf(to, "VD%u", from->milliDegSecond);
}


void easycommGetVelocityDownSprintf(const EasycommGetVelocityDown *from, char *to)
{
    sprintf(to, "VD");
}


void easycommGetConfigRegisterSprintf(const EasycommGetConfigRegister *from, char *to)
{
    sprintf(to, "CR%u", from->registerNumber);
}


void easycommSetConfigRegisterSprintf(const EasycommSetConfigRegister *from, char *to)
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


void easycommDoResetSprintf(const EasycommDoReset *from, char *to) { sprintf(to, "RESET"); }


void easycommDoParkSprintf(const EasycommDoPark *from, char *to) { sprintf(to, "PARK"); }


void easycommDataSprintf(const EasycommData *from, char *to)
{
    // clang-format off
        if      ( from->commandId == EasycommIdInvalid) {easycommInvalidSprintf(from, to); }
        else if ( from->commandId == EasycommIdSingleLine) {easycommSingleLineSprintf(&from->as.singleLine, to); }
        else if ( from->commandId == EasycommIdSetAzimuth) {easycommSetAzimuthSprintf(&from->as.setAzimuth, to); }
        else if ( from->commandId == EasycommIdGetAzimuth) {easycommGetAzimuthSprintf(&from->as.getAzimuth, to); }
        else if ( from->commandId == EasycommIdSetElevation) {easycommSetElevationSprintf(&from->as.setElevation, to); }
        else if ( from->commandId == EasycommIdGetElevation) {easycommGetElevationSprintf(&from->as.getElevation, to); }
        else if ( from->commandId == EasycommIdSetUplinkFrequency) {easycommSetUplinkFrequencySprintf(&from->as.setUplinkFrequency, to); }
        else if ( from->commandId == EasycommIdGetUplinkFrequency) {easycommGetUplinkFrequencySprintf(&from->as.getUplinkFrequency, to); }
        else if ( from->commandId == EasycommIdSetDownlinkFrequency) {easycommSetDownlinkFrequencySprintf(&from->as.setDownlinkFrequency, to); }
        else if ( from->commandId == EasycommIdGetDownlinkFrequency) {easycommGetDownlinkFrequencySprintf(&from->as.getDownlinkFrequency, to); }
        else if ( from->commandId == EasycommIdSetUplinkMode) {easycommSetUplinkModeSprintf(&from->as.setUplinkMode, to); }
        else if ( from->commandId == EasycommIdGetUplinkMode) {easycommGetUplinkModeSprintf(&from->as.getUplinkMode, to); }
        else if ( from->commandId == EasycommIdSetDownlinkMode) {easycommSetDownlinkModeSprintf(&from->as.setDownlinkMode, to); }
        else if ( from->commandId == EasycommIdGetDownlinkMode) {easycommGetDownlinkModeSprintf(&from->as.getDownlinkMode, to); }
        else if ( from->commandId == EasycommIdSetUplinkRadio) {easycommSetUplinkRadioSprintf(&from->as.setUplinkRadio, to); }
        else if ( from->commandId == EasycommIdGetUplinkRadio) {easycommGetUplinkRadioSprintf(&from->as.getUplinkRadio, to); }
        else if ( from->commandId == EasycommIdSetDownlinkRadio) {easycommSetDownlinkRadioSprintf(&from->as.setDownlinkRadio, to); }
        else if ( from->commandId == EasycommIdGetDownlinkRadio) {easycommGetDownlinkRadioSprintf(&from->as.getDownlinkRadio, to); }
        else if ( from->commandId == EasycommIdDoMoveLeft) {easycommDoMoveLeftSprintf(&from->as.doMoveLeft, to); }
        else if ( from->commandId == EasycommIdDoMoveRight) {easycommDoMoveRightSprintf(&from->as.doMoveRight, to); }
        else if ( from->commandId == EasycommIdDoMoveUp) {easycommDoMoveUpSprintf(&from->as.doMoveUp, to); }
        else if ( from->commandId == EasycommIdDoMoveDown) {easycommDoMoveDownSprintf(&from->as.doMoveDown, to); }
        else if ( from->commandId == EasycommIdDoStopAzimuthMove) {easycommDoStopAzimuthMoveSprintf(&from->as.doStopAzimuthMove, to); }
        else if ( from->commandId == EasycommIdDoStopElevationMove) {easycommDoStopElevationMoveSprintf(&from->as.doStopElevationMove, to); }
        else if ( from->commandId == EasycommIdAcquisitionOfSignal) {easycommAcquisitionOfSignalSprintf(&from->as.acquisitionOfSignal, to); }
        else if ( from->commandId == EasycommIdLossOfSignal) {easycommLossOfSignalSprintf(&from->as.lossOfSignal, to); }
        else if ( from->commandId == EasycommIdSetDigitalOutput) {easycommSetDigitalOutputSprintf(&from->as.setDigitalOutput, to); }
        else if ( from->commandId == EasycommIdGetDigitalInput) {easycommGetDigitalInputSprintf(&from->as.getDigitalInput, to); }
        else if ( from->commandId == EasycommIdGetAnalogueInput) {easycommGetAnalogueInputSprintf(&from->as.getAnalogueInput, to); }
        else if ( from->commandId == EasycommIdSetTime) {easycommSetTimeSprintf(&from->as.setTime, to); }
        else if ( from->commandId == EasycommIdGetTime) {easycommGetTimeSprintf(&from->as.getTime, to); }
        else if ( from->commandId == EasycommIdGetVersion) {easycommGetVersionSprintf(&from->as.getVersion, to); }
        else if ( from->commandId == EasycommIdSetVelocityLeft) {easycommSetVelocityLeftSprintf(&from->as.setVelocityLeft, to); }
        else if ( from->commandId == EasycommIdGetVelocityLeft) {easycommGetVelocityLeftSprintf(&from->as.getVelocityLeft, to); }
        else if ( from->commandId == EasycommIdSetVelocityRight) {easycommSetVelocityRightSprintf(&from->as.setVelocityRight, to); }
        else if ( from->commandId == EasycommIdGetVelocityRight) {easycommGetVelocityRightSprintf(&from->as.getVelocityRight, to); }
        else if ( from->commandId == EasycommIdSetVelocityUp) {easycommSetVelocityUpSprintf(&from->as.setVelocityUp, to); }
        else if ( from->commandId == EasycommIdGetVelocityUp) {easycommGetVelocityUpSprintf(&from->as.getVelocityUp, to); }
        else if ( from->commandId == EasycommIdSetVelocityDown) {easycommSetVelocityDownSprintf(&from->as.setVelocityDown, to); }
        else if ( from->commandId == EasycommIdGetVelocityDown) {easycommGetVelocityDownSprintf(&from->as.getVelocityDown, to); }
        else if ( from->commandId == EasycommIdGetConfigRegister) {easycommGetConfigRegisterSprintf(&from->as.getConfigRegister, to); }
        else if ( from->commandId == EasycommIdSetConfigRegister) {easycommSetConfigRegisterSprintf(&from->as.setConfigRegister, to); }
        else if ( from->commandId == EasycommIdGetStatusRegister) {easycommGetStatusRegisterSprintf(&from->as.getStatusRegister, to); }
        else if ( from->commandId == EasycommIdGetErrorRegister) {easycommGetErrorRegisterSprintf(&from->as.getErrorRegister, to); }
        else if ( from->commandId == EasycommIdDoReset) {easycommDoResetSprintf(&from->as.doReset, to); }
        else if ( from->commandId == EasycommIdDoPark) {easycommDoParkSprintf(&from->as.doPark, to); }
    // clang-format on
}
