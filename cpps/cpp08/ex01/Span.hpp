#pragma once
#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <iostream>
#include <vector>

class Span
{
private:
    unsigned int _N;
    std::vector<int> _vec;

public:
    Span(unsigned int N);
    void addNumber(int number);
    template <typename InputIterator>
    void addNumber(InputIterator begin, InputIterator end);
    int shortestSpan() const;
    int longestSpan() const;
    class SpanFull : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
    class NotEnoughNumbers : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};