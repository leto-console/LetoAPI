/**
 * @file LetoAllocator_V1.h
 * @date Jul 30, 2026
 * @author Rakhimov T.
 */

#ifndef INC_LETO_API_V1_GLOBALS_LETO_ALLOCATOR_V1_H_
#define INC_LETO_API_V1_GLOBALS_LETO_ALLOCATOR_V1_H_

#include <stdint.h>

// Align to 4-byte boundary
#pragma pack(push, 4)

struct LetoAllocator_V1
{
    /**
     * @brief Allocate memory in application dynamic memory
     * 
     * @param size Size of allocated memory in bytes
     * @return Pointer to the allocated memory block
     */
    void* (*const Alloc)(uint32_t size);

    /**
     * @brief Free memory in application dynamic memory
     * 
     * @param ptr Pointer to the memory block
     */
    void (*const Free)(const void* ptr);
};

#pragma pack(pop)

#ifdef __cplusplus
#include <type_traits>
static_assert(std::is_standard_layout<LetoAllocator_V1>::value, "LetoAllocator_V1 must be a standard layout type");
#endif

#endif
