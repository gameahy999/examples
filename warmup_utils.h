#ifndef __WARMUP_UTILS_H__
#define __WARMUP_UTILS_H__

#include <cstddef>
#include <cstdint>

// Return the crc32c of concat(A, data[0,n-1]) where init_crc is the
// crc32c of some string A.  Extend() is often used to maintain the
// crc32c of a stream of data.
uint32_t Extend(uint32_t init_crc, const char* data, size_t n);

#endif
