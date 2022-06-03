#pragma once
#ifdef __cplusplus
extern "C"
{
#endif
/**
 * Easycomm 1, 2 and 3 references:
 * - description https://github.com/Hamlib/Hamlib/blob/master/rotators/easycomm/easycomm.txt
 * - implementation details https://github.com/Hamlib/Hamlib/blob/master/rotators/easycomm/easycomm.c
 */
#include <inttypes.h>
#include <stdbool.h>

    /**
     * Status mapping
     */
    typedef enum
    {
        EasycommStatusInvalid,
        EasycommStatusIdle,
        EasycommStatusMoving,
        EasycommStatusPointing,
        EasycommStatusError
    } EasycommStatusRegister;

    /**
     * Error mapping
     */
    typedef enum
    {
        EasycommErrorInvalid,
        EasycommErrorSensor,
        EasycommErrorJam,
        EasycommErrorHoming,
    } EasycommErrorRegister;

    /**
     * Command Id
     * note: do not assign values to enum items
     */
    typedef enum
    {
        EasycommIdInvalid,
        EasycommIdSingleLine,
        EasycommIdSetAzimuth,
        EasycommIdGetAzimuth,
        EasycommIdSetElevation,
        EasycommIdGetElevation,
        EasycommIdSetUplinkFrequency,
        EasycommIdGetUplinkFrequency,
        EasycommIdSetDownlinkFrequency,
        EasycommIdGetDownlinkFrequency,
        EasycommIdSetUplinkMode,
        EasycommIdGetUplinkMode,
        EasycommIdSetDownlinkMode,
        EasycommIdGetDownlinkMode,
        EasycommIdSetUplinkRadio,
        EasycommIdGetUplinkRadio,
        EasycommIdSetDownlinkRadio,
        EasycommIdGetDownlinkRadio,
        EasycommIdDoMoveLeft,
        EasycommIdDoMoveRight,
        EasycommIdDoMoveUp,
        EasycommIdDoMoveDown,
        EasycommIdDoStopAzimuthMove,
        EasycommIdDoStopElevationMove,
        EasycommIdAcquisitionOfSignal,
        EasycommIdLossOfSignal,
        EasycommIdSetDigitalOutput,
        EasycommIdGetDigitalInput,
        EasycommIdGetAnalogueInput,
        EasycommIdSetTime,
        EasycommIdGetTime,
        EasycommIdGetVersion,
        EasycommIdSetVelocityLeft,
        EasycommIdGetVelocityLeft,
        EasycommIdSetVelocityRight,
        EasycommIdGetVelocityRight,
        EasycommIdSetVelocityUp,
        EasycommIdGetVelocityUp,
        EasycommIdSetVelocityDown,
        EasycommIdGetVelocityDown,
        EasycommIdSetConfigRegister,
        EasycommIdGetConfigRegister,
        EasycommIdGetStatusRegister,
        EasycommIdGetErrorRegister,
        EasycommIdDoReset,
        EasycommIdDoPark,
        EasycommIdsCount
    } EasycommCommandId;

    /**
     * Received command string and response string length constraints (exclusive '\n')
     */
    typedef enum EasycommCommandLength
    {
        // standard 1 - requests
        EasycommSingleLineMinLength = 27, // "AZa.a ELe.e UPuuu UUU DNddd DDD"

        // standard 2 - requests
        EasycommSingleLineMaxLength = 47,  // "AZaaa.a ELeee.e UPuuuuuuuuu UUU DNddddddddd DDD"
        EasycommSetAzimuthMinLength = 5,   // "ACa.a"
        EasycommSetAzimuthMaxLength = 7,   // "AZaaa.a"
        EasycommGetAzimuthLength = 2,      // "AZ"
        EasycommSetElevationMinLength = 5, // "ELe.e"
        EasycommSetElevationMaxLength = 7, // "ELeee.e"
        EasycommGetElevationLength = 2,    // "EL"
        EasycommSetUplinkFrequencyMinLength = 3,    // "UPu"
        EasycommSetUplinkFrequencyMaxLength = 11,   // "UPuuuuuuuuu"
        EasycommGetUplinkFrequencyLength = 2,       // "UP"
        EasycommSetDownlinkFrequencyMinLength = 3,  // "DNd"
        EasycommSetDownlinkFrequencyMaxLength = 11, // "DNddddddddd"
        EasycommGetDownlinkFrequencyLength = 2,     // "DN"
        EasycommSetUplinkModeMinLength = 3,         // "UMa"
        EasycommSetUplinkModeMaxLength = 5,         // "UMabc"
        EasycommGetUplinkModeLength = 2,            // "UM"
        EasycommSetDownlinkModeMinLength = 3,       // "DMa"
        EasycommSetDownlinkModeMaxLength = 5,       // "DMabc"
        EasycommGetDownlinkModeLength = 2,          // "DM"
        EasycommSetDownlinkRadioMinLength = 3,      // "DRd"
        EasycommSetDownlinkRadioMaxLength = 5,      // "DRddd"
        EasycommGetDownlinkRadioLength = 2,         // "DR"
        EasycommSetUplinkRadioMinLength = 3,        // "URu"
        EasycommSetUplinkRadioMaxLength = 5,        // "URuuu"
        EasycommGetUplinkRadioLength = 2,           // "UR"
        EasycommDoMoveLeftLength = 2,               // "ML"
        EasycommDoMoveRightLength = 2,              // "MR"
        EasycommDoMoveUpLength = 2,                 // "MU"
        EasycommDoMoveDownLength = 2,               // "MD"
        EasycommDoStopAzimuthMoveLength = 2,        // "SA"
        EasycommDoStopElevationMoveLength = 2,      // "SE"
        EasycommAcquisitionOfSignalLength = 2,      // "AO"  TODO: clarification needed
        EasycommLossOfSignalLength = 2,             // "LO"  TODO: clarification needed
        EasycommSetDigitalOutputMinLength = 5,      // "OPn,b" TODO: high vs low or set vs clear?
        EasycommSetDigitalOutputMaxLength = 7,      // "OPnnn,b"
        EasycommGetDigitalInputMinLength = 3,       // "IPn"
        EasycommGetDigitalInputMaxLength = 5,       // "IPnnn"
        EasycommGetAnalogueInputMinLength = 3,      // "An"
        EasycommGetAnalogueInputMaxLength = 5,      // "ANnnn"
        EasycommSetTimeMinLength = 13,              // "STY:m:d:h:M:s"
        EasycommSetTimeMaxLength = 19,              // "STYY:mm:dd:hh:MM:ss"
        EasycommGetTimeLength = 2,                  // "ST"
        EasycommGetVersionLength = 2,               // "VE"

        // standard 2 - responses
        EasycommResponseSingleLineLength = 47, // "AZaaa.a ELeee.e UPuuuuuuuuu UUU DNddddddddd DDD"
        EasycommResponseAzimuthLength = 7,     // "AZaaa.a"
        EasycommResponseElevationLength = 7,   // "ELeee.e"
        EasycommResponseUplinkFrequencyLength = 11,    // "UPuuuuuuuuu"
        EasycommResponseDownlinkFrequencyLength = 11,  // "DNddddddddd"
        EasycommResponseUplinkModeLength = 5,          // "UMabc"
        EasycommResponseDownlinkModeLength = 5,        // "DMabc"
        EasycommResponseDownlinkRadioLength = 5,       // "DRddd"
        EasycommResponseUplinkRadioLength = 5,         // "URuuu"
        EasycommResponseAcquisitionOfSignalLength = 2, // "AO"  TODO: clarification needed
        EasycommResponseLossOfSignalLength = 2,        // "LO"  TODO: clarification needed
        EasycommResponseOutputLength = 7,              // "OPnnn,b"
        EasycommResponseDigitalInputLength = 5,        // "IPnnn"
        EasycommResponseAnalogueInputLength = 5,       // "ANnnn"
        EasycommResponseTimeLength = 19,               // "STYY:MM:DD:HH:MM:SS"
        EasycommResponseVersionLength = 2,             // "VE"
        EasycommResponseAlarmLength = 32,              // "AL[a-zA-Z]{0,32}"

        // standard 3 - requests
        EasycommSetVelocityLeftMinLength = 3,    // "VLv"
        EasycommSetVelocityLeftMaxLength = 11,   // "VLvvvvvvvvv"
        EasycommGetVelocityLeftLength = 2,       // "VL"
        EasycommSetVelocityRightMinLength = 3,   // "VRv"
        EasycommSetVelocityRightMaxLength = 11,  // "VRvvvvvvvvv"
        EasycommGetVelocityRightLength = 2,      // "VR"
        EasycommSetVelocityUpMinLength = 3,      // "VUv"
        EasycommSetVelocityUpMaxLength = 11,     // "VUvvvvvvvvv"
        EasycommGetVelocityUpLength = 2,         // "VU"
        EasycommSetVelocityDownMinLength = 3,    // "VDv"
        EasycommSetVelocityDownMaxLength = 11,   // "VDvvvvvvvvv"
        EasycommGetVelocityDownLength = 2,       // "VD"
        EasycommGetConfigRegisterMinLength = 3,  // "CRn"
        EasycommGetConfigRegisterMaxLength = 5,  // "CRnnn"
                                                 // TODO rubienr: "CWn,v" payload is not defined,
                                                 //   see config hamlib config token
        EasycommSetConfigRegisterMinLength = 5,  // "CWn,v"
        EasycommSetConfigRegisterMaxLength = 15, // "CWnnn,vvvvvvvvv"
        EasycommGetStatusRegisterLength = 2,     // "GS"
        EasycommGetErrorRegisterLength = 2,      // "GE"
        EasycommDoResetLength = 5,               // "RESET"
        EasycommDoParkLength = 4,                // "PARK"

        // standard 3 - responses
        EasycommResponseVelocityLeftLength = 11,       // "VLvvvvvvvvv"
        EasycommResponseVelocityRightLength = 11,      // "VRvvvvvvvvv"
        EasycommResponseVelocityUpLength = 11,         // "VUvvvvvvvvv"
        EasycommResponseVelocityDownLength = 11,       // "VDvvvvvvvvv"
        EasycommResponseStatusRegisterLength = 3,      // "GSs"
        EasycommResponseErrorRegisterLength = 3,       // "GEe"
        EasycommResponseConfigRegisterLength = 6 + 32, // "CRnnn,[a-zA-Z]{32}"
    } EasycommCommandLength;


    typedef union EasycommFrequency
    {
        struct
        {
            uint32_t uint32;
            uint8_t array[4];
            struct
            {
                uint16_t low;
                uint16_t high;
            } dwords;
        } as;
    } EasycommFrequency;

    typedef struct EasycommConfigRegisterValue
    {
        union
        {
            uint8_t uint8;
            int8_t int8;
            uint16_t uint16;
            int16_t int16;
            uint32_t uint32;
            int32_t int32;
            uint8_t bytes[28]; // response example "CRx,[a-zA-Z]{0,26}"
            char str[28];      // response_host_buffer == 32 -> 32-len("CRx,") = 30-4 = 28
        } as;
    } EasycommConfigRegisterValue;


#ifdef __cplusplus
}
#endif
