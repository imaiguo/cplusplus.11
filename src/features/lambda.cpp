
#include <iostream>
#include <functional>

using namespace std;

class A {
public:
    A() {
        cout << "A()" << endl;
    };
    ~A() {
        cout << "~A()" << endl;
    };

    A(const A& a) {
        cout << "A(const A&)" << endl;
    }

    A(A&& a) noexcept {
        cout << "A(A&&) noexcept" << endl;
    }

    A& operator=(const A& a) {
        cout << "operator=(const A& a)" << endl;
        return *this;
    }

    A& operator=(A&& a) noexcept {
        cout << "operator=(A&& a) noexcept" << endl;
        return *this;
    }

    int i_ = 100;
};


// auto func() {
//     A a;  // 第1次构造 进入lambda
//     // = 表示复制一份a，调用的是拷贝构造函数   // 第2次构造 进入lambda 第3次构造 赋值给f并返回
//     auto f = (
//         [=]() {
//             cout << "a.i_=" << a.i_ << endl;
//         }
//     );

//     return f;
// }

// void lambdaTest()
// {
//     {
//         A a;
//         // & 以引用的方式使用a
//         auto f = (
//             [&]() {
//                 a.i_ = 102;
//                 cout << "a.i_=" << a.i_ << endl;
//             }
//         );
//         f();
//         cout << "a.i_=" << a.i_ << endl;
//     }
//     cout << endl;

//     {
//         std::function<void(void)> f = func(); // 第4次构造 赋值给f
//         f();
//     }
//     cout << endl;

//     {
//         A a;
//         // 使用mutable表示可以改变变量a的值
//         auto lam = [=](int i) mutable -> int {
//             // 修改a的值
//             a.i_ = 101;
//             cout << "a.i_=" << a.i_ << endl;
//             cout << "i=" << i << endl;
//             return 103;
//         };
//         auto r = lam(102);
//         cout << "r=" << r << endl;
//         cout << "a.i_=" << a.i_ << endl;
//     }
// }
