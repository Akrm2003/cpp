#include "iter.hpp"
#include <iostream>
#include <string>


void incrementElements(int &x)
{
    x += 1;
}
void print(const std::string &x)
{
    std::cout << x << std::endl;
}

int main( void )
{
    int tab[] = { 0, 1, 2, 3, 4 };
    ::iter( tab, 5, incrementElements);
    for (size_t i = 0; i < 5; i++)
        std::cout << tab[i] << ' ';
    std::cout << std::endl;



    const std::string tab2[] = { "hello", "world", "!" };
    ::iter( tab2, 3, print);
    return 0;
}

// template <typename T>
// void incrementElements(T &x)
// {
//     x += 1;
// }

// template <typename T>
// void print(const T &x)
// {
//     std::cout << x << std::endl;
// }

// int main( void )
// {
//     int tab[] = { 0, 1, 2, 3, 4 };
//     ::iter( tab, 5, incrementElements<int> );
//     for (size_t i = 0; i < 5; i++)
//         std::cout << tab[i] << ' ';
//     std::cout << std::endl;



//     const std::string tab2[] = { "hello", "world", "!" };
//     ::iter( tab2, 3, print<std::string> );
//     return 0;
// }