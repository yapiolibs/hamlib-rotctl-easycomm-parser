#include "../easycomm-parser-types-ctors.h"
#include "../easycomm-parser.h"
#include <stdio.h>
#include <string.h> // size_t

static bool isCommandPattern(const char *buffer, size_t min_length, size_t max_length, char *prefix, size_t prefix_length)
{
    if(buffer == NULL)
        return false;

    size_t len = strlen(buffer);
    if(min_length <= len && len <= max_length)
        return 0 == memcmp(buffer, prefix, prefix_length);

    return false;
}

static bool isFixedCommandPattern(const char *buffer, size_t length, char *prefix, size_t prefix_length)
{
    if(buffer == NULL)
        return false;

    size_t len = strlen(buffer);
    if(length == len)
        return 0 == memcmp(buffer, prefix, prefix_length);

    return false;
}

// ----- predicates


bool isEasycomm1SingleLine(const char *buffer)
{
    return isCommandPattern(buffer, EasycommSingleLineMinLength, EasycommSingleLineMaxLength, "AZ", 2);
}


bool isEasycomm2Azimuth(const char *buffer)
{
    return isCommandPattern(buffer, EasycommAzimuthMinLength, EasycommAzimuthMaxLength, "AZ", 2);
}


bool isEasycomm2Elevation(const char *buffer)
{
    return isCommandPattern(buffer, EasycommElevationMinLength, EasycommElevationMaxLength, "EL", 2);
}


bool isEasycomm2AzimuthElevation(const char *buffer)
{
    return isCommandPattern(buffer, EasycommAzimuthElevationMinLength,
                            EasycommAzimuthElevationMaxLength, "AZ", 2);
}


bool isEasycomm2ElevationAzimuth(const char *buffer)
{
    return isCommandPattern(buffer, EasycommElevationAzimuthMinLength,
                            EasycommElevationAzimuthMaxLength, "EL", 2);
}

bool isEasycomm2UplinkFrequency(const char *buffer)
{
    return isCommandPattern(buffer, EasycommUplinkFrequencyMinLength,
                            EasycommUplinkFrequencyMaxLength, "UP", 2);
}


bool isEasycomm2DownlinkFrequency(const char *buffer)
{
    return isCommandPattern(buffer, EasycommDownlinkFrequencyMinLength,
                            EasycommDownlinkFrequencyMaxLength, "DN", 2);
}


bool isEasycomm2UplinkMode(const char *buffer)
{
    return isCommandPattern(buffer, EasycommUplinkModeMinLength, EasycommUplinkModeMaxLength, "UM", 2);
}


bool isEasycomm2DownlinkMode(const char *buffer)
{
    return isCommandPattern(buffer, EasycommDownlinkModeMinLength, EasycommDownlinkModeMaxLength, "DM", 2);
}


bool isEasycomm2UplinkRadioNumber(const char *buffer)
{
    return isCommandPattern(buffer, EasycommUplinkRadioNumberMinLength,
                            EasycommUplinkRadioNumberMaxLength, "UR", 2);
}


bool isEasycomm2DownlinkRadioNumber(const char *buffer)
{
    return isCommandPattern(buffer, EasycommUplinkRadioNumberMinLength,
                            EasycommUplinkRadioNumberMaxLength, "DR", 2);
}


bool isEasycomm2MoveLeft(const char *buffer)
{
    return isFixedCommandPattern(buffer, EasycommMoveLeftLength, "ML", 2);
}


bool isEasycomm2MoveRight(const char *buffer)
{
    return isFixedCommandPattern(buffer, EasycommMoveRightLength, "MR", 2);
}


bool isEasycomm2MoveUp(const char *buffer)
{
    return isFixedCommandPattern(buffer, EasycommMoveUpLength, "MU", 2);
}


bool isEasycomm2MoveDown(const char *buffer)
{
    return isFixedCommandPattern(buffer, EasycommMoveDownLength, "MD", 2);
}


bool isEasycomm2StopAzimuthMove(const char *buffer)
{
    return isFixedCommandPattern(buffer, EasycommIdStopAzimuthMove, "SA", 2);
}


bool isEasycomm2StopElevationMove(const char *buffer)
{
    return isFixedCommandPattern(buffer, EasycommIdStopElevationMove, "SE", 2);
}


bool isEasycomm2AcquisitionOfSignal(const char *buffer)
{
    return isFixedCommandPattern(buffer, EasycommIdAcquisitionOfSignal, "AO", 2);
}


bool isEasycomm2LossOfSignal(const char *buffer)
{
    return isFixedCommandPattern(buffer, EasycommIdLossOfSignal, "Lo", 2);
}


bool isEasycomm2SetOutput(const char *buffer)
{
    return isCommandPattern(buffer, EasycommSetOutputMinLength, EasycommSetOutputMaxLength, "OP", 2);
}


bool isEasycomm2ReadInput(const char *buffer)
{
    return isCommandPattern(buffer, EasycommReadInputMinLength, EasycommReadInputMaxLength, "IP", 2);
}


bool isEasycomm2ReadAnalogueInput(const char *buffer)
{
    return isCommandPattern(buffer, EasycommReadAnalogueInputMinLength,
                            EasycommReadAnalogueInputMaxLength, "AN", 2);
}


bool isEasycomm2SetTime(const char *buffer)
{
    return isFixedCommandPattern(buffer, EasycommSetTimeLength, "ST", 2);
}


bool isEasycomm2RequestVersion(const char *buffer)
{
    return isFixedCommandPattern(buffer, EasycommRequestVersionLength, "VE", 2);
}


bool isEasycomm3VelocityLeft(const char *buffer)
{
    return isCommandPattern(buffer, EasycommVelocityLeftMinLength, EasycommVelocityLeftMaxLength, "VL", 2);
}


bool isEasycomm3VelocityRight(const char *buffer)
{
    return isCommandPattern(buffer, EasycommVelocityRightMinLength, EasycommVelocityRightMaxLength, "VR", 2);
}


bool isEasycomm3VelocityUp(const char *buffer)
{
    return isCommandPattern(buffer, EasycommVelocityUpMinLength, EasycommVelocityUpMaxLength, "VU", 2);
}


bool isEasycomm3VelocityDown(const char *buffer)
{
    return isCommandPattern(buffer, EasycommVelocityDownMinLength, EasycommVelocityDownMaxLength, "VD", 2);
}


bool isEasycomm3ReadConfig(const char *buffer)
{
    return isCommandPattern(buffer, EasycommReadConfigMinLength, EasycommReadConfigMaxLength, "CR", 2);
}


bool isEasycomm3WriteConfig(const char *buffer)
{
    return isCommandPattern(buffer, EasycommWriteConfigMinLength, EasycommWriteConfigMaxLength, "CW", 2);
}


bool isEasycomm3GetStatusRegister(const char *buffer)
{
    return isFixedCommandPattern(buffer, EasycommGetStatusRegisterLength, "GS", 2);
}


bool isEasycomm3GetErrorRegister(const char *buffer)
{
    return isFixedCommandPattern(buffer, EasycommGetErrorRegisterLength, "GE", 2);
}


// ----- parsers


bool readEasycomm1SingleLine(const char *buffer, EasycommData *parsed)
{
    // buffer examples:
    // - "AZaaa.a ELeee.e UPuuuuuuuuu UUU DNddddddddd DDD"
    // - "AZa.a ELeee.e UPuuu UUU DNddddddddd DDD"
    // - "AZa.a ELe.e UPuuu UUU DNddd DDD"
    char c;
    easycommSingleLine(&parsed->as.singleLine);

    uint8_t items =
    sscanf(buffer,
#ifdef ARDUINO_AVR_MEGA2560
           "%c%c%f %c%c%f %c%c%ld %c%c%c %c%c%ld %c%c%c",
#else
           "%c%c%f %c%c%f %c%c%d %c%c%c %c%c%d %c%c%c",
#endif
           &c, &c, &parsed->as.singleLine.azimuth, &c, &c, &parsed->as.singleLine.elevation, &c, &c,
           &parsed->as.singleLine.uplinkFrequency.as.uint32, &parsed->as.singleLine.modeUp[0],
           &parsed->as.singleLine.modeUp[1], &parsed->as.singleLine.modeUp[2], &c, &c,
           &parsed->as.singleLine.downlinkFrequency.as.uint32, &parsed->as.singleLine.modeDown[0],
           &parsed->as.singleLine.modeDown[1], &parsed->as.singleLine.modeDown[2]);

    return items == 18;
}


bool readEasycomm2Azimuth(const char *buffer, EasycommData *parsed)
{
    // buffer: "AZaaa.a", ..., "AZa.a"
    char c;
    easycommAzimuth(&parsed->as.azimuth);
    uint8_t items = sscanf(buffer, "%c%c%f", &c, &c, &parsed->as.azimuth.azimuth);
    return items == 3;
}


bool readEasycomm2Elevation(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "ELeee.e", ..., "ELeee.e"
    char c;
    easycommElevation(&parsed->as.elevation);
    uint8_t items = sscanf(buffer, "%c%c%f", &c, &c, &parsed->as.elevation.elevation);
    return items == 3;
}


bool readEasycomm2AzimuthElevation(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "AZaaa.a ELeee.e", "AZa.a ELeee.e", ..., "AZa.a ELe.e"
    char c;
    easycommAzimuthElevation(&parsed->as.azimuthElevation);
    uint8_t items = sscanf(buffer, "%c%c%f %c%c%f", &c, &c, &parsed->as.azimuthElevation.azimuth,
                           &c, &c, &parsed->as.azimuthElevation.elevation);
    return items == 6;
}


bool readEasycomm2ElevationAzimuth(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "ELeee.e AZaaa.a", "ELeee.e AZa.a", ..., "ELe.e AZa.a"
    char c;
    easycommAzimuthElevation(&parsed->as.azimuthElevation);
    uint8_t items = sscanf(buffer, "%c%c%f %c%c%f", &c, &c, &parsed->as.azimuthElevation.elevation,
                           &c, &c, &parsed->as.azimuthElevation.azimuth);
    return items == 6;
}


bool readEasycomm2UplinkFrequency(const char *buffer, EasycommData *parsed)
{
    // buffer examples: ""
    // char c;
    easycommUplinkFrequency(&parsed->as.uplinkFrequency);
    // uint8_t items = sscanf(buffer, "%c%c", &c, &c, xxx);
    // return items == 3;
    return false;
}


bool readEasycomm2DownlinkFrequency(const char *buffer, EasycommData *parsed)
{
    // buffer examples: ""
    // char c;
    easycommDownlinkFrequency(&parsed->as.downlinkFrequency);
    // uint8_t items = sscanf(buffer, "%c%c", &c, &c, xxx);
    // return items == 3;
    return false;
}


bool readEasycomm2UplinkMode(const char *buffer, EasycommData *parsed)
{
    // buffer examples: ""
    // char c;
    easycommUplinkMode(&parsed->as.uplinkMode);
    // uint8_t items = sscanf(buffer, "%c%c", &c, &c, xxx);
    // return items == 3;
    return false;
}


bool readEasycomm2DownlinkMode(const char *buffer, EasycommData *parsed)
{
    // buffer examples: ""
    // char c;
    easycommDownlinkMode(&parsed->as.downlinkMode);
    // uint8_t items = sscanf(buffer, "%c%c", &c, &c, xxx);
    // return items == 3;
    return false;
}


bool readEasycomm2UplinkRadioNumber(const char *buffer, EasycommData *parsed)
{
    // buffer examples: ""
    // char c;
    easycommUplinkRadioNumber(&parsed->as.uplinkRadio);
    // uint8_t items = sscanf(buffer, "%c%c", &c, &c, xxx);
    // return items == 3;
    return false;
}


bool readEasycomm2DownlinkRadioNumber(const char *buffer, EasycommData *parsed)
{
    // buffer examples: ""
    // char c;
    easycommDownlinkRadioNumber(&parsed->as.downlinkRadio);
    // uint8_t items = sscanf(buffer, "%c%c", &c, &c, xxx);
    // return items == 3;
    return false;
}


bool readEasycomm2MoveLeft(const char *buffer, EasycommData *parsed)
{
    // buffer examples: ""
    // char c;
    easycommMoveLeft(&parsed->as.moveLeft);
    // uint8_t items = sscanf(buffer, "%c%c", &c, &c, xxx);
    // return items == 3;
    return false;
}


bool readEasycomm2MoveRight(const char *buffer, EasycommData *parsed)
{
    // buffer examples: ""
    // char c;
    easycommMoveRight(&parsed->as.moveRight);
    // uint8_t items = sscanf(buffer, "%c%c", &c, &c, xxx);
    // return items == 3;
    return false;
}


bool readEasycomm2MoveUp(const char *buffer, EasycommData *parsed)
{
    // buffer examples: ""
    // char c;
    easycommMoveUp(&parsed->as.moveUp);
    // uint8_t items = sscanf(buffer, "%c%c", &c, &c, xxx);
    // return items == 3;
    return false;
}


bool readEasycomm2MoveDown(const char *buffer, EasycommData *parsed)
{
    // buffer examples: ""
    // char c;
    easycommMoveDown(&parsed->as.moveDown);
    // uint8_t items = sscanf(buffer, "%c%c", &c, &c, xxx);
    // return items == 3;
    return false;
}


bool readEasycomm2StopAzimuthMove(const char *buffer, EasycommData *parsed)
{
    // buffer examples: ""
    // char c;
    easycommStopAzimuthMove(&parsed->as.stopAzimuthMove);
    // uint8_t items = sscanf(buffer, "%c%c", &c, &c, xxx);
    // return items == 3;
    return false;
}


bool readEasycomm2StopElevationMove(const char *buffer, EasycommData *parsed)
{
    // buffer examples: ""
    // char c;
    easycommStopElevationMove(&parsed->as.stopElevationMove);
    // uint8_t items = sscanf(buffer, "%c%c", &c, &c, xxx);
    // return items == 3;
    return false;
}


bool readEasycomm2AcquisitionOfSignal(const char *buffer, EasycommData *parsed)
{
    // buffer examples: ""
    // char c;
    easycommAcquisitionOfSignal(&parsed->as.acquisitionOfSignal);
    // uint8_t items = sscanf(buffer, "%c%c", &c, &c, xxx);
    // return items == 3;
    return false;
}


bool readEasycomm2LossOfSignal(const char *buffer, EasycommData *parsed)
{
    // buffer examples: ""
    // char c;
    easycommLossOfSignal(&parsed->as.lossOfSignal);
    // uint8_t items = sscanf(buffer, "%c%c", &c, &c, xxx);
    // return items == 3;
    return false;
}


bool readEasycomm2SetOutput(const char *buffer, EasycommData *parsed)
{
    // buffer examples: ""
    // char c;
    easycommSetOutput(&parsed->as.setOutput);
    // uint8_t items = sscanf(buffer, "%c%c", &c, &c, xxx);
    // return items == 3;
    return false;
}


bool readEasycomm2ReadInput(const char *buffer, EasycommData *parsed)
{
    // buffer examples: ""
    // char c;
    easycommReadInput(&parsed->as.readInput);
    // uint8_t items = sscanf(buffer, "%c%c", &c, &c, xxx);
    // return items == 3;
    return false;
}


bool readEasycomm2ReadAnalogueInput(const char *buffer, EasycommData *parsed)
{
    // buffer examples: ""
    // char c;
    easycommReadAnalogueInput(&parsed->as.readAnalogueInput);
    // uint8_t items = sscanf(buffer, "%c%c", &c, &c, xxx);
    // return items == 3;
    return false;
}


bool readEasycomm2SetTime(const char *buffer, EasycommData *parsed)
{
    // buffer examples: ""
    // char c;
    easycommSetTime(&parsed->as.setTime);
    // uint8_t items = sscanf(buffer, "%c%c", &c, &c, xxx);
    // return items == 3;
    return false;
}


bool readEasycomm2RequestVersion(const char *buffer, EasycommData *parsed)
{
    // buffer examples: ""
    // char c;
    easycommRequestVersion(&parsed->as.requestVersion);
    // uint8_t items = sscanf(buffer, "%c%c", &c, &c, xxx);
    // return items == 3;
    return false;
}


bool readEasycomm3VelocityLeft(const char *buffer, EasycommData *parsed)
{
    // buffer examples: ""
    // char c;
    easycommVelocityLeft(&parsed->as.velocityLeft);
    // uint8_t items = sscanf(buffer, "%c%c", &c, &c, xxx);
    // return items == 3;
    return false;
}


bool readEasycomm3VelocityRight(const char *buffer, EasycommData *parsed)
{
    // buffer examples: ""
    // char c;
    easycommVelocityRight(&parsed->as.velocityRight);
    // uint8_t items = sscanf(buffer, "%c%c", &c, &c, xxx);
    // return items == 3;
    return false;
}


bool readEasycomm3VelocityUp(const char *buffer, EasycommData *parsed)
{
    // buffer examples: ""
    // char c;
    easycommVelocityUp(&parsed->as.velocityUp);
    // uint8_t items = sscanf(buffer, "%c%c", &c, &c, xxx);
    // return items == 3;
    return false;
}


bool readEasycomm3VelocityDown(const char *buffer, EasycommData *parsed)
{
    // buffer examples: ""
    // char c;
    easycommVelocityDown(&parsed->as.velocityDown);
    // uint8_t items = sscanf(buffer, "%c%c", &c, &c, xxx);
    // return items == 3;
    return false;
}


bool readEasycomm3ReadConfig(const char *buffer, EasycommData *parsed)
{
    // buffer examples: ""
    // char c;
    easycommReadConfig(&parsed->as.readConfig);
    // uint8_t items = sscanf(buffer, "%c%c", &c, &c, xxx);
    // return items == 3;
    return false;
}


bool readEasycomm3WriteConfig(const char *buffer, EasycommData *parsed)
{
    // buffer examples: ""
    // char c;
    easycommWriteConfig(&parsed->as.writeConfig);
    // uint8_t items = sscanf(buffer, "%c%c", &c, &c, xxx);
    // return items == 3;
    return false;
}


bool readEasycomm3GetStatusRegister(const char *buffer, EasycommData *parsed)
{
    // buffer examples: ""
    // char c;
    easycommGetStatusRegister(&parsed->as.getStatusRegister);
    // uint8_t items = sscanf(buffer, "%c%c", &c, &c, xxx);
    // return items == 3;
    return false;
}


bool readEasycomm3GetErrorRegister(const char *buffer, EasycommData *parsed)
{
    // buffer examples: ""
    // char c;
    easycommGetErrorRegister(&parsed->as.getErrorRegister);
    // uint8_t items = sscanf(buffer, "%c%c", &c, &c, xxx);
    // return items == 3;
    return false;
}
