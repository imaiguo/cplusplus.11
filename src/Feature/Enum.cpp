
// 强枚举类

#include <iostream>

using namespace std;

class A {
public:
    enum  {
        WX,
        QQ
    };
};


// 强枚举
class B {
public:
    enum class Type : int
    {
        WX,
        QQ
    };
};

void EnumTest()
{
    cout << A::WX << endl;

    cout << (__int64)B::Type::WX << endl;

    cout << sizeof(B::Type::WX) << endl;

    long i = A::WX;

    // 报错
    // i = B::Type::WX;
    i = (int)B::Type::WX;
}
