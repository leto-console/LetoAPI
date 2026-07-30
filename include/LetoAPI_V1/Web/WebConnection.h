/**
 * @file WebConnection.h
 * @date Jun 04, 2026
 * @author Rakhimov T.
 */

#ifndef INC_LETO_API_V1_WEB_WEB_CONNECTION_H_
#define INC_LETO_API_V1_WEB_WEB_CONNECTION_H_

#include <stdint.h>

typedef uint8_t WC_CHANNEL;
typedef uint8_t WC_PORT;

#define WC_CHANNEL_ALL 		0x00U;				///< Connection with all devices
#define WC_CHANNEL_UART 	0x01U;				///< Connection via UART
#define WC_CHANNEL_NRF 		0x02U;				///< Connection via nRF
#define WC_CHANNEL_MAX 		WC_CHANNEL_NRF;		///< Maximum channel variety

#define WC_PORT_PING		0x01U;				///< Port for ping requests
#define WC_PORT_INFO		0x02U;				///< Information port (heartbeat)
#define WC_PORT_SYSTEM 		0x20U;				///< Initial port for system ports (0x20...0x60 - 64 ports)
#define WC_PORT_INF_LOBBY	0x70U;				///< Port for lobby discovery and information exchange
#define WC_PORT_CON_LOBBY	0x77U;				///< Port for interaction within game lobbies
#define WC_PORT_APP 		0x80U;				///< Initial port for application interaction (0x80...0xC0 - 64 ports)

#pragma pack(push, 4)

/**
 * @brief Callback for data reception handling
 *
 * @param[in] channel Channel of the sender
 * @param[in] port Port of the sender
 * @param[in] id Identifier of the sender
 * @param[in] data Received data buffer
 * @param[in] size Size of the received data
 */
typedef void (*WebConnection_V1_Callback)(uint8_t channel, uint8_t port, uint32_t id, const void* data, uint32_t size);

/**
 * @brief Connection data structure
 */
struct WebConnection_V1
{
	/// Connection channel (COM, nRF, other) (0 for all)
	WC_CHANNEL channel;
	
	/// Connection port (system message, game message, etc.)
	WC_PORT port;
	
	/// Identifier of the target device (0 for broadcast)
	uint32_t id;
	
	/// Callback for data reception handling
	WebConnection_V1_Callback callback;

	/// Reserved for future function expansion
	uint32_t _reserved_[5];
};

#pragma pack(pop)

#ifdef __cplusplus
#include <type_traits>
static_assert(std::is_standard_layout<WebConnection_V1>::value, "WebConnection_V1 must be a standard layout type");
#endif

#endif /* INC_LETO_API_V1_WEB_WEB_CONNECTION_H_ */
