#include <iostream>
#include <tuple>

#include <gtest/gtest.h>

// std::tuple 提供编译期中的元组 std::pair是std::tuple的特殊形式
// Provides access to the number of elements in a tuple-like type as a compile-time constant expression.
template <class T>
void test(T value)
{
    int a[std::tuple_size_v<T>]; // can be used at compile time, obtains the number of elements of a tuple-like type
 
    std::cout << std::tuple_size<T>{} << ' ' // or at run time
              << sizeof(a) << ' ' 
              << sizeof(value) << '\n';
}
 
TEST(TUPLE,TUPLE_SIZE){

    test(std::make_tuple(1, 2, 1, "abcdefghijklmnopqrtuvwxyz", true));
}

TEST(TUPLE,GET){

    auto t = std::make_tuple(1, "Foo", 3.14);
 
    // Index-based access
    std::cout << "( " << std::get<0>(t)
              << ", " << std::get<1>(t)
              << ", " << std::get<2>(t)
              << " )\n";
 
    // Type-based access (C++14 or later)
    std::cout << "( " << std::get<int>(t)
              << ", " << std::get<const char*>(t)
              << ", " << std::get<double>(t)
              << " )\n";
}

std::tuple<double, char, std::string> get_student(int id){
    switch (id)
    {
        case 0: return {3.8, 'A', "Lisa Simpson"};
        case 1: return {2.9, 'C', "Milhouse Van Houten"};
        case 2: return {1.7, 'D', "Ralph Wiggum"};
        case 3: return {0.6, 'F', "Bart Simpson"};
    }
 
    throw std::invalid_argument("id");
}

std::tuple<int, int> foo_tuple(){
    return {1, -1};  // Error until N4387
    return std::tuple<int, int>{1, -1}; // Always works
    return std::make_tuple(1, -1); // Always works
}

TEST(TUPLE,TUPLE){
    foo_tuple();
}

TEST(TUPLE,TIE){
    const auto student0 = get_student(0);
    std::cout << "ID: 0, "
              << "GPA: " << std::get<0>(student0) << ", "
              << "grade: " << std::get<1>(student0) << ", "
              << "name: " << std::get<2>(student0) << '\n';
 
    const auto student1 = get_student(1);
    std::cout << "ID: 1, "
              << "GPA: " << std::get<double>(student1) << ", "
              << "grade: " << std::get<char>(student1) << ", "
              << "name: " << std::get<std::string>(student1) << '\n';
 
    double gpa2;
    char grade2;
    std::string name2;
    std::tie(gpa2, grade2, name2) = get_student(2);
    std::cout << "ID: 2, "
              << "GPA: " << gpa2 << ", "
              << "grade: " << grade2 << ", "
              << "name: " << name2 << '\n';
 
    // // C++17 structured binding:
    // const auto [gpa3, grade3, name3] = get_student(3);
    // std::cout << "ID: 3, "
    //           << "GPA: " << gpa3 << ", "
    //           << "grade: " << grade3 << ", "
    //           << "name: " << name3 << '\n';
}

TEST(TUPLE,MAKE_PAIR){
    int n = 1;
    int a[5] = {1, 2, 3, 4, 5};
 
    // build a pair from two ints
    auto p1 = std::make_pair(n, a[1]);
    std::cout << "The value of p1 is "
              << "(" << p1.first << ", " << p1.second << ")\n";
 
    // build a pair from a reference to int and an array (decayed to pointer)
    auto p2 = std::make_pair(std::ref(n), a); // 与&n不同 &n是取地址
    n = 7;
    std::cout << "The value of p2 is "
              << "(" << p2.first << ", " << *(p2.second + 2) << ")\n";
}

