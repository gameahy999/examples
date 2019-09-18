#include <iostream>
#include "test_const.h"

class Kindle {
public:
    Kindle(float price);
    ~Kindle();
private:
    float price_;
};

Kindle::Kindle(float price) : price_(price) {
    std::cout << "Kindle object constructor" << std::endl;
}

Kindle::~Kindle() {
    std::cout << "Kindle object deconstructor" << std::endl;
}

// const Kindle kk = Kindle(998.0);
// const float kKindlePrice = 998.0;
// extern const float kKindlePrice = 998.0;

void test_constVariables() {
    // std::cout << "const variable in " << __FILE__ << " is " << kKindlePrice << std::endl;
}
