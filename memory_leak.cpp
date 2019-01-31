#include <chrono>
#include <iostream>
#include <thread>

#include "memory_leak.h"

#define MEMORY_SIZE 1024 * 1024 * 10

void func() {
    static int a = 0;
    for(;;) {
        // make the process at first in top command output
        a++;
        if (a % 100000000 == 0)
            std::cout << "Hello World" << std::endl;
    }
}

void test_memoryLeak() {
    std::thread t1(func);

    for (int i = 0; i < 10000; i++) {
        int *p = new int[MEMORY_SIZE];
        std::cout << "4 * MEMORY_SIZE bytes allocated." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        std::cout << p[MEMORY_SIZE-1] << std::endl;
        delete [] p;
    }

    t1.join();
}
