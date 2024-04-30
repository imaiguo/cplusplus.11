// 原子类型 atomic 内存模型

#include <iostream>
#include <atomic>
// #include <Windows.h>

#include <gtest/gtest.h>

TEST(atomicTest, atomicTest){
    {
        // long、int、long long、short、char、wchar_t
        // 编译器保证原子类型在多线程间互斥的访问
        std::atomic<int> a;
        a = 0;
        a.store(0);
        a = 1;
        std::cout << a.load() << std::endl;
        std::cout << a << std::endl;
        std::cout << a.fetch_add(1) << std::endl;
        std::cout << a.load() << std::endl;

        std::cout << "测试compare_exchange" << std::endl;
        {
            int i = 2;
            std::cout << "a=" << a << ",i=" << i << std::endl;
            bool r = a.compare_exchange_strong(i, 10); // 原子地比较原子对象与非原子参数的值，若相等则进行交换，若不相等则进行加载
            std::cout << "a.compare_exchange_strong(i, 10)的返回值是" << r << ",a = " << a << ",i = " << i << std::endl;
        }

        {
            a = 2;
            int i = 1;
            std::cout << "a=" << a << ",i=" << i << std::endl;
            bool r = a.compare_exchange_strong(i, 10);
            std::cout << "a.compare_exchange_strong(i, 10)的返回值是" << r << ",a = " << a << ",i = " << i << std::endl;
        }

        // 原子交换
        {
            std::cout << "测试原子交换exchange" << std::endl;
            std::cout << "a=" << a << std::endl;
            std::cout << "a.exchange(100)的返回值是" << a.exchange(100) << std::endl;
            std::cout << "a=" << a << std::endl;
        }

    }

#ifdef _WIN32
    {
        int a = 0;
        int b = 0;
        _ReadWriteBarrier(); // 内存栅栏
        int c = 0;
    }
#endif

}
