/**
 * @file GlobalsAPI_V1.h
 * @date May 23, 2026
 * @author Rakhimov T.
 */

#ifndef INC_LETO_API_V1_GLOBALS_GLOBALS_API_V1_H_
#define INC_LETO_API_V1_GLOBALS_GLOBALS_API_V1_H_

#include <stdint.h>
#include <stdbool.h>

#include <LetoAPI_V1/Globals/LetoAllocator_V1.h>

// Align to 4-byte boundary
#pragma pack(push, 4)

/// Global context functions
struct GlobalsAPI_V1
{
    // ===================================================
    //               Dynamic Memory Management            
    // ===================================================

    /// TODO: Warning! Potential single point of failure.
    /// The allocator can crash the entire application.
    /**
     * @brief Get application dynamic memory allocator
     */
    struct LetoAllocator_V1* (*const GetAllocator)();

    // ===================================================
    //                   State Management                 
    // ===================================================

    /**
     * @brief Get system debug mode state
     * @return `true` if enabled, `false` if disabled
     */
    bool (*const GetDebugMode)();

    /**
     * @brief Get number of milliseconds elapsed since MCU startup
     */
    uint32_t (*const GetCurrentMs)();

    /**
     * @brief Get device hardware identifier
     */
    uint32_t (*const GetDeviceID)();

};

#pragma pack(pop)

#ifdef __cplusplus
#include <type_traits>
static_assert(std::is_standard_layout<GlobalsAPI_V1>::value, "GlobalsAPI_V1 must be a standard layout type");
#endif

#endif
