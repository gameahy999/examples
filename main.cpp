#include <cstdlib>
#include <ctime>

#include "boost_stuff.h"
#include "closure.h"
#include "copy_control.h"
#include "default_constructor.h"
#include "folly_stuff.h"
#include "grammer.h"
#include "long_integer.h"
#include "math_experiment.h"
#include "memory_leak.h"
#include "misc.h"
#include "parallel_programming.h"
#include "standard_library.h"
#include "template_specialization.h"
#include "test_const.h"
#include "test_json.h"
#include "trait_template.h"
#include "trivial_template.h"

int main() {
    // Do some preparation here
    std::srand(std::time(0));

    // Begin testing
    test_callFunctionInDerivedClassTemplate();
    // test_nonTypeTemplateParameter();
    // test_traitTemplate();
    // test_string2Int();
    // test_defaultConstructor();
    // test_boostStuff();
    // test_sort();
    // test_resizingVector();
    // test_constVariables();
    // test_follyStuff();
    // test_closure();
    // test_json();
    // test_callerAndCallee();
    // test_callerAndCalleeFromOuterModule(1, 2, 3);
    // test_copyToVector();
    // test_int64();
    // test_openMP();
    // test_longInteger();
    // test_bitset();
    // test_templateSpecialization();
    // test_wasteOrNot();
    // test_typeid();
    // test_sigmoid();
    // test_memoryUsedForCStyleStringInArray();
    // test_memoryUsedForCStyleString();
    // test_memoryUsedForString();
    // test_memoryLeak();
    // test_copyFromStaticVariable();
    // test_future();
    // test_inherit();
    // test_sortAlgorithms();
    // test_copyReference();
    // test_copyUniquePtr();
    // test_copyControl();
    // test_referenceToStringInClass();
    // test_referenceToString();
    // test_objectInitialize();
    // test_deleteNull();
    // test_operatorEqual();
    return 0;
}
