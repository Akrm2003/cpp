#include "MutantStack.hpp"
#include <iostream>
#include <deque>
#include <list>

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    return 0;
}

// int main()
// {
//     std::string str1;
//     MutantStack<std::string> mstack;
//     mstack.push("first");
//     try{
//         str1 = mstack.top();
//         std::cout << "Popped element: " << str1 << std::endl;
//         mstack.pop();
//     }
//     catch(const std::out_of_range& e){
//         std::cerr << "exception: " <<  e.what() << '\n';
//     }

//     // std::cout << "Top element: " << mstack.top() << std::endl;
//     // mstack.pop();
//     // std::cout << "Size after pop: " << mstack.size() << std::endl;

//     // std::cout << "Elements in MutantStack:" << std::endl;
//     // for (MutantStack<std::string>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
//     //     std::cout << *it << std::endl;
//     // }

//     return 0;
// }