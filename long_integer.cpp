#include <climits>
#include <iostream>

#include "long_integer.h"

void test_longInteger() {
    int size = 3; // both int and long are ok
    long count = LONG_MAX - 1;

    int model = count % size; // both int and long are ok
    std::cout << count << ", " << model << std::endl;

    for (int i = 0; i < 5; i++) {
        count = (count >= LONG_MAX ? 0 : count + 1);
        model = count % size;
        std::cout << count << ", " << model << std::endl;
    }
}

void simple_unpairing(int64_t id, int64_t& sku, int64_t& activity_id) {
    sku = static_cast<uint64_t>(id) >> 24;
    activity_id = id & 0xFFFFFF;
}

void test_int64() {
    int64_t sku = 0, activity_id = 0;
    simple_unpairing(64264169911006, sku, activity_id);
    std::cout << sku << std::endl;
    std::cout << activity_id << std::endl;

    simple_unpairing(-5, sku, activity_id);
    std::cout << sku << std::endl;
    std::cout << activity_id << std::endl;

    int64_t t = 0x1000000000000000;
    std::cout << t << std::endl;
}
