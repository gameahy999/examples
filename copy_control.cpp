#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "copy_control.h"
#include "utils.h"

// static const Person static_p = Person();

Person::Person() : age_(18), name_("LiLei") {
    std::cout << "Default Constructor" << std::endl;
}

Person::Person(int a, const std::string &name) : age_(a), name_(name) {
    std::cout << "Construct with specified age & name." << std::endl;
}

Person::Person(const Person &p) {
    std::cout << "Copy Constructor" << std::endl;
}

Person& Person::operator =(const Person &p) {
    std::cout << "Assignment Operator" << std::endl;
    return *this;
}

Person& Person::operator =(const Person &&p) {
    std::cout << "Move Assignment Operator" << std::endl;
    return *this;
}

Person getPersonInfo() {
    Person p;
    p.setAge(12);
    p.setName("Hanmeimei");
    return p;
}

void fillPersonInfo(Person& p) {
    p.setAge(12);
    p.setName("Xiaohan");
}

void test_wasteOrNot() {
    std::unordered_map<std::string, Person> personMap;
    getPersonInfo();
//    Person p;
//    fillPersonInfo(p);
//    personMap.emplace("someone", p);
//     personMap.emplace("someone", getPersonInfo());
//    personMap.insert(std::make_pair<std::string, Person>("someone", getPersonInfo()));
//    personMap["someone"] = getPersonInfo();
}

void func1(Person p) {
    return;
}

Person func2() {
    Person p;
    std::cout << "My age is: " << p.getAge() << std::endl;
    return p;
}

std::unique_ptr<Person> getPersonPtr() {
    auto ptr = std::make_unique<Person>();
    return ptr;
}

void test_copyUniquePtr() {
    std::unique_ptr<Person> personPtr;
    personPtr = getPersonPtr();
    std::cout << personPtr->getName() << std::endl;
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

void test_initializeObjectInArray() {
    Person ps[2];
    std::cout << ps[0].getAge() << std::endl;
    std::cout << ps[0].getName() << std::endl;
}

class Holder {
public:
    Holder() {}
    Person &getPersonReference();
private:
    Person p;
};

Person &Holder::getPersonReference() {
    return p;
}

void test_copyReference() {
    Holder h = Holder();
    std::cout << "======================" << std::endl;

    Person p = h.getPersonReference();

    std::cout << "======================" << std::endl;
}

void test_copyFromStaticVariable() {
    /*
    Person tmp_p = Person(1, "Hanmeimei");
    tmp_p = std::move(static_p);

    utils::separator(1);

    Person tmp_p1 = Person();
    tmp_p = tmp_p1;
    */
}

class Item {
public:
    Item(int a, int b) : a_(a), b_(b) {}
    int a_;
    int b_;
};

void test_copyToVector() {
    std::vector<Item> items;
    items.push_back(Item(1, 2));
    std::cout << "size: " << items.size() << std::endl;
    items.push_back(Item(1, 3));
    std::cout << "size: " << items.size() << std::endl;
}
