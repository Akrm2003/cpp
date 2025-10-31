#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cstdlib>

class RPN
{
private:
    std::stack<double> _stack;
    
    bool isOperator(const std::string& token) const;
    bool isNumber(const std::string& token) const;
    void executeOperation(const std::string& op);

public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();
    
    double calculate(const std::string& expression);
};

#endif