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
    TestObject(TestObject&& obj) {
        std::cout << "move constructor" << std::endl;
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
    ~TestObject() {
        std::cout << "TestObject " << val_ << " deleted." << std::endl;
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

TestObject getTestObjectViaMove() {
    TestObject obj;
    obj.setValue(13);
    return std::move(obj);
}

}

static void test_rvo1() {
    rvo::TestObject obj1 = rvo::getTestObject();
    std::cout << obj1.getValue() << std::endl;
}

static void test_rvo2() {
    rvo::TestObject obj2 = rvo::getTestObjectViaMove();
    std::cout << obj2.getValue() << std::endl;
}

void test_rvo() {
    test_rvo1();

    std::cout << "======================" << std::endl;

    test_rvo2();
}
