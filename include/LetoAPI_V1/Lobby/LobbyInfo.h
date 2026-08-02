/**
 * @file LobbyInfo.h
 * @date Jun 10, 2026
 * @author Rakhimov T.
 */

#ifndef INC_LETO_API_V1_LOBBY_LOBBY_INFO_H_
#define INC_LETO_API_V1_LOBBY_LOBBY_INFO_H_

#include <stdint.h>

#pragma pack(push, 2)

/**
 * @brief Game lobby information
 */
struct LobbyInfo_V1
{
    /// Lobby creator (owner)
    uint32_t owner;
    
	/// Application identifier
	uint16_t app_id;

    /// Number of connected members (including creator)
    uint16_t connected;

    /// Maximum allowed number of members
    uint16_t max_count;

    /// Timestamp of the last room information transmission
    uint32_t last_info;
};

#pragma pack(pop)

#ifdef __cplusplus
#include <type_traits>
static_assert(std::is_standard_layout<LobbyInfo_V1>::value, "LobbyConnection_V1 must be a standard layout type");
#endif

#endif /* INC_LETO_API_V1_LOBBY_LOBBY_INFO_H_ */
