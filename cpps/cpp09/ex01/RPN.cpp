#include "RPN.hpp"

// Constructors and Destructor
RPN::RPN() {}

RPN::RPN(const RPN& other) : _stack(other._stack) {}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
    {
        _stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {}

// Helper functions
bool RPN::isOperator(const std::string& token) const
{
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool RPN::isNumber(const std::string& token) const
{
    if (token.empty())
        return false;
    
    size_t start = 0;
    if (token[0] == '-' || token[0] == '+')
        start = 1;
    
    if (start >= token.length())
        return false;
    
    for (size_t i = start; i < token.length(); i++)
    {
        if (!isdigit(token[i]))
            return false;
    }
    return true;
}

void RPN::executeOperation(const std::string& op)
{
    if (_stack.size() < 2)
        throw std::runtime_error("Error: insufficient operands for operation");
    
    double b = _stack.top();
    _stack.pop();
    double a = _stack.top();
    _stack.pop();
    
    double result = 0;
    
    if (op == "+")
        result = a + b;
    else if (op == "-")
        result = a - b;
    else if (op == "*")
        result = a * b;
    else if (op == "/")
    {
        if (b == 0)
            throw std::runtime_error("Error: division by zero");
        result = a / b;
    }
    
    _stack.push(result);
}

double RPN::calculate(const std::string& expression)
{
    std::istringstream iss(expression);
    std::string token;
    
    while (iss >> token)
    {
        if (isNumber(token))
        {
            // Check if the number is a single digit (less than 10 as per requirements)
            int num = atoi(token.c_str());
            if (num >= 10 || num <= -10)
                throw std::runtime_error("Error: numbers must be less than 10 and greater than -10");
            
            _stack.push(static_cast<double>(num));
        }
        else if (isOperator(token))
        {
            executeOperation(token);
        }
        else
        {
            throw std::runtime_error("Error: invalid token '" + token + "'");
        }
    }
    
    if (_stack.size() != 1)
        throw std::runtime_error("Error: invalid expression, stack has more than one element");
    
    return _stack.top();
}
