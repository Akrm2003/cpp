#pragma once
#include <iostream>


// note for maeen it showed a segfault here when a (-) number was intruduced as length not sure if its needed to be handled cause size_t is unsigned
template <typename T, typename Func>
void iter(T &array, const size_t length, Func f)
{
    for (size_t i = 0; i < length; i++)
    {
        f(array[i]);
    }
}

template <typename T, typename Func>
void iter(const T &array, const size_t length, Func f)
{
    for (size_t i = 0; i < length; i++)
    {
        f(array[i]);
    }
}
