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
