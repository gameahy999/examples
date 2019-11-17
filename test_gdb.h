#ifndef __TEST_GDB_H__
#define __TEST_GDB_H__

#include <string>

class CustomizedDataStructure {
public:
    explicit CustomizedDataStructure() {}
    std::string debugString() const;
    int i = 10;
    float f = 14.0f;
    double d = 1.2f;
    std::string s = "Hello World.";
};

void test_gdb();

#endif
