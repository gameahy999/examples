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

    int getAge() const {return age_;}
    std::string getName() const {return name_;}

private:
    int age_;
    std::string name_;
};

void test_copyUniquePtr();
void test_copyControl();
void test_copyReference();
void test_copyFromStaticVariable();

#endif
