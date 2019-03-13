#include <iostream>
#include <string>
#include <typeinfo>

#include "grammer.h"

using namespace std;

OperatorTest::OperatorTest()
        : x_(0) {
    cout << "Constructor is called" << endl;
}

OperatorTest::~OperatorTest() {

}

void OperatorTest::operator ()(const int a) {
    cout << "a == " << a << endl;
}

//string& createTmpString() {
//    string tmp("Hello World!");
//    cout << tmp << endl;
//    return tmp;
//}

TestReference::TestReference() : s("Hi World!") {

}

std::string& TestReference::getStringReference() {
    return this->s;
}

void Inherit::saySomething() {

}

void test_inherit() {
    Inherit i = Inherit();
    i.setAge(12);
    std::cout << i.getAge() << std::endl;
}

void test_referenceToStringInClass() {
    TestReference *tr = new TestReference();
    string& tmp = tr->getStringReference();
    delete tr;

    cout << tmp << endl;
}

void test_referenceToString() {
    // it will trigger a warning message
    // string &s = createTmpString();
    // cout << s << endl;
}

void test_operatorEqual() {
     OperatorTest ot = OperatorTest();
     ot(12);
}

void test_deleteNull() {
    OperatorTest *pot = NULL;
    delete pot;
    cout << "Yes" << endl;
}

void test_objectInitialize() {
    // no need to write "OperatorTest ot = OperatorTest();" any more
    OperatorTest ot;
    ot(12);
}

class KnnSkuSearcher {
public:
    int a = 5;
};

void test_typeid() {
    OperatorTest ot;
    cout << typeid(ot).name() << endl;

    int a = 5;
    cout << typeid(a).name() << endl;

    KnnSkuSearcher s;
    cout << typeid(s).name() << endl;
}
