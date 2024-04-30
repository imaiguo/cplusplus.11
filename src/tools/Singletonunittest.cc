

#include <iostream>
#include <gtest/gtest.h>

#include "Singleton.h"

TEST(Singleton, SingletonTest){

    int *single1 =  PatternTool::Singleton<int>::instance();
    int *single2 =  PatternTool::Singleton<int>::instance();

    *single1 = 0;
    EXPECT_EQ(*single1, 0);
    EXPECT_EQ(*single2, 0);

    *single2 = 2;    
    EXPECT_EQ(*single1, 2);
    EXPECT_EQ(*single2, 2);
}