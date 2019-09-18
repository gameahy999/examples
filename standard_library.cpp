#include <algorithm>
#include <bitset>
#include <chrono>
#include <cstdlib>
#include <future>
#include <iostream>
#include <thread>
#include <vector>

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

class MockData {
public:
    explicit MockData(int d) : data(d) {}
    MockData() : data(0) {}
    ~MockData() {
        std::cout << "mock data: " << data << " destroyed" << std::endl;
    }

private:
    int data;
};

template <typename T>
static void displayVector(const std::vector<T>& ivec) {
    for (const auto& item : ivec) {
        std::cout << item << ", ";
    }
    std::cout << std::endl;
}

void test_resizingVector() {
    std::vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "ivec size(before resize): " << ivec.size() << std::endl;
    displayVector<int>(ivec);

    ivec.resize(5);
    std::cout << "ivec size(after resize): " << ivec.size() << std::endl;
    displayVector<int>(ivec);

    std::vector<MockData> dvec;
    dvec.reserve(10);
    dvec.emplace_back(MockData(0));
    dvec.emplace_back(MockData(1));
    dvec.emplace_back(MockData(2));
    dvec.emplace_back(MockData(3));
    dvec.emplace_back(MockData(4));

    dvec.resize(2);

    std::cout << "after resize dvec" << std::endl;
}

static float getRandomFloat() {
    float r = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
    return r;
}

void test_sort() {
    std::vector<float> fvec;
    for (int i = 0; i < 5; i++) {
        fvec.push_back(getRandomFloat());
    }
    displayVector<float>(fvec);

    std::sort(fvec.begin(), fvec.end(),
              [](const float& a, const float& b) {
                  return a > b;
              });

    displayVector<float>(fvec);
}
