#include <iostream>
#include "grammer.h"

using namespace std;

OperatorTest::OperatorTest()
        : x_(0) {

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
