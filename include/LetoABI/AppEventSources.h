/**
 * @file AppEventSources.h
 * @date Jun 02, 2026
 * @author Rakhimov T.
 */

#ifndef INC_ABI_APP_EVENT_SOURCES_H_
#define INC_ABI_APP_EVENT_SOURCES_H_

/**
 * @brief Источники событий
 */
typedef enum AppEventSources
{
	AE_None = 0, 			///< Отсутствие события
	
	/**
	 * Глобальные события
	 */
	AE_Global = 1,			///< Глобальные события (системные прерывания)
	
	/**
	 * События ввода
	 */
	
	AE_Button = 16,			///< Кнопка
	AE_Encoder,				///< Энкодер
	AE_Discrete,			///< Дискретная команда
} 
AppEventSources;

#endif /* INC_ABI_APP_EVENT_SOURCES_H_ */
