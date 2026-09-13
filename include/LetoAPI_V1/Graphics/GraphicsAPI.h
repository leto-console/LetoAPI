/**
 * @file GraphicsAPI_V1.h
 * @date Sep 13, 2026
 * @author Rakhimov T.
 */

#ifndef INC_LETO_API_V1_GRAPHICS_GRAPHICS_API_V1_H_
#define INC_LETO_API_V1_GRAPHICS_GRAPHICS_API_V1_H_

#include <LetoAPI_V1/LetoAPI_V1_Def.h>
#include <LetoAPI_V1/Graphics/LetoColor_V1.hpp>

#include <stdint.h>

// Align to 4-byte boundary
#pragma pack(push, 4)

/// Graphics management functions
typedef struct GraphicsAPI_V1
{
    /**
     * @brief Draw bitmap on display at specified coordinates
     * @param[in] x Start X coordinate on screen
     * @param[in] y Start Y coordinate on screen
     * @param[in] bitmap Bitmap to draw
     * @param[in] color Drawing color (if display supports it)
     */
    void (*const DrawBitmap)(LetoScreen_V1* screen, int32_t x, int32_t y, const LetoBitmap_V1* bitmap, LetoColor_V1 color);

} GraphicsAPI_V1;

#pragma pack(pop)

#ifdef __cplusplus
#include <type_traits>
static_assert(std::is_standard_layout<GraphicsAPI_V1>::value, "GraphicsAPI_V1 must be a standard layout type");
#endif

#endif