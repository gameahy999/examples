#include <bitset>
#include <chrono>
#include <future>
#include <iostream>
#include <thread>

#include "standard_library.h"

// a non-optimized way of checking for prime numbers:
bool is_prime (int x) {
    std::cout << "Calculating. Please, wait...\n";
    for (int i = 2; i < x; ++i) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << i << std::endl;
        if (x % i == 0) {
            std::cout << "The factor is: " << i << std::endl;
            return false;
        }
    }
    return true;
}

void test_future() {
    // call is_prime(313222313) asynchronously:
    std::future<bool> fut = std::async(is_prime, 313222313);

    std::cout << "Checking whether 313222313 is prime.\n";
    // ...

    bool ret = fut.get();      // waits for is_prime to return

    if (ret) {
        std::cout << "It is prime!\n";
    } else {
        std::cout << "It is not prime.\n";
    }
}

void test_bitset() {
    std::bitset<64> bitvec;
    std::cout << sizeof(bitvec) << std::endl;
}
