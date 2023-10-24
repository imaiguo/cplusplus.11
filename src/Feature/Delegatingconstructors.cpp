
// 在构造函数里面调用另外一个构造函数，这是提高编码效率，减少冗余的设计

#include <iostream>

class A {
public:
    A() : A(0, 0, 0) {};
    A(int hour, int min, int sec) : hour_(hour), min_(min), sec_(sec) {}

    std::ostream& operator<<(std::ostream& os) {
        os << hour_ << min_ << sec_;
        return os;
    }

    int hour_;
    int min_;
    int sec_;
};

void Delegatingconstructors()
{
    A a;
    a << std::cout << std::endl;
}
