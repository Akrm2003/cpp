#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>
#include <map>

int main()
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    lst.push_back(50);

    std::deque<int> deq;
    deq.push_back(100);
    deq.push_back(200);
    deq.push_back(300);
    deq.push_back(400);
    deq.push_back(500);

    try
    {
        std::vector<int>::iterator it_vec = easyfind(vec, 3);
        std::cout << "Found in vector: " << *it_vec << std::endl;

        std::list<int>::iterator it_lst = easyfind(lst, 20);
        std::cout << "Found in list: " << *it_lst << std::endl;

        std::deque<int>::iterator it_deq = easyfind(deq, 400);
        std::cout << "Found in deque: " << *it_deq << std::endl;
        
        
        easyfind(vec, 6);

        // this won't be called because the exception will be thrown

        std::deque<int>::iterator another_it_deq = easyfind(deq, 400);
        std::cout << "Found in deque: " << *another_it_deq << std::endl;
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
