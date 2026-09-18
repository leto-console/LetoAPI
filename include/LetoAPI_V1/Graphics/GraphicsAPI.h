/**
 * @file GraphicsAPI_V1.h
 * @date Sep 13, 2026
 * @author Rakhimov T.
 */

#ifndef INC_LETO_API_V1_GRAPHICS_GRAPHICS_API_V1_H_
#define INC_LETO_API_V1_GRAPHICS_GRAPHICS_API_V1_H_

#include <LetoAPI_V1/LetoAPI_V1_Def.h>
#include <LetoAPI_V1/Graphics/LetoColor_V1.h>

#include <stdint.h>

// Align to 4-byte boundary
#pragma pack(push, 4)

/// Graphics management functions
typedef struct GraphicsAPI_V1
{
    /**
     * @brief Draw bitmap on display at specified coordinates
     * 
     * @param[in] screen Target screen instance
     * @param[in] x Start X coordinate on screen
     * @param[in] y Start Y coordinate on screen
     * @param[in] bitmap Bitmap to draw
     * @param[in] color Drawing color
     * @param[in] inverse Inverse bitmap (1=0, 0=1)
     */
    void (*const DrawBitmap)(LetoScreen_V1* screen, int32_t x, int32_t y, const LetoBitmap_V1* bitmap, LetoColor_V1 color, bool inverse);

    /**
     * @brief Draw single pixel on display
     * 
     * @param[in] screen Target screen instance
     * @param[in] x X coordinate
     * @param[in] y Y coordinate
     * @param[in] color Pixel color
     */
    void (*const DrawPixel)(LetoScreen_V1* screen, int32_t x, int32_t y, LetoColor_V1 color);

    /**
     * @brief Draw a line between two points
     * 
     * @param[in] screen Target screen instance
     * @param[in] x1 Start X coordinate
     * @param[in] y1 Start Y coordinate
     * @param[in] x2 End X coordinate
     * @param[in] y2 End Y coordinate
     * @param[in] thickness Line thickness in pixels
     * @param[in] color Line color
     */
    void (*const DrawLine)(LetoScreen_V1* screen, int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t thickness, LetoColor_V1 color);

    /**
     * @brief Draw a rectangle
     * 
     * @param[in] screen Target screen instance
     * @param[in] x Top-left X coordinate
     * @param[in] y Top-left Y coordinate
     * @param[in] width Rectangle width
     * @param[in] height Rectangle height
     * @param[in] thickness Border thickness (if 0, rectangle is filled)
     * @param[in] color Drawing color
     */
    void (*const DrawRect)(LetoScreen_V1* screen, int32_t x, int32_t y, int32_t width, int32_t height, int32_t thickness, LetoColor_V1 color);

    /**
     * @brief Draw a rectangle with rounded corners
     * 
     * @param[in] screen Target screen instance
     * @param[in] x Top-left X coordinate
     * @param[in] y Top-left Y coordinate
     * @param[in] width Rectangle width
     * @param[in] height Rectangle height
     * @param[in] radius Corner radius
     * @param[in] thickness Border thickness (if 0, shape is filled)
     * @param[in] color Drawing color
     */
    void (*const DrawRoundRect)(LetoScreen_V1* screen, int32_t x, int32_t y, int32_t width, int32_t height, int32_t radius, int32_t thickness, LetoColor_V1 color);

    /**
     * @brief Draw an ellipse
     * 
     * @param[in] screen Target screen instance
     * @param[in] centerX Center X coordinate
     * @param[in] centerY Center Y coordinate
     * @param[in] width Horizontal diameter
     * @param[in] height Vertical diameter
     * @param[in] thickness Border thickness (if 0, ellipse is filled)
     * @param[in] color Drawing color
     */
    void (*const DrawEllipse)(LetoScreen_V1* screen, int32_t centerX, int32_t centerY, int32_t width, int32_t height, int32_t thickness, LetoColor_V1 color);

    /**
     * @brief Draw a triangle
     * 
     * @param[in] screen Target screen instance
     * @param[in] x1 First vertex X
     * @param[in] y1 First vertex Y
     * @param[in] x2 Second vertex X
     * @param[in] y2 Second vertex Y
     * @param[in] x3 Third vertex X
     * @param[in] y3 Third vertex Y
     * @param[in] thickness Border thickness (if 0, triangle is filled)
     * @param[in] color Drawing color
     */
    void (*const DrawTriangle)(LetoScreen_V1* screen, int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, int32_t thickness, LetoColor_V1 color);

} GraphicsAPI_V1;

#pragma pack(pop)

#ifdef __cplusplus
#include <type_traits>
static_assert(std::is_standard_layout<GraphicsAPI_V1>::value, "GraphicsAPI_V1 must be a standard layout type");
#endif

#endif