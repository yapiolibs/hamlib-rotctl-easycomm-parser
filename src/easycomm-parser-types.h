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
     * Command Id
     */
    typedef enum
    {
        EasycommInvalidId,
        EasycommSingleLineId,
        EasycommAzimuthId,
        EasycommElevationId,
        EasycommAzimuthElevationId,
    } EasycommCommandId;

    /**
     * Command string length exclusive '\n'
     */
    typedef enum EasycommCommandLength
    {
        EasycommSingleLineMinLength = 31,       // "AZa.a ELe.e UPuuu UUU DNddd DDD"
        EasycommSingleLineMaxLength = 47,       // "AZaaa.a ELeee.e UPuuuuuuuuu UUU DNddddddddd DDD"
        EasycommAzimuthMinLength = 5,           // "ACa.a"
        EasycommAzimuthMaxLength = 7,           // "AZaaa.a"
        EasycommElevationMinLength = 5,         // "ELe.e"
        EasycommElevationMaxLength = 7,         // "ELeee.e"
        EasycommAzimuthElevationMinLength = 11, // "AZa.a ELe.e"
        EasycommAzimuthElevationMaxLength = 15, // "AZaaa.a ELeee.e"
        EasycommElevationAzimuthMinLength = 11, // "ELe.e AZa.a"
        EasycommElevationAzimuthMaxLength = 15, // "ELeee.e AZaaa.a"
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

    /*!
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
        EasycommFrequency uplink_frequency;
        EasycommFrequency downlink_frequency;
        char mode_up[3];
        char mode_down[3];
    } EasycommSingleLine;

    /*!
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

    /*!
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

    /*!
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


    // ----- equals (equivalent to ==)

    bool easycommDataEquals(const EasycommData *a, const EasycommData *b);
    bool easycommPayloadEquals(const EasycommPayload *a, const EasycommPayload *b);
    bool easycommSingleLineEquals(const EasycommSingleLine *a, const EasycommSingleLine *b);
    bool easycommFrequencyEquals(const EasycommFrequency *a, const EasycommFrequency *b);
    bool easycommAzimuthEquals(const EasycommAzimuth *a, const EasycommAzimuth *b);
    bool easycommElevationEquals(const EasycommElevation *a, const EasycommElevation *b);
    bool easycommAzimuthElevationEquals(const EasycommAzimuthElevation *a, const EasycommAzimuthElevation *b);


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

#ifdef __cplusplus
}
#endif