#ifndef __GRAMMER_H__
#define __GRAMMER_H__

class OperatorTest {
public:
    OperatorTest();
    ~OperatorTest();
    void operator()(const int a);
private:
    int x_;
};

void test_operatorEqual();
void test_deleteNull();

#endif
