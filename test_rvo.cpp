#include <iostream>

#include "test_rvo.h"

namespace rvo {

class TestObject {
public:
    TestObject() {
        std::cout << "default constructor" << std::endl;
    }
    TestObject(const TestObject& obj) {
        std::cout << "copy constructor" << std::endl;
        this->val_ = obj.val_;
    }
    TestObject& operator=(const TestObject& rhs) {
        std::cout << "copy assignment" << std::endl;
        this->val_ = rhs.val_;
        return *this;
    }
    TestObject& operator=(TestObject&& rhs) {
        std::cout << "move assignment" << std::endl;
        this->val_ = rhs.val_;
        return *this;
    }

    void setValue(int val) {val_ = val;}
    int getValue() {return val_;}

private:
    int val_ = 0;
};

TestObject getTestObject() {
    TestObject obj;
    obj.setValue(12);
    return obj;
}

}

void test_rvo() {
    rvo::TestObject obj = rvo::getTestObject();
    std::cout << obj.getValue() << std::endl;
}
