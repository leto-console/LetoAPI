/**
 * @file AppEventSources.h
 * @date Jun 02, 2026
 * @author Rakhimov T.
 */

#ifndef INC_ABI_APP_EVENT_SOURCES_H_
#define INC_ABI_APP_EVENT_SOURCES_H_

/**
 * @brief Event sources
 */
typedef enum AppEventSources
{
	AE_None = 0, 			///< No event
	
	/**
	 * Global events
	 */
	AE_Global = 1,			///< Global events (system interrupts)
	
	/**
	 * Input events
	 */
	
	AE_Button = 16,			///< Button press / release
	AE_Encoder,				///< Rotary encoder turn
	AE_Discrete,			///< Discrete command
} 
AppEventSources;

#endif /* INC_ABI_APP_EVENT_SOURCES_H_ */
