#include <iostream>

template<unsigned i>
struct Fibonacci
{
    static const unsigned result=Fibonacci<i-1>::result+Fibonacci<i-2>::result;
};

template<>
struct Fibonacci<0> { static const unsigned result=1; };

template<>
struct Fibonacci<1> { static const unsigned result=1; };

int main()
{
    std::cout<<Fibonacci<5>::result<<std::endl;
}
