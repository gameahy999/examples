#include <iostream>

#include "closure.h"

void Line83WithClosure::doSomething() {
    int originX = 0;
    int originY = 0;
    int length = 100;
    int height = 80;

    auto calculate = [&]() {
        int targetX = originX + length;
        int targetY = originY + height;
        std::cout << "x = " << targetX << ", " << "y = " << targetY << std::endl;
    };

    auto drawRect = [=]() {
        std::cout << "Drawing..." << std::endl;
    };

    calculate();
    drawRect();
}

void test_closure() {
    Line83WithClosure closure = Line83WithClosure();
    closure.doSomething();
}
