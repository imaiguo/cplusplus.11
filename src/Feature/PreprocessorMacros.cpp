
// 编译器 预处理宏(Preprocessor macros) 比如关键字__func__  、 ## 

#include <iostream>
#include <stdio.h>

#include "gtest/gtest.h"

// 打印下划线编译器支持变量
class A {
public:
    void print() {
        std::cout << "__FILE__:[" << __FILE__  << "]."<< std::endl;
        std::cout << "__func__:[" << __func__  << "]."<< std::endl;
        std::cout << "__DATE__:[" << __DATE__  << "]."<< std::endl;
        std::cout << "__TIME__:[" << __TIME__  << "]."<< std::endl;

#ifdef __STDC__
        std::cout << "__STDC__:[" << __STDC__  << "]."<< std::endl;
#endif

#ifdef __STDC_VERSION__
        std::cout << "__STDC_VERSION__:[" << __STDC_VERSION__  << "]."<< std::endl;
#endif

#ifdef __STDCPP_DEFAULT_NEW_ALIGNMENT__
    std::cout << "__STDCPP_DEFAULT_NEW_ALIGNMENT__:[" << __STDCPP_DEFAULT_NEW_ALIGNMENT__  << "]."<< std::endl;
#endif

        std::cout << "__cplusplus:[" << __cplusplus  << "]."<< std::endl;
        std::cout << "__cpp_constexpr:[" << __cpp_constexpr  << "]."<< std::endl;
        std::cout << "__STDC_HOSTED__:[" << __STDC_HOSTED__  << "]."<< std::endl;
        std::cout << "__STDCPP_THREADS__:[" << __STDCPP_THREADS__  << "]."<< std::endl;

#ifdef __STDCPP_STRICT_POINTER_SAFETY__
        std::cout << "__STDCPP_STRICT_POINTER_SAFETY__:[" << __STDCPP_STRICT_POINTER_SAFETY__  << "]."<< std::endl;
#endif

#ifdef __STDC_MB_MIGHT_NEQ_WC__
        std::cout << "__STDC_MB_MIGHT_NEQ_WC__:[" << __STDC_MB_MIGHT_NEQ_WC__  << "]."<< std::endl;
#endif

    }
  
};


// 通过宏定义 定义可以使用的函数
#define FUNCTION(name, a) int fun_##name() { return a; }
 
FUNCTION(abcd, 12)
FUNCTION(fff, 2)
FUNCTION(qqq, 23)
 
#undef FUNCTION
#define FUNCTION 34
#define OUTPUT(a) std::cout << "output: " #a << '\n'
 
// 在宏定义中使用宏 支持...表示的不定参数
#define WORD "Hello "
#define OUTER(...) WORD #__VA_ARGS__


TEST(MacroFunc, Print){
    A a;
    a.print();
}


TEST(MacroFunc, PrintPound){
    std::cout << "abcd: " << fun_abcd() << '\n';
    std::cout << "fff: " << fun_fff() << '\n';
    std::cout << "qqq: " << fun_qqq() << '\n';
 
    std::cout << FUNCTION << '\n';
    OUTPUT(million);
 
    std::cout << OUTER(World) << '\n';
    std::cout << OUTER(WORD World) << '\n';
    std::cout << OUTER(123 456 789 World) << '\n';
}
