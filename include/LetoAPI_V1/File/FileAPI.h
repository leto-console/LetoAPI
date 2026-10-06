/**
 * @file FileAPI_V1.h
 * @date Oct 06, 2026
 * @author Rakhimov T.
 */

#ifndef INC_LETO_API_V1_FILE_FILE_API_V1_H_
#define INC_LETO_API_V1_FILE_FILE_API_V1_H_

#include <LetoAPI_V1/LetoAPI_V1_Def.h>
#include <LetoAPI_V1/File/FileInfo.h>

#include <stdint.h>

/// Opaque pointer to File handler
LETO_HANDLE(LetoFile_V1);

#define LFV1_ERROR (-1)

enum 
{
    LFM_V1_NONE,
    LFM_V1_READ,
    LFM_V1_WRITE,
    LFM_V1_APPEND,
};
typedef uint8_t LetoFileMode_V1;

enum LetoFileSeek_V1_enum
{
    LFS_V1_SEEK_SET,
    LFS_V1_SEEK_CUR,
    LFS_V1_SEEK_END,
};
typedef uint8_t LetoFileSeek_V1;

// Align to 4-byte boundary
#pragma pack(push, 4)

/// File management functions
typedef struct FileAPI_V1
{
    /**
     * @brief Scan the directory and get info
     *
     * @param[in] path Directory path
     * @param[out] array Array of FileInfo_V1 structures
     * @param[in] size Size of the array (max number of entries to fill)
     *
     * @return Count of found items (can be greater than 'size' if directory contains more files)
     */
    uint32_t (*const Scan)(const char* path, FileInfo_V1* array, uint32_t size);

    /**
     * @brief Open the file
     *
     * @param[in] path File path
     * @param[in] mode Open mode
     *
     * @return File handle ('NULL' if error)
     */
    LetoFile_V1* (*const Open)(const char* path, LetoFileMode_V1 mode);
    
    /**
     * @brief Close the file
     *
     * @param[in] file File handle
     *
     * @return Result (`-1` if error, `0` if successful)
     */
    int8_t (*const Close)(LetoFile_V1* file);

    /**
     * @brief Delete the file
     *
     * @param[in] path File or empty directory path
     *
     * @return Result (`-1` if error, `0` if successful)
     */
    int8_t (*const Delete)(const char* path);

    /**
     * @brief Read data from the file
     *
     * @param[in] file File handle
     * @param[out] buffer Data buffer
     * @param[in] size Size of data buffer
     *
     * @return Number of bytes read (`-1` if error)
     */
    int32_t (*const Read)(LetoFile_V1* file, void* buffer, uint32_t size);
    
    /**
     * @brief Write data to the file
     *
     * @param[in] file File handle
     * @param[in] buffer Data buffer
     * @param[in] size Size of data buffer
     *
     * @return Number of bytes written (`-1` if error)
     */
    int32_t (*const Write)(LetoFile_V1* file, const void* buffer, uint32_t size);

    /**
     * @brief Flush write buffers to physical media
     *
     * @param[in] file File handle
     *
     * @return Result (`-1` if error, `0` if successful)
     */
    int8_t (*const Flush)(LetoFile_V1* file);

    /**
     * @brief Seek read/write offset 
     *
     * @param[in] file File handle
     * @param[in] pos Offset value
     * @param[in] origin Origin position (e.g., start, current, end)
     *
     * @return Result (`-1` if error, `0` if successful)
     */
    int8_t (*const Seek)(LetoFile_V1* file, int32_t pos, LetoFileSeek_V1 origin);
        
    /**
     * @brief Get current read/write offset 
     *
     * @param[in] file File handle
     *
     * @return Current read/write offset (`-1` if error)
     */
    int32_t (*const Tell)(LetoFile_V1* file);
    
    // Future extensions:
    // bool (*const GetInfo)(const char* path, FileInfo_V1* info);
    // int8_t (*const Mkdir)(const char* path);

} FileAPI_V1;

#pragma pack(pop)

#ifdef __cplusplus
#include <type_traits>
static_assert(std::is_standard_layout<FileAPI_V1>::value, "FileAPI_V1 must be a standard layout type");
#endif

#endif /* INC_LETO_API_V1_FILE_FILE_API_V1_H_ */