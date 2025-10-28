#pragma once

template <typename T>
void swap(T &first, T &second)
{
    T temp = first;
    first = second;
    second = temp;
}

template <typename T>
T const &min(T const &first, T const &second)
{
    if (first < second)
        return first;
    return second;
}

template <typename T>
T const& max(T const &first, T const &second)
{
    if (first > second)
        return first;
    return second;
}