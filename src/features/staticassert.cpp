
// static_assert 编译期决议，编译器检查

#include <iostream>

template<typename T>
class A {
public:
    A() {
        static_assert(sizeof(T) == 4, "sizeof(T) != 4");
    }
};

void staticAssertTest()
{
    static_assert(__cplusplus >= 199711LL, "");

    A<int> a;
    std::cout << "Hello World!\n";
}
