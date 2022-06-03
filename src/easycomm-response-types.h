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
    typedef struct EasycommResponseAzimuth
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
    typedef struct EasycommResponseDownlinkRadio
    {
        uint16_t number;
    } EasycommResponseDownlinkRadio;

    /**
     * example: "URnnn"
     * standard: Easycomm 2
     */
    typedef struct EasycommResponseUplinkRadio
    {
        uint16_t number;
    } EasycommResponseUplinkRadio;

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
     * current time: [y]{1,2}:[m]{1,2}:[d]{1,2}:[M]{1,2}:[h]{1,2}:[s]{1,2}
     * example: "STyy:mm:dd:hh:MM:ss"
     * standard: Easycomm 2
     */
    typedef struct EasycommResponseTime
    {
        EasycommCommandId commandId;
        uint8_t year;
        uint8_t month;
        uint8_t day;
        uint8_t hour;
        uint8_t minute;
        uint8_t second;
    } EasycommResponseTime;

    /**
     * example: "CRnnn,vvv"
     * standard: Easycomm 3
     */
    typedef struct EasycommResponseConfigRegister
    {
        uint16_t registerNumber;
        EasycommConfigRegisterValue value;
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
