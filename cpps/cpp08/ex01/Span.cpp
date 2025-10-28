#include "Span.hpp"

Span::Span(unsigned int N) : _N(N)
{
    this->_vec.reserve(N);
}

void Span::addNumber(int number)
{
    if (this->_vec.size() >= this->_N)
        throw Span::SpanFull();
    this->_vec.push_back(number);
}

template <typename InputIterator>
void Span::addNumber(InputIterator begin, InputIterator end)
{
    if (this->_vec.size() + std::distance(begin, end) > this->_N)
        throw Span::SpanFull();
    this->_vec.insert(this->_vec.end(), begin, end);
}


template void Span::addNumber<std::vector<int>::iterator>(std::vector<int>::iterator, std::vector<int>::iterator);
template void Span::addNumber<std::vector<int>::const_iterator>(std::vector<int>::const_iterator, std::vector<int>::const_iterator);

int Span::shortestSpan() const
{
    if (this->_vec.size() < 2)
        throw Span::NotEnoughNumbers();
    std::vector<int> sortedVec = this->_vec;
    std::sort(sortedVec.begin(), sortedVec.end());
    int minSpan = sortedVec[1] - sortedVec[0];
    for (size_t i = 1; i < sortedVec.size() - 1; i++)
    {
        int span = sortedVec[i + 1] - sortedVec[i];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}


int Span::longestSpan() const
{
    if (this->_vec.size() < 2)
        throw Span::NotEnoughNumbers();
    int min = *std::min_element(this->_vec.begin(), this->_vec.end());
    int max = *std::max_element(this->_vec.begin(), this->_vec.end());
    return max - min;
}


const char* Span::SpanFull::what() const throw()
{
    return "Span is full";
}

const char* Span::NotEnoughNumbers::what() const throw()
{
    return "Not enough numbers to find a span";
}

