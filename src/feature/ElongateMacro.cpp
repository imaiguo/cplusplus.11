
// 变长参数的宏定义

#include <iostream>

using namespace std;

#define LOG(...) { \
    fprintf(stderr,"%s:line %d:\t", "15变长参数的宏定义.cpp", __LINE__);\
    fprintf(stderr, __VA_ARGS__);\
  }

void ElongateMacro()
{
    LOG("%s\n", "hello world");
    LOG("%s%s\n", "hello world ", "hello world");
}
