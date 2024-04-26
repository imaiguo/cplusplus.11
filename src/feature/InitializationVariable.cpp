// 类定义里面初始化成员变量

#include <iostream>

using namespace std;

class A {
public:
    A() : i_(1) {
        cout << i_ << endl;
        i_ = 2;
    }
    int i_ = 0; // 构造对象时，最早执行
};

void InitializationVariable()
{
    A a;
    cout << a.i_ << endl;
}
