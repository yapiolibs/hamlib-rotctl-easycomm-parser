#pragma once
#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * Responses are issued by the controller to the host.
     *
     * Easycomm 1, 2 and 3 references:
     * - description https://github.com/Hamlib/Hamlib/blob/master/rotators/easycomm/easycomm.txt
     * - implementation details https://github.com/Hamlib/Hamlib/blob/master/rotators/easycomm/easycomm.c
     */

#include "easycomm-types.h"
#include <inttypes.h>
#include <stdbool.h>


    /**
     * example: "AZaaa.a ELeee.e UPuuuuuuuuu UUU DNddddddddd DDD"
     * standard: Easycomm 1
     */
    typedef struct EasycommResponseSingleLine
    {
        EasycommCommandId commandId;
        float azimuth;
        float elevation;
        EasycommFrequency uplinkFrequency;
        EasycommFrequency downlinkFrequency;
        char modeUp[4];
        char modeDown[4];
    } EasycommResponseSingleLine;

    /**
     * example: "AZaaa.a"
     * standard: Easycomm 2
     */
    typedef struct EassycommResponseAzimuth
    {
        float azimuth;
    } EasycommResponseAzimuth;

    /**
     * example: "ELeee.e"
     * standard: Easycomm 2
     */
    typedef struct EasycommResponseElevation
    {
        float elevation;
    } EasycommResponseElevation;

    /**
     * example: "UPfff"
     * standard: Easycomm 2
     */
    typedef struct EasycommResponseUplinkFrequency
    {
        EasycommFrequency frequency;
    } EasycommResponseUplinkFrequency;

    /**
     * example: "DNfff"
     * standard: Easycomm 2
     */
    typedef struct EasycommResponseDownlinkFrequency
    {
        EasycommFrequency frequency;
    } EasycommResponseDownlinkFrequency;

    /**
     * example: "UMmmm"
     * standard: Easycomm 2
     */
    typedef struct EasycommResponseUplinkMode
    {
        char mode[4];
    } EasycommResponseUplinkMode;

    /**
     * example: "DMmmm"
     * standard: Easycomm 2
     */
    typedef struct EasycommResponseDownlinkMode
    {
        char mode[4];
    } EasycommResponseDownlinkMode;

    /**
     * example: "DRnnn"
     * standard: Easycomm 2
     */
    typedef struct EasycommResponseDownlinkRadioNumber
    {
        uint16_t number;
    } EasycommResponseDownlinkRadioNumber;

    /**
     * example: "URnnn"
     * standard: Easycomm 2
     */
    typedef struct EasycommResponseUplinkRadioNumber
    {
        uint16_t number;
    } EasycommResponseUplinkRadioNumber;

    /**
     * example: "IPnnn"
     * standard: Easycomm 2
     */
    typedef struct EasycommResponseDigitalInput
    {
        uint16_t number;
        bool value;
    } EasycommResponseDigitalInput;

    /**
     * example: "ANnnn"
     * standard: Easycomm 2
     */
    typedef struct EasycommResponseAnalogueInput
    {
        uint16_t number;
        uint16_t value;
    } EasycommResponseAnalogueInput;


    /**
     * example: "VEnnn.nnn"
     * standard: Easycomm 2
     */
    typedef struct EasycommResponseVersion
    {
        uint8_t minor;
        uint8_t major;
    } EasycommResponseVersion;

    /**
     * example: "ALtextnospaces"
     * standard: Easycomm 2
     */
    typedef struct EasycommResponseAlarm
    {
        char message[33];
    } EasycommResponseAlarm;

    /**
     * example: "VLnnn"
     * standard: Easycomm 3
     */
    typedef struct EasycommResponseVelocityLeft
    {
        uint16_t milliDegSecond;
    } EasycommResponseVelocityLeft;

    /**
     * example: "VRnnn"
     * standard: Easycomm 3
     */
    typedef struct EasycommResponseVelocityRight
    {
        uint16_t milliDegSecond;
    } EasycommResponseVelocityRight;

    /**
     * example: "VUnnn"
     * standard: Easycomm 3
     */
    typedef struct EasycommResponseVelocityUp
    {
        uint16_t milliDegSecond;
    } EasycommResponseVelocityUp;

    /**
     * example: "VDnnn"
     * standard: Easycomm 3
     */
    typedef struct EasycommResponseVelocityDown
    {
        uint16_t milliDegSecond;
    } EasycommResponseVelocityDown;

    /**
     * example: "CRnnn,vvv"
     * standard: Easycomm 3
     */
    typedef struct EasycommResponseConfigRegister
    {
        uint16_t registerNumber;
        EasycommConfigValue value;
    } EasycommResponseConfigRegister;

    /**
     * example: "GSn"
     * standard: Easycomm 3
     */
    typedef struct EasycommResponseStatusRegister
    {
        EasycommStatusRegister status;
    } EasycommResponseStatusRegister;

    /**
     * example: "GEn"
     * standard: Easycomm 3
     */
    typedef struct EasycommResponseErrorRegister
    {
        EasycommErrorRegister status;
    } EasycommResponseErrorRegister;


#ifdef __cplusplus
}
#endif
