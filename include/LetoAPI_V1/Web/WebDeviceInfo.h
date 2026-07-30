/**
 * @file WebDeviceInfo.h
 * @date Jun 04, 2026
 * @author Rakhimov T.
 */

#ifndef INC_LETO_API_V1_WEB_WEB_DEVICE_INFO_H_
#define INC_LETO_API_V1_WEB_WEB_DEVICE_INFO_H_

#include <stdint.h>

#pragma pack(push, 1)

typedef uint8_t WD_FLAG;

#define WD_FLAG_NONE 		(0x00U);
#define WD_FLAG_READY 		(0x01U << 0);

/**
 * @brief Network device information
 */
struct WebDeviceInfo_V1
{
	/// Connection channel (COM, nRF, other)
	uint8_t channel;

	/// Identifier
	uint32_t id;
		
	/// Avatar identifier
	uint32_t avatar_id;

	/// Active application identifier
	uint32_t app_id;
	
	/// Network name (UTF-8)
	char web_name[32];

	/// Lobby connection ownership status
	uint32_t lobby_owner;

	/// Lobby connection request status
	uint32_t joining_lobby;

	/// Device flags
	WD_FLAG flags;
};

#pragma pack(pop)

#ifdef __cplusplus
#include <type_traits>
static_assert(std::is_standard_layout<WebDeviceInfo_V1>::value, "WebDeviceInfo_V1 must be a standard layout type");
#endif

#endif /* INC_LETO_API_V1_WEB_WEB_DEVICE_INFO_H_ */
