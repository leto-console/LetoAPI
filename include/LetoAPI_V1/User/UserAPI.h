/**
 * @file UserAPI_V1.h
 * @date May 24, 2026
 * @author Rakhimov T.
 */

#ifndef INC_LETO_API_V1_USER_USER_API_V1_H_
#define INC_LETO_API_V1_USER_USER_API_V1_H_

#include <LetoAPI_V1/LetoAPI_V1_Def.h>

#include <stdint.h>
#include <stdbool.h>

// Align to 4-byte boundary
#pragma pack(push, 4)

// User management functions
typedef struct UserAPI_V1
{
    /// @brief Get user space
    //NamedSpace* (*const GetUserSpace)();
    
    /// @brief Get avatar by identifier
    bool (*const GetAvatarByID)(uint32_t ID, LetoBitmap_V1* data);
    
} UserAPI_V1;

#pragma pack(pop)

#ifdef __cplusplus
#include <type_traits>
static_assert(std::is_standard_layout<UserAPI_V1>::value, "UserAPI_V1 must be a standard layout type");
#endif

#endif
