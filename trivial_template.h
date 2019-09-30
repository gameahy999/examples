#ifndef __TRIVIAL_TEMPLATE_H__
#define __TRIVIAL_TEMPLATE_H__

/*
 * ‘double’ is not a valid type for a template non-type parameter
 * template<double VAT>
 * double process(double v) {
 *     return v * VAT;
 * }
 */

#include <bitset>
#include <iostream>
#include <string>

template<int N>
void printBitset(const std::bitset<N>& bs) {
    std::cout << bs.template to_string<char,
                                       std::char_traits<char>,
                                       std::allocator<char>>() << std::endl;
}

void test_nonTypeTemplateParameter();

template<typename T>
class BaseClassTemplate {
public:
    void exit();

private:
    T i_;
};

template<typename T>
void BaseClassTemplate<T>::exit() {
    std::cout << "This is the exit function in Base class." << std::endl;
}

// template<typename T>
// void Base::exit() {
//     std::cout << "This is the exit function in Base class." << std::endl;
// }

template<typename T>
class DerivedClassTemplate : public BaseClassTemplate<T> {
public:
    void foo() {
        // exit();
        this->exit();  // this-> is necessary here.
    }
};

void test_callFunctionInDerivedClassTemplate();

#endif
