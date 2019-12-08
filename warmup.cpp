#include <cstring>
#include <fstream>
#include <iostream>

#include "warmup.h"
#include "warmup_utils.h"

static const bool kLittleEndian = __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__;
static const uint32_t kMaskDelta = 0xa282ead8ul;

// Return the crc32c of data[0,n-1]
inline uint32_t Value(const char* data, size_t n) {
    return Extend(0, data, n);
}

// Return a masked representation of crc.
//
// Motivation: it is problematic to compute the CRC of a string that
// contains embedded CRCs.  Therefore we recommend that CRCs stored
// somewhere (e.g., in files) should be masked before being stored.
inline uint32_t Mask(uint32_t crc) {
    // Rotate right by 15 bits and add a constant.
    return ((crc >> 15) | (crc << 17)) + kMaskDelta;
}

// Return the crc whose masked representation is masked_crc.
inline uint32_t Unmask(uint32_t masked_crc) {
    uint32_t rot = masked_crc - kMaskDelta;
    return ((rot >> 17) | (rot << 15));
}

inline uint32_t MaskedCrc(const char* data, size_t n) {
    return Mask(Value(data, n));
}

inline void EncodeFixed32(char* buf, uint32_t value) {
    memcpy(buf, &value, sizeof(value));
}

inline void EncodeFixed64(char* buf, uint64_t value) {
    memcpy(buf, &value, sizeof(value));
}

inline uint32_t DecodeFixed32(const char* ptr) {
    uint32_t result;
    memcpy(&result, ptr, sizeof(result));
    return result;
}

inline uint64_t DecodeFixed64(const char* ptr) {
    uint64_t result;
    memcpy(&result, ptr, sizeof(result));
    return result;
}

void PutFixed32(std::string* dst, uint32_t value) {
    char buf[sizeof(value)];
    EncodeFixed32(buf, value);
    dst->append(buf, sizeof(buf));
}

void PutFixed64(std::string* dst, uint64_t value) {
    char buf[sizeof(value)];
    EncodeFixed64(buf, value);
    dst->append(buf, sizeof(buf));
}

std::string ReadBinaryContentFromFile(const std::string& filename) {
    std::ifstream infile(filename, std::ios::binary);
    std::string str(std::istreambuf_iterator<char>(infile), {});
    return str;
}

void WriteBinaryContentToFile(const std::string& filename, const std::string& str) {
    std::ofstream outfile(filename, std::ios::binary);
    outfile << str;
    outfile.close();
}

void test_warmup() {
    std::cout << (kLittleEndian ? "little endian" : "big endian") << std::endl;
    std::cout << "warmup saved model" << std::endl;

    uint8_t length[8] = {0xc5, 0x59, 0x01, 0x0, 0x0, 0x0, 0x0, 0x0};
    uint32_t crc = MaskedCrc(reinterpret_cast<const char*>(length), 8);
    std::cout << "masked crc value: " << std::hex << crc << std::dec <<  std::endl;

    if (Unmask(crc) == Value(reinterpret_cast<const char*>(length), 8)) {
        std::cout << "Yes, it matches" << std::endl;
    } else {
        std::cout << "Error, there is something wrong" << std::endl;
    }

    // WriteBinaryContentToFile("Hello World!");
    std::string result = ReadBinaryContentFromFile("./resources/myrequest.txt");
    std::cout << "request file length: " << result.size() << std::endl;

    // TODO(ahy)
}
