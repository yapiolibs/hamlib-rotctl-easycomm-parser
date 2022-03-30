#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <inttypes.h>
#include "parser-types.h"

bool easycommParse(const char *buffer, EasycommData *parsed);

#ifdef __cplusplus
}
#endif