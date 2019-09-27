#include <iostream>
#include <memory>
#include <vector>
#include "default_constructor.h"

void test_defaultConstructor() {
    using ItemContextVec = std::vector<std::shared_ptr<ItemContext>>;
    // using ItemContextVectorPtr = std::shared_ptr<std::vector<ItemContext>>;

    auto itemContextVecPtr = std::make_shared<ItemContextVec>();
    // ItemPropertyPtrVec ivec;

    auto itemPropertyPtr = std::make_shared<ItemProperty>(1);
    // itemPropertyPtr->skuData.MultiVersionData.emplace_back
    // ivec.push_back(itemPropertyPtr);

    auto itemContextPtr = std::make_shared<ItemContext>();
    itemContextPtr->itemproperty = itemPropertyPtr;

    itemContextVecPtr->push_back(itemContextPtr);
    std::cout << itemContextVecPtr->size() << std::endl;
}
