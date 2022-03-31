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
     */
    typedef enum
    {
        EasycommIdInvalid,
        EasycommIdSingleLine,
        EasycommIdAzimuth,
        EasycommIdElevation,
        EasycommIdAzimuthElevation,
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
    } EasycommCommandId;

    /**
     * Command string length constraints (exclusive '\n')
     */
    typedef enum EasycommCommandLength
    {
        // standard 1
        EasycommSingleLineMinLength = 31, // "AZa.a ELe.e UPuuu UUU DNddd DDD"

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
        EasycommStopAzimuthMoveMinLength = 2,     // "SA"
        EasycommStopElevationMoveMinLength = 2,   // "SE"
        EasycommAcquisitionOfSignalMinLength = 2, // "AO"
        EasycommLossOfSignalMinLength = 2,        // "LO"
        EasycommSetOutputMinLength = 3,           // "OPn" TODO: high vs low or set vs clear?
        EasycommSetOutputMaxLength = 5,           // "OPnnn"
        EasycommReadInputMinLength = 3,           // "IPn"
        EasycommReadInputMaxLength = 5,           // "IPnnn"
        EasycommReadAnalogueInputMinLength = 3,   // "An"
        EasycommReadAnalogueInputMaxLength = 5,   // "ANnnn"
        EasycommSetTimeLength = 19,               // "STYY:MM:DD:HH:MM:SS"
        EasycommRequestVersionLength = 2,         // "VE"

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
        EasycommWriteConfigMinLength = 3, // "CWn" // TODO: payload is not defined, see config hamlib config token
        EasycommWriteConfigMaxLength = 5,    // "CWnnn"
        EasycommGetStatusRegisterLength = 2, // "GS"
        EasycommGetErrorRegisterLength = 2,  // "GE"

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
            } dword;
        } as;
    } EasycommFrequency;

    /**
     * command: single line
     * meaning: set/get AZ, EL, UP frequency, DN frequency, UP mode and DN mode
     * issued by: host (set), controller (push state)
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
        char modeUp[3];
        char modeDown[3];
    } EasycommSingleLine;

    /**
     * command: AZ
     * meaning: set/get Azimuth
     * issued by: host (set), controller (push state)
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
     * issued by: host (set), controller (push state)
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
     * command: AZ EL
     * meaning: Azimuth and Elevation
     * issued by: host (set), controller (push state)
     * parameters: not fixed width with 1 decimal [deg]
     * examples:
     * - "AZaaa.a ELeee.e"
     * - "AZaaa.a ELe.e"
     * - "AZa.a ELe.e"
     * Easycomm 2 standard
     */
    typedef struct EasycommAzimuthElevation
    {
        EasycommCommandId commandId;
        float azimuth;
        float elevation;
    } EasycommAzimuthElevation;

    /**
     * command:
     * meaning:
     * issued by:
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
     * issued by:
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
     * issued by:
     * parameters:
     * examples:
     * standard: Easycomm 2
     */
    typedef struct EasycommUplinkMode
    {
        EasycommCommandId commandId;
        char mode[3];
    } EasycommUplinkMode;

    /**
     * command:
     * meaning:
     * issued by:
     * parameters:
     * examples:
     * standard: Easycomm 2
     */
    typedef struct EasycommDownlinkMode
    {
        EasycommCommandId commandId;
        char mode[3];
    } EasycommDownlinkMode;

    /**
     * command:
     * meaning:
     * issued by:
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
     * issued by:
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
     * issued by:
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
     * issued by:
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
     * issued by:
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
     * issued by:
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
     * issued by:
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
     * issued by:
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
     * issued by:
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
     * issued by:
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
     * issued by:
     * parameters:
     * examples:
     * standard: Easycomm 2
     */
    typedef struct EasycommSetOutput
    {
        EasycommCommandId commandId;
        uint16_t number;
    } EasycommSetOutput;

    /**
     * command:
     * meaning:
     * issued by:
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
     * issued by:
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
     * issued by:
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
     * issued by:
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
     * issued by:
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
     * issued by:
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
     * issued by:
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
     * issued by:
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
     * issued by:
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
     * issued by:
     * parameters:
     * examples:
     * standard: Easycomm 3
     */
    typedef struct EasycommWriteConfig
    {
        EasycommCommandId commandId;
        uint16_t registerNumber;
        // TODO: paylod
    } EasycommWriteConfig;

    /**
     * command:
     * meaning:
     * issued by:
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
     * issued by:
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
        EasycommAzimuthElevation azimuthElevation;
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


    // ----- constructors

    void easycommData(EasycommData *d);
    void easycommPayload(EasycommPayload *d);
    void easycommSingleLine(EasycommSingleLine *d);
    void easycommFrequency(EasycommFrequency *d);
    void easycommAzimuth(EasycommAzimuth *d);
    void easycommElevation(EasycommElevation *d);
    void easycommAzimuthElevation(EasycommAzimuthElevation *d);
    void easycommUplinkFrequency(EasycommUplinkFrequency *d);
    void easycommDownlinkFrequency(EasycommDownlinkFrequency *d);
    void easycommUplinkMode(EasycommUplinkMode *d);
    void easycommDownlinkMode(EasycommDownlinkMode *d);
    void easycommUplinkRadioNumber(EasycommUplinkRadioNumber *d);
    void easycommDownlinkRadioNumber(EasycommDownlinkRadioNumber *d);
    void easycommMoveLeft(EasycommMoveLeft *d);
    void easycommMoveRight(EasycommMoveRight *d);
    void easycommMoveUp(EasycommMoveUp *d);
    void easycommMoveDown(EasycommMoveDown *d);
    void easycommStopAzimuthMove(EasycommStopAzimuthMove *d);
    void easycommStopElevationMove(EasycommStopElevationMove *d);
    void easycommAcquisitionOfSignal(EasycommAcquisitionOfSignal *d);
    void easycommLossOfSignal(EasycommLossOfSignal *d);
    void easycommSetOutput(EasycommSetOutput *d);
    void easycommReadInput(EasycommReadInput *d);
    void easycommReadAnalogueInput(EasycommReadAnalogueInput *d);
    void easycommSetTime(EasycommSetTime *d);
    void easycommRequestVersion(EasycommRequestVersion *d);
    void easycommVelocityLeft(EasycommVelocityLeft *d);
    void easycommVelocityRight(EasycommVelocityRight *d);
    void easycommVelocityUp(EasycommVelocityUp *d);
    void easycommVelocityDown(EasycommVelocityDown *d);
    void easycommReadConfig(EasycommReadConfig *d);
    void easycommWriteConfig(EasycommWriteConfig *d);
    void easycommGetStatusRegister(EasycommGetStatusRegister *d);
    void easycommGetErrorRegister(EasycommGetErrorRegister *d);

    // ----- equals (equivalent to ==)

    bool easycommDataEquals(const EasycommData *a, const EasycommData *b);
    bool easycommPayloadEquals(const EasycommPayload *a, const EasycommPayload *b);
    bool easycommSingleLineEquals(const EasycommSingleLine *a, const EasycommSingleLine *b);
    bool easycommFrequencyEquals(const EasycommFrequency *a, const EasycommFrequency *b);
    bool easycommAzimuthEquals(const EasycommAzimuth *a, const EasycommAzimuth *b);
    bool easycommElevationEquals(const EasycommElevation *a, const EasycommElevation *b);
    bool easycommAzimuthElevationEquals(const EasycommAzimuthElevation *a, const EasycommAzimuthElevation *b);
    bool easycommUplinkFrequencyEquals(const EasycommUplinkFrequency *a, const EasycommUplinkFrequency *b);
    bool easycommDownlinkFrequencyEquals(const EasycommDownlinkFrequency *a, const EasycommDownlinkFrequency *b);
    bool easycommUplinkModeEquals(const EasycommUplinkMode *a, const EasycommUplinkMode *b);
    bool easycommDownlinkModeEquals(const EasycommDownlinkMode *a, const EasycommDownlinkMode *b);
    bool easycommUplinkRadioNumberEquals(const EasycommUplinkRadioNumber *a, const EasycommUplinkRadioNumber *b);
    bool easycommDownlinkRadioNumberEquals(const EasycommDownlinkRadioNumber *a,
                                           const EasycommDownlinkRadioNumber *b);
    bool easycommMoveLeftEquals(const EasycommMoveLeft *a, const EasycommMoveLeft *b);
    bool easycommMoveRightEquals(const EasycommMoveRight *a, const EasycommMoveRight *b);
    bool easycommMoveUpEquals(const EasycommMoveUp *a, const EasycommMoveUp *b);
    bool easycommMoveDownEquals(const EasycommMoveDown *a, const EasycommMoveDown *b);
    bool easycommStopAzimuthMoveEquals(const EasycommStopAzimuthMove *a, const EasycommStopAzimuthMove *b);
    bool easycommStopElevationMoveEquals(const EasycommStopElevationMove *a, const EasycommStopElevationMove *b);
    bool easycommAcquisitionOfSignalEquals(const EasycommAcquisitionOfSignal *a,
                                           const EasycommAcquisitionOfSignal *b);
    bool easycommLossOfSignalEquals(const EasycommLossOfSignal *a, const EasycommLossOfSignal *b);
    bool easycommSetOutputEquals(const EasycommSetOutput *a, const EasycommSetOutput *b);
    bool easycommReadInputEquals(const EasycommReadInput *a, const EasycommReadInput *b);
    bool easycommReadAnalogueInputEquals(const EasycommReadAnalogueInput *a, const EasycommReadAnalogueInput *b);
    bool easycommSetTimeEquals(const EasycommSetTime *a, const EasycommSetTime *b);
    bool easycommRequestVersionEquals(const EasycommRequestVersion *a, const EasycommRequestVersion *b);
    bool easycommVelocityLeftEquals(const EasycommVelocityLeft *a, const EasycommVelocityLeft *b);
    bool easycommVelocityRightEquals(const EasycommVelocityRight *a, const EasycommVelocityRight *b);
    bool easycommVelocityUpEquals(const EasycommVelocityUp *a, const EasycommVelocityUp *b);
    bool easycommVelocityDownEquals(const EasycommVelocityDown *a, const EasycommVelocityDown *b);
    bool easycommReadConfigEquals(const EasycommReadConfig *a, const EasycommReadConfig *b);
    bool easycommWriteConfigEquals(const EasycommWriteConfig *a, const EasycommWriteConfig *b);
    bool easycommGetStatusRegisterEquals(const EasycommGetStatusRegister *a, const EasycommGetStatusRegister *b);
    bool easycommGetErrorRegisterEquals(const EasycommGetErrorRegister *a, const EasycommGetErrorRegister *b);


    // ----- copy (equivalent to =, shallow copy)

    void easycommDataCopy(const EasycommData *from, EasycommData *to);
    void easycommPayloadCopy(const EasycommPayload *from, EasycommPayload *to);
    void easycommSingleLineCopy(const EasycommSingleLine *from, EasycommSingleLine *to);
    void easycommFrequencyCopy(const EasycommFrequency *from, EasycommFrequency *to);
    void easycommAzimuthCopy(const EasycommAzimuth *from, EasycommAzimuth *to);
    void easycommElevationCopy(const EasycommElevation *from, EasycommElevation *to);
    void easycommAzimuthElevationCopy(const EasycommAzimuthElevation *from, EasycommAzimuthElevation *to);


    // ----- command to string conversions

    void easycommSingleLineSprintf(const EasycommSingleLine *from, char *to);
    void easycommAzimuthSprintf(const EasycommAzimuth *from, char *to);
    void easycommElevationSprintf(const EasycommElevation *from, char *to);
    void easycommAzimuthElevationSprintf(const EasycommAzimuthElevation *from, char *to);
    void easycommUplinkFrequencySprintf(const EasycommUplinkFrequency *from, char *to);
    void easycommDownlinkFrequencySprintf(const EasycommDownlinkFrequency *from, char *to);
    void easycommUplinkModeSprintf(const EasycommUplinkMode *from, char *to);
    void easycommDownlinkModeSprintf(const EasycommDownlinkMode *from, char *to);
    void easycommUplinkRadioNumberSprintf(const EasycommUplinkRadioNumber *from, char *to);
    void easycommDownlinkRadioNumberSprintf(const EasycommDownlinkRadioNumber *from, char *to);
    void easycommMoveLeftSprintf(const EasycommMoveLeft *from, char *to);
    void easycommMoveRightSprintf(const EasycommMoveRight *from, char *to);
    void easycommMoveUpSprintf(const EasycommMoveUp *from, char *to);
    void easycommMoveDownSprintf(const EasycommMoveDown *from, char *to);
    void easycommStopAzimuthMoveSprintf(const EasycommStopAzimuthMove *from, char *to);
    void easycommStopElevationMoveSprintf(const EasycommStopElevationMove *from, char *to);
    void easycommAcquisitionOfSignalSprintf(const EasycommAcquisitionOfSignal *from, char *to);
    void easycommLossOfSignalSprintf(const EasycommLossOfSignal *from, char *to);
    void easycommSetOutputSprintf(const EasycommSetOutput *from, char *to);
    void easycommReadInputSprintf(const EasycommReadInput *from, char *to);
    void easycommReadAnalogueInputSprintf(const EasycommReadAnalogueInput *from, char *to);
    void easycommSetTimeSprintf(const EasycommSetTime *from, char *to);
    void easycommRequestVersionSprintf(const EasycommRequestVersion *from, char *to);
    void easycommVelocityLeftSprintf(const EasycommVelocityLeft *from, char *to);
    void easycommVelocityRightSprintf(const EasycommVelocityRight *from, char *to);
    void easycommVelocityUpSprintf(const EasycommVelocityUp *from, char *to);
    void easycommVelocityDownSprintf(const EasycommVelocityDown *from, char *to);
    void easycommReadConfigSprintf(const EasycommReadConfig *from, char *to);
    void easycommWriteConfigSprintf(const EasycommWriteConfig *from, char *to);
    void easycommGetStatusRegisterSprintf(const EasycommGetStatusRegister *from, char *to);
    void easycommGetErrorRegisterSprintf(const EasycommGetErrorRegister *from, char *to);


#ifdef __cplusplus
}
#endif