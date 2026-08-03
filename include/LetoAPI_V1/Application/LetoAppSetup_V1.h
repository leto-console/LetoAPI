/**
 * @file LetoEvent.h
 * @date May 27, 2026
 * @author Rakhimov T.
 */

#ifndef INC_LETO_API_V1_APPLICATION_LETO_APP_SETUP_H_
#define INC_LETO_API_V1_APPLICATION_LETO_APP_SETUP_H_

#include <LetoAPI_V1/LetoAPI_V1_Export.h>

#include <LetoAPI_V1/Application/LetoResult_V1.h>
#include <LetoAPI_V1/LetoAPI_V1.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Global initialization function for binary application
 */
extern LetoResult_V1 LetoAppSetup(const LetoAPI_V1* api);

#ifdef __cplusplus
}
#endif

#endif
