#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <unistd.h>

int main() {
    Base* base_ptr;
    base_ptr = generate();
    identify(base_ptr);
    Base& base_ref = *base_ptr;
    identify(base_ref);
    delete base_ptr;
    // testing identify by reference
}