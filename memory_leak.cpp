#include <chrono>
#include <cstring>
#include <iostream>
#include <thread>
#include <vector>
#include <unistd.h>

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

void initRandomInfrastructure() {
    srand(time(NULL));
}

inline int getRandomNumber(int low, int high) {
    return rand() % (high - low) + low;
}

#define BIG_SIZE 1024 * 1024 * 1024

void test_memoryUsedForString() {
    initRandomInfrastructure();

    std::vector<std::string> svec;
    for (int i = 0; i < BIG_SIZE; i++) {
        svec.push_back(std::to_string(getRandomNumber(1000, 9999)) +
                       ":" + std::to_string(getRandomNumber(1000, 9999)));
        svec[i].shrink_to_fit();
        // std::cout << svec[i] << std::endl;
        if (i % (1024 * 1024) == 0) {
            std::cout << i / (1024 * 1024) << std::endl;
        }
    }
    /*
    std::cout << svec[0].size() << std::endl;
    std::cout << svec[0].capacity() << std::endl;
    */
    svec.shrink_to_fit();

    for (;;) {} // hold the program here and observe the memory usage
}

void test_memoryUsedForCStyleString() {
    initRandomInfrastructure();

    std::vector<const char *> svec;
    static char buffer[16] = {0};
    for (int i = 0; i < BIG_SIZE; i++) {
        snprintf(buffer, 16, "%d:%d",
                 getRandomNumber(1000, 9999),
                 getRandomNumber(1000, 9999));
        char *str = new char[strlen(buffer) + 1];
        strncpy(str, buffer, strlen(buffer));
        // std::cout << str << std::endl;
        svec.push_back(str);

        if (i % (1024 * 1024) == 0) {
            std::cout << i / (1024 * 1024) << std::endl;
        }
    }
    svec.shrink_to_fit();

    for (;;) {}
}

void threadFunc(int n) {
    for (;;) {}
}

void test_memoryUsedForCStyleStringInArray() {
    std::cout << sizeof(char) << std::endl;
    std::cout << sizeof(char *) << std::endl;
    // std::thread t(threadFunc, 1);
    initRandomInfrastructure();
    std::cout << "Begin" << std::endl;

    // 8 Bytes * 1G = 8GB
    // char **svec = new (char *)[BIG_SIZE];
    char **svec = (char **) malloc(BIG_SIZE * sizeof(char *));
    memset(svec, 0, BIG_SIZE);

    static char buffer[16] = {0};
    for (int i = 0; i < BIG_SIZE; i++) {
        snprintf(buffer, 16, "%d:%d",
                 getRandomNumber(1000, 9999),
                 getRandomNumber(1000, 9999));

        // 10 Bytes * 1G = 10GB
        // char *str = new char[strlen(buffer) + 1];
        char *str = (char *) malloc((strlen(buffer) + 1) * sizeof(char));
        memset(str, 0, strlen(buffer) + 1);
        strncpy(str, buffer, strlen(buffer));

        svec[i] = str;

        if (i % (1024 * 1024) == 0) {
            std::cout << i / (1024 * 1024) << std::endl;
        }
    }

    std::cout << "End" << std::endl;
    for (;;) {}
}
