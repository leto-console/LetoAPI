/**
 * @file AppEvent.h
 * @date Jun 02, 2026
 * @author Rakhimov T.
 */

#ifndef INC_ABI_APP_EVENT_H_
#define INC_ABI_APP_EVENT_H_

#include <stdint.h>
#include <stdbool.h>

#include <LetoABI/AppEventSources.h>

#pragma pack(push, 4)

/**
 * @brief Application event structure
 */
typedef struct AppEvent
{
	/// Event source (values from AppEventSources)
	uint16_t source;
	
	/// Event identifier
	uint16_t id;
	
	/// Event payload data
	uint32_t data;
} 
AppEvent;

#pragma pack(pop)

/**
 * @brief Function pointer type for comparing two events
 */
typedef bool (*AppEventComparator)(const AppEvent* e1, const AppEvent* e2);

#endif /* INC_ABI_APP_EVENT_H_ */
