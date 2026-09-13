/**
 * @file BitmapAPI_V1.h
 * @date Sep 13, 2026
 * @author Rakhimov T.
 */

#ifndef INC_LETO_API_V1_BITMAP_BITMAP_API_V1_H_
#define INC_LETO_API_V1_BITMAP_BITMAP_API_V1_H_

#include <LetoAPI_V1/LetoAPI_V1_Def.h>
#include <LetoAPI_V1/Globals/LetoAllocator_V1.h>

#include <stdint.h>

// Align to 4-byte boundary
#pragma pack(push, 4)

/// Bitmap management functions
typedef struct BitmapAPI_V1
{
    /**
     * @brief Create bitmap
     * 
     * @param[in] allocator Allocator
     * @param[in] width Bitmap width
     * @param[in] height Bitmap height
     * 
     * @return Created bitmap or `nullptr` if failed
     */
    LetoBitmap_V1* (*const CreateBitmap)(const LetoAllocator_V1* allocator, uint16_t width, uint16_t height);

    /**
     * @brief Load bitmap from file
     * 
     * @param[in] allocator Allocator
     * @param[in] path Path to bitmap file
     * 
     * @return Loaded bitmap or `nullptr` if failed
     */
    LetoBitmap_V1* (*const LoadFromFile)(const LetoAllocator_V1* allocator, const char* path);

    /**
     * @brief Copy bitmap
     * 
     * @param[in] source Source bitmap
     * @param[in] allocator Allocator
     * 
     * @return Copied bitmap or `nullptr` if failed
     */
    LetoBitmap_V1* (*const CopyBitmap)(const LetoBitmap_V1* source, const LetoAllocator_V1* allocator);

    /**
     * @brief Get bitmap width
     * 
     * @param[in] bitmap Bitmap
     * 
     * @return Bitmap width or `0` if failed
     */
    uint32_t (*const GetWidth)(const LetoBitmap_V1* bitmap);

    /**
     * @brief Get bitmap height
     * 
     * @param[in] bitmap Bitmap
     * 
     * @return Bitmap height or `0` if failed
     */
    uint32_t (*const GetHeight)(const LetoBitmap_V1* bitmap);

    /**
     * @brief Set pixel state in bitmap
     * 
     * @param[in] bitmap Bitmap
     * @param[in] x X position
     * @param[in] y Y position
     * @param[in] state Pixel state
     */
    void (*const SetPixel)(LetoBitmap_V1* bitmap, uint32_t x, uint32_t y, bool state);

    /**
     * @brief Get pixel state from bitmap
     * 
     * @param[in] bitmap Bitmap
     * @param[in] x X position
     * @param[in] y Y position
     * 
     * @return Pixel state or `false` if failed
     */
    bool (*const GetPixel)(const LetoBitmap_V1* bitmap, uint32_t x, uint32_t y);

    /**
     * @brief Create resized copy of bitmap with specified target dimensions
     * 
     * @param[in] bitmap Source bitmap
     * @param[in] allocator Allocator for memory allocation
     * @param[in] target_width Target bitmap width
     * @param[in] target_height Target bitmap height
     * 
     * @return Resized bitmap copy or `nullptr` if failed
     * 
     * @note If target size > source: image is centered, edges filled with transparent (0)
     * @note If target size < source: image is cropped from center
     * @note Caller is responsible for freeing the returned bitmap memory
     */
    LetoBitmap_V1* (*const ResizeCopyBitmap)(
        const LetoBitmap_V1* bitmap, const LetoAllocator_V1* allocator, 
        uint32_t target_width, uint32_t target_height);

    /**
     * @brief Rotate bitmap by specified angle around center
     * 
     * @param[in] source Source bitmap (not modified)
     * @param[out] destination Destination bitmap for result (must have same dimensions)
     * @param[in] angle_degrees Rotation angle in degrees (positive = counter-clockwise)
     * 
     * @return `true` if rotation succeeded
     * @return `false` if dimensions mismatch or invalid data
     * 
     * @note Destination buffer is cleared before drawing
     * @warning source and destination must be different objects!
     */
    bool (*const RotateBitmap)(const LetoBitmap_V1* source, LetoBitmap_V1* destination, int16_t angle_degrees);

    /**
     * @brief Create outlined version of bitmap
     * 
     * @param[in] bitmap Source bitmap
     * @param[in] allocator Allocator for memory allocation
     * @param[in] radius Outline radius
     * 
     * @return Outlined bitmap or `nullptr` if failed
     */
    LetoBitmap_V1* (*const MakeOutlinedBitmap)(const LetoBitmap_V1* bitmap, const LetoAllocator_V1* allocator, int16_t radius);

    /**
     * @brief Create sticker version of bitmap with rounded corners
     * 
     * @param[in] bitmap Source bitmap
     * @param[in] allocator Allocator for memory allocation
     * @param[in] radius Corner radius
     * 
     * @return Sticker bitmap or `nullptr` if failed
     */
    LetoBitmap_V1* (*const MakeStickerBitmap)(LetoBitmap_V1* bitmap, const LetoAllocator_V1* allocator, int16_t radius);

} BitmapAPI_V1;

#pragma pack(pop)

#ifdef __cplusplus
#include <type_traits>
static_assert(std::is_standard_layout<BitmapAPI_V1>::value, "BitmapAPI_V1 must be a standard layout type");
#endif

#endif