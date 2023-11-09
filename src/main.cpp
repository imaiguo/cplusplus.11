
#include "log4cplus/initializer.h"
#include "Utils/log4cplusInit.h"

#include "gtest/gtest.h"

#include "./Utils/utils.h"

int add(int a, int b)
{
    return a + b;
}

TEST(addTest, abc)
{
    EXPECT_EQ(add(2,3), 5);
}

int main(int argc, char **argv) {
    log4cplus::Initializer initializer;
    InitLog4cplus(argv[0]);

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
