#pragma once

#ifdef __cplusplus
extern "C"
{
#endif
/**
 * Commandos are issued by the host to the controller.
 *
 * Easycomm 1, 2 and 3 references:
 * - description https://github.com/Hamlib/Hamlib/blob/master/rotators/easycomm/easycomm.txt
 * - implementation details https://github.com/Hamlib/Hamlib/blob/master/rotators/easycomm/easycomm.c
 */
#include "easycomm-types.h"
#include <inttypes.h>
#include <stdbool.h>

    /**
     * command: single line
     * meaning: set/get AZ, EL, UP frequency, DN frequency, UP mode and DN mode
     * parameters:
     * - "AZaaa.a" not fixed width number with 1 decimal in [deg]
     * - "ELeee.e" not fixed width number with 1 decimal in [deg]
     * - "UPuuuuuuuuu" or "UPuuu" in [Hz]
     *   TODO: long version in doc. vs short version in code -> assume not fixed width
     * - "UUU"  in [Hz]
     * - "DNddddddddd" or "DNddd" in [Hz]
     *   TODO: long version in doc. vs short version in code -> assume not fixed width
     * - "DDD"
     * examples:
     * - "AZaaa.a ELeee.e UPuuuuuuuuu UUU DNddddddddd DDD"
     * - "AZaaa.a ELeee.e UPuuu UUU DNddd DDD"
     * standard: Easycomm 1
     */
    typedef struct EasycommSingleLine
    {
        EasycommCommandId commandId;
        float azimuth;
        float elevation;
        EasycommFrequency uplinkFrequency;
        EasycommFrequency downlinkFrequency;
        char modeUp[4];
        char modeDown[4];
    } EasycommSingleLine;

    /**
     * command: AZ
     * meaning: set/get Azimuth
     * parameters: not fixed width with 1 decimal [deg]
     * examples:
     * - "AZaaa.a"
     * - "AZa.a"
     * standard: Easycomm 2
     */
    typedef struct EassycommAzimuth
    {
        EasycommCommandId commandId;
        float azimuth;
    } EasycommAzimuth;

    /**
     * command: EL
     * meaning: Elevation
     * parameters: not fixed width with 1 decimal [deg]
     * examples:
     * - "ELeee.e"
     * - "ELe.e"
     * standard: Easycomm 2
     */
    typedef struct EasycommElevation
    {
        EasycommCommandId commandId;
        float elevation;
    } EasycommElevation;

    /**
     * command:
     * meaning:
     * parameters:
     * examples:
     * standard: Easycomm 2
     */
    typedef struct EasycommUplinkFrequency
    {
        EasycommCommandId commandId;
        EasycommFrequency frequency;
    } EasycommUplinkFrequency;

    /**
     * command:
     * meaning:
     * parameters:
     * examples:
     * standard: Easycomm 2
     */
    typedef struct EasycommDownlinkFrequency
    {
        EasycommCommandId commandId;
        EasycommFrequency frequency;
    } EasycommDownlinkFrequency;

    /**
     * command:
     * meaning:
     * parameters:
     * examples:
     * standard: Easycomm 2
     */
    typedef struct EasycommUplinkMode
    {
        EasycommCommandId commandId;
        char mode[4];
    } EasycommUplinkMode;

    /**
     * command:
     * meaning:
     * parameters:
     * examples:
     * standard: Easycomm 2
     */
    typedef struct EasycommDownlinkMode
    {
        EasycommCommandId commandId;
        char mode[4];
    } EasycommDownlinkMode;

    /**
     * command:
     * meaning:
     * parameters:
     * examples:
     * standard: Easycomm 2
     */
    typedef struct EasycommDownlinkRadioNumber
    {
        EasycommCommandId commandId;
        uint16_t number;
    } EasycommDownlinkRadioNumber;

    /**
     * command:
     * meaning:
     * parameters:
     * examples:
     * standard: Easycomm 2
     */
    typedef struct EasycommUplinkRadioNumber
    {
        EasycommCommandId commandId;
        uint16_t number;

    } EasycommUplinkRadioNumber;


    /**
     * command:
     * meaning:
     * parameters:
     * examples:
     * standard: Easycomm 2
     */
    typedef struct EasycommMoveLeft
    {
        EasycommCommandId commandId;
    } EasycommMoveLeft;


    /**
     * command:
     * meaning:
     * parameters:
     * examples:
     * standard: Easycomm 2
     */
    typedef struct EasycommMoveRight
    {
        EasycommCommandId commandId;
    } EasycommMoveRight;

    /**
     * command:
     * meaning:
     * parameters:
     * examples:
     * standard: Easycomm 2
     */
    typedef struct EasycommMoveUp
    {
        EasycommCommandId commandId;
    } EasycommMoveUp;

    /**
     * command:
     * meaning:
     * parameters:
     * examples:
     * standard: Easycomm 2
     */
    typedef struct EasycommMoveDown
    {
        EasycommCommandId commandId;
    } EasycommMoveDown;

    /**
     * command:
     * meaning:
     * parameters:
     * examples:
     * standard: Easycomm 2
     */
    typedef struct EasycommStopAzimuthMove
    {
        EasycommCommandId commandId;
    } EasycommStopAzimuthMove;

    /**
     * command:
     * meaning:
     * parameters:
     * examples:
     * standard: Easycomm 2
     */
    typedef struct EasycommStopElevationMove
    {
        EasycommCommandId commandId;
    } EasycommStopElevationMove;

    /**
     * command:
     * meaning:
     * parameters:
     * examples:
     * standard: Easycomm 2
     */
    typedef struct EasycommAcquisitionOfSignal
    {
        EasycommCommandId commandId;
    } EasycommAcquisitionOfSignal;

    /**
     * command:
     * meaning:
     * parameters:
     * examples:
     * standard: Easycomm 2
     */
    typedef struct EasycommLossOfSignal
    {
        EasycommCommandId commandId;
    } EasycommLossOfSignal;

    /**
     * command:
     * meaning:
     * parameters:
     * examples:
     * standard: Easycomm 2
     */
    typedef struct EasycommSetOutput
    {
        EasycommCommandId commandId;
        uint16_t number;
        bool value;
    } EasycommSetOutput;

    /**
     * command:
     * meaning:
     * parameters:
     * examples:
     * standard: Easycomm 2
     */
    typedef struct EasycommReadInput
    {
        EasycommCommandId commandId;
        uint16_t number;
    } EasycommReadInput;

    /**
     * command:
     * meaning:
     * parameters:
     * examples:
     * standard: Easycomm 2
     */
    typedef struct EasycommReadAnalogueInput
    {
        EasycommCommandId commandId;
        uint16_t number;
    } EasycommReadAnalogueInput;

    /**
     * command:
     * meaning:
     * parameters:
     * examples:
     * standard: Easycomm 2
     */
    typedef struct EasycommSetTime
    {
        EasycommCommandId commandId;
        uint8_t year;
        uint8_t month;
        uint8_t day;
        uint8_t hour;
        uint8_t minute;
        uint8_t second;
    } EasycommSetTime;

    /**
     * command:
     * meaning:
     * parameters:
     * examples:
     * standard: Easycomm 2
     */
    typedef struct EasycommRequestVersion
    {
        EasycommCommandId commandId;
    } EasycommRequestVersion;

    /**
     * command:
     * meaning:
     * parameters:
     * examples:
     * standard: Easycomm 3
     */
    typedef struct EasycommVelocityLeft
    {
        EasycommCommandId commandId;
        uint16_t milliDegSecond;
    } EasycommVelocityLeft;

    /**
     * command:
     * meaning:
     * parameters:
     * examples:
     * standard: Easycomm 3
     */
    typedef struct EasycommVelocityRight
    {
        EasycommCommandId commandId;
        uint16_t milliDegSecond;
    } EasycommVelocityRight;

    /**
     * command:
     * meaning:
     * parameters:
     * examples:
     * standard: Easycomm 3
     */
    typedef struct EasycommVelocityUp
    {
        EasycommCommandId commandId;
        uint16_t milliDegSecond;
    } EasycommVelocityUp;

    /**
     * command:
     * meaning:
     * parameters:
     * examples:
     * standard: Easycomm 3
     */
    typedef struct EasycommVelocityDown
    {
        EasycommCommandId commandId;
        uint16_t milliDegSecond;
    } EasycommVelocityDown;

    /**
     * command:
     * meaning:
     * parameters:
     * examples:
     * standard: Easycomm 3
     */
    typedef struct EasycommReadConfig
    {
        EasycommCommandId commandId;
        uint16_t registerNumber;
    } EasycommReadConfig;

    /**
     * command:
     * meaning:
     * parameters:
     * examples:
     * standard: Easycomm 3
     */
    typedef struct EasycommWriteConfig
    {
        EasycommCommandId commandId;
        uint16_t registerNumber;
        EasycommConfigValue value;
    } EasycommWriteConfig;

    /**
     * command:
     * meaning:
     * parameters:
     * examples:
     * standard: Easycomm 3
     */
    typedef struct EasycommGetStatusRegister
    {
        EasycommCommandId commandId;
    } EasycommGetStatusRegister;

    /**
     * command:
     * meaning:
     * parameters:
     * examples:
     * standard: Easycomm 3
     */
    typedef struct EasycommGetErrorRegister
    {
        EasycommCommandId commandId;
    } EasycommGetErrorRegister;

    /*!
     * Convenience union for cast in between message types.
     */
    typedef union EasycommPayload
    {
        EasycommCommandId commandId;
        EasycommSingleLine singleLine;
        EasycommAzimuth azimuth;
        EasycommElevation elevation;
        EasycommUplinkFrequency uplinkFrequency;
        EasycommDownlinkFrequency downlinkFrequency;
        EasycommUplinkMode uplinkMode;
        EasycommDownlinkMode downlinkMode;
        EasycommUplinkRadioNumber uplinkRadio;
        EasycommDownlinkRadioNumber downlinkRadio;
        EasycommMoveLeft moveLeft;
        EasycommMoveRight moveRight;
        EasycommMoveUp moveUp;
        EasycommMoveDown moveDown;
        EasycommStopAzimuthMove stopAzimuthMove;
        EasycommStopElevationMove stopElevationMove;
        EasycommAcquisitionOfSignal acquisitionOfSignal;
        EasycommLossOfSignal lossOfSignal;
        EasycommSetOutput setOutput;
        EasycommReadInput readInput;
        EasycommReadAnalogueInput readAnalogueInput;
        EasycommSetTime setTime;
        EasycommRequestVersion requestVersion;
        EasycommVelocityLeft velocityLeft;
        EasycommVelocityRight velocityRight;
        EasycommVelocityUp velocityUp;
        EasycommVelocityDown velocityDown;
        EasycommReadConfig readConfig;
        EasycommWriteConfig writeConfig;
        EasycommGetStatusRegister getStatusRegister;
        EasycommGetErrorRegister getErrorRegister;
    } EasycommPayload;


    typedef union EasycommData
    {
        EasycommCommandId commandId;
        EasycommPayload as;
    } EasycommData;

#ifdef __cplusplus
}
#endif