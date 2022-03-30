#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#include "parser-types.h"
#include <inttypes.h>

    bool easycommParse(const char *buffer, EasycommData *parsed);

#ifdef __cplusplus
}
#endif