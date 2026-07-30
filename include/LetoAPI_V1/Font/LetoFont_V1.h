/**
 * @file LetoFont_V1.h
 * @date Jul 30, 2026
 * @author Rakhimov T.
 */

#ifndef INC_LETO_API_V1_FONT_LETO_FONT_V1_H_
#define INC_LETO_API_V1_FONT_LETO_FONT_V1_H_

#include <stdint.h>
#include <stdbool.h>

// Align to 4-byte boundary
#pragma pack(push, 4)

struct LetoFont_V1
{
    // ...
    bool none;
};

#pragma pack(pop)

#ifdef __cplusplus
#include <type_traits>
static_assert(std::is_standard_layout<LetoFont_V1>::value, "LetoFont_V1 must be a standard layout type");
#endif

#endif
