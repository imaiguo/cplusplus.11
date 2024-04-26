#include "gtest/gtest.h"

#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <numeric>
#include <random>
#include <vector>
 
void f(int& n1, int& n2, const int& n3)
{
    std::cout << "In function: " << n1 << ' ' << n2 << ' ' << n3 << '\n';
    ++n1; // increments the copy of n1 stored in the function object
    ++n2; // increments the main()'s n2
    // ++n3; // compile error
}
 
TEST(ReferenceWrapper, REF){
    int n1 = 1, n2 = 2, n3 = 3;
    std::function<void()> bound_f = std::bind(f, n1, std::ref(n2), std::cref(n3));
    n1 = 10;
    n2 = 11;
    n3 = 12;
    std::cout << "Before function: " << n1 << ' ' << n2 << ' ' << n3 << '\n';
    bound_f();
    std::cout << "After function: " << n1 << ' ' << n2 << ' ' << n3 << '\n';
}

TEST(ReferenceWrapper, Wrapper){
    std::list<int> l(10);
    std::iota(l.begin(), l.end(), -4);
    std::cout<<"l = ";
     for(int i : l){
        std::cout<< i << " ";
    }

    std::cout<<std::endl;

    // can't use shuffle on a list (requires random access), but can use it on a vector
    std::vector<std::reference_wrapper<int>> v(l.begin(), l.end());

    *(l.begin()) += 10;
    std::cout<<"v = ";
    for(int i : v){
        std::cout<< i << " ";
    }

    std::cout<<std::endl;
}
