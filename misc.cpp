#include <algorithm>
#include <iostream>
#include <vector>

#include "misc.h"

void displayIntVector(std::vector<int> &ivec) {
    for (auto item : ivec) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

void test_sortAlgorithms() {
    std::vector<int> ivec { 1, 4, 2, 9, 7, 3, 10};
    displayIntVector(ivec);
    struct CompPair {
        bool operator() (int x, int y) {
            return x > y;
        }
    };
    std::sort(ivec.begin(), ivec.end(), CompPair());
    displayIntVector(ivec);
}
