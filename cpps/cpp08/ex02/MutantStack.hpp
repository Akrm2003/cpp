#pragma once

# include <stack>
# include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
    MutantStack();
    MutantStack(const MutantStack& other);
    MutantStack& operator=(const MutantStack& other);
    ~MutantStack();

    typedef typename Container::iterator iterator;
    iterator begin();
    iterator end();

    void pop();
    T top();

};

#include "MutantStack.tpp" // 👈 include implementation here
