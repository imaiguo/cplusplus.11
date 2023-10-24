
// long long 数据格式

#include <iostream>
#include <climits>

void longlongTest()
{
    std::cout << sizeof(char) << std::endl;
    std::cout << sizeof(int) << std::endl;
    std::cout << sizeof(long long) << std::endl;
    std::cout << sizeof(__int64) << std::endl;
    std::cout << sizeof(void *) << std::endl;

    std::cout << LLONG_MIN << std::endl;
    std::cout << LLONG_MAX << std::endl;
    std::cout << ULLONG_MAX << std::endl;
}
