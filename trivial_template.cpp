#include <iostream>
#include "trivial_template.h"

void test_nonTypeTemplateParameter() {
    // ‘double’ is not a valid type for a template non-type parameter
    // std::cout << process<2.0>(5.0) << std::endl;
}
