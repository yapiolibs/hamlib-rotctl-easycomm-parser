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
        EasycommIdAzimuth,
        EasycommIdElevation,
        EasycommIdUplinkFrequency,
        EasycommIdDownlinkFrequency,
        EasycommIdUplinkMode,
        EasycommIdDownlinkMode,
        EasycommIdUplinkRadioNumber,
        EasycommIdDownlinkRadioNumber,
        EasycommIdMoveLeft,
        EasycommIdMoveRight,
        EasycommIdMoveUp,
        EasycommIdMoveDown,
        EasycommIdStopAzimuthMove,
        EasycommIdStopElevationMove,
        EasycommIdAcquisitionOfSignal,
        EasycommIdLossOfSignal,
        EasycommIdSetOutput,
        EasycommIdReadInput,
        EasycommIdReadAnalogueInput,
        EasycommIdSetTime,
        EasycommIdRequestVersion,
        EasycommIdVelocityLeft,
        EasycommIdVelocityRight,
        EasycommIdVelocityUp,
        EasycommIdVelocityDown,
        EasycommIdReadConfig,
        EasycommIdWriteConfig,
        EasycommIdGetStatusRegister,
        EasycommIdGetErrorRegister,
        EasycommIdsCount
    } EasycommCommandId;

    /**
     * Received command string and response string length constraints (exclusive '\n')
     */
    typedef enum EasycommCommandLength
    {
        // standard 1
        EasycommSingleLineMinLength = 27, // "AZa.a ELe.e UPuuu UUU DNddd DDD"

        // standard 2
        EasycommSingleLineMaxLength = 47,       // "AZaaa.a ELeee.e UPuuuuuuuuu UUU DNddddddddd DDD"
        EasycommAzimuthMinLength = 5,           // "ACa.a"
        EasycommAzimuthMaxLength = 7,           // "AZaaa.a"
        EasycommElevationMinLength = 5,         // "ELe.e"
        EasycommElevationMaxLength = 7,         // "ELeee.e"
        EasycommAzimuthElevationMinLength = 11, // "AZa.a ELe.e"
        EasycommAzimuthElevationMaxLength = 15, // "AZaaa.a ELeee.e"
        EasycommElevationAzimuthMinLength = 11, // "ELe.e AZa.a"
        EasycommElevationAzimuthMaxLength = 15, // "ELeee.e AZaaa.a"
        EasycommUplinkFrequencyMinLength = 3,   // "UPu"
        EasycommUplinkFrequencyMaxLength = 11,  // "UPuuuuuuuuu"
        EasycommDownlinkFrequencyMinLength = 3, // "DNd"
        EasycommDownlinkFrequencyMaxLength = 11,  // "DNddddddddd"
        EasycommUplinkModeMinLength = 3,          // "UMa"
        EasycommUplinkModeMaxLength = 5,          // "UMabc"
        EasycommDownlinkModeMinLength = 3,        // "DMa"
        EasycommDownlinkModeMaxLength = 5,        // "DMabc"
        EasycommDownlinkRadioNumberMinLength = 3, // "DRd"
        EasycommDownlinkRadioNumberMaxLength = 5, // "DRddd"
        EasycommUplinkRadioNumberMinLength = 3,   // "URu"
        EasycommUplinkRadioNumberMaxLength = 5,   // "URuuu"
        EasycommMoveLeftLength = 2,               // "ML"
        EasycommMoveRightLength = 2,              // "MR"
        EasycommMoveUpLength = 2,                 // "MU"
        EasycommMoveDownLength = 2,               // "MD"
        EasycommStopAzimuthMoveLength = 2,        // "SA"
        EasycommStopElevationMoveLength = 2,      // "SE"
        EasycommAcquisitionOfSignalLength = 2,    // "AO"  TODO: clarification needed
        EasycommLossOfSignalLength = 2,           // "LO"  TODO: clarification needed
        EasycommSetOutputMinLength = 5,           // "OPn,b" TODO: high vs low or set vs clear?
        EasycommSetOutputMaxLength = 7,           // "OPnnn,b"
        EasycommReadInputMinLength = 3,           // "IPn"
        EasycommReadInputMaxLength = 5,           // "IPnnn"
        EasycommReadAnalogueInputMinLength = 3,   // "An"
        EasycommReadAnalogueInputMaxLength = 5,   // "ANnnn"
        EasycommSetTimeMinLength = 13,            // "STY:m:d:h:M:s"
        EasycommSetTimeMaxLength = 19,            // "STYY:mm:dd:hh:MM:ss"
        EasycommRequestVersionLength = 2,         // "VE"

        EasycommResponseSingleLineLength = 47, // "AZaaa.a ELeee.e UPuuuuuuuuu UUU DNddddddddd DDD"
        EasycommResponseAzimuthLength = 7,     // "AZaaa.a"
        EasycommResponseElevationLength = 7,   // "ELeee.e"
        EasycommResponseAzimuthElevationLength = 15,   // "AZaaa.a ELeee.e"
        EasycommResponseElevationAzimuthLength = 15,   // "ELeee.e AZaaa.a"
        EasycommResponseUplinkFrequencyLength = 11,    // "UPuuuuuuuuu"
        EasycommResponseDownlinkFrequencyLength = 11,  // "DNddddddddd"
        EasycommResponseUplinkModeLength = 5,          // "UMabc"
        EasycommResponseDownlinkModeLength = 5,        // "DMabc"
        EasycommResponseDownlinkRadioNumberLength = 5, // "DRddd"
        EasycommResponseUplinkRadioNumberLength = 5,   // "URuuu"
        EasycommResponseAcquisitionOfSignalLength = 2, // "AO"  TODO: clarification needed
        EasycommResponseLossOfSignalLength = 2,        // "LO"  TODO: clarification needed
        EasycommResponseSetOutputLength = 7,           // "OPnnn,b"
        EasycommResponseReadInputLength = 5,           // "IPnnn"
        EasycommResponseReadAnalogueInputLength = 5,   // "ANnnn"
        EasycommResponseSetTimeLength = 19,            // "STYY:MM:DD:HH:MM:SS"
        EasycommResponseRequestVersionLength = 2,      // "VE"
        EasycommResponseAlarmLength = 32,              // "AL[a-zA-Z]{0,32}"

        // standard 3
        EasycommVelocityLeftMinLength = 3,   // "VLv"
        EasycommVelocityLeftMaxLength = 11,  // "VLvvvvvvvvv"
        EasycommVelocityRightMinLength = 3,  // "VRv"
        EasycommVelocityRightMaxLength = 11, // "VRvvvvvvvvv"
        EasycommVelocityUpMinLength = 3,     // "VUv"
        EasycommVelocityUpMaxLength = 11,    // "VUvvvvvvvvv"
        EasycommVelocityDownMinLength = 3,   // "VDv"
        EasycommVelocityDownMaxLength = 11,  // "VDvvvvvvvvv"
        EasycommReadConfigMinLength = 3,     // "CRn"
        EasycommReadConfigMaxLength = 5,     // "CRnnn"
        EasycommWriteConfigMinLength = 5, // "CWn,v" // TODO: payload is not defined, see config hamlib config token
        EasycommWriteConfigMaxLength = 15,   // "CWnnn,vvvvvvvvv"
        EasycommGetStatusRegisterLength = 2, // "GS"
        EasycommGetErrorRegisterLength = 2,  // "GE"

        EasycommResponseVelocityLeftLength = 11,     // "VLvvvvvvvvv"
        EasycommResponseVelocityRightLength = 11,    // "VRvvvvvvvvv"
        EasycommResponseVelocityUpLength = 11,       // "VUvvvvvvvvv"
        EasycommResponseVelocityDownLength = 11,     // "VDvvvvvvvvv"
        EasycommResponseGetStatusRegisterLength = 3, // "GSs"
        EasycommResponseGetErrorRegisterLength = 3,  // "GEe"
        EasycommResponseReadConfigLength = 6 + 32,   // "CRnnn,[a-zA-Z]{32}"

        // TODO: VE IP OP AN are mentioned to be new in standard 3 but already defined in standard 2
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

    typedef struct EasycommConfigValue
    {
        union
        {
            uint8_t uint8;
            int8_t int8;
            uint16_t uint16;
            int16_t int16;
            uint32_t uint32;
            int32_t int32;
            uint8_t bytes[16];
            char str[16];
        } as;
    } EasycommConfigValue;


#ifdef __cplusplus
}
#endif