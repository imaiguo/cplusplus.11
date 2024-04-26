
// 非静态成员变量的sizeof

#include <iostream>

using namespace std;

class A {
public:
    int i_;
};

void NonstaticSizeof()
{
    cout << sizeof(A::i_) << endl;
}
