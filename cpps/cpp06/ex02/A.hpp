#pragma once
# include "Base.hpp" 

class A : public Base {
    public:
        ~A() { std::cout << "A destructor called" << std::endl; }
};