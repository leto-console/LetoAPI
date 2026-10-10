/**
 * @file LetoLanguage_V1.h
 * @date Oct 10, 2026
 * @author Rakhimov T.
 */

#ifndef INC_LETO_API_V1_GLOBALS_LETO_LANGUAGE_V1_H_
#define INC_LETO_API_V1_GLOBALS_LETO_LANGUAGE_V1_H_

#include <stdint.h>

typedef uint8_t LetoLanguage_V1;

/**
 * @brief Language
 */
typedef enum LetoLanguage_V1_enum
{
    LETO_LANG_V1_NONE = 0,      ///< None
    LETO_LANG_V1_ENG,           ///< English language (default language of system)
    LETO_LANG_V1_RUS,           ///< Russian language (Русский язык)
    
    _LETO_LANG_V1_COUNT,        ///< Count of languages
} 
LetoLanguage_V1_enum;

#endif
