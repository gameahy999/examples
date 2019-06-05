#include <iostream>

#include "parallel_programming.h"

static void openMPHelloWorld() {
#pragma omp parallel for
    for (int i = 0; i < 10; i++) {
        std::cout << i;
    }
    std::cout << std::endl;
}

void test_openMP() {
    openMPHelloWorld();
}
