/**
 * @file AppEvent.h
 * @date Jun 02, 2026
 * @author Rakhimov T.
 */

#ifndef INC_ABI_APP_EVENT_H_
#define INC_ABI_APP_EVENT_H_

#include <stdint.h>
#include <stdbool.h>

#include <ABI/AppEventSources.h>

#pragma pack(push, 4)

/**
 * @brief Application event structure
 */
struct AppEvent
{
	/// Event source (values from AppEventSources)
	uint16_t source;
	
	/// Event identifier
	uint16_t id;
	
	/// Event payload data
	uint32_t data
};

#pragma pack(pop)

/**
 * @brief Function pointer type for comparing two events
 */
typedef bool (*AppEventComparator)(const struct AppEvent* e1, const struct AppEvent* e2);

#endif /* INC_ABI_APP_EVENT_H_ */
