#ifndef __DEFAULT_CONSTRUCTOR_H__
#define __DEFAULT_CONSTRUCTOR_H__

#include <iostream>
#include <memory>
#include <string>
#include <vector>

struct MultiVersionData {
    MultiVersionData(const std::string& d, int v, float s = -1.0)
        : data(d), version(v), score(s) {
        std::cout << __FUNCTION__ << " is called" << std::endl;
    }
    std::string data;
    int version;
    float score;
};

struct SkuPropertyExtra {
    int cid1 = 0;
    int cid2 = 0;
    int cid3 = 0;
    std::vector<MultiVersionData> multiVersionTitle;
};

struct ItemProperty {
    int itemId = 0;
    bool isForeign = false;
    union {
        int nullData;
        SkuPropertyExtra skuData;
    };

    ItemProperty() : nullData(0) {}
    ItemProperty(int id) : itemId(id) {
        new(&skuData) SkuPropertyExtra();
    }
    ~ItemProperty() {
        skuData.~SkuPropertyExtra();
    }
};

struct ItemContext {
    std::shared_ptr<ItemProperty> itemproperty;
    float score;
};

void test_defaultConstructor();

#endif
