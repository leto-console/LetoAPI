/**
 * @file FileInfo.h
 * @date Oct 06, 2026
 * @author Rakhimov T.
 */

#ifndef INC_LETO_API_V1_FILE_FILE_INFO_H_
#define INC_LETO_API_V1_FILE_FILE_INFO_H_

#include <stdint.h>

#pragma pack(push, 2)

/**
 * @brief File information
 */
typedef struct FileInfo_V1
{
#ifdef __STM32__
    char path[32];       ///< Directory path (null-terminated, max 31 chars + '\0')
    char filename[32];   ///< Filename (null-terminated)
#else
    char path[260];      ///< Directory path (null-terminated, max 259 chars + '\0')
    char filename[64];   ///< Filename (null-terminated)
#endif
    uint32_t size;       ///< File size in bytes (0 indicates directory or empty file)};
    
} FileInfo_V1;
#pragma pack(pop)

#ifdef __cplusplus
#include <type_traits>
static_assert(std::is_standard_layout<FileInfo_V1>::value, "FileInfo_V1 must be a standard layout type");
#endif

#endif /* INC_LETO_API_V1_FILE_FILE_INFO_H_ */
