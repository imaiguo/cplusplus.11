

#include <chrono>
#include <random>
#include <iostream>

#include "gtest/gtest.h"
 
TEST(MT19937, RANDOM){
	std::random_device rd;
	unsigned int seed = rd();
	std::mt19937 engine(seed);
  	engine.seed(rd());
  	std::cout << "std::mt19937 min :" << engine.min() << std::endl;
	std::cout << "std::mt19937 max :" << engine.max() << std::endl;
	std::cout << "std::mt19937 get random :" << engine() << std::endl;
	engine.discard(5);
}