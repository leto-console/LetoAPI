/**
 * @file AppBinHeader.h
 * @date May 27, 2026
 * @author Rakhimov T.
 */

#ifndef INC_ABI_APP_BIN_HEADER_H_
#define INC_ABI_APP_BIN_HEADER_H_

#include <stdint.h>

/// Standard binary executable type
#define LETO_EXECUTABLE_TYPE_BIN "LETO_EXEC_BIN"

/// Game binary executable type
#define LETO_EXECUTABLE_TYPE_GAME "LETO_EXEC_GAME"

#define LETO_EXECUTABLE_INFO_VAR_NAME __leto_exec_info__
#define LETO_EXECUTABLE_INFO_VAR_TEXT "__leto_exec_info__"

#pragma pack(push, 4)

/**
 * @brief Information about the executable binary file (application)
 */
typedef struct AppBinHeader
{
	/// Magic string for validation
	char type[16] /*{ LETO_EXECUTABLE_TYPE_BIN }*/;

	/// API major version used by the application
	uint16_t api_version;

	/// Unique application identifier
	uint16_t id;
		
	/// Application name in English
	char en_name[32] {};
	
	/// Application name in Russian
	char ru_name[32] {};
} AppBinHeader;

#pragma pack(pop)

#ifdef __cplusplus
#include <type_traits>
static_assert(std::is_standard_layout<AppBinHeader>::value, "AppBinHeader must be a standard layout type");
#endif

#endif /* INC_ABI_APP_BIN_HEADER_H_ */
