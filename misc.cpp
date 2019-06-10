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

int callee(int a, int b, int c) {
    return a + b + c;
}

int calleeWith5Parameters(int a, int b, int c, int d, int e) {
    return a + b + c + d + e;
}

int calleeWithManyParameters(int a, int b, int c, int d, int e, int f,
                             int g, int h, int i, int j, int k, int l,
                             int m, int n, int o, int p, int q, int r) {
    return a + b + c + d + e + f + g + h + i + j + k + l + m + n + o + p + q + r;
}

int caller() {
    int ret = 0;
    ret = callee(1, 2, 3);
    ret += 5;

    int b = calleeWith5Parameters(6, 7, 8, 9, 10);
    ret += b;

    int c = calleeWithManyParameters(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18);
    ret += c;

    return ret;
}

void test_callerAndCallee() {
    std::cout << caller() << std::endl;
}

void test_callerAndCalleeFromOuterModule(int a, int b, int c) {
    std::cout << a + b + c << std::endl;
}
