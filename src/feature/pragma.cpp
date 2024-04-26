 // #pragma 操作符

// 方式1: 表示头文件只能包含一次
#pragma once
_Pragma("once")


// 方式2: 表示内存按1个字节对齐 结构体大小为1 + 4 = 5 字节
#pragma pack(push, 1)
struct MyStruct1{
    char c;
    int i;
};
#pragma pack(pop)

// 方式3: 表示内存按1个字节对齐
_Pragma("pack(push, 1)")
struct MyStruct2{
    char c;
    int i;
};
_Pragma("pack(pop)")

// 方式4: 表示内存按1个字节对齐
#define PRAGPUSH(x) PRAGMA(pack(push, x)) 
#define PRAGMA(x) _Pragma(#x)
#define PRAGPOP _Pragma("pack(pop)")

PRAGPUSH(1)
struct MyStruct3{
    char c;
    int i;
};
PRAGPOP

// 方式5: 使用默认内存对齐方式 一般是4字节对齐
struct MyStruct4{
    char c;
    int i;
};

#include <iostream>

#include "gtest/gtest.h"

TEST(PragmaTest,PragmaTest)
{
    std::cout << sizeof(MyStruct1) << std::endl;
    std::cout << sizeof(MyStruct2) << std::endl;
    std::cout << sizeof(MyStruct3) << std::endl;
    std::cout << sizeof(MyStruct4) << std::endl;
}
