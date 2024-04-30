// 28nullptr.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

void nullptrFunc(int) {
    cout << "func(int)" << endl;
}

void nullptrFunc(char*) {
    cout << "func(char*)" << endl;
}

void nullptrTest()
{
    // func(NULL);
    nullptrFunc((char*)NULL);
    nullptrFunc(nullptr);
    cout << (nullptr == 0) << endl;
}
