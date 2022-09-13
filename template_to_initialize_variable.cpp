#include <iostream>

template <typename T>
constexpr T pi = static_cast<T>(3.141592653589793238462643383);

template <>
constexpr const char* pi<const char*> = "pi";

int main ()
{
    std::cout << "int pi: " << pi<int> << std::endl;
    std::cout << "float pi: " << pi<float> << std::endl;
    std::cout << "double pi: " << pi<double> << std::endl;
    std::cout << "char pi: " << pi<const char*> << std::endl;

    return 0;
}
