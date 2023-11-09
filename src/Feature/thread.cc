
#include <iostream>
#include <thread>

#include "gtest/gtest.h"

void foo() 
{
  // do stuff...
  std::cout<< "no arg" <<std::endl;
}

void bar(int x)
{
  // do stuff...
  std::cout<< "x=" << x <<std::endl;
}

TEST(Thread, test){
  std::thread first (foo);     // spawn new thread that calls foo()
  std::thread second (bar, 10);  // spawn new thread that calls bar(0)

  std::cout << "main, foo and bar now execute concurrently...\n";

  // synchronize threads:
  first.join();                // pauses until first finishes
  second.join();               // pauses until second finishes

  std::cout << "foo and bar completed.\n";
}
