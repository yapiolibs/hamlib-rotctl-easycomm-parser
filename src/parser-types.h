#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <inttypes.h>


typedef enum {
    EasycommIdInvalid,
    EasycommIdSingleLine,
} EasycommCommandId;


typedef union EasycommFrequency {
    struct {
        uint32_t uint32;
        uint8_t array[4];
        struct {
            uint16_t low;
            uint16_t high;
        } dword;
    } as;
} EasycommFrequency;


typedef struct EasycommSingleLine {
    float azimuth; // [deg]
    float elevation; // [deg]
    EasycommFrequency uplink_frequency; // [Hz] 100 000 000 000
    EasycommFrequency downlink_frequency;  // [Hz]
    char mode_up[3];
    char mode_down[3];
} EasycommSingleLine;


typedef union EasycommPayload {
    EasycommSingleLine singleLine;
} EasycommPayload;


typedef struct EasycommData {
    EasycommCommandId commandId;
    EasycommPayload as;
} EasycommData;


void easycommFrequency(EasycommFrequency *d);

void easycommSingleLine(EasycommSingleLine *d);

void easycommPayload(EasycommPayload *d);

void easycommData(EasycommData *d);


bool easycommFrequencyEquals(const EasycommFrequency *a, const EasycommFrequency *b);

bool easycommSingleLineEquals(const EasycommSingleLine *a, const EasycommSingleLine *b);

bool easycommPayloadEquals(const EasycommPayload *a, const EasycommPayload *b);

bool easycommDataEquals(const EasycommData *a, const EasycommData *b);


void easycommFrequencyCopy(const EasycommFrequency *from, EasycommFrequency *to);

void easycommSingleLineCopy(const EasycommSingleLine *from, EasycommSingleLine *to);

void easycommPayloadCopy(const EasycommPayload *from, EasycommPayload *to);

void easycommDataCopy(const EasycommData *from, EasycommData *to);

void easycommSingleLineSprintf(const EasycommSingleLine *from, char *to);

#ifdef __cplusplus
}
#endif