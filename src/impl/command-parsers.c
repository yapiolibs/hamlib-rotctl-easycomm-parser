#include "../easycomm-parser-types-ctors.h"
#include "../easycomm-parser.h"
#include <stdio.h>
#include <string.h> // size_t

static bool
isDynamicLengthCommandPattern(const char *buffer, size_t min_length, size_t max_length, char *prefix, size_t prefix_length)
{
    if(buffer == NULL || prefix == NULL)
        return false;

    size_t len = strlen(buffer);
    if(min_length <= len && len <= max_length)
        return 0 == memcmp(buffer, prefix, prefix_length);

    return false;
}

static bool isFixedLengthCommandPattern(const char *buffer, size_t length, char *prefix, size_t prefix_length)
{
    if(buffer == NULL || prefix == NULL)
        return false;

    if(length == strlen(buffer))
        return 0 == memcmp(buffer, prefix, prefix_length);

    return false;
}

// ----- predicates

bool fallbackPredicate(const char *buffer) { return true; }


bool isEasycomm1SingleLine(const char *buffer)
{
    return isDynamicLengthCommandPattern(buffer, EasycommSingleLineMinLength,
                                         EasycommSingleLineMaxLength, "AZ", 2);
}


bool isEasycomm2Azimuth(const char *buffer)
{
    return isDynamicLengthCommandPattern(buffer, EasycommAzimuthMinLength, EasycommAzimuthMaxLength, "AZ", 2);
}


bool isEasycomm2Elevation(const char *buffer)
{
    return isDynamicLengthCommandPattern(buffer, EasycommElevationMinLength,
                                         EasycommElevationMaxLength, "EL", 2);
}


bool isEasycomm2UplinkFrequency(const char *buffer)
{
    return isDynamicLengthCommandPattern(buffer, EasycommUplinkFrequencyMinLength,
                                         EasycommUplinkFrequencyMaxLength, "UP", 2);
}


bool isEasycomm2DownlinkFrequency(const char *buffer)
{
    return isDynamicLengthCommandPattern(buffer, EasycommDownlinkFrequencyMinLength,
                                         EasycommDownlinkFrequencyMaxLength, "DN", 2);
}


bool isEasycomm2UplinkMode(const char *buffer)
{
    return isDynamicLengthCommandPattern(buffer, EasycommUplinkModeMinLength,
                                         EasycommUplinkModeMaxLength, "UM", 2);
}


bool isEasycomm2DownlinkMode(const char *buffer)
{
    return isDynamicLengthCommandPattern(buffer, EasycommDownlinkModeMinLength,
                                         EasycommDownlinkModeMaxLength, "DM", 2);
}


bool isEasycomm2UplinkRadioNumber(const char *buffer)
{
    return isDynamicLengthCommandPattern(buffer, EasycommUplinkRadioNumberMinLength,
                                         EasycommUplinkRadioNumberMaxLength, "UR", 2);
}


bool isEasycomm2DownlinkRadioNumber(const char *buffer)
{
    return isDynamicLengthCommandPattern(buffer, EasycommUplinkRadioNumberMinLength,
                                         EasycommUplinkRadioNumberMaxLength, "DR", 2);
}


bool isEasycomm2MoveLeft(const char *buffer)
{
    return isFixedLengthCommandPattern(buffer, EasycommMoveLeftLength, "ML", 2);
}


bool isEasycomm2MoveRight(const char *buffer)
{
    return isFixedLengthCommandPattern(buffer, EasycommMoveRightLength, "MR", 2);
}


bool isEasycomm2MoveUp(const char *buffer)
{
    return isFixedLengthCommandPattern(buffer, EasycommMoveUpLength, "MU", 2);
}


bool isEasycomm2MoveDown(const char *buffer)
{
    return isFixedLengthCommandPattern(buffer, EasycommMoveDownLength, "MD", 2);
}


bool isEasycomm2StopAzimuthMove(const char *buffer)
{
    return isFixedLengthCommandPattern(buffer, EasycommStopAzimuthMoveLength, "SA", 2);
}


bool isEasycomm2StopElevationMove(const char *buffer)
{
    return isFixedLengthCommandPattern(buffer, EasycommStopElevationMoveLength, "SE", 2);
}


bool isEasycomm2AcquisitionOfSignal(const char *buffer)
{
    return isFixedLengthCommandPattern(buffer, EasycommAcquisitionOfSignalLength, "AO", 2);
}


bool isEasycomm2LossOfSignal(const char *buffer)
{
    return isFixedLengthCommandPattern(buffer, EasycommLossOfSignalLength, "LO", 2);
}


bool isEasycomm2SetOutput(const char *buffer)
{
    return isDynamicLengthCommandPattern(buffer, EasycommSetOutputMinLength,
                                         EasycommSetOutputMaxLength, "OP", 2);
}


bool isEasycomm2ReadInput(const char *buffer)
{
    return isDynamicLengthCommandPattern(buffer, EasycommReadInputMinLength,
                                         EasycommReadInputMaxLength, "IP", 2);
}


bool isEasycomm2ReadAnalogueInput(const char *buffer)
{
    return isDynamicLengthCommandPattern(buffer, EasycommReadAnalogueInputMinLength,
                                         EasycommReadAnalogueInputMaxLength, "AN", 2);
}


bool isEasycomm2SetTime(const char *buffer)
{
    return isDynamicLengthCommandPattern(buffer, EasycommSetTimeMinLength, EasycommSetTimeMaxLength, "ST", 2);
}


bool isEasycomm2RequestVersion(const char *buffer)
{
    return isFixedLengthCommandPattern(buffer, EasycommRequestVersionLength, "VE", 2);
}


bool isEasycomm3VelocityLeft(const char *buffer)
{
    return isDynamicLengthCommandPattern(buffer, EasycommVelocityLeftMinLength,
                                         EasycommVelocityLeftMaxLength, "VL", 2);
}


bool isEasycomm3VelocityRight(const char *buffer)
{
    return isDynamicLengthCommandPattern(buffer, EasycommVelocityRightMinLength,
                                         EasycommVelocityRightMaxLength, "VR", 2);
}


bool isEasycomm3VelocityUp(const char *buffer)
{
    return isDynamicLengthCommandPattern(buffer, EasycommVelocityUpMinLength,
                                         EasycommVelocityUpMaxLength, "VU", 2);
}


bool isEasycomm3VelocityDown(const char *buffer)
{
    return isDynamicLengthCommandPattern(buffer, EasycommVelocityDownMinLength,
                                         EasycommVelocityDownMaxLength, "VD", 2);
}


bool isEasycomm3ReadConfig(const char *buffer)
{
    return isDynamicLengthCommandPattern(buffer, EasycommReadConfigMinLength,
                                         EasycommReadConfigMaxLength, "CR", 2);
}


bool isEasycomm3WriteConfig(const char *buffer)
{
    return isDynamicLengthCommandPattern(buffer, EasycommWriteConfigMinLength,
                                         EasycommWriteConfigMaxLength, "CW", 2);
}


bool isEasycomm3GetStatusRegister(const char *buffer)
{
    return isFixedLengthCommandPattern(buffer, EasycommGetStatusRegisterLength, "GS", 2);
}


bool isEasycomm3GetErrorRegister(const char *buffer)
{
    return isFixedLengthCommandPattern(buffer, EasycommGetErrorRegisterLength, "GE", 2);
}


// ----- parsers


bool fallbackParser(const char *buffer, EasycommData *parsed)
{
    parsed->commandId = EasycommIdInvalid;
    return false;
}


bool readEasycomm1SingleLine(const char *buffer, EasycommData *parsed)
{
    // buffer examples:
    // - "AZaaa.a ELeee.e UPuuuuuuuuu UUU DNddddddddd DDD"
    // - AZ/EL: "ddd.d", "dd.d", "d.d", ".d"
    // - UP/DN: "fffffffff", ..., "f"
    // - "UUU", "UU", "U"
    // - "DDD", "DD", "D"
    char c;
    easycommSingleLine(&parsed->as.singleLine);
    return 14 ==
           sscanf(buffer,
#ifdef ARDUINO_AVR_MEGA2560
                  "%c%c%f %c%c%f %c%c%lu %s %c%c%lu %s", // TODO limit mode %s to max 3 letters %3s
#else
                  "%c%c%f %c%c%f %c%c%u %s %c%c%u %s", // TODO limit mode %s to max 3 letters %3s
#endif
                  &c, &c, &parsed->as.singleLine.azimuth, &c, &c, &parsed->as.singleLine.elevation, &c,
                  &c, &parsed->as.singleLine.uplinkFrequency.as.uint32, parsed->as.singleLine.modeUp,
                  &c, &c, &parsed->as.singleLine.downlinkFrequency.as.uint32, parsed->as.singleLine.modeDown);
}


bool readEasycomm2Azimuth(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "AZaaa.a", "AZaa.a", "AZa.a", "AZ.a"
    char c;
    easycommAzimuth(&parsed->as.azimuth);
    return 3 == sscanf(buffer, "%c%c%f", &c, &c, &parsed->as.azimuth.azimuth);
}


bool readEasycomm2Elevation(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "ELeee.e", "ELee.e", "ELe.e", "EL.e"
    char c;
    easycommElevation(&parsed->as.elevation);
    return 3 == sscanf(buffer, "%c%c%f", &c, &c, &parsed->as.elevation.elevation);
}


bool readEasycomm2UplinkFrequency(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "UFuuuuuuuuu", ..., "UFu"
    char c;
    easycommUplinkFrequency(&parsed->as.uplinkFrequency);
    return 3 == sscanf(buffer,
#ifdef ARDUINO_AVR_MEGA2560
                       "%c%c%lu",
#else
                       "%c%c%u",
#endif
                       &c, &c, &parsed->as.uplinkFrequency.frequency.as.uint32);
}


bool readEasycomm2DownlinkFrequency(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "DNddddddddd", ..., "DNd"
    char c;
    easycommDownlinkFrequency(&parsed->as.downlinkFrequency);
    return 3 == sscanf(buffer,
#ifdef ARDUINO_AVR_MEGA2560
                       "%c%c%lu",
#else
                       "%c%c%u",
#endif
                       &c, &c, &parsed->as.downlinkFrequency.frequency.as.uint32);
}


bool readEasycomm2UplinkMode(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "UMmmm", "UMmm", "UMm"
    char c;
    easycommUplinkMode(&parsed->as.uplinkMode);
    return 3 <= sscanf(buffer, "%c%c%c%c%c", &c, &c, &parsed->as.uplinkMode.mode[0],
                       &parsed->as.uplinkMode.mode[1], &parsed->as.uplinkMode.mode[2]);
}


bool readEasycomm2DownlinkMode(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "DMmmm", "DMmm", "DMm"
    char c;
    easycommDownlinkMode(&parsed->as.downlinkMode);
    return 3 <= sscanf(buffer, "%c%c%c%c%c", &c, &c, &parsed->as.downlinkMode.mode[0],
                       &parsed->as.downlinkMode.mode[1], &parsed->as.downlinkMode.mode[2]);
}


bool readEasycomm2UplinkRadioNumber(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "URnnn", "URnn", "URn"
    char c;
    easycommUplinkRadioNumber(&parsed->as.uplinkRadio);
    return 3 == sscanf(buffer,
#ifdef ARDUINO_AVR_MEGA2560
                       "%c%c%u",
#else
                       "%c%c%hu",
#endif
                       &c, &c, &parsed->as.uplinkRadio.number);
}


bool readEasycomm2DownlinkRadioNumber(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "DRnnn", "DRnn", "DRn"
    char c;
    easycommDownlinkRadioNumber(&parsed->as.downlinkRadio);
    return 3 == sscanf(buffer,
#ifdef ARDUINO_AVR_MEGA2560
                       "%c%c%u",
#else
                       "%c%c%hu",
#endif
                       &c, &c, &parsed->as.downlinkRadio.number);
}


bool readEasycomm2MoveLeft(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "ML"
    easycommMoveLeft(&parsed->as.moveLeft);
    return true;
}


bool readEasycomm2MoveRight(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "MR"
    easycommMoveRight(&parsed->as.moveRight);
    return true;
}


bool readEasycomm2MoveUp(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "MU"
    easycommMoveUp(&parsed->as.moveUp);
    return true;
}


bool readEasycomm2MoveDown(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "MD"
    easycommMoveDown(&parsed->as.moveDown);
    return true;
}


bool readEasycomm2StopAzimuthMove(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "SA"
    easycommStopAzimuthMove(&parsed->as.stopAzimuthMove);
    return true;
}


bool readEasycomm2StopElevationMove(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "SE"
    easycommStopElevationMove(&parsed->as.stopElevationMove);
    return true;
}


bool readEasycomm2AcquisitionOfSignal(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "AO"
    easycommAcquisitionOfSignal(&parsed->as.acquisitionOfSignal);
    return true;
}


bool readEasycomm2LossOfSignal(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "LO"
    easycommLossOfSignal(&parsed->as.lossOfSignal);
    return true;
}


bool readEasycomm2SetOutput(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "OPnnn,v", "OPnn,v", "OPn,v"
    char c, value;
    easycommSetOutput(&parsed->as.setOutput);
    size_t items = sscanf(buffer,
#ifdef ARDUINO_AVR_MEGA2560
                          "%c%c%u%c%c",
#else
                          "%c%c%hu%c%c",
#endif
                          &c, &c, &parsed->as.setOutput.number, &c, &value);
    parsed->as.setOutput.value = (value == '0') ? false : true;
    return 5 == items;
}


bool readEasycomm2ReadInput(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "IPnnn", "IPn", "IPn"
    char c;
    easycommReadInput(&parsed->as.readInput);
    return 3 == sscanf(buffer,
#ifdef ARDUINO_AVR_MEGA2560
                       "%c%c%u",
#else
                       "%c%c%hu",
#endif
                       &c, &c, &parsed->as.readInput.number);
}


bool readEasycomm2ReadAnalogueInput(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "ANnnn", "ANn", "ANn"
    char c;
    easycommReadAnalogueInput(&parsed->as.readAnalogueInput);
    return 3 == sscanf(buffer,
#ifdef ARDUINO_AVR_MEGA2560
                       "%c%c%u",
#else
                       "%c%c%hu",
#endif
                       &c, &c, &parsed->as.readAnalogueInput.number);
}


bool readEasycomm2SetTime(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "STyy:MM:dd:hh:mm:ss"
    char c;
    easycommSetTime(&parsed->as.setTime);
    return 8 == sscanf(buffer, "%c%c%hhu:%hhu:%hhu:%hhu:%hhu:%hhu", &c, &c, &parsed->as.setTime.year,
                       &parsed->as.setTime.month, &parsed->as.setTime.day, &parsed->as.setTime.hour,
                       &parsed->as.setTime.minute, &parsed->as.setTime.second);
}


bool readEasycomm2RequestVersion(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "VE"
    easycommRequestVersion(&parsed->as.requestVersion);
    return true;
}


bool readEasycomm3VelocityLeft(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "VLddd", "VLdd", "VLd"
    char c;
    easycommVelocityLeft(&parsed->as.velocityLeft);
    return 3 == sscanf(buffer,

#ifdef ARDUINO_AVR_MEGA2560
                       "%c%c%u",
#else
                       "%c%c%hu",
#endif
                       &c, &c, &parsed->as.velocityLeft.milliDegSecond);
}


bool readEasycomm3VelocityRight(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "VRddd", "VRdd", "VRd"
    char c;
    easycommVelocityRight(&parsed->as.velocityRight);
    return 3 == sscanf(buffer,
#ifdef ARDUINO_AVR_MEGA2560
                       "%c%c%u",
#else
                       "%c%c%hu",
#endif
                       &c, &c, &parsed->as.velocityRight.milliDegSecond);
}


bool readEasycomm3VelocityUp(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "VUddd", "VUdd", "VUd"
    char c;
    easycommVelocityUp(&parsed->as.velocityUp);
    return 3 == sscanf(buffer,
#ifdef ARDUINO_AVR_MEGA2560
                       "%c%c%u",
#else
                       "%c%c%hu",
#endif
                       &c, &c, &parsed->as.velocityUp.milliDegSecond);
}


bool readEasycomm3VelocityDown(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "VDddd", "VDdd", "VDd"
    char c;
    easycommVelocityDown(&parsed->as.velocityDown);
    return 3 == sscanf(buffer,
#ifdef ARDUINO_AVR_MEGA2560
                       "%c%c%u",
#else
                       "%c%c%hu",
#endif
                       &c, &c, &parsed->as.velocityDown.milliDegSecond);
}


bool readEasycomm3ReadConfig(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "CRrrr", "CRrr", "CRr"
    char c;
    easycommReadConfig(&parsed->as.readConfig);
    return 3 == sscanf(buffer,
#ifdef ARDUINO_AVR_MEGA2560
                       "%c%c%u",
#else
                       "%c%c%hu",
#endif
                       &c, &c, &parsed->as.readConfig.registerNumber);
}


bool readEasycomm3WriteConfig(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "CWnnn,vvvvvvvvv", ..., "CWn,v"
    char c;
    easycommWriteConfig(&parsed->as.writeConfig);
    return 4 == sscanf(buffer,
#ifdef ARDUINO_AVR_MEGA2560
                       "%c%c%u,%s",
#else
                       "%c%c%hu,%s",
#endif
                       &c, &c, &parsed->as.writeConfig.registerNumber,
                       parsed->as.writeConfig.value.as.str);
}


bool readEasycomm3GetStatusRegister(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "GS"
    easycommGetStatusRegister(&parsed->as.getStatusRegister);
    return true;
}


bool readEasycomm3GetErrorRegister(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "GE"
    easycommGetErrorRegister(&parsed->as.getErrorRegister);
    return true;
}
