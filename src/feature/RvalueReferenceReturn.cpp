

// 一个 lvalue 是通常可以放在等号左边的表达式，左值
// 一个 rvalue 是通常只能放在等号右边的表达式，右值

#include <iostream>
#include <type_traits>

using namespace std;

void print(string& s) {
    cout << "print(string& s)" << endl;
}

void print(string&& s) {
    cout << "print(string&& s)" << endl;
}

template<typename Ty>
void func(Ty&& s) {
    // C++11新增语法，用来进行左右值判断
    std::cout << "is_lvalue_reference:" << std::is_lvalue_reference<decltype(s)>::value << endl;
    std::cout << "is_rvalue_reference:" << std::is_rvalue_reference<decltype(s)>::value << endl;
    //print(s);

    // 完美转发。如果是左值，按照左值传递；如果是右值，按照右值传递。新增了一个规则：引用折叠
    print(std::forward<Ty>(s));
}

void RvalueReferenceReturn()
{
    std::cout << std::boolalpha;
    {
        std::cout << "is_lvalue_reference:" << std::endl;
        std::cout << "int: " << std::is_lvalue_reference<int>::value << std::endl;
        std::cout << "int&: " << std::is_lvalue_reference<int&>::value << std::endl;
        std::cout << "int&&: " << std::is_lvalue_reference<int&&>::value << std::endl;

        std::cout << "is_rvalue_reference:" << std::endl;
        std::cout << "int&&: " << std::is_rvalue_reference<int&&>::value << std::endl;
        cout<<endl;
    }

    string s1{ "hello world" };
    string& s1_lr = s1;
    {
        std::cout << std::is_lvalue_reference<decltype(s1)>::value << std::endl;
        std::cout << std::is_lvalue_reference<decltype(s1_lr)>::value << std::endl;
    }
    cout << endl;

    // string&& s1_rr = s1;
    string&& s1_rr = static_cast<string&&>(s1);
    std::cout << std::is_rvalue_reference<decltype(s1_rr)>::value << std::endl;

    func(s1);
    func(s1_lr);
    func(s1_rr);
    func(static_cast<string&&>(s1));
    func(std::move(s1));

}
