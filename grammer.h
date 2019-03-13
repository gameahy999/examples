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

class Base {
public:
    void setAge(int i) {age = i;}
    int getAge() const {return age;}
protected:
    int age;
};

class Inherit : public Base {
public:
    void saySomething();
};

void test_inherit();
void test_referenceToStringInClass();
void test_referenceToString();
void test_operatorEqual();
void test_deleteNull();
void test_objectInitialize();
void test_typeid();

#endif
