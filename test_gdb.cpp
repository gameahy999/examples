#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include "test_gdb.h"

void basicSTLOperations() {
    const std::string s = "hello world";
    std::cout << s << std::endl;

    std::map<std::string, float> sfMap;
    sfMap["a"] = 1.0f;
    sfMap["b"] = 2.0f;
    sfMap["c"] = 3.0f;

    const std::string& tmp = s;
    std::unordered_map<int, std::string> isMap;
    isMap[1] = "Hello World";
    isMap[2] = "JD";
    isMap[3] = "TMall";
    isMap[4] = tmp;

    std::unordered_map<int, std::string>* pIsMap = &isMap;
    std::cout << pIsMap << std::endl;

    std::vector<std::string> svec;
    svec.push_back("Hello World");
    svec.push_back("JD");
    svec.push_back("TMall");
}

float mockFeaturePlugin() {
    float sum = 0.0f;
    for (int i = 0; i < 100; i++) {
        float weight = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        sum += weight;;
    }
    return sum;
}

int compilerOptimization() {
    int sum = 0;
    for (int i = 1; i <= 100; i++) {
        sum += i;
    }
    return sum;
}

std::string CustomizedDataStructure::debugString() const {
    return "This is debug string from function call.";
}

void test_gdb() {
    basicSTLOperations();
    float num = mockFeaturePlugin();
    std::cout << num << std::endl;
    compilerOptimization();
    CustomizedDataStructure c = CustomizedDataStructure();
    std::cout << c.s << std::endl;
}
