#include "../easycomm-parser-types-sprintf.h"
#include <stdio.h>
#include <string.h>

void easycommInvalidSprintf(const EasycommData *from, char *to) { sprintf(to, "<invalid>"); }

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


void easycommGetAzimuthSprintf(const EasycommGetAzimuth *from, char *to) { sprintf(to, "AZ"); }


void easycommElevationSprintf(const EasycommElevation *from, char *to)
{
    sprintf(to, "EL%.1f", from->elevation);
}


void easycommGetElevationSprintf(const EasycommGetElevation *from, char *to) { sprintf(to, "EL"); }


void easycommGetAzimuthElevationSprintf(const EasycommGetAzimuthElevation *from, char *to)
{
    sprintf(to, "AZ EL");
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


void easycommGetVelocityLeftSprintf(const EasycommGetVelocityLeft *from, char *to)
{
    sprintf(to, "VL");
}


void easycommVelocityRightSprintf(const EasycommVelocityRight *from, char *to)
{
    sprintf(to, "VR%u", from->milliDegSecond);
}


void easycommGetVelocityRightSprintf(const EasycommGetVelocityRight *from, char *to)
{
    sprintf(to, "VR");
}


void easycommVelocityUpSprintf(const EasycommVelocityUp *from, char *to)
{
    sprintf(to, "VU%u", from->milliDegSecond);
}


void easycommGetVelocityUpSprintf(const EasycommGetVelocityUp *from, char *to)
{
    sprintf(to, "VU");
}


void easycommVelocityDownSprintf(const EasycommVelocityDown *from, char *to)
{
    sprintf(to, "VD%u", from->milliDegSecond);
}


void easycommGetVelocityDownSprintf(const EasycommGetVelocityDown *from, char *to)
{
    sprintf(to, "VD");
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


void easycommResetSprintf(const EasycommReset *from, char *to) { sprintf(to, "RESET"); }


void easycommParkSprintf(const EasycommPark *from, char *to) { sprintf(to, "PARK"); }


void easycommDataSprintf(const EasycommData *from, char *to)
{
    // clang-format off
        if      ( from->commandId == EasycommIdInvalid) {easycommInvalidSprintf(from, to); }
        else if ( from->commandId == EasycommIdSingleLine) {easycommSingleLineSprintf(&from->as.singleLine, to); }
        else if ( from->commandId == EasycommIdAzimuth) {easycommAzimuthSprintf(&from->as.azimuth, to); }
        else if ( from->commandId == EasycommIdGetAzimuth) {easycommGetAzimuthSprintf(&from->as.getAzimuth, to); }
        else if ( from->commandId == EasycommIdElevation) {easycommElevationSprintf(&from->as.elevation, to); }
        else if ( from->commandId == EasycommIdGetElevation) {easycommGetElevationSprintf(&from->as.getElevation, to); }
        else if ( from->commandId == EasycommIdGetAzimuthElevation) {easycommGetAzimuthElevationSprintf(&from->as.getAzimuthElevation, to); }
        else if ( from->commandId == EasycommIdUplinkFrequency) {easycommUplinkFrequencySprintf(&from->as.uplinkFrequency, to); }
        else if ( from->commandId == EasycommIdDownlinkFrequency) {easycommDownlinkFrequencySprintf(&from->as.downlinkFrequency, to); }
        else if ( from->commandId == EasycommIdUplinkMode) {easycommUplinkModeSprintf(&from->as.uplinkMode, to); }
        else if ( from->commandId == EasycommIdDownlinkMode) {easycommDownlinkModeSprintf(&from->as.downlinkMode, to); }
        else if ( from->commandId == EasycommIdUplinkRadioNumber) {easycommUplinkRadioNumberSprintf(&from->as.uplinkRadio, to); }
        else if ( from->commandId == EasycommIdDownlinkRadioNumber) {easycommDownlinkRadioNumberSprintf(&from->as.downlinkRadio, to); }
        else if ( from->commandId == EasycommIdMoveLeft) {easycommMoveLeftSprintf(&from->as.moveLeft, to); }
        else if ( from->commandId == EasycommIdMoveRight) {easycommMoveRightSprintf(&from->as.moveRight, to); }
        else if ( from->commandId == EasycommIdMoveUp) {easycommMoveUpSprintf(&from->as.moveUp, to); }
        else if ( from->commandId == EasycommIdMoveDown) {easycommMoveDownSprintf(&from->as.moveDown, to); }
        else if ( from->commandId == EasycommIdStopAzimuthMove) {easycommStopAzimuthMoveSprintf(&from->as.stopAzimuthMove, to); }
        else if ( from->commandId == EasycommIdStopElevationMove) {easycommStopElevationMoveSprintf(&from->as.stopElevationMove, to); }
        else if ( from->commandId == EasycommIdAcquisitionOfSignal) {easycommAcquisitionOfSignalSprintf(&from->as.acquisitionOfSignal, to); }
        else if ( from->commandId == EasycommIdLossOfSignal) {easycommLossOfSignalSprintf(&from->as.lossOfSignal, to); }
        else if ( from->commandId == EasycommIdSetOutput) {easycommSetOutputSprintf(&from->as.setOutput, to); }
        else if ( from->commandId == EasycommIdReadInput) {easycommReadInputSprintf(&from->as.readInput, to); }
        else if ( from->commandId == EasycommIdReadAnalogueInput) {easycommReadAnalogueInputSprintf(&from->as.readAnalogueInput, to); }
        else if ( from->commandId == EasycommIdSetTime) {easycommSetTimeSprintf(&from->as.setTime, to); }
        else if ( from->commandId == EasycommIdRequestVersion) {easycommRequestVersionSprintf(&from->as.requestVersion, to); }
        else if ( from->commandId == EasycommIdVelocityLeft) {easycommVelocityLeftSprintf(&from->as.velocityLeft, to); }
        else if ( from->commandId == EasycommIdGetVelocityLeft) {easycommGetVelocityLeftSprintf(&from->as.getVelocityLeft, to); }
        else if ( from->commandId == EasycommIdVelocityRight) {easycommVelocityRightSprintf(&from->as.velocityRight, to); }
        else if ( from->commandId == EasycommIdGetVelocityRight) {easycommGetVelocityRightSprintf(&from->as.getVelocityRight, to); }
        else if ( from->commandId == EasycommIdVelocityUp) {easycommVelocityUpSprintf(&from->as.velocityUp, to); }
        else if ( from->commandId == EasycommIdGetVelocityUp) {easycommGetVelocityUpSprintf(&from->as.getVelocityUp, to); }
        else if ( from->commandId == EasycommIdVelocityDown) {easycommVelocityDownSprintf(&from->as.velocityDown, to); }
        else if ( from->commandId == EasycommIdGetVelocityDown) {easycommGetVelocityDownSprintf(&from->as.getVelocityDown, to); }
        else if ( from->commandId == EasycommIdReadConfig) {easycommReadConfigSprintf(&from->as.readConfig, to); }
        else if ( from->commandId == EasycommIdWriteConfig) {easycommWriteConfigSprintf(&from->as.writeConfig, to); }
        else if ( from->commandId == EasycommIdGetStatusRegister) {easycommGetStatusRegisterSprintf(&from->as.getStatusRegister, to); }
        else if ( from->commandId == EasycommIdGetErrorRegister) {easycommGetErrorRegisterSprintf(&from->as.getErrorRegister, to); }
        else if ( from->commandId == EasycommIdReset) {easycommResetSprintf(&from->as.reset, to); }
        else if ( from->commandId == EasycommIdPark) {easycommParkSprintf(&from->as.park, to); }
    // clang-format on
}