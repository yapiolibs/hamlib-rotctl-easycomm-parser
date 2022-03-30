#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#include "easycomm-parser-types.h"
#include <stdbool.h>


    bool easycommParse(const char *buffer, EasycommData *parsed);

#ifdef __cplusplus
}
#endif