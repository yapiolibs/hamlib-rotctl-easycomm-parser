#include "parser-types.h"
#include <string.h>
#include <stdio.h>


void easycommFrequency(EasycommFrequency *d) {
    memset(d, 0, sizeof(EasycommFrequency));
}


void easycommSingleLine(EasycommSingleLine *d) {
    memset(d, 0, sizeof(EasycommSingleLine));
}


void easycommPayload(EasycommPayload *d) {
    memset(d, 0, sizeof(EasycommPayload));
}


void easycommData(EasycommData *d) {
    memset(d, 0, sizeof(EasycommData));
}


bool easycommFrequencyEquals(const EasycommFrequency *a, const EasycommFrequency *b) {
    return 0 == memcmp(a, b, sizeof(EasycommFrequency));
}


bool easycommSingleLineEquals(const EasycommSingleLine *a, const EasycommSingleLine *b) {
    return (a == NULL && b == NULL) ||
           ((a != NULL && b != NULL) &&
            a->azimuth == b->azimuth &&
            a->elevation == b->elevation &&
            a->uplink_frequency.as.uint32 == b->uplink_frequency.as.uint32 &&
            a->downlink_frequency.as.uint32 == b->downlink_frequency.as.uint32 &&
            a->mode_down[0] == b->mode_down[0] &&
            a->mode_down[1] == b->mode_down[1] &&
            a->mode_down[2] == b->mode_down[2] &&
            a->mode_up[0] == b->mode_up[0] &&
            a->mode_up[1] == b->mode_up[1] &&
            a->mode_up[2] == b->mode_up[2]);
}


bool easycommPayloadEquals(const EasycommPayload *a, const EasycommPayload *b) {
    return 0 == memcmp(a, b, sizeof(EasycommPayload));
}


bool easycommDataEquals(const EasycommData *a, const EasycommData *b) {
    return 0 == memcmp(a, b, sizeof(EasycommData));
}


void easycommFrequencyCopy(const EasycommFrequency *from, EasycommFrequency *to) {
    memcpy(to, from, sizeof(EasycommFrequency));
}


void easycommSingleLineCopy(const EasycommSingleLine *from, EasycommSingleLine *to) {
    memcpy(to, from, sizeof(EasycommSingleLine));
}


void easycommPayloadCopy(const EasycommPayload *from, EasycommPayload *to) {
    memcpy(to, from, sizeof(EasycommPayload));
}


void easycommDataCopy(const EasycommData *from, EasycommData *to) {
    memcpy(to, from, sizeof(EasycommData));
}


void easycommSingleLineSprintf(const EasycommSingleLine *from, char *to) {
    // example "AZaaa.a ELeee.e UPuuuuuuuuu UUU DNddddddddd DDD": 47 chars + \n

    sprintf(to,
#ifdef ARDUINO_AVR_MEGA2560
            "AZ%05.1f EL%05.1f UP%09lu %c%c%c DN%09lu %c%c%c",
#else
            "AZ%05.1f EL%05.1f UP%09u %c%c%c DN%09u %c%c%c",
#endif
            from->azimuth,
            from->elevation,
            from->uplink_frequency.as.uint32,
            from->mode_up[0], from->mode_up[1], from->mode_up[2],
            from->downlink_frequency.as.uint32,
            from->mode_down[0], from->mode_down[1], from->mode_down[2]);
}