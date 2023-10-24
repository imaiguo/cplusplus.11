
// 类的默认模板参数本来就支持，C++11增加了函数的返回值类型

#include <iostream>

using namespace std;

template<typename T, typename S>
S func(T t) { 
    cout << t << endl;
    return sizeof(S);
}

void funcSTLTest() {
    cout << (func<float,float>(5.5));
}
