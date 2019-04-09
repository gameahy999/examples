#ifndef __TEMPLATE_SPECIALIZATION_H__
#define __TEMPLATE_SPECIALIZATION_H__

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <unordered_map>

typedef std::vector<std::pair<std::string, float>> IDFeatureInfo;

class TestFeaturePlug {
public:
    explicit TestFeaturePlug(const std::string& featureName)
            : feature_name_(featureName) {}
    const std::string& getFeatureName() {return feature_name_;}

    template<typename T>
    void function1(const std::unordered_map<T, float>& src, IDFeatureInfo* dst);
    void function1(const std::unordered_map<std::string, float>& src, IDFeatureInfo* dst);

private:
    std::string feature_name_;
};

template<typename T>
void TestFeaturePlug::function1(const std::unordered_map<T, float>& src,
                                IDFeatureInfo* dst) {
    std::cout << "template version" << std::endl;
    for (const auto& kv : src) {
        dst->push_back(std::make_pair(std::to_string(kv.first), kv.second));
    }
}

void test_templateSpecialization();

#endif
