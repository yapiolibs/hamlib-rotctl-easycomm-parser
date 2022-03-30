#include "easycomm-parser.h"
#include <stdio.h>
#include <string.h>


typedef bool (*ParserPredicate)(const char *);

typedef bool (*CommandReader)(const char *, EasycommData *);


typedef struct CommandParser {
    ParserPredicate isCommand;
    CommandReader parseCommand;
} CommandParser;


bool isEasycommISingleLine(const char *buffer) {
    // buffer: "AZaaa.a ELeee.e UPuuuuuuuuu UUU DNddddddddd DDD"
    // buffer length: 47 + '\n'
    if (buffer == NULL || strlen(buffer) != EasycommSingleLineLength) {
        return false;
    }

    return buffer[0] == 'A' && buffer[1] == 'Z';
}


bool readEasycommISingleLine(const char *buffer, EasycommData *parsed) {
    // buffer: "AZaaa.a ELeee.e UPuuuuuuuuu UUU DNddddddddd DDD"
    char c;
    parsed->commandId = EasycommIdSingleLine;

    uint8_t items = sscanf(buffer,
#ifdef ARDUINO_AVR_MEGA2560
            "%c%c%f %c%c%f %c%c%ld %c%c%c %c%c%ld %c%c%c",
#else
                           "%c%c%f %c%c%f %c%c%d %c%c%c %c%c%d %c%c%c",
#endif
                           &c, &c, &parsed->as.singleLine.azimuth,
                           &c, &c, &parsed->as.singleLine.elevation,
                           &c, &c, &parsed->as.singleLine.uplink_frequency.as.uint32,
                           &parsed->as.singleLine.mode_up[0], &parsed->as.singleLine.mode_up[1],
                           &parsed->as.singleLine.mode_up[2],
                           &c, &c, &parsed->as.singleLine.downlink_frequency.as.uint32,
                           &parsed->as.singleLine.mode_down[0], &parsed->as.singleLine.mode_down[1],
                           &parsed->as.singleLine.mode_down[2]);

    return items == 18;
}


bool easycommParse(const char *buffer, EasycommData *parsed) {
    static CommandParser parsers[1] = {
            {.isCommand=isEasycommISingleLine, .parseCommand=readEasycommISingleLine}
    };

    for (size_t i = sizeof(parsers) / sizeof(CommandParser); i > 0; i--) {
        if (parsers[i - 1].isCommand(buffer)) {
            return parsers[i - 1].parseCommand(buffer, parsed);
        }
    }

    return false;
}
