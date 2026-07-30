/**
 * @file LobbyConnection.h
 * @date Jun 10, 2026
 * @author Rakhimov T.
 */

#ifndef INC_LETO_API_V1_LOBBY_LOBBY_CONNECTION_H_
#define INC_LETO_API_V1_LOBBY_LOBBY_CONNECTION_H_

#include <stdint.h>

#define LC_MEMBERS_COUNT 6

typedef enum
{
	LC_STATE_DISCONNECTED 	= 0x00,	///< No connection
	LC_STATE_JOINING		= 0x01,	///< Connection in progress (entering lobby)
	LC_STATE_CONNECTED		= 0x02,	///< Connection established
} 
LC_State;

#pragma pack(push, 2)

/**
 * @brief Callback for data reception handling
 *
 * @param[in] id Identifier of the sender
 * @param[in] data Received data buffer
 * @param[in] size Size of the received data
 */
typedef void (*LobbyConnection_V1_Callback)(uint32_t id, const void* data, uint32_t size);

/**
 * @brief Lobby connection data structure
 */
struct LobbyConnection_V1
{
	/// Lobby creator (owner)
	uint32_t owner;
    
	/// Application identifier
	uint16_t app_id;

	/// Number of connected members (including creator)
	uint16_t connected;

	/// Maximum allowed number of members
	uint16_t max_count;

	/// Lobby members
	uint32_t members[LC_MEMBERS_COUNT];
	
	/// Callback for data reception handling
	LobbyConnection_V1_Callback callback;

	/// Connection state
	uint8_t state;
};

#pragma pack(pop)

#ifdef __cplusplus
#include <type_traits>
static_assert(std::is_standard_layout<LobbyConnection_V1>::value, "LobbyConnection_V1 must be a standard layout type");
#endif

#endif /* INC_LETO_API_V1_LOBBY_LOBBY_CONNECTION_H_ */
