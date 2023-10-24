#include <iostream>
#include <vector>
#include <chrono>

#include "gtest/gtest.h"

//1.auto 变量
//2.using return_type = typename std::result_of<F(Args...)>::type;
//3.template<class F, class... Args>
//4.std::thread 
//5.std::function
//6.std::future
//7.std::mutex queue_mutex;
//8.std::condition_variable condition;
//9.task->get_future()
//10.std::make_shared
//11.std::packaged_task
//12.std::bind
//13.std::forward

/*
另外，最新的C++标准更新了auto关键字的功能
除了具有原有的含义外，还增加了一种类似其他高级语言的型别推导特性
使用auto来代替变量的类型，
前提是被明确类型的初始化变量初始化的，可以使用auto关键字
比如int i=10; auto a = i; //这样a也是int类型了
这在使用一些模板类的时候，对于减少冗赘的代码也很有用
auto和lambda解决了线程参数传递和返回值个数和类型的限制了
*/

#include "ThreadPool.h"

TEST(ThreadPool, runtest)
{
    ThreadPool pool(4);
    std::vector< std::future<int> > results;

    int j = 2;
    for(int i = 0; i < 8; ++i)
	{
        results.emplace_back(
            pool.enqueue([i,j]{
                std::this_thread::sleep_for(std::chrono::seconds(1));
                return i*j;
            })
        );
    }

    for(auto && result: results)
        std::cout << "get:"<<result.get() << ' ';
}
