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
    typedef struct EasycommSetAzimuth
    {
        EasycommCommandId commandId;
        float azimuth;
    } EasycommSetAzimuth;

    /**
     * command: AZ
     * meaning: get azimuth in [deg]
     * example: "AZ"
     * standard: Easycomm 2
     */
    typedef struct EasycommGetAzimuth
    {
        EasycommCommandId commandId;
    } EasycommGetAzimuth;

    /**
     * command: EL
     * meaning: set elevation in [deg]
     * example: "ELnnn.n"
     * standard: Easycomm 2
     */
    typedef struct EasycommSetElevation
    {
        EasycommCommandId commandId;
        float elevation;
    } EasycommSetElevation;

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
     * command: UP
     * meaning: set uplink frequency in [Hz]
     * example: "UPnnnnnnnnn"
     * standard: Easycomm 2
     */
    typedef struct EasycommSetUplinkFrequency
    {
        EasycommCommandId commandId;
        EasycommFrequency frequency;
    } EasycommSetUplinkFrequency;

    /**
     * command: UP
     * meaning: get uplink frequency in [Hz]
     * example: "UP"
     * standard: Easycomm 2
     */
    typedef struct EasycommGetUplinkFrequency
    {
        EasycommCommandId commandId;
    } EasycommGetUplinkFrequency;

    /**
     * command: DN
     * meaning: set downlink frequeny in [Hz]
     * example: "DNnnnnnnnnn"
     * standard: Easycomm 2
     */
    typedef struct EasycommSetDownlinkFrequency
    {
        EasycommCommandId commandId;
        EasycommFrequency frequency;
    } EasycommSetDownlinkFrequency;

    /**
     * command: DN
     * meaning: get downlink frequeny in [Hz]
     * example: "DN"
     * standard: Easycomm 2
     */
    typedef struct EasycommGetDownlinkFrequency
    {
        EasycommCommandId commandId;
    } EasycommGetDownlinkFrequency;

    /**
     * command: UM
     * meaning: set uplink mode as string
     * example: "UMccc"
     * standard: Easycomm 2
     */
    typedef struct EasycommSetUplinkMode
    {
        EasycommCommandId commandId;
        char mode[4];
    } EasycommSetUplinkMode;

    /**
     * command: UM
     * meaning: get uplink mode as string
     * example: "UM"
     * standard: Easycomm 2
     */
    typedef struct EasycommGetUplinkMode
    {
        EasycommCommandId commandId;
    } EasycommGetUplinkMode;

    /**
     * command: DM
     * meaning: set downlink mode as string
     * examples: "DMccc"
     * standard: Easycomm 2
     */
    typedef struct EasycommSetDownlinkMode
    {
        EasycommCommandId commandId;
        char mode[4];
    } EasycommSetDownlinkMode;

    /**
     * command: DM
     * meaning: get downlink mode as string
     * examples: "DM"
     * standard: Easycomm 2
     */
    typedef struct EasycommGetDownlinkMode
    {
        EasycommCommandId commandId;
    } EasycommGetDownlinkMode;

    /**
     * command: DR
     * meaning: set downlink radio number
     * example: "DRnnn"
     * standard: Easycomm 2
     */
    typedef struct EasycommSetDownlinkRadio
    {
        EasycommCommandId commandId;
        uint16_t number;
    } EasycommSetDownlinkRadio;

    /**
     * command: DR
     * meaning: get downlink radio number
     * example: "DR"
     * standard: Easycomm 2
     */
    typedef struct EasycommGetDownlinkRadio
    {
        EasycommCommandId commandId;
    } EasycommGetDownlinkRadio;

    /**
     * command: UR
     * meaning: set uplink radio number
     * example: "URnnn"
     * standard: Easycomm 2
     */
    typedef struct EasycommSetUplinkRadio
    {
        EasycommCommandId commandId;
        uint16_t number;
    } EasycommSetUplinkRadio;

    /**
     * command: UR
     * meaning: get uplink radio number
     * example: "UR"
     * standard: Easycomm 2
     */
    typedef struct EasycommGetUplinkRadio
    {
        EasycommCommandId commandId;
    } EasycommGetUplinkRadio;

    /**
     * command: ML
     * meaning: move left
     * example: "ML"
     * standard: Easycomm 2
     */
    typedef struct EasycommDoMoveLeft
    {
        EasycommCommandId commandId;
    } EasycommDoMoveLeft;


    /**
     * command: MR
     * meaning: move right
     * example: "MR"
     * standard: Easycomm 2
     */
    typedef struct EasycommDoMoveRight
    {
        EasycommCommandId commandId;
    } EasycommDoMoveRight;

    /**
     * command: MU
     * meaning: move up
     * example: "MU"
     * standard: Easycomm 2
     */
    typedef struct EasycommDoMoveUp
    {
        EasycommCommandId commandId;
    } EasycommDoMoveUp;

    /**
     * command: MD
     * meaning: move down
     * example: "MD"
     * standard: Easycomm 2
     */
    typedef struct EasycommDoMoveDown
    {
        EasycommCommandId commandId;
    } EasycommDoMoveDown;

    /**
     * command: SA
     * meaning: stop azimuth movement
     * example: "SA"
     * standard: Easycomm 2
     */
    typedef struct EasycommDoStopAzimuthMove
    {
        EasycommCommandId commandId;
    } EasycommDoStopAzimuthMove;

    /**
     * command: SE
     * meaning: stop elevation movement
     * example: "SE"
     * standard: Easycomm 2
     */
    typedef struct EasycommDoStopElevationMove
    {
        EasycommCommandId commandId;
    } EasycommDoStopElevationMove;

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
    typedef struct EasycommSetDigitalOutput
    {
        EasycommCommandId commandId;
        uint16_t number;
        bool value;
    } EasycommSetDigitalOutput;

    /**
     * command: IP
     * meaning: read digital input, [0|1]
     * example: "IPnnn"
     * standard: Easycomm 2
     */
    typedef struct EasycommGetDigitalInput
    {
        EasycommCommandId commandId;
        uint16_t number;
    } EasycommGetDigitalInput;

    /**
     * command: AN
     * meaning: read analogue input, raw value [0-n]
     * example: "ANnnn"
     * standard: Easycomm 2
     */
    typedef struct EasycommGetAnalogueInput
    {
        EasycommCommandId commandId;
        uint16_t number;
    } EasycommGetAnalogueInput;

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
    typedef struct EasycommGetVersion
    {
        EasycommCommandId commandId;
    } EasycommGetVersion;

    /**
     * command: VL
     * meaning: set velocity for left movement [deg*10^-3/sec]
     * example: "VLnnn"
     * standard: Easycomm 3
     */
    typedef struct EasycommSetVelocityLeft
    {
        EasycommCommandId commandId;
        uint16_t milliDegSecond;
    } EasycommSetVelocityLeft;

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
    typedef struct EasycommSetVelocityRight
    {
        EasycommCommandId commandId;
        uint16_t milliDegSecond;
    } EasycommSetVelocityRight;

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
    typedef struct EasycommSetVelocityUp
    {
        EasycommCommandId commandId;
        uint16_t milliDegSecond;
    } EasycommSetVelocityUp;

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
    typedef struct EasycommSetVelocityDown
    {
        EasycommCommandId commandId;
        uint16_t milliDegSecond;
    } EasycommSetVelocityDown;

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
    typedef struct EasycommGetConfigRegister
    {
        EasycommCommandId commandId;
        uint16_t registerNumber;
    } EasycommGetConfigRegister;

    /**
     * command: CW
     * meaning: write configuration value to register
     * example: "CWnnn,nnn"
     * standard: Easycomm 3
     */
    typedef struct EasycommSetConfigRegister
    {
        EasycommCommandId commandId;
        uint16_t registerNumber;
        EasycommConfigRegisterValue value;
    } EasycommSetConfigRegister;

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
    typedef struct EasycommDoReset
    {
        EasycommCommandId commandId;
    } EasycommDoReset;

    /**
     * command: PARK
     * meaning: park
     * example: "PARK"
     * standard: Easycomm ?
     */
    typedef struct EasycommDoPark
    {
        EasycommCommandId commandId;
    } EasycommDoPark;

    /*!
     * Convenience union for cast in between message types.
     */
    typedef union EasycommPayload
    {
        EasycommCommandId commandId;
        EasycommSingleLine singleLine;
        EasycommSetAzimuth setAzimuth;
        EasycommGetAzimuth getAzimuth;
        EasycommSetElevation setElevation;
        EasycommGetElevation getElevation;
        EasycommSetUplinkFrequency setUplinkFrequency;
        EasycommGetUplinkFrequency getUplinkFrequency;
        EasycommSetDownlinkFrequency setDownlinkFrequency;
        EasycommGetDownlinkFrequency getDownlinkFrequency;
        EasycommSetUplinkMode setUplinkMode;
        EasycommGetUplinkMode getUplinkMode;
        EasycommSetDownlinkMode setDownlinkMode;
        EasycommGetDownlinkMode getDownlinkMode;
        EasycommSetUplinkRadio setUplinkRadio;
        EasycommGetUplinkRadio getUplinkRadio;
        EasycommSetDownlinkRadio setDownlinkRadio;
        EasycommGetDownlinkRadio getDownlinkRadio;
        EasycommDoMoveLeft doMoveLeft;
        EasycommDoMoveRight doMoveRight;
        EasycommDoMoveUp doMoveUp;
        EasycommDoMoveDown doMoveDown;
        EasycommDoStopAzimuthMove doStopAzimuthMove;
        EasycommDoStopElevationMove doStopElevationMove;
        EasycommAcquisitionOfSignal acquisitionOfSignal;
        EasycommLossOfSignal lossOfSignal;
        EasycommSetDigitalOutput setDigitalOutput;
        EasycommGetDigitalInput getDigitalInput;
        EasycommGetAnalogueInput getAnalogueInput;
        EasycommSetTime setTime;
        EasycommGetTime getTime;
        EasycommGetVersion getVersion;
        EasycommSetVelocityLeft setVelocityLeft;
        EasycommGetVelocityLeft getVelocityLeft;
        EasycommSetVelocityRight setVelocityRight;
        EasycommGetVelocityRight getVelocityRight;
        EasycommSetVelocityUp setVelocityUp;
        EasycommGetVelocityUp getVelocityUp;
        EasycommSetVelocityDown setVelocityDown;
        EasycommGetVelocityDown getVelocityDown;
        EasycommGetConfigRegister getConfigRegister;
        EasycommSetConfigRegister setConfigRegister;
        EasycommGetStatusRegister getStatusRegister;
        EasycommGetErrorRegister getErrorRegister;
        EasycommDoReset doReset;
        EasycommDoPark doPark;
    } EasycommPayload;


    typedef union EasycommData
    {
        EasycommCommandId commandId;
        EasycommPayload as;
    } EasycommData;

#ifdef __cplusplus
}
#endif
