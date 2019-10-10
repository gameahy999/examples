#include <boost/algorithm/string.hpp>
#include <boost/regex.hpp>
#include <iostream>

void test_boostStuff() {
    std::string str1 = "hello, world!";
    std::string str2 = "HELLO, WORLD!";

    if (boost::iequals(str1, str2)) {
        // Strings are identical
        std::cout << "Strings are identical" << std::endl;
    }
}

static void displayTrueOrFalse(bool b) {
    if (b) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }
}

void test_boostRegex() {
    displayTrueOrFalse(boost::regex_match("v10", boost::regex("[V|v][0-9]*")));
    displayTrueOrFalse(boost::regex_match("V10", boost::regex("[V|v][0-9]*")));
    displayTrueOrFalse(boost::regex_match("asdf", boost::regex("[V|v][0-9]*")));
    displayTrueOrFalse(boost::regex_match("1234", boost::regex("[V|v][0-9]*")));
    displayTrueOrFalse(boost::regex_match("a12", boost::regex("[V|v][0-9]*")));
    displayTrueOrFalse(boost::regex_match("", boost::regex("[V|v][0-9]*")));
}
