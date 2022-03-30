#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#include "../easycomm-parser-types.h"
#include <inttypes.h>

    // ----- predicates

    bool isEasycomm1SingleLine(const char *buffer);
    bool isEasycomm2Azimuth(const char *buffer);
    bool isEasycomm2Elevation(const char *buffer);
    bool isEasycomm2AzimuthElevation(const char *buffer);
    bool isEasycomm2ElevationAzimuth(const char *buffer);

    // ----- parsers

    bool readEasycomm1SingleLine(const char *buffer, EasycommData *parsed);
    bool readEasycomm2Azimuth(const char *buffer, EasycommData *parsed);
    bool readEasycomm2Elevation(const char *buffer, EasycommData *parsed);
    bool readEasycomm2AzimuthElevation(const char *buffer, EasycommData *parsed);
    bool readEasycomm2ElevationAzimuth(const char *buffer, EasycommData *parsed);
#ifdef __cplusplus
}
#endif