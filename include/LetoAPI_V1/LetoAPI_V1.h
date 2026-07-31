/**
 * @file LetoAPI_V1.h
 * @date May 22, 2026
 * @author Rakhimov T.
 */

#ifndef INC_LETO_API_V1_LETO_API_V1_H_
#define INC_LETO_API_V1_LETO_API_V1_H_

#include <stdint.h>

#include <LetoAPI_V1/Text/TextAPI.h>
#include <LetoAPI_V1/Globals/GlobalsAPI.h>
#include <LetoAPI_V1/Web/WebAPI.h>
#include <LetoAPI_V1/User/UserAPI.h>
#include <LetoAPI_V1/Font/FontAPI.h>
#include <LetoAPI_V1/Math/MathAPI.h>
#include <LetoAPI_V1/Lobby/LobbyAPI.h>

// Align to 4-byte boundary
#pragma pack(push, 4)

typedef struct LetoAPI_V1
{
#if LETO_API_V1_USE >= 0

    /// API version details
    const struct VersionAPI
    {
        uint16_t major;		///< Major API version
        uint16_t minor;		///< Minor API version
    }
    *const Version;

    /// Text processing functions
    const TextAPI_V1* const Text;
    
    /// Global context functions
    const GlobalsAPI_V1* const Globals;

    /// Network interaction functions
    const WebAPI_V1* const Web;

    /// User management functions
    const UserAPI_V1* const User;

    /// Font management functions
    const FontAPI_V1* const Font;

    /// Mathematical functions
    const MathAPI_V1* const Math;

    /// Game lobby management functions
    const LobbyAPI_V1* const Lobby;

#endif /* LETO_API_V1_USE */
} LetoAPI_V1;

#pragma pack(pop)

#ifdef __cplusplus
#include <type_traits>
static_assert(std::is_standard_layout<LetoAPI_V1>::value, "LetoAPI_V1 must be a standard layout type");
#endif

#include <LetoAPI_V1/LetoAPI_V1_Instance.h>
#include <LetoAPI_V1/LetoAPI_V1_New.h>

#endif
