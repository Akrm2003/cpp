#pragma once
# include "utils.hpp"
# include <limits>
# include <cctype>
# include <cstdlib>
#include <iostream>
#include <string>

enum TypeName {
    CHAR = 0,
    INT = 1,
    DOUBLE = 2,
    FLOAT = 3,
    INVALID = 4
};

int DetectType(std::string &l);
void printType(int type);