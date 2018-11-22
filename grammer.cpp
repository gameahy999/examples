#include <iostream>
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
