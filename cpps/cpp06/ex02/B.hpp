#pragma once
# include "Base.hpp" 

class B : public Base {
    public:
        ~B() { std::cout << "B destructor called" << std::endl; }
};