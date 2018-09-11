#pragma once

#include <iostream>

template<int M, int K, int S>
struct Unit
{
    enum { m=M, kg=K, s=S };
};

template<typename Unit>
struct Value
{
    double val_;
    Value(double val);
};

// nicknames for the Units to avoid complex syntax
using Meter = Unit<1,0,0>;   // unit: m
using Second = Unit<0,0,1>;  // unit: sec
using Second2 = Unit<0,0,2>; // unit: sec^2

using Speed = Value<Unit<1,0,-1>>;          // meters/second
using Acceleration = Value<Unit<1,0,-2>>;   // meters/second^2


// division operator for Speed
Speed operator/(Value<Meter> dist, Value<Second> time)
{
    return Speed(dist.val_/time.val_);
}

// Implementation needs to go in the header file
// This is know issue in C++, as the compiler cannot generate
// all the possible implementations for the template structure,
// either we put the implementation in the header file or we explictly define
// the ones we want in the cpp file together with the definition.
// The first approach will possibily compile the same structure many times, once
// in each translation unit. Although, this is not a big problem since the linker
// will correctly ignore duplicate implementations, it certainly will slow down the compilation.
// The latter will require explicit definitions of the templates we want to use
// in the cpp file, e.g.:
// - template struct Value<Unit<1,0,0>>;
// - template class Value<Unit<1,0,-1>>;
template<typename Unit>
Value<Unit>::Value(double val)
    : val_(val) {}
