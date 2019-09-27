#ifndef __TRAIT_TEMPLATE_H__
#define __TRAIT_TEMPLATE_H__

#include "policy_template.h"

/*
template<typename T>
inline T accum(const T* beg, const T* end) {
    T total = T();
    while (beg != end) {
        total += *beg;
        ++beg;
    }
    return total;
}
*/

template<typename T>
class AccumulationTraits;

template<>
class AccumulationTraits<char> {
public:
    using AccT = int;
    // static const AccT zero = 0;
    static AccT zero() {
        return 0;
    }
};

template<>
class AccumulationTraits<int> {
public:
    using AccT = long;
    // static const AccT zero = 0;
    static AccT zero() {
        return 0;
    }
};

template<>
class AccumulationTraits<float> {
public:
    using AccT = float;
    // static const float zero = 0.0; // will cause an error, integral type needed
    static AccT zero() {
        return 0;
    }
};

template<typename T>
inline typename AccumulationTraits<T>::AccT accum(const T* beg, const T* end) {
    using AccT = typename AccumulationTraits<T>::AccT;

    // AccT total = AccT();
    // AccT total = AccumulationTraits<T>::zero;
    AccT total = AccumulationTraits<T>::zero();
    while (beg != end) {
        total += *beg;
        ++beg;
    }
    return total;
}

template<typename T, typename AT = AccumulationTraits<T> >
inline typename::AccumulationTraits<T>::AccT super_accum(const T* beg, const T* end) {
    using AccT = typename AT::AccT;

    AccT total = AT::zero();
    while (beg != end) {
        total += *beg;
        ++beg;
    }
    return total;
}

template<typename T,
         typename Policy = SumPolicy,
         typename Traits = AccumulationTraits<T> >
inline typename Traits::AccT best_accum(const T* beg, const T* end) {
    using AccT = typename Traits::AccT;

    AccT total = Traits::zero();
    while (beg != end) {
        Policy::accumulate(total, *beg);
        ++beg;
    }
    return total;
}

void test_traitTemplate();

#endif
