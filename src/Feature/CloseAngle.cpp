
// vs2008编译不过，必须多敲一个空格，小优化，本该如此
// 右尖括号

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
struct item {
    T t_;
};

void CloseAngle()
{
    vector<item<int>> v;
    std::cout << "Hello World!\n";
}
