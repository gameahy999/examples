#include <boost/algorithm/string.hpp>
#include <iostream>

void test_boostStuff() {
    std::string str1 = "hello, world!";
    std::string str2 = "HELLO, WORLD!";

    if (boost::iequals(str1, str2)) {
        // Strings are identical
        std::cout << "Strings are identical" << std::endl;
    }
}
