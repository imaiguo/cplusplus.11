
#include <iostream>
#include <string>

using namespace std;

namespace RvalueTest{

class A {
public:
    A() {
        i_ = 101;
    }

    ~A() {
        delete ptr_;
    }

    // 构造函数
    A(const A& a);

    // move的实现
    A(A&& a) noexcept {
        if (ptr_) {
            delete ptr_;
        }
        ptr_ = a.ptr_;
        a.ptr_ = nullptr;
    };

    A& operator=(const A& a) {
    }

    A& operator=(A&& a) {
    }

    int i_ = 100;
    int* ptr_ = nullptr;
};

A::A(const A& a) {
    i_ = a.i_;
    if (a.ptr_) {
        ptr_ = new int{ *a.ptr_ };
    }
}

A func() {
    A a;
    return a;
}

string func1() {
    string s = "abc";
    // 请勿使用std::move返回局部变量
    // return std::move(s);
    return s;
}

void RvalueReferenceMove()
{

    // 语法作用：提升性能
    {
        A a = func();
        cout << a.i_ << endl;
        string r = func1();
    }

    // 移动构造，执行完成后，s1就不再使用了
    {
        string s1 = "abc...";
        string s2 = std::move(s1);
    }

    {
        A a;
        a.ptr_ = new int{ 100 };
        cout << a.ptr_ << "  " << *a.ptr_ << endl;

        A a1{a};
        cout << a.ptr_ << endl;
        cout << a1.ptr_ << "  " << *a1.ptr_ << endl;

        A a2 = std::move(a1);
        cout << a2.ptr_ << endl;
        cout << a2.ptr_ << "  " << *a2.ptr_ << endl;

        cout << a1.ptr_ << endl;
    }
}

}