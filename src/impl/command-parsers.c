#include "../easycomm-parser-types-ctors.h"
#include "../easycomm-parser.h"
#include <stdio.h>
#include <string.h> // size_t

static bool
isDynamicLengthCommandPattern(const char *buffer, size_t min_length, size_t max_length, const char *prefix, size_t prefix_length)
{
    if(buffer == NULL || prefix == NULL)
        return false;

    size_t len = strlen(buffer);
    if(min_length <= len && len <= max_length)
        return 0 == memcmp(buffer, prefix, prefix_length);

    return false;
}

static bool isFixedLengthCommandPattern(const char *buffer, size_t length, const char *prefix, size_t prefix_length)
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


bool isEasycomm2SetAzimuth(const char *buffer)
{
    return isDynamicLengthCommandPattern(buffer, EasycommSetAzimuthMinLength,
                                         EasycommSetAzimuthMaxLength, "AZ", 2);
}


bool isEasycomm2GetAzimuth(const char *buffer)
{
    return isFixedLengthCommandPattern(buffer, EasycommGetAzimuthLength, "AZ", 2);
}


bool isEasycomm2SetElevation(const char *buffer)
{
    return isDynamicLengthCommandPattern(buffer, EasycommSetElevationMinLength,
                                         EasycommSetElevationMaxLength, "EL", 2);
}


bool isEasycomm2GetElevation(const char *buffer)
{
    return isFixedLengthCommandPattern(buffer, EasycommGetElevationLength, "EL", 2);
}


bool isEasycomm2SetUplinkFrequency(const char *buffer)
{
    return isDynamicLengthCommandPattern(buffer, EasycommSetUplinkFrequencyMinLength,
                                         EasycommSetUplinkFrequencyMaxLength, "UP", 2);
}


bool isEasycomm2GetUplinkFrequency(const char *buffer)
{
    return isFixedLengthCommandPattern(buffer, EasycommGetUplinkFrequencyLength, "UP", 2);
}


bool isEasycomm2SetDownlinkFrequency(const char *buffer)
{
    return isDynamicLengthCommandPattern(buffer, EasycommSetDownlinkFrequencyMinLength,
                                         EasycommSetDownlinkFrequencyMaxLength, "DN", 2);
}


bool isEasycomm2GetDownlinkFrequency(const char *buffer)
{
    return isFixedLengthCommandPattern(buffer, EasycommGetDownlinkFrequencyLength, "DN", 2);
}


bool isEasycomm2SetUplinkMode(const char *buffer)
{
    return isDynamicLengthCommandPattern(buffer, EasycommSetUplinkModeMinLength,
                                         EasycommSetUplinkModeMaxLength, "UM", 2);
}


bool isEasycomm2GetUplinkMode(const char *buffer)
{
    return isFixedLengthCommandPattern(buffer, EasycommGetUplinkModeLength, "UM", 2);
}


bool isEasycomm2SetDownlinkMode(const char *buffer)
{
    return isDynamicLengthCommandPattern(buffer, EasycommSetDownlinkModeMinLength,
                                         EasycommSetDownlinkModeMaxLength, "DM", 2);
}


bool isEasycomm2GetDownlinkMode(const char *buffer)
{
    return isFixedLengthCommandPattern(buffer, EasycommGetDownlinkModeLength, "DM", 2);
}


bool isEasycomm2SetUplinkRadio(const char *buffer)
{
    return isDynamicLengthCommandPattern(buffer, EasycommSetUplinkRadioMinLength,
                                         EasycommSetUplinkRadioMaxLength, "UR", 2);
}


bool isEasycomm2GetUplinkRadio(const char *buffer)
{
    return isFixedLengthCommandPattern(buffer, EasycommGetUplinkRadioLength, "UR", 2);
}


bool isEasycomm2SetDownlinkRadio(const char *buffer)
{
    return isDynamicLengthCommandPattern(buffer, EasycommSetUplinkRadioMinLength,
                                         EasycommSetUplinkRadioMaxLength, "DR", 2);
}


bool isEasycomm2GetDownlinkRadio(const char *buffer)
{
    return isFixedLengthCommandPattern(buffer, EasycommGetDownlinkRadioLength, "DR", 2);
}


bool isEasycomm2DoMoveLeft(const char *buffer)
{
    return isFixedLengthCommandPattern(buffer, EasycommDoMoveLeftLength, "ML", 2);
}


bool isEasycomm2DoMoveRight(const char *buffer)
{
    return isFixedLengthCommandPattern(buffer, EasycommDoMoveRightLength, "MR", 2);
}


bool isEasycomm2DoMoveUp(const char *buffer)
{
    return isFixedLengthCommandPattern(buffer, EasycommDoMoveUpLength, "MU", 2);
}


bool isEasycomm2DoMoveDown(const char *buffer)
{
    return isFixedLengthCommandPattern(buffer, EasycommDoMoveDownLength, "MD", 2);
}


bool isEasycomm2DoStopAzimuthMove(const char *buffer)
{
    return isFixedLengthCommandPattern(buffer, EasycommDoStopAzimuthMoveLength, "SA", 2);
}


bool isEasycomm2DoStopElevationMove(const char *buffer)
{
    return isFixedLengthCommandPattern(buffer, EasycommDoStopElevationMoveLength, "SE", 2);
}


bool isEasycomm2AcquisitionOfSignal(const char *buffer)
{
    return isFixedLengthCommandPattern(buffer, EasycommAcquisitionOfSignalLength, "AO", 2);
}


bool isEasycomm2LossOfSignal(const char *buffer)
{
    return isFixedLengthCommandPattern(buffer, EasycommLossOfSignalLength, "LO", 2);
}


bool isEasycomm2SetDigitalOutput(const char *buffer)
{
    return isDynamicLengthCommandPattern(buffer, EasycommSetDigitalOutputMinLength,
                                         EasycommSetDigitalOutputMaxLength, "OP", 2);
}


bool isEasycomm2GetDigitalInput(const char *buffer)
{
    return isDynamicLengthCommandPattern(buffer, EasycommGetDigitalInputMinLength,
                                         EasycommGetDigitalInputMaxLength, "IP", 2);
}


bool isEasycomm2GetAnalogueInput(const char *buffer)
{
    return isDynamicLengthCommandPattern(buffer, EasycommGetAnalogueInputMinLength,
                                         EasycommGetAnalogueInputMaxLength, "AN", 2);
}


bool isEasycomm2SetTime(const char *buffer)
{
    return isDynamicLengthCommandPattern(buffer, EasycommSetTimeMinLength, EasycommSetTimeMaxLength, "ST", 2);
}


bool isEasycomm2GetTime(const char *buffer)
{
    return isFixedLengthCommandPattern(buffer, EasycommGetTimeLength, "ST", 2);
}


bool isEasycomm2GetVersion(const char *buffer)
{
    return isFixedLengthCommandPattern(buffer, EasycommGetVersionLength, "VE", 2);
}


bool isEasycomm3SetVelocityLeft(const char *buffer)
{
    return isDynamicLengthCommandPattern(buffer, EasycommSetVelocityLeftMinLength,
                                         EasycommSetVelocityLeftMaxLength, "VL", 2);
}


bool isEasycomm3GetVelocityLeft(const char *buffer)
{
    return isFixedLengthCommandPattern(buffer, EasycommGetVelocityLeftLength, "VL", 2);
}


bool isEasycomm3SetVelocityRight(const char *buffer)
{
    return isDynamicLengthCommandPattern(buffer, EasycommSetVelocityRightMinLength,
                                         EasycommSetVelocityRightMaxLength, "VR", 2);
}


bool isEasycomm3GetVelocityRight(const char *buffer)
{
    return isFixedLengthCommandPattern(buffer, EasycommGetVelocityRightLength, "VR", 2);
}


bool isEasycomm3SetVelocityUp(const char *buffer)
{
    return isDynamicLengthCommandPattern(buffer, EasycommSetVelocityUpMinLength,
                                         EasycommSetVelocityUpMaxLength, "VU", 2);
}


bool isEasycomm3GetVelocityUp(const char *buffer)
{
    return isFixedLengthCommandPattern(buffer, EasycommGetVelocityUpLength, "VU", 2);
}


bool isEasycomm3SetVelocityDown(const char *buffer)
{
    return isDynamicLengthCommandPattern(buffer, EasycommSetVelocityDownMinLength,
                                         EasycommSetVelocityDownMaxLength, "VD", 2);
}


bool isEasycomm3GetVelocityDown(const char *buffer)
{
    return isFixedLengthCommandPattern(buffer, EasycommGetVelocityDownLength, "VD", 2);
}


bool isEasycomm3GetConfigRegister(const char *buffer)
{
    return isDynamicLengthCommandPattern(buffer, EasycommGetConfigRegisterMinLength,
                                         EasycommGetConfigRegisterMaxLength, "CR", 2);
}


bool isEasycomm3SetConfigRegister(const char *buffer)
{
    return isDynamicLengthCommandPattern(buffer, EasycommSetConfigRegisterMinLength,
                                         EasycommSetConfigRegisterMaxLength, "CW", 2);
}


bool isEasycomm3GetStatusRegister(const char *buffer)
{
    return isFixedLengthCommandPattern(buffer, EasycommGetStatusRegisterLength, "GS", 2);
}


bool isEasycomm3GetErrorRegister(const char *buffer)
{
    return isFixedLengthCommandPattern(buffer, EasycommGetErrorRegisterLength, "GE", 2);
}


bool isEasycommDoReset(const char *buffer)
{
    return isFixedLengthCommandPattern(buffer, EasycommDoResetLength, "RESET", 5);
}


bool isEasycommDoPark(const char *buffer)
{
    return isFixedLengthCommandPattern(buffer, EasycommDoParkLength, "PARK", 4);
}


// ----- parsers


bool fallbackParser(const char *buffer, EasycommData *parsed)
{
    parsed->commandId = EasycommIdInvalid;
    return false;
}


bool parseEasycomm1SingleLine(const char *buffer, EasycommData *parsed)
{
    // buffer examples:
    // - "AZaaa.a ELeee.e UPuuuuuuuuu UUU DNddddddddd DDD"
    // - AZ/EL: "ddd.d", "dd.d", "d.d", ".d"
    // - UP/DN: "fffffffff", ..., "f"
    // - "UUU", "UU", "U"
    // - "DDD", "DD", "D"
    char c;
    easycommSingleLine(&parsed->as.singleLine);
    return 14 == sscanf(buffer,

// TODO limit mode %s to max 3 letters %3s
#if defined(ARDUINO_ARCH_AVR)
                        "%c%c%f %c%c%f %c%c%lu %s %c%c%lu %s",
#elif defined(ARDUINO_ARCH_STM32)
                        "%c%c%f %c%c%f %c%c%lu %s %c%c%lu %s",
#elif defined(ARDUINO_ARCH_ESP8266)
                        "%c%c%f %c%c%f %c%c%u %s %c%c%u %s",
#elif defined(ARDUINO_ARCH_ESP32)
                        "%c%c%f %c%c%f %c%c%u %s %c%c%u %s",
#else // assume native platform
                        "%c%c%f %c%c%f %c%c%u %s %c%c%u %s",
#endif
                        &c, &c, &parsed->as.singleLine.azimuth, &c, &c, &parsed->as.singleLine.elevation,
                        &c, &c, &parsed->as.singleLine.uplinkFrequency.as.uint32,
                        parsed->as.singleLine.modeUp, &c, &c,
                        &parsed->as.singleLine.downlinkFrequency.as.uint32, parsed->as.singleLine.modeDown);
}


bool parseEasycomm2SetAzimuth(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "AZaaa.a", "AZaa.a", "AZa.a", "AZ.a"
    char c;
    easycommSetAzimuth(&parsed->as.setAzimuth);
    return 3 == sscanf(buffer, "%c%c%f", &c, &c, &parsed->as.setAzimuth.azimuth);
}


bool parseEasycomm2GetAzimuth(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "AZ"
    easycommGetAzimuth(&parsed->as.getAzimuth);
    return true;
}


bool parseEasycomm2SetElevation(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "ELeee.e", "ELee.e", "ELe.e", "EL.e"
    char c;
    easycommSetElevation(&parsed->as.setElevation);
    return 3 == sscanf(buffer, "%c%c%f", &c, &c, &parsed->as.setElevation.elevation);
}


bool parseEasycomm2GetElevation(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "EL"
    easycommGetElevation(&parsed->as.getElevation);
    return true;
}


bool parseEasycomm2SetUplinkFrequency(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "UFuuuuuuuuu", ..., "UFu"
    char c;
    easycommSetUplinkFrequency(&parsed->as.setUplinkFrequency);
    return 3 == sscanf(buffer,

#if defined(ARDUINO_ARCH_AVR)
                       "%c%c%lu",
#elif defined(ARDUINO_ARCH_STM32)
                       "%c%c%lu",
#elif defined(ARDUINO_ARCH_ESP8266)
                       "%c%c%u",
#elif defined(ARDUINO_ARCH_ESP32)
                       "%c%c%u",
#else // assume native platform
                       "%c%c%u",
#endif
                       &c, &c, &parsed->as.setUplinkFrequency.frequency.as.uint32);
}


bool parseEasycomm2GetUplinkFrequency(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "UF"
    easycommGetUplinkFrequency(&parsed->as.getUplinkFrequency);
    return true;
}


bool parseEasycomm2SetDownlinkFrequency(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "DNddddddddd", ..., "DNd"
    char c;
    easycommSetDownlinkFrequency(&parsed->as.setDownlinkFrequency);
    return 3 == sscanf(buffer,

#if defined(ARDUINO_ARCH_AVR)
                       "%c%c%lu",
#elif defined(ARDUINO_ARCH_STM32)
                       "%c%c%lu",
#elif defined(ARDUINO_ARCH_ESP8266)
                       "%c%c%u",
#elif defined(ARDUINO_ARCH_ESP32)
                       "%c%c%u",
#else // assume native platform
                       "%c%c%u",
#endif
                       &c, &c, &parsed->as.setDownlinkFrequency.frequency.as.uint32);
}


bool parseEasycomm2GetDownlinkFrequency(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "DF"
    easycommGetDownlinkFrequency(&parsed->as.getDownlinkFrequency);
    return true;
}


bool parseEasycomm2SetUplinkMode(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "UMmmm", "UMmm", "UMm"
    char c;
    easycommSetUplinkMode(&parsed->as.setUplinkMode);
    return 3 <= sscanf(buffer, "%c%c%c%c%c", &c, &c, &parsed->as.setUplinkMode.mode[0],
                       &parsed->as.setUplinkMode.mode[1], &parsed->as.setUplinkMode.mode[2]);
}


bool parseEasycomm2GetUplinkMode(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "UM"
    easycommGetUplinkMode(&parsed->as.getUplinkMode);
    return true;
}


bool parseEasycomm2SetDownlinkMode(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "DMmmm", "DMmm", "DMm"
    char c;
    easycommSetDownlinkMode(&parsed->as.setDownlinkMode);
    return 3 <= sscanf(buffer, "%c%c%c%c%c", &c, &c, &parsed->as.setDownlinkMode.mode[0],
                       &parsed->as.setDownlinkMode.mode[1], &parsed->as.setDownlinkMode.mode[2]);
}


bool parseEasycomm2GetDownlinkMode(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "UM"
    easycommGetDownlinkMode(&parsed->as.getDownlinkMode);
    return true;
}


bool parseEasycomm2SetUplinkRadio(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "URnnn", "URnn", "URn"
    char c;
    easycommSetUplinkRadio(&parsed->as.setUplinkRadio);
    return 3 == sscanf(buffer,
#if defined(ARDUINO_ARCH_AVR)
                       "%c%c%u",
#elif defined(ARDUINO_ARCH_STM32) || defined(ARDUINO_ARCH_ESP8266) || defined(ARDUINO_ARCH_ESP32)
                       "%c%c%hu",
#else // assume native platform
                       "%c%c%hu",
#endif
                       &c, &c, &parsed->as.setUplinkRadio.number);
}


bool parseEasycomm2GetUplinkRadio(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "UR"
    easycommGetUplinkRadio(&parsed->as.getUplinkRadio);
    return true;
}


bool parseEasycomm2SetDownlinkRadio(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "DRnnn", "DRnn", "DRn"
    char c;
    easycommSetDownlinkRadio(&parsed->as.setDownlinkRadio);
    return 3 == sscanf(buffer,
#if defined(ARDUINO_ARCH_AVR)
                       "%c%c%u",
#elif defined(ARDUINO_ARCH_STM32)
                       "%c%c%hu",
#elif defined(ARDUINO_ARCH_ESP8266)
                       "%c%c%hu",
#elif defined(ARDUINO_ARCH_ESP32)
                       "%c%c%hu",
#else // assume native platform
                       "%c%c%hu",
#endif
                       &c, &c, &parsed->as.setDownlinkRadio.number);
}


bool parseEasycomm2GetDownlinkRadio(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "DR"
    easycommGetDownlinkRadio(&parsed->as.getDownlinkRadio);
    return true;
}


bool parseEasycomm2DoMoveLeft(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "ML"
    easycommDoMoveLeft(&parsed->as.doMoveLeft);
    return true;
}


bool parseEasycomm2DoMoveRight(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "MR"
    easycommDoMoveRight(&parsed->as.doMoveRight);
    return true;
}


bool parseEasycomm2DoMoveUp(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "MU"
    easycommDoMoveUp(&parsed->as.doMoveUp);
    return true;
}


bool parseEasycomm2DoMoveDown(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "MD"
    easycommDoMoveDown(&parsed->as.doMoveDown);
    return true;
}


bool parseEasycomm2DoStopAzimuthMove(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "SA"
    easycommDoStopAzimuthMove(&parsed->as.doStopAzimuthMove);
    return true;
}


bool parseEasycomm2DoStopElevationMove(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "SE"
    easycommDoStopElevationMove(&parsed->as.doStopElevationMove);
    return true;
}


bool parseEasycomm2AcquisitionOfSignal(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "AO"
    easycommAcquisitionOfSignal(&parsed->as.acquisitionOfSignal);
    return true;
}


bool parseEasycomm2LossOfSignal(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "LO"
    easycommLossOfSignal(&parsed->as.lossOfSignal);
    return true;
}


bool parseEasycomm2SetDigitalOutput(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "OPnnn,v", "OPnn,v", "OPn,v"
    char c, value;
    easycommSetDigitalOutput(&parsed->as.setDigitalOutput);
    size_t items = sscanf(buffer,
#if defined(ARDUINO_ARCH_AVR)
                          "%c%c%u%c%c",
#elif defined(ARDUINO_ARCH_STM32)
                          "%c%c%hu%c%c",
#elif defined(ARDUINO_ARCH_ESP8266)
                          "%c%c%hu%c%c",
#elif defined(ARDUINO_ARCH_ESP32)
                          "%c%c%hu%c%c",
#else // assume native platform
                          "%c%c%hu%c%c",
#endif
                          &c, &c, &parsed->as.setDigitalOutput.number, &c, &value);
    parsed->as.setDigitalOutput.value = (value == '0') ? false : true;
    return 5 == items;
}


bool parseEasycomm2GetDigitalInput(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "IPnnn", "IPn", "IPn"
    char c;
    easycommGetDigitalInput(&parsed->as.getDigitalInput);
    return 3 == sscanf(buffer,
#if defined(ARDUINO_ARCH_AVR)
                       "%c%c%u",
#elif defined(ARDUINO_ARCH_STM32)
                       "%c%c%hu",
#elif defined(ARDUINO_ARCH_ESP8266)
                       "%c%c%hu",
#elif defined(ARDUINO_ARCH_ESP32)
                       "%c%c%hu",
#else // assume native platform
                       "%c%c%hu",
#endif
                       &c, &c, &parsed->as.getDigitalInput.number);
}


bool parseEasycomm2GetAnalogueInput(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "ANnnn", "ANn", "ANn"
    char c;
    easycommGetAnalogueInput(&parsed->as.getAnalogueInput);
    return 3 == sscanf(buffer,
#if defined(ARDUINO_ARCH_AVR)
                       "%c%c%u",
#elif defined(ARDUINO_ARCH_STM32)
                       "%c%c%hu",
#elif defined(ARDUINO_ARCH_ESP8266)
                       "%c%c%hu",
#elif defined(ARDUINO_ARCH_ESP32)
                       "%c%c%hu",
#else // assume native platform
                       "%c%c%hu",
#endif
                       &c, &c, &parsed->as.getAnalogueInput.number);
}


bool parseEasycomm2SetTime(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "STyy:MM:dd:hh:mm:ss"
    easycommSetTime(&parsed->as.setTime);
    return 6 == sscanf(buffer,
#if defined(ARDUINO_ARCH_AVR)
                       "ST%hhu:%hhu:%hhu:%hhu:%hhu:%hhu",
#elif defined(ARDUINO_ARCH_STM32) || defined(ARDUINO_ARCH_ESP8266) || defined(ARDUINO_ARCH_ESP32)
                       "ST%hhu:%hhu:%hhu:%hhu:%hhu:%hhu",
#else // assume native platform
                       "ST%hhu:%hhu:%hhu:%hhu:%hhu:%hhu",
#endif
                       &parsed->as.setTime.year, &parsed->as.setTime.month, &parsed->as.setTime.day,
                       &parsed->as.setTime.hour, &parsed->as.setTime.minute, &parsed->as.setTime.second);
}


bool parseEasycomm2GetTime(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "ST"
    easycommGetTime(&parsed->as.getTime);
    return true;
}


bool parseEasycomm2GetVersion(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "VE"
    easycommGetVersion(&parsed->as.getVersion);
    return true;
}


bool parseEasycomm3SetVelocityLeft(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "VLddd", "VLdd", "VLd"
    char c;
    easycommSetVelocityLeft(&parsed->as.setVelocityLeft);
    return 3 == sscanf(buffer,
#if defined(ARDUINO_ARCH_AVR)
                       "%c%c%u",
#elif defined(ARDUINO_ARCH_STM32)
                       "%c%c%hu",
#elif defined(ARDUINO_ARCH_ESP8266)
                       "%c%c%hu",
#elif defined(ARDUINO_ARCH_ESP32)
                       "%c%c%hu",
#else // assume native platform
                       "%c%c%hu",
#endif
                       &c, &c, &parsed->as.setVelocityLeft.milliDegSecond);
}


bool parseEasycomm3GetVelocityLeft(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "VL"
    easycommGetVelocityLeft(&parsed->as.getVelocityLeft);
    return true;
}


bool parseEasycomm3SetVelocityRight(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "VRddd", "VRdd", "VRd"
    char c;
    easycommSetVelocityRight(&parsed->as.setVelocityRight);
    return 3 == sscanf(buffer,
#if defined(ARDUINO_ARCH_AVR)
                       "%c%c%u",
#elif defined(ARDUINO_ARCH_STM32) || defined(ARDUINO_ARCH_ESP8266) || defined(ARDUINO_ARCH_ESP32)
                       "%c%c%hu",
#else // assume native platform
                       "%c%c%hu",
#endif
                       &c, &c, &parsed->as.setVelocityRight.milliDegSecond);
}


bool parseEasycomm3GetVelocityRight(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "VR"
    easycommGetVelocityRight(&parsed->as.getVelocityRight);
    return true;
}


bool parseEasycomm3SetVelocityUp(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "VUddd", "VUdd", "VUd"
    char c;
    easycommSetVelocityUp(&parsed->as.setVelocityUp);
    return 3 == sscanf(buffer,
#if defined(ARDUINO_ARCH_AVR)
                       "%c%c%u",
#elif defined(ARDUINO_ARCH_STM32) || defined(ARDUINO_ARCH_ESP8266) || defined(ARDUINO_ARCH_ESP32)
                       "%c%c%hu",
#else // assume native platform
                       "%c%c%hu",
#endif
                       &c, &c, &parsed->as.setVelocityUp.milliDegSecond);
}


bool parseEasycomm3GetVelocityUp(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "VU"
    easycommGetVelocityUp(&parsed->as.getVelocityUp);
    return true;
}


bool parseEasycomm3SetVelocityDown(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "VDddd", "VDdd", "VDd"
    char c;
    easycommSetVelocityDown(&parsed->as.setVelocityDown);
    return 3 == sscanf(buffer,
#if defined(ARDUINO_ARCH_AVR)
                       "%c%c%u",
#elif defined(ARDUINO_ARCH_STM32)
                       "%c%c%hu",
#elif defined(ARDUINO_ARCH_ESP8266)
                       "%c%c%hu",
#elif defined(ARDUINO_ARCH_ESP32)
                       "%c%c%hu",
#else // assume native platform
                       "%c%c%hu",
#endif
                       &c, &c, &parsed->as.setVelocityDown.milliDegSecond);
}


bool parseEasycomm3GetVelocityDown(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "VD"
    easycommGetVelocityDown(&parsed->as.getVelocityDown);
    return true;
}


bool parseEasycomm3GetConfigRegister(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "CRrrr", "CRrr", "CRr"
    char c;
    easycommGetConfigRegister(&parsed->as.getConfigRegister);
    return 3 == sscanf(buffer,
#if defined(ARDUINO_ARCH_AVR)
                       "%c%c%u",
#elif defined(ARDUINO_ARCH_STM32)
                       "%c%c%hu",
#elif defined(ARDUINO_ARCH_ESP8266)
                       "%c%c%hu",
#elif defined(ARDUINO_ARCH_ESP32)
                       "%c%c%hu",
#else // assume native platform
                       "%c%c%hu",
#endif
                       &c, &c, &parsed->as.getConfigRegister.registerNumber);
}


bool parseEasycomm3SetConfigRegister(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "CWnnn,vvvvvvvvv", ..., "CWn,v"
    char c;
    easycommSetConfigRegister(&parsed->as.setConfigRegister);
    return 4 == sscanf(buffer,
#if defined(ARDUINO_ARCH_AVR)
                       "%c%c%u,%s",
#elif defined(ARDUINO_ARCH_STM32)
                       "%c%c%hu,%s",
#elif defined(ARDUINO_ARCH_ESP8266)
                       "%c%c%hu,%s",
#elif defined(ARDUINO_ARCH_ESP32)
                       "%c%c%hu,%s",
#else // assume native platform
                       "%c%c%hu,%s",
#endif
                       &c, &c, &parsed->as.setConfigRegister.registerNumber,
                       parsed->as.setConfigRegister.value.as.str);
}


bool parseEasycomm3GetStatusRegister(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "GS"
    easycommGetStatusRegister(&parsed->as.getStatusRegister);
    return true;
}


bool parseEasycomm3GetErrorRegister(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "GE"
    easycommGetErrorRegister(&parsed->as.getErrorRegister);
    return true;
}

bool parseEasycommDoReset(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "RESET"
    easycommDoReset(&parsed->as.doReset);
    return true;
}

bool parseEasycommDoPark(const char *buffer, EasycommData *parsed)
{
    // buffer examples: "PARK"
    easycommDoPark(&parsed->as.doPark);
    return true;
}
