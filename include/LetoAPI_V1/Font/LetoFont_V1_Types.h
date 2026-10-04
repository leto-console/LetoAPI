/**
 * @file LetoFont_V1_Types.h
 * @date Oct 03, 2026
 * @author Rakhimov T.
 */

#ifndef INC_LETO_API_V1_FONT_LETO_FONT_V1_TYPES_H_
#define INC_LETO_API_V1_FONT_LETO_FONT_V1_TYPES_H_

#include <stdint.h>

typedef uint8_t LetoFont_V1_Type;

/**
 * @brief Font types
 */
typedef enum LetoFont_V1_Type_enum
{
    LFV1_NONE = 0,          ///< None type font
    LFV1_BASE_NORMAL,       ///< Base Normal font
    LFV1_BASE_BOLD,         ///< Base Bold font

    _LFV1_COUNT,            ///< Count of font types
} 
LetoFont_V1_Type_enum;

#endif
