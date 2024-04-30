
#include <iostream>
#include <functional>

using namespace std;

class A {
public:
    A() = default;
    A(int i) : m_i(i) {
        std::cout << "A(int i)" << std::endl;
    }
    void func(double d) {
        std::cout << d - m_i << std::endl;
    }
    ~A() {
        std::cout << "~A()" << std::endl;
    }
private:
    int m_i;
};

int functionbind(int i) {
    cout << i << endl;
    return i;
}

// 绑定创建A对象,并调用方法A::func
// std::function<void(double)> obtain() {
//     return std::bind(&A::func, std::make_shared<A>(100), std::placeholders::_1);
// }

void FuntionBind() {

    {
        // auto func = obtain();
        // func(100.5);
    }

    // 带参数绑定func
    {
        std::function<int()> funcc = std::bind(&functionbind, 101);
        int r = funcc();
        cout << r << endl;
    }

    // 不带参数绑定func
    {
        std::function<void(int)> funcc = std::bind(&functionbind, std::placeholders::_1);
        funcc(101);
    }
}
