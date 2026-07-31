/**
 * @file LetoAPI_V1_New.h
 * @date Jul 10, 2026
 * @author Rakhimov T.
 */

#ifndef INC_LETO_API_V1_LETO_API_V1_NEW_H_
#define INC_LETO_API_V1_LETO_API_V1_NEW_H_

#ifdef __cplusplus

#include <cstdint>
#include <LetoAPI_V1/Globals/LetoAllocator_V1.h>

// Placement new overload to work with the LetoAllocator_V1 interface
inline void* operator new(size_t size, LetoAllocator_V1* allocator) noexcept
{
    return allocator->Alloc(static_cast<uint32_t>(size));
}

// Placement new[] overload for arrays (if required)
inline void* operator new[](size_t size, LetoAllocator_V1* allocator) noexcept
{
    return allocator->Alloc(static_cast<uint32_t>(size));
}

// Placement delete overload (called automatically if the constructor throws an exception)
inline void operator delete(void* ptr, LetoAllocator_V1* allocator) noexcept
{
    allocator->Free(ptr);
}

// Placement delete[] overload for arrays
inline void operator delete[](void* ptr, LetoAllocator_V1* allocator) noexcept
{
    allocator->Free(ptr);
}

/// Custom placement new macro using the Leto API global allocator
#define leto_new new(leto_api_v1->Globals->GetAllocator())

/// Safely destroys an object and frees its memory using the specified allocator.
template <typename T>
inline void leto_delete(T* ptr) noexcept
{
    if (ptr)
    {
        ptr->~T();
        leto_api_v1->Globals->GetAllocator()->Free(ptr);
    }
}

#endif /* __cplusplus */

#endif /* INC_LETO_API_V1_LETO_API_V1_NEW_H_ */
