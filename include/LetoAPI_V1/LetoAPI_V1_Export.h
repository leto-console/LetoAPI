#pragma once

#if !defined LETO_API_V1_USE
#include <LetoAPI_V1/LetoAPI_V1_Version.h>
#define LETO_API_V1_USE LETO_API_V1_MINOR
#endif

#if LETO_API_V1_USE < 0
#error LETO_API_V1_USE must be a non-negative number
#endif

#ifdef _WIN32
    #ifdef LETOAPI_EXPORT_LIBRARY
        #define LETO_API_EXPORT __declspec(dllexport)
    #else
        #define LETO_API_EXPORT __declspec(dllimport)
    #endif
#else
    #define LETO_API_EXPORT //__attribute__((visibility("default")))
#endif
