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
     * meaning: get AZ, EL, UP frequency, DN frequency, UP mode and DN mode
     * example: "AZnnn.n ELnnn.n UPnnnnnnnnn UUU DNnnnnnnnnn DDD"
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
     * meaning: set azimuth in [deg]
     * example: "AZnnn.n"
     * standard: Easycomm 2
     */
    typedef struct EassycommAzimuth
    {
        EasycommCommandId commandId;
        float azimuth;
    } EasycommAzimuth;

    /**
     * command: AZ
     * meaning: get azimuth in [deg]
     * example: "AZ"
     * standard: Easycomm 2
     */
    typedef struct EassycommGetAzimuth
    {
        EasycommCommandId commandId;
    } EasycommGetAzimuth;

    /**
     * command: EL
     * meaning: set elevation in [deg]
     * example: "ELnnn.n"
     * standard: Easycomm 2
     */
    typedef struct EasycommElevation
    {
        EasycommCommandId commandId;
        float elevation;
    } EasycommElevation;

    /**
     * command: EL
     * meaning: get elevation in [deg]
     * example: "EL"
     * standard: Easycomm 2
     */
    typedef struct EasycommGetElevation
    {
        EasycommCommandId commandId;
        float elevation;
    } EasycommGetElevation;

    /**
     * command: AZ EL
     * meaning: get azimuth and elevation in [deg]
     * example: "AZ EL"
     * standard: Easycomm 2
     */
    typedef struct EasycommGetAzimuthElevation
    {
        EasycommCommandId commandId;
    } EasycommGetAzimuthElevation;

    /**
     * command: UP
     * meaning: set uplink frequency in [Hz]
     * example: "UPnnnnnnnnn"
     * standard: Easycomm 2
     */
    typedef struct EasycommUplinkFrequency
    {
        EasycommCommandId commandId;
        EasycommFrequency frequency;
    } EasycommUplinkFrequency;

    /**
     * command: DN
     * meaning: set downlink frequeny in [Hz]
     * example: "DNnnnnnnnnn"
     * standard: Easycomm 2
     */
    typedef struct EasycommDownlinkFrequency
    {
        EasycommCommandId commandId;
        EasycommFrequency frequency;
    } EasycommDownlinkFrequency;

    /**
     * command: UM
     * meaning: set uplink mode as string
     * example: "UMccc"
     * standard: Easycomm 2
     */
    typedef struct EasycommUplinkMode
    {
        EasycommCommandId commandId;
        char mode[4];
    } EasycommUplinkMode;

    /**
     * command: DM
     * meaning: set downlink mode as string
     * examples: "DMccc"
     * standard: Easycomm 2
     */
    typedef struct EasycommDownlinkMode
    {
        EasycommCommandId commandId;
        char mode[4];
    } EasycommDownlinkMode;

    /**
     * command: DR
     * meaning: set downlink radio number
     * example: "DRnnn"
     * standard: Easycomm 2
     */
    typedef struct EasycommDownlinkRadioNumber
    {
        EasycommCommandId commandId;
        uint16_t number;
    } EasycommDownlinkRadioNumber;

    /**
     * command: UR
     * meaning: set uplink radio number
     * example: "URnnn"
     * standard: Easycomm 2
     */
    typedef struct EasycommUplinkRadioNumber
    {
        EasycommCommandId commandId;
        uint16_t number;

    } EasycommUplinkRadioNumber;


    /**
     * command: ML
     * meaning: move left
     * example: "ML"
     * standard: Easycomm 2
     */
    typedef struct EasycommMoveLeft
    {
        EasycommCommandId commandId;
    } EasycommMoveLeft;


    /**
     * command: MR
     * meaning: move right
     * example: "MR"
     * standard: Easycomm 2
     */
    typedef struct EasycommMoveRight
    {
        EasycommCommandId commandId;
    } EasycommMoveRight;

    /**
     * command: MU
     * meaning: move up
     * example: "MU"
     * standard: Easycomm 2
     */
    typedef struct EasycommMoveUp
    {
        EasycommCommandId commandId;
    } EasycommMoveUp;

    /**
     * command: MD
     * meaning: move down
     * example: "MD"
     * standard: Easycomm 2
     */
    typedef struct EasycommMoveDown
    {
        EasycommCommandId commandId;
    } EasycommMoveDown;

    /**
     * command: SA
     * meaning: stop azimuth movement
     * example: "SA"
     * standard: Easycomm 2
     */
    typedef struct EasycommStopAzimuthMove
    {
        EasycommCommandId commandId;
    } EasycommStopAzimuthMove;

    /**
     * command: SE
     * meaning: stop elevation movement
     * example: "SE"
     * standard: Easycomm 2
     */
    typedef struct EasycommStopElevationMove
    {
        EasycommCommandId commandId;
    } EasycommStopElevationMove;

    /**
     * command: AO
     * meaning: acquisition of signal (AOS, TODO: bearing, elevation, signal or time?)
     * example: "AO"
     * standard: Easycomm 2
     */
    typedef struct EasycommAcquisitionOfSignal
    {
        EasycommCommandId commandId;
    } EasycommAcquisitionOfSignal;

    /**
     * command: LO
     * meaning: acquisition of signal (LOS, TODO: bearing, elevation, signal or time?)
     * example: "LO"
     * standard: Easycomm 2
     */
    typedef struct EasycommLossOfSignal
    {
        EasycommCommandId commandId;
    } EasycommLossOfSignal;

    /**
     * command: OP
     * meaning: set digital output [0|1]
     * example: "OPnnn,b"
     * standard: Easycomm 2
     */
    typedef struct EasycommSetOutput
    {
        EasycommCommandId commandId;
        uint16_t number;
        bool value;
    } EasycommSetOutput;

    /**
     * command: IP
     * meaning: read digital input, [0|1]
     * example: "IPnnn"
     * standard: Easycomm 2
     */
    typedef struct EasycommReadInput
    {
        EasycommCommandId commandId;
        uint16_t number;
    } EasycommReadInput;

    /**
     * command: AN
     * meaning: read analogue input, raw value [0-n]
     * example: "ANnnn"
     * standard: Easycomm 2
     */
    typedef struct EasycommReadAnalogueInput
    {
        EasycommCommandId commandId;
        uint16_t number;
    } EasycommReadAnalogueInput;

    /**
     * command: ST
     * meaning: set current time [y]{1,2}:[m]{1,2}:[d]{1,2}:[M]{1,2}:[h]{1,2}:[s]{1,2}
     * example: "STyy:mm:dd:hh:MM:ss"
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
     * command: ST
     * meaning: Get current time [y]{1,2}:[m]{1,2}:[d]{1,2}:[M]{1,2}:[h]{1,2}:[s]{1,2}
     * example: "ST"
     * standard: Easycomm 2
     */
    typedef struct EasycommGetTime
    {
        EasycommCommandId commandId;
    } EasycommGetTime;

    /**
     * command: VE
     * meaning: request version
     * example: "VE"
     * standard: Easycomm 2
     */
    typedef struct EasycommRequestVersion
    {
        EasycommCommandId commandId;
    } EasycommRequestVersion;

    /**
     * command: VL
     * meaning: set velocity for left movement [deg*10^-3/sec]
     * example: "VLnnn"
     * standard: Easycomm 3
     */
    typedef struct EasycommVelocityLeft
    {
        EasycommCommandId commandId;
        uint16_t milliDegSecond;
    } EasycommVelocityLeft;

    /**
     * command: VL
     * meaning: get velocity for left movement [deg*10^-3/sec]
     * example: "VL"
     * standard: Easycomm 3
     */
    typedef struct EasycommGetVelocityLeft
    {
        EasycommCommandId commandId;
    } EasycommGetVelocityLeft;

    /**
     * command: VR
     * meaning: set velocity for right movement [deg*10^-3/sec]
     * example: "VRnnn"
     * standard: Easycomm 3
     */
    typedef struct EasycommVelocityRight
    {
        EasycommCommandId commandId;
        uint16_t milliDegSecond;
    } EasycommVelocityRight;

    /**
     * command: VR
     * meaning: get velocity for right movement [deg*10^-3/sec]
     * example: "VR"
     * standard: Easycomm 3
     */
    typedef struct EasycommGetVelocityRight
    {
        EasycommCommandId commandId;
    } EasycommGetVelocityRight;

    /**
     * command: VU
     * meaning: set velocity for up movement [deg*10^-3/sec]
     * example: "VUnnn"
     * standard: Easycomm 3
     */
    typedef struct EasycommVelocityUp
    {
        EasycommCommandId commandId;
        uint16_t milliDegSecond;
    } EasycommVelocityUp;

    /**
     * command: VU
     * meaning: get velocity for up movement [deg*10^-3/sec]
     * example: "VU"
     * standard: Easycomm 3
     */
    typedef struct EasycommGetVelocityUp
    {
        EasycommCommandId commandId;
    } EasycommGetVelocityUp;

    /**
     * command: VD
     * meaning: set velocity for down movement [deg*10^-3/sec]
     * example: "VDnnn"
     * standard: Easycomm 3
     */
    typedef struct EasycommVelocityDown
    {
        EasycommCommandId commandId;
        uint16_t milliDegSecond;
    } EasycommVelocityDown;

    /**
     * command: VD
     * meaning: set velocity for down movement [deg*10^-3/sec]
     * example: "VDnnn"
     * standard: Easycomm 3
     */
    typedef struct EasycommGetVelocityDown
    {
        EasycommCommandId commandId;
    } EasycommGetVelocityDown;


    /**
     * command: CR
     * meaning: read configuration value from register
     * example: "CRnnn"
     * standard: Easycomm 3
     */
    typedef struct EasycommReadConfig
    {
        EasycommCommandId commandId;
        uint16_t registerNumber;
    } EasycommReadConfig;

    /**
     * command: CW
     * meaning: write configuration value to register
     * example: "CWnnn,nnn"
     * standard: Easycomm 3
     */
    typedef struct EasycommWriteConfig
    {
        EasycommCommandId commandId;
        uint16_t registerNumber;
        EasycommConfigValue value;
    } EasycommWriteConfig;

    /**
     * command: GS
     * meaning: get status register
     * example: "GS"
     * standard: Easycomm 3
     */
    typedef struct EasycommGetStatusRegister
    {
        EasycommCommandId commandId;
    } EasycommGetStatusRegister;

    /**
     * command: GE
     * meaning: get error register
     * example: "GE"
     * standard: Easycomm 3
     */
    typedef struct EasycommGetErrorRegister
    {
        EasycommCommandId commandId;
    } EasycommGetErrorRegister;

    /**
     * command: RESET
     * meaning: reset
     * example: "RESET"
     * standard: Easycomm ?
     */
    typedef struct EasycommReset
    {
        EasycommCommandId commandId;
    } EasycommReset;

    /**
     * command: PARK
     * meaning: park
     * example: "PARK"
     * standard: Easycomm ?
     */
    typedef struct EasycommPark
    {
        EasycommCommandId commandId;
    } EasycommPark;

    /*!
     * Convenience union for cast in between message types.
     */
    typedef union EasycommPayload
    {
        EasycommCommandId commandId;
        EasycommSingleLine singleLine;
        EasycommAzimuth azimuth;
        EasycommGetAzimuth getAzimuth;
        EasycommElevation elevation;
        EasycommGetElevation getElevation;
        EasycommGetAzimuthElevation getAzimuthElevation;
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
        EasycommGetVelocityLeft getVelocityLeft;
        EasycommVelocityRight velocityRight;
        EasycommGetVelocityRight getVelocityRight;
        EasycommVelocityUp velocityUp;
        EasycommGetVelocityUp getVelocityUp;
        EasycommVelocityDown velocityDown;
        EasycommGetVelocityDown getVelocityDown;
        EasycommReadConfig readConfig;
        EasycommWriteConfig writeConfig;
        EasycommGetStatusRegister getStatusRegister;
        EasycommGetErrorRegister getErrorRegister;
        EasycommReset reset;
        EasycommPark park;
    } EasycommPayload;


    typedef union EasycommData
    {
        EasycommCommandId commandId;
        EasycommPayload as;
    } EasycommData;

#ifdef __cplusplus
}
#endif