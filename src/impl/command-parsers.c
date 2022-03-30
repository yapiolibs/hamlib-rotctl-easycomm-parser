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
           &parsed->as.singleLine.uplink_frequency.as.uint32, &parsed->as.singleLine.mode_up[0],
           &parsed->as.singleLine.mode_up[1], &parsed->as.singleLine.mode_up[2], &c, &c,
           &parsed->as.singleLine.downlink_frequency.as.uint32, &parsed->as.singleLine.mode_down[0],
           &parsed->as.singleLine.mode_down[1], &parsed->as.singleLine.mode_down[2]);

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