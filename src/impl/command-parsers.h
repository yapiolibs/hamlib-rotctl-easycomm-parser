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
    bool isEasycomm2SetAzimuth(const char *buffer);
    bool isEasycomm2GetAzimuth(const char *buffer);
    bool isEasycomm2SetElevation(const char *buffer);
    bool isEasycomm2GetElevation(const char *buffer);
    bool isEasycomm2SetUplinkFrequency(const char *buffer);
    // TODO: bool isEasycomm2GetUplinkFrequency(const char *buffer);
    bool isEasycomm2SetDownlinkFrequency(const char *buffer);
    // TODO: bool isEasycomm2GetDownlinkFrequency(const char *buffer);
    bool isEasycomm2SetUplinkMode(const char *buffer);
    // TODO: bool isEasycomm2GetUplinkMode(const char *buffer);
    bool isEasycomm2SetDownlinkMode(const char *buffer);
    // TODO: bool isEasycomm2GetDownlinkMode(const char *buffer);
    bool isEasycomm2SetUplinkRadioNumber(const char *buffer);
    // TODO: bool isEasycomm2GetUplinkRadioNumber(const char *buffer);
    bool isEasycomm2SetDownlinkRadioNumber(const char *buffer);
    // TODO: bool isEasycomm2GetDownlinkRadioNumber(const char *buffer);
    bool isEasycomm2DoMoveLeft(const char *buffer);
    bool isEasycomm2DoMoveRight(const char *buffer);
    bool isEasycomm2DoMoveUp(const char *buffer);
    bool isEasycomm2DoMoveDown(const char *buffer);
    bool isEasycomm2DoStopAzimuthMove(const char *buffer);
    bool isEasycomm2DoStopElevationMove(const char *buffer);
    bool isEasycomm2AcquisitionOfSignal(const char *buffer);
    bool isEasycomm2LossOfSignal(const char *buffer);
    bool isEasycomm2SetDigitalOutput(const char *buffer);
    bool isEasycomm2GetDigitalInput(const char *buffer);
    bool isEasycomm2GetAnalogueInput(const char *buffer);
    bool isEasycomm2SetTime(const char *buffer);
    // TODO: bool isEasycomm2GetTime(const char *buffer);
    bool isEasycomm2GetVersion(const char *buffer);
    bool isEasycomm3SetVelocityLeft(const char *buffer);
    bool isEasycomm3GetVelocityLeft(const char *buffer);
    bool isEasycomm3SetVelocityRight(const char *buffer);
    bool isEasycomm3GetVelocityRight(const char *buffer);
    bool isEasycomm3SetVelocityUp(const char *buffer);
    bool isEasycomm3GetVelocityUp(const char *buffer);
    bool isEasycomm3SetVelocityDown(const char *buffer);
    bool isEasycomm3GetVelocityDown(const char *buffer);
    bool isEasycomm3GetConfigRegister(const char *buffer);
    bool isEasycomm3SetConfigRegister(const char *buffer);
    bool isEasycomm3GetStatusRegister(const char *buffer);
    bool isEasycomm3GetErrorRegister(const char *buffer);
    bool isEasycommDoReset(const char *buffer);
    bool isEasycommDoPark(const char *buffer);


    // ----- parsers

    bool fallbackParser(const char *buffer, EasycommData *parsed);
    bool parseEasycomm1SingleLine(const char *buffer, EasycommData *parsed);
    bool parseEasycomm2SetAzimuth(const char *buffer, EasycommData *parsed);
    bool parseEasycomm2GetAzimuth(const char *buffer, EasycommData *parsed);
    bool parseEasycomm2SetElevation(const char *buffer, EasycommData *parsed);
    bool parseEasycomm2GetElevation(const char *buffer, EasycommData *parsed);
    bool parseEasycomm2SetUplinkFrequency(const char *buffer, EasycommData *parsed);
    // bool parseEasycomm2GetUplinkFrequency(const char *buffer, EasycommData *parsed);
    bool parseEasycomm2SetDownlinkFrequency(const char *buffer, EasycommData *parsed);
    // bool parseEasycomm2GetDownlinkFrequency(const char *buffer, EasycommData *parsed);
    bool parseEasycomm2SetUplinkMode(const char *buffer, EasycommData *parsed);
    // bool parseEasycomm2GetUplinkMode(const char *buffer, EasycommData *parsed);
    bool parseEasycomm2SetDownlinkMode(const char *buffer, EasycommData *parsed);
    // bool parseEasycomm2GetDownlinkMode(const char *buffer, EasycommData *parsed);
    bool parseEasycomm2SetUplinkRadioNumber(const char *buffer, EasycommData *parsed);
    // bool parseEasycomm2GetUplinkRadioNumber(const char *buffer, EasycommData *parsed);
    bool parseEasycomm2SetDownlinkRadioNumber(const char *buffer, EasycommData *parsed);
    // bool parseEasycomm2GetDownlinkRadioNumber(const char *buffer, EasycommData *parsed);
    bool parseEasycomm2DoMoveLeft(const char *buffer, EasycommData *parsed);
    bool parseEasycomm2DoMoveRight(const char *buffer, EasycommData *parsed);
    bool parseEasycomm2DoMoveUp(const char *buffer, EasycommData *parsed);
    bool parseEasycomm2DoMoveDown(const char *buffer, EasycommData *parsed);
    bool parseEasycomm2DoStopAzimuthMove(const char *buffer, EasycommData *parsed);
    bool parseEasycomm2DoStopElevationMove(const char *buffer, EasycommData *parsed);
    bool parseEasycomm2AcquisitionOfSignal(const char *buffer, EasycommData *parsed);
    bool parseEasycomm2LossOfSignal(const char *buffer, EasycommData *parsed);
    bool parseEasycomm2SetDigitalOutput(const char *buffer, EasycommData *parsed);
    bool parseEasycomm2GetDigitalInput(const char *buffer, EasycommData *parsed);
    bool parseEasycomm2GetAnalogueInput(const char *buffer, EasycommData *parsed);
    bool parseEasycomm2SetTime(const char *buffer, EasycommData *parsed);
    // bool parseEasycomm2GetTime(const char *buffer, EasycommData *parsed);
    bool parseEasycomm2GetVersion(const char *buffer, EasycommData *parsed);
    bool parseEasycomm3SetVelocityLeft(const char *buffer, EasycommData *parsed);
    bool parseEasycomm3GetVelocityLeft(const char *buffer, EasycommData *parsed);
    bool parseEasycomm3SetVelocityRight(const char *buffer, EasycommData *parsed);
    bool parseEasycomm3GetVelocityRight(const char *buffer, EasycommData *parsed);
    bool parseEasycomm3SetVelocityUp(const char *buffer, EasycommData *parsed);
    bool parseEasycomm3GetVelocityUp(const char *buffer, EasycommData *parsed);
    bool parseEasycomm3SetVelocityDown(const char *buffer, EasycommData *parsed);
    bool parseEasycomm3GetVelocityDown(const char *buffer, EasycommData *parsed);
    bool parseEasycomm3GetConfigRegister(const char *buffer, EasycommData *parsed);
    bool parseEasycomm3SetConfigRegister(const char *buffer, EasycommData *parsed);
    bool parseEasycomm3GetStatusRegister(const char *buffer, EasycommData *parsed);
    bool parseEasycomm3GetErrorRegister(const char *buffer, EasycommData *parsed);
    bool parseEasycommDoReset(const char *buffer, EasycommData *parsed);
    bool parseEasycommDoPark(const char *buffer, EasycommData *parsed);

#ifdef __cplusplus
}
#endif
