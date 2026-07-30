/**
 * @file UserAPI_V1.h
 * @date May 24, 2026
 * @author Rakhimov T.
 */

#ifndef INC_LETO_API_V1_USER_USER_API_V1_H_
#define INC_LETO_API_V1_USER_USER_API_V1_H_

#include <stdint.h>
#include <stdbool.h>

//#include <Storage/NamedSpace.h>
//#include <Graphics/BitmapData.h>

// Align to 4-byte boundary
#pragma pack(push, 4)

/// User management functions
//struct UserAPI_V1
//{
//    /// @brief Get user space
//    NamedSpace* (*const GetUserSpace)();
//    
//    /// @brief Get avatar by identifier
//    bool (*const GetAvatarByID)(uint32_t ID, BitmapData* data);
//};

#pragma pack(pop)

#ifdef __cplusplus
#include <type_traits>
static_assert(std::is_standard_layout<UserAPI_V1>::value, "UserAPI_V1 must be a standard layout type");
#endif

#endif
