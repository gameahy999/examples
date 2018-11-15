#include <iostream>

using namespace std;

class OperatorTest {
public:
    OperatorTest();
    ~OperatorTest();
    void operator()(const int a);
private:
    int x_;
};

OperatorTest::OperatorTest()
        : x_(0) {

}

OperatorTest::~OperatorTest() {

}

void OperatorTest::operator ()(const int a) {
    cout << "a == " << a << endl;
}

int main() {
    OperatorTest ot = OperatorTest();
    ot(12);
    return 0;
}
