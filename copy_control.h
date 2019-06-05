#ifndef __COPY_CONTROL_H__
#define __COPY_CONTROL_H__

#include <string>

class Person
{
public:
    Person();
    Person(int a, const std::string &name);
    Person(const Person &p);
    Person& operator=(const Person &p);
    Person& operator=(const Person &&p);

    void setAge(int age) {age_ = age;}
    int getAge() const {return age_;}
    const std::string& getName() const {return name_;}
    void setName(const std::string& name) {name_ = name;}

private:
    int age_;
    std::string name_;
};

void test_wasteOrNot();
void test_copyUniquePtr();
void test_copyControl();
void test_copyReference();
void test_copyFromStaticVariable();
void test_copyToVector();

#endif
