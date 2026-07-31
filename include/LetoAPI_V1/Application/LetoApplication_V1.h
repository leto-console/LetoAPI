/**
 * @file LetoApplication_V1.h
 * @date May 27, 2026
 * @author Rakhimov T.
 */

#ifndef INC_LETO_API_V1_APPLICATION_LETO_APPLICATION_V1_H_
#define INC_LETO_API_V1_APPLICATION_LETO_APPLICATION_V1_H_

#include <stdint.h>

#include <ABI/AppBinHeader.h>
#include <ABI/AppEvent.h>

#include <LetoAPI_V1/LetoAPI_V1.h>
#include <LetoAPI_V1/Application/LetoAppStatus_V1.h>
#include <LetoAPI_V1/Application/LetoResult_V1.h>
#include <LetoAPI_V1/Application/LetoScreen_V1.h>

#pragma pack(push, 4)

/**
 * @brief Leto OS application interface
 */
struct LetoApplication_V1
{
	/// Executable application header
	AppBinHeader Header;

	/**
	 * @brief Initialize application
	 */
	LetoResult_V1 (*Init) (const struct LetoAPI_V1* api);
	
	/**
	 * @brief Clean up and release application resources
	 */
	LetoResult_V1 (*Clean) ();

	/**
	 * @brief Get current application status
	 */
	LetoAppStatus_V1 (*GetStatus) ();
	
	/**
	 * @brief Process incoming event
	 *
	 * @return 
	 * - `APP_SUCCESS` if event was successfully handled
	 * 
	 * - `APP_UNSUPPORT` if event is not supported by application
	 */
	LetoResult_V1 (*ProcessEvent) (AppEvent event);
	
	/**
	 * @brief Render application UI
	 */
	LetoResult_V1 (*Draw) (struct LetoScreen_V1* screen);
	
	/**
	 * @brief Execute background tasks or main loop iteration
	 */
	LetoResult_V1 (*Loop) ();
	
};

#pragma pack(pop)

#ifdef __cplusplus
#include <type_traits>
static_assert(std::is_standard_layout<LetoApplication_V1>::value, "LetoApplication_V1 must be a standard layout type");
#endif

#endif
