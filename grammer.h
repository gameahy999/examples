#ifndef __GRAMMER_H__
#define __GRAMMER_H__

#include <string>

class OperatorTest {
public:
    OperatorTest();
    ~OperatorTest();
    void operator()(const int a);
private:
    int x_;
};

class TestReference {
public:
    TestReference();
    std::string& getStringReference();
private:
    std::string s;
};

void test_referenceToStringInClass();
void test_referenceToString();
void test_operatorEqual();
void test_deleteNull();
void test_objectInitialize();

#endif
