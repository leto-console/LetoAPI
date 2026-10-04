/**
 * @file LetoTextStyle_V1.h
 * @date Oct 01, 2026
 * @author Rakhimov T.
 */

#ifndef INC_LETO_API_V1_GRAPHICS_LETO_TEXT_STYLE_V1_H_
#define INC_LETO_API_V1_GRAPHICS_LETO_TEXT_STYLE_V1_H_

#include <stdint.h>

// Align to 4-byte boundary
#pragma pack(push, 4)

/**
 * @brief Text style parameters
 */
typedef struct LetoTextStyle_V1
{
    uint8_t intersymbol_interval;   ///< Char spacing adjustment (pixels, can be 0)
    uint8_t line_spacing;           ///< Line spacing adjustment (pixels, can be 0)
    
    uint8_t rotation;               ///< Rotation: 0=0°, 1=90°, 2=180°, 3=270°
    uint8_t scale;                  ///< Font scale factor (0,1=normal, 2=2x, etc.)

} LetoTextStyle_V1;

#pragma pack(pop)

#ifdef __cplusplus
#include <type_traits>
static_assert(std::is_standard_layout<LetoTextStyle_V1>::value, "LetoTextStyle_V1 must be a standard layout type");
#endif

#endif
