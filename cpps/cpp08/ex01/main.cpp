#include "Span.hpp"

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;

    try
    {
        sp.addNumber(42); // This should throw an exception
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    Span sp2 = Span(10000);
    std::vector<int> vec(10000);
    for (int i = 0; i < 10000; i++)
        vec[i] = i * 2;
    sp2.addNumber(vec.begin(), vec.end());
    std::cout << "Shortest span in large span: " << sp2.shortestSpan() << std::endl;
    std::cout << "Longest span in large span: " << sp2.longestSpan() << std::endl;

    return 0;
}