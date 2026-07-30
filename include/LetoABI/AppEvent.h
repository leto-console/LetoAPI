/**
 * @file AppEvent.h
 * @date Jun 02, 2026
 * @author Rakhimov T.
 */

#ifndef INC_ABI_APP_EVENT_H_
#define INC_ABI_APP_EVENT_H_

#include <stdint.h>

#include <ABI/AppEventSources.h>

#pragma pack(push, 4)

/**
 * @brief Событие для приложения
 */
struct AppEvent
{
	/// Источник события
	uint16_t source;
	
	/// Идентификатор события
	uint16_t id;
	
	/// Данные события
	uint32_t data;
};

#pragma pack(pop)

/**
 * @brief Тип функции для сравнения двух событий
 */
using AppEventComparator = bool(*)(const AppEvent& e1, const AppEvent& e2);

#endif /* INC_ABI_APP_EVENT_H_ */
