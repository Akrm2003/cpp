#include "Base.hpp"

Base::~Base() { std::cout << "Base destructor called" << std::endl; }


Base *generate(void) {
    std::srand(std::time(0));
    int num = (std::rand() % 3);

    if (num == 0) {
        std::cout << "Generating instance of A" << std::endl;
        return new A();
    } else if (num == 1) {
        std::cout << "Generating instance of B" << std::endl;
        return new B();
    } else {
        std::cout << "Generating instance of C" << std::endl;
        return new C();
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "Identified as A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "Identified as B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "Identified as C" << std::endl;
    } else {
        std::cout << "Unknown type" << std::endl;
    }
}

void identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "Identified as A" << std::endl;
        return;
    } catch (std::exception&) {}

    try {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "Identified as B" << std::endl;
        return;
    } catch (std::exception&) {}

    try {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "Identified as C" << std::endl;
        return;
    } catch (std::exception&) {}

    std::cout << "Unknown type" << std::endl;
}