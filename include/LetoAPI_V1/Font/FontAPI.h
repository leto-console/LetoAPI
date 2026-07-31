/**
 * @file FontAPI_V1.h
 * @date May 30, 2026
 * @author Rakhimov T.
 */

#ifndef INC_LETO_API_V1_FONT_FONT_API_V1_H_
#define INC_LETO_API_V1_FONT_FONT_API_V1_H_

#include <LetoAPI_V1/LetoAPI_V1_Def.h>

#include <stdint.h>

// Align to 4-byte boundary
#pragma pack(push, 4)

/// Font management functions
typedef struct FontAPI_V1
{
    /**
     * @brief Get font
     * 
     * @param width Font width
     * @param height Font height
     * @param type Font type (0 - regular, 1 - small)
     */
    const LetoFont_V1* (*const GetFont)(uint32_t width, uint32_t height, uint32_t type);

} FontAPI_V1;

#pragma pack(pop)

#ifdef __cplusplus
#include <type_traits>
static_assert(std::is_standard_layout<FontAPI_V1>::value, "FontAPI_V1 must be a standard layout type");
#endif

#endif
