#include <cstring>
#include <iostream>

#include "warmup.h"

constexpr bool kLittleEndian = __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__;

inline uint32_t DecodeFixed32(const char* ptr) {
    // Load the raw bytes
    uint32_t result;
    memcpy(&result, ptr, sizeof(result));  // gcc optimizes this to a plain load
    return result;
}

inline uint64_t DecodeFixed64(const char* ptr) {
    // Load the raw bytes
    uint64_t result;
    memcpy(&result, ptr, sizeof(result));  // gcc optimizes this to a plain load
    return result;
}

void test_warmup() {
    std::cout << (kLittleEndian ? "little endian" : "big endian") << std::endl;
    std::cout << "warmup saved model" << std::endl;
}
