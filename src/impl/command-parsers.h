#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#include "../easycomm-parser-types.h"
#include <inttypes.h>

    // ----- predicates

    bool fallbackPredicate(const char *buffer);
    bool isEasycomm1SingleLine(const char *buffer);
    bool isEasycomm2Azimuth(const char *buffer);
    bool isEasycomm2GetAzimuth(const char *buffer);
    bool isEasycomm2Elevation(const char *buffer);
    bool isEasycomm2GetElevation(const char *buffer);
    bool isEasycomm2UplinkFrequency(const char *buffer);
    bool isEasycomm2DownlinkFrequency(const char *buffer);
    bool isEasycomm2UplinkMode(const char *buffer);
    bool isEasycomm2DownlinkMode(const char *buffer);
    bool isEasycomm2UplinkRadioNumber(const char *buffer);
    bool isEasycomm2DownlinkRadioNumber(const char *buffer);
    bool isEasycomm2MoveLeft(const char *buffer);
    bool isEasycomm2MoveRight(const char *buffer);
    bool isEasycomm2MoveUp(const char *buffer);
    bool isEasycomm2MoveDown(const char *buffer);
    bool isEasycomm2StopAzimuthMove(const char *buffer);
    bool isEasycomm2StopElevationMove(const char *buffer);
    bool isEasycomm2AcquisitionOfSignal(const char *buffer);
    bool isEasycomm2LossOfSignal(const char *buffer);
    bool isEasycomm2SetOutput(const char *buffer);
    bool isEasycomm2ReadInput(const char *buffer);
    bool isEasycomm2ReadAnalogueInput(const char *buffer);
    bool isEasycomm2SetTime(const char *buffer);
    bool isEasycomm2RequestVersion(const char *buffer);
    bool isEasycomm3VelocityLeft(const char *buffer);
    bool isEasycomm3GetVelocityLeft(const char *buffer);
    bool isEasycomm3VelocityRight(const char *buffer);
    bool isEasycomm3GetVelocityRight(const char *buffer);
    bool isEasycomm3VelocityUp(const char *buffer);
    bool isEasycomm3GetVelocityUp(const char *buffer);
    bool isEasycomm3VelocityDown(const char *buffer);
    bool isEasycomm3GetVelocityDown(const char *buffer);
    bool isEasycomm3ReadConfig(const char *buffer);
    bool isEasycomm3WriteConfig(const char *buffer);
    bool isEasycomm3GetStatusRegister(const char *buffer);
    bool isEasycomm3GetErrorRegister(const char *buffer);
    bool isEasycommReset(const char *buffer);
    bool isEasycommPark(const char *buffer);


    // ----- parsers

    bool fallbackParser(const char *buffer, EasycommData *parsed);
    bool readEasycomm1SingleLine(const char *buffer, EasycommData *parsed);
    bool readEasycomm2Azimuth(const char *buffer, EasycommData *parsed);
    bool readEasycomm2GetAzimuth(const char *buffer, EasycommData *parsed);
    bool readEasycomm2Elevation(const char *buffer, EasycommData *parsed);
    bool readEasycomm2GetElevation(const char *buffer, EasycommData *parsed);
    bool readEasycomm2UplinkFrequency(const char *buffer, EasycommData *parsed);
    bool readEasycomm2DownlinkFrequency(const char *buffer, EasycommData *parsed);
    bool readEasycomm2UplinkMode(const char *buffer, EasycommData *parsed);
    bool readEasycomm2DownlinkMode(const char *buffer, EasycommData *parsed);
    bool readEasycomm2UplinkRadioNumber(const char *buffer, EasycommData *parsed);
    bool readEasycomm2DownlinkRadioNumber(const char *buffer, EasycommData *parsed);
    bool readEasycomm2MoveLeft(const char *buffer, EasycommData *parsed);
    bool readEasycomm2MoveRight(const char *buffer, EasycommData *parsed);
    bool readEasycomm2MoveUp(const char *buffer, EasycommData *parsed);
    bool readEasycomm2MoveDown(const char *buffer, EasycommData *parsed);
    bool readEasycomm2StopAzimuthMove(const char *buffer, EasycommData *parsed);
    bool readEasycomm2StopElevationMove(const char *buffer, EasycommData *parsed);
    bool readEasycomm2AcquisitionOfSignal(const char *buffer, EasycommData *parsed);
    bool readEasycomm2LossOfSignal(const char *buffer, EasycommData *parsed);
    bool readEasycomm2SetOutput(const char *buffer, EasycommData *parsed);
    bool readEasycomm2ReadInput(const char *buffer, EasycommData *parsed);
    bool readEasycomm2ReadAnalogueInput(const char *buffer, EasycommData *parsed);
    bool readEasycomm2SetTime(const char *buffer, EasycommData *parsed);
    bool readEasycomm2RequestVersion(const char *buffer, EasycommData *parsed);
    bool readEasycomm3VelocityLeft(const char *buffer, EasycommData *parsed);
    bool readEasycomm3GetVelocityLeft(const char *buffer, EasycommData *parsed);
    bool readEasycomm3VelocityRight(const char *buffer, EasycommData *parsed);
    bool readEasycomm3GetVelocityRight(const char *buffer, EasycommData *parsed);
    bool readEasycomm3VelocityUp(const char *buffer, EasycommData *parsed);
    bool readEasycomm3GetVelocityUp(const char *buffer, EasycommData *parsed);
    bool readEasycomm3VelocityDown(const char *buffer, EasycommData *parsed);
    bool readEasycomm3GetVelocityDown(const char *buffer, EasycommData *parsed);
    bool readEasycomm3ReadConfig(const char *buffer, EasycommData *parsed);
    bool readEasycomm3WriteConfig(const char *buffer, EasycommData *parsed);
    bool readEasycomm3GetStatusRegister(const char *buffer, EasycommData *parsed);
    bool readEasycomm3GetErrorRegister(const char *buffer, EasycommData *parsed);
    bool readEasycommReset(const char *buffer, EasycommData *parsed);
    bool readEasycommPark(const char *buffer, EasycommData *parsed);

#ifdef __cplusplus
}
#endif
