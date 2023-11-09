

// POD = Plain Old Data
/*
用来说明类/结构体的属性，具体来说它是指没有使用面相对象的思想来设计的类/结构体。POD的全称是Plain Old Data，Plain表明它是一个普通的类型，没有虚函数虚继承等特性；Old表明它与C兼容。

POD类型在C++中有两个独立的特性：

支持静态初始化（static initialization）
拥有和C语言一样的内存布局（memory layout
*/

#include <type_traits>

#include <gtest/gtest.h>

// #pragma pack(push, 1)
struct S
{
    char   m0;
    double m1;
    short  m2;
    char   m3;
    // private: int z; // warning: 'S' is a non-standard-layout type
};
// #pragma pack(pop)

TEST(PODCLASS, PTRDIFF){
 
    std::cout << "sizeof(S) = [" << sizeof(S) << "]."<<std::endl;
    std::cout << "sizeof(char) = [" << sizeof(char) << "]."<<std::endl;
    std::cout << "sizeof(double) = [" << sizeof(double) << "]."<<std::endl;
    std::cout << "sizeof(short) = [" << sizeof(short) << "]."<<std::endl;
    std::cout << "sizeof(char) = [" << sizeof(char) << "]."<<std::endl;
    std::cout
        << "offset of char   m0 = " << offsetof(S, m0) << '\n'
        << "offset of double m1 = " << offsetof(S, m1) << '\n'
        << "offset of short  m2 = " << offsetof(S, m2) << '\n'
        << "offset of char   m3 = " << offsetof(S, m3) << '\n';
        // << "offset of char   z = " << offsetof(S, z) << '\n';
}


TEST(PODCLASS, STAND){
    struct A { int m; };
    static_assert(std::is_standard_layout_v<A> == true);

    class B: public A { int m; };
    static_assert(std::is_standard_layout_v<B> == false);

    struct C { virtual void foo(){}; };
    static_assert(std::is_standard_layout_v<C> == false);

    static_assert(std::is_pod_v<A> == true);
    static_assert(std::is_pod_v<B> == false);
    static_assert(std::is_pod_v<C> == false);
}

class A {
    A() = default;
    int a_;
    int b_;
};

struct B {
    B() {}
    int b_;
};

class C {
    public:
        C() = default;
        C(int i) : c_(0) { i_ = i; }
        int i_;

    private:
        char c_;
};

TEST(PODCLASS, STANDTRIVIAL){
    std::cout << std::boolalpha;

    // 平凡类型(trivial)，可靠的复制
    {
        // 有默认构造函数
        std::cout << "is_trivial<A>:" << std::is_trivial<A>::value << '\n';
        std::cout << "is_trivial<B>:" << std::is_trivial<B>::value << '\n';
        std::cout << "is_trivial<C>:" << std::is_trivial<C>::value << '\n';
    }

    std::cout << std::endl;
    // 标准布局类型，C语言安全的访问
    {
        // 成员变量访问权限一致
        std::cout << "is_standard_layout<A>:" << std::is_standard_layout<A>::value << '\n';
        std::cout << "is_standard_layout<B>:" << std::is_standard_layout<B>::value << '\n';
        std::cout << "is_standard_layout<C>:" << std::is_standard_layout<C>::value << '\n';
    }

    std::cout << std::endl;
    //  简单旧数据类型，可被C语言支持 POD
    {
        std::cout << "is_pod<A>:" << std::is_pod<A>::value << '\n';
        std::cout << "is_pod<B>:" << std::is_pod<B>::value << '\n';
        std::cout << "is_pod<C>:" << std::is_pod<C>::value << '\n';
    }
}

TEST(PODCLASS, IS_TRIVIALLY_COPYABLE){
    struct A { int m; };
    static_assert(std::is_trivially_copyable_v<A> == true);

    struct B { B(B const&) {} };
    static_assert(std::is_trivially_copyable_v<B> == false);

    struct C { virtual void foo(){}; };
    static_assert(std::is_trivially_copyable_v<C> == false);

    struct D
    {
        int m;

        D(D const&) = default; // -> trivially copyable
        D(int x) : m(x + 1) {}
    };
    static_assert(std::is_trivially_copyable_v<D> == true);
}


TEST(PODCLASS, IS_DEFAULT_CONSTRUCTIBLE){
    struct Ex1
    {
        std::string str; // member has a non-trivial default ctor
    };
    
    struct Ex2
    {
        int n;
        Ex2() = default; // trivial and non-throwing
    };

    std::cout << std::boolalpha
              << "Ex1 is default-constructible? "
              << std::is_default_constructible<Ex1>::value << '\n'
              << "Ex1 is trivially default-constructible? "
              << std::is_trivially_default_constructible<Ex1>::value << '\n'
              << "Ex2 is trivially default-constructible? "
              << std::is_trivially_default_constructible<Ex2>::value << '\n'
              << "Ex2 is nothrow default-constructible? "
              << std::is_nothrow_default_constructible<Ex2>::value << '\n';
}

// std::integral_constant wraps a static constant of specified type. It is the base class for the C++ type traits.
TEST(PODCLASS, INTEGRAL_CONSTANT){

    typedef std::integral_constant<int, 2> two_t;
    typedef std::integral_constant<int, 4> four_t;
 
    static_assert(!std::is_same<two_t, four_t>::value, "two_t and four_t are equal!");
 
    static_assert(two_t::value * 2 == four_t::value, "2*2 != 4");
 
    enum class my_e { e1, e2 };
 
    typedef std::integral_constant<my_e, my_e::e1> my_e_e1;
    typedef std::integral_constant<my_e, my_e::e2> my_e_e2;
 
    static_assert(my_e_e1() == my_e::e1);
 
    static_assert(my_e_e1::value != my_e::e2, "my_e_e1::value == my_e::e2");
 
    static_assert(std::is_same<my_e_e2, my_e_e2>::value, "my_e_e2 != my_e_e2");
}

TEST(PODCLASS, NEGATION){
static_assert(
    std::is_same<
        std::bool_constant<false>,
        typename std::negation<std::bool_constant<true>>::type>::value,
    "");

static_assert(
    std::is_same<
        std::bool_constant<true>,
        typename std::negation<std::bool_constant<false>>::type>::value,
    "");

    std::cout << std::boolalpha;
    std::cout << std::negation<std::bool_constant<true>>::value << '\n';
    std::cout << std::negation<std::bool_constant<false>>::value << '\n';
}