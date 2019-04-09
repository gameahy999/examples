#include <iostream>

#include "template_specialization.h"

void TestFeaturePlug::function1(const std::unordered_map<std::string, float>& src,
                                IDFeatureInfo* dst) {
    std::cout << "Specialized templated version." << std::endl;
}

void test_templateSpecialization() {
    TestFeaturePlug plug("uskus");
    std::cout << plug.getFeatureName() << std::endl;

    std::unordered_map<std::string, float> src;
    IDFeatureInfo dst;
    plug.function1(src, &dst);

    std::unordered_map<int, float> srcc;
    plug.function1(srcc, &dst);
}
