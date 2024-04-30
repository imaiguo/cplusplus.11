
// auto和decltype

#include <iostream>

using namespace std;

int func(int i) {
    if (i > 0) {
        return i;
    } else {
        return 9;
    }
}

void AutoDecltype(){
    // auto代替类型
    auto i = func(5);

    // 推到类型
    decltype(i) i1;
    i1 = 100;
    cout << i1 << endl;
}
