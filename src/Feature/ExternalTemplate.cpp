
// extern声明外部模板，减少重复代码编译，提升编译效率

// 编译
// > cl 20外部模板.cpp extern_tmpl.cpp /o a.exe

#include <iostream>
#include "./extern_tmpl.h"

using namespace std;

extern template void gen<int>(int);

void ExternalTemplate ()
{
   gen(100);
}
