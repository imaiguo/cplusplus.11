
// 线程私有变量 tls 和 thread_local

#include <iostream>
#include <thread>
#include <Windows.h>

using namespace std;
namespace TlsTest{

DWORD slot_ = TlsAlloc();

class A {
    public:
        int b;
        thread_local static int i;
};
thread_local int A::i = 0;

void func() {
    for (;;) {
        int64_t i = (int64_t)TlsGetValue(slot_);
        TlsSetValue(slot_, (LPVOID)++i);
        cout << "func " <<  i << endl;
        if (i >= 10)
            break;
    }
}

void func1() {
    for (;;) {
        ++A::i;
        cout << "func1 " << A::i << endl;
        if (A::i >= 10)
            break;
    }
}

void func2() {
    thread_local int i = 0;
    for (;;) {
        cout << "func2 " << ++i << endl;
        if (i >= 10)
            break;
    }
}

void tlsTest()
{
    // TlsGetValue和 TlsSetValue的使用
    {
        thread t1(func);
        this_thread::sleep_for(500ms);
        thread t2(func);

        t1.join();
        t2.join();
    }

    // thread_local放在类中成员变量的使用
    {
        thread t1(func1);
        this_thread::sleep_for(500ms);
        thread t2(func1);

        t1.join();
        t2.join();
    }

    // thread_local放在函数局部变量的使用
    {
        thread t1(func2);
        this_thread::sleep_for(500ms);
        thread t2(func2);

        t1.join();
        t2.join();
    }
}
};
