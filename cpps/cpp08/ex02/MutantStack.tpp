#include "MutantStack.hpp"

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack()
    : std::stack<T, Container>() {}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack& other)
    : std::stack<T, Container>(other) {}

template <typename T, typename Container>
MutantStack<T, Container>&
MutantStack<T, Container>::operator=(const MutantStack& other) {
    if (this != &other)
        std::stack<T, Container>::operator=(other);
    return *this;
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack() {}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator
MutantStack<T, Container>::begin() {
    return this->c.begin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator
MutantStack<T, Container>::end() {
    return this->c.end();
}

template <typename T, typename Container>
void MutantStack<T, Container>::pop() {
    if (this->empty()) {
        throw std::out_of_range("MutantStack::pop(): empty stack");
    }
    std::stack<T, Container>::pop();
}

template <typename T, typename Container>
T MutantStack<T, Container>::top() {
    if (this->empty()) {
        throw std::out_of_range("MutantStack::top(): empty stack");
    }
    return std::stack<T, Container>::top();
}