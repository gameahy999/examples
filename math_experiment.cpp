#include <iostream>
#include <math.h>
#include "math_experiment.h"

float sigmoid(float x) {
    return (1 / (1 + exp(-x)));
}

float cal(float x) {
    return 2 - 2 * sigmoid(x);
}

void test_sigmoid() {
    std::cout << cal(0.794344) << std::endl;
    std::cout << cal(1) << std::endl;
    std::cout << cal(0.794284) << std::endl;
    std::cout << cal(0) << std::endl;
    std::cout << cal(1000) << std::endl;
}
