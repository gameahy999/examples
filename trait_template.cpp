#include <iostream>
#include "trait_template.h"

void test_traitTemplate() {
    int num[] = {1, 2, 3, 4, 5};
    std::cout << "average value in num: "
              << CppTemplatesGuide::accum(&num[0], &num[5]) / 5
              << std::endl;
    std::cout << "average value in num: "
              << CppTemplatesGuide::super_accum(&num[0], &num[5]) / 5
              << std::endl;

    char name[] = "templates";
    int length = sizeof(name) - 1;
    std::cout << "average value in name: "
              << CppTemplatesGuide::accum(&name[0], &name[length]) / length
              << std::endl;
    std::cout << "average value in name: "
              << CppTemplatesGuide::super_accum(&name[0], &name[length]) / length
              << std::endl;

    std::cout << "best_accum x value: "
              << CppTemplatesGuide::best_accum<int, CppTemplatesGuide::MultPolicy>(&num[0], &num[5])
              << std::endl;
    std::cout << "best_accum + value: "
              << CppTemplatesGuide::best_accum(&num[0], &num[5])
              << std::endl;
}
