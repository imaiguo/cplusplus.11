
#include <iostream>

using namespace std;

class B;

template<typename T>
class A {
private:

// T可以是类，也可以是基本类型，基本类型编译器自动忽略friend，用于泛型编程
    friend T;
    void func() {
        cout << typeid(T).name() << endl;
    }
};

class B {
public:
    void func(A<B> a) {
        a.func();
    }
};

void FriendOptimize()
{
    A<B> a;

    B b;
    b.func(a);

    A<int> a1;
}
