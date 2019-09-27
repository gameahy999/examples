#ifndef __POLICY_TEMPLATE_H__
#define __POLICY_TEMPLATE_H__

class SumPolicy {
public:
    template<typename T1, typename T2>
    static void accumulate(T1& total, const T2& value) {
        total += value;
    }
};

class MultPolicy {
public:
    template<typename T1, typename T2>
    static void accumulate(T1& total, const T2& value) {
        total *= value;
    }
};

#endif
