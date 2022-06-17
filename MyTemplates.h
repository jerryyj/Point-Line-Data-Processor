#ifndef MYTEMPLATES_H
#define MYTEMPLATES_H

#include <cmath>
#include <type_traits>

// Template definition and implementation for scalar_difference function
template <typename T>
double scalar_difference(T arg1, T arg2)
{
    return std::abs(arg1.getScalarValue() - arg2.getScalarValue());
}

// Template definition and implementation for equals function
template <typename T>
bool equals(T arg1, T arg2)
{
    return (arg1 == arg2);
}

#endif