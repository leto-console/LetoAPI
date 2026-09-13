/**
 * @file LetoColor_V1.h
 * @date Sep 13, 2026
 * @author Rakhimov T.
 */

#ifndef INC_LETO_API_V1_GRAPHICS_LETO_COLOR_V1_H_
#define INC_LETO_API_V1_GRAPHICS_LETO_COLOR_V1_H_

#include <stdint.h>

// Align to 4-byte boundary
#pragma pack(push, 4)

/**
 * @brief RGB Color structure
 */
typedef struct LetoColor_V1
{
    uint8_t R; ///< Red component (0-255)
    uint8_t G; ///< Green component (0-255)
    uint8_t B; ///< Blue component (0-255)

} LetoColor_V1;

#pragma pack(pop)

#ifdef __cplusplus
#include <type_traits>
static_assert(std::is_standard_layout<LetoColor_V1>::value, "LetoColor_V1 must be a standard layout type");
#endif

#endif
