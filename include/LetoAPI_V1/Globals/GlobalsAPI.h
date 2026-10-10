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
#include <LetoAPI_V1/Globals/LetoLanguage_V1.h>

// Align to 4-byte boundary
#pragma pack(push, 4)

/// Global context functions
typedef struct GlobalsAPI_V1
{
    // ===================================================
    //               Dynamic Memory Management            
    // ===================================================

    /**
     * @brief Get application dynamic memory allocator
     */
    const LetoAllocator_V1* (*const GetAllocator)(void);

    // ===================================================
    //                   State Management                 
    // ===================================================

    /**
     * @brief Get system debug mode state
     * @return `true` if enabled, `false` if disabled
     */
    bool (*const GetDebugMode)(void);

    /**
     * @brief Get number of milliseconds elapsed since MCU startup
     */
    uint32_t (*const GetCurrentMs)(void);

    /**
     * @brief Get device hardware identifier
     */
    uint32_t (*const GetDeviceID)(void);

    /**
     * @brief Calculates the CRC16 checksum for a given data buffer.
     * 
     * @param[in] data   Pointer to the input data buffer.
     * @param[in] length Size of the data buffer in bytes.
     * 
     * @return The calculated 16-bit CRC value.
     */
    uint16_t (*const CalcCRC16)(const void* data, uint32_t length);

    /**
     * @brief Get application execution directory.
     * 
     * Always writes a null-terminated string. Truncates if buffer is too small.
     * 
     * @param[out] buffer Destination buffer.
     * @param[in] length Buffer size in bytes.
     * 
     * @return `true` on success, `false` if truncated or app not running.
     */
    bool (*const GetAppDir)(char* buffer, uint32_t length);

    /**
     * @brief Get current system language.
     */
    LetoLanguage_V1 (*const GetSystemLanguage) (void);

} GlobalsAPI_V1;

#pragma pack(pop)

#ifdef __cplusplus
#include <type_traits>
static_assert(std::is_standard_layout<GlobalsAPI_V1>::value, "GlobalsAPI_V1 must be a standard layout type");
#endif

#endif
