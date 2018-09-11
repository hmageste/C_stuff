#include <iostream>

#include "calculate_with_units.h"

// define literals
Value<Meter> operator""m(long double d)
{
    return Value<Meter>(d);
}

Value<Second> operator""s(long double d)
{
    return Value<Second>(d);
}

using namespace std;

int main()
{
    // Examples of usage
    Value<Unit<1,0,-1>> speed1(Value<Meter>(110.0)/Value<Second>(9.8)); 
    Speed speed2(Value<Meter>(110.0)/Value<Second>(9.8));
    Speed speed3 = 100.m/9.8s;

    std::cout << "Speed = " << speed3.val_ << std::endl;

    return 0;
}
