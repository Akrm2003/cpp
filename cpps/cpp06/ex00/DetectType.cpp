#include "DetectType.hpp"
#include <cctype>
#include <string>

#include <iostream>

void printType(int type) {
    switch (type) {
        case CHAR:   std::cout << "type of the input is " <<  "CHAR" << std::endl; break;
        case INT:    std::cout << "type of the input is " <<  "INT" << std::endl; break;
        case DOUBLE: std::cout << "type of the input is " <<  "DOUBLE" << std::endl; break;
        case FLOAT:  std::cout << "type of the input is " <<  "FLOAT" << std::endl; break;
        case INVALID:std::cout << "type of the input is " <<  "INVALID" << std::endl; break;
        default:     std::cout << "type of the input is " <<  "UNKNOWN" << std::endl; break;
    }
}

bool isChar(const std::string& s) {
    return s.length() == 1 && std::isprint(s[0]) && !std::isdigit(s[0]);
}

bool isInt(const std::string& s) {
    if (s.empty()) return false;
    size_t i = 0;
    if (s[0] == '-' || s[0] == '+') i++;
    for (; i < s.length(); i++)
        if (!std::isdigit(s[i])) return false;
    return true;
}

//check  - akram
bool isFloat(const std::string& s) {
    if (isPseudoFloat(s)) return true;
    if (s.empty() || s[s.length() - 1] != 'f') return false;

    std::string numericPart = s.substr(0, s.length() - 1);
    const char* str = numericPart.c_str();
    char* pos = 0;

    std::strtod(str, &pos);

    if (pos == str || *pos != '\0')
        return false;

    return true;
}

//check  - akram
bool isDouble(const std::string& s) {
    if (isPseudoDouble(s)) return true;
    if (s.empty() || s[s.length() - 1] == 'f') return false;

    const char* str = s.c_str();
    char* pos = 0;

    std::strtod(str, &pos);

    if (pos == str || *pos != '\0')
        return false;

    return true;
}

int DetectType(std::string &l) {
    if (isChar(l)) return CHAR;
    if (isInt(l)) return INT;
    if (isFloat(l)) return FLOAT;
    if (isDouble(l)) return DOUBLE;
    return INVALID;
}
