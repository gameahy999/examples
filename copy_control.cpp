#include <iostream>

#include "copy_control.h"
#include "utils.h"

Person::Person() : age_(0), name_("LiLei") {
    std::cout << "Default Constructor" << std::endl;
}

Person::Person(const Person &p) {
    std::cout << "Copy Constructor" << std::endl;
}

Person& Person::operator =(const Person &p) {
    std::cout << "Assignment Operator" << std::endl;
    return *this;
}

void func1(Person p) {
    return;
}

Person func2() {
    Person p;
    std::cout << "My age is: " << p.getAge() << std::endl;
    return p;
}

void test_copyControl() {
    utils::separator();
    Person p;
    std::cout << "My name is: " << p.getName() << std::endl;
    Person p1 = p;

    utils::separator(1);
    func1(p);

    utils::separator(2);
    Person tmp = func2();

    utils::separator(3);
    tmp = p1;
}
