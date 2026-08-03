#pragma once

#if !defined LETO_API_V1_USE
#include <LetoAPI_V1/LetoAPI_V1_Version.h>
#define LETO_API_V1_USE LETO_API_V1_MINOR
#endif

#if LETO_API_V1_USE < 0
#error LETO_API_V1_USE must be a non-negative number
#endif
