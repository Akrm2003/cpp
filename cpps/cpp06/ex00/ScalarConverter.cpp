#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(char *literal)
{
    int type = 0;
    if (!literal)
    {
        std::cerr << "Error:\ncan't convert Null";
        exit (1);
    }
    std::string strLiteral = literal;
    type = DetectType(strLiteral);
    printType(type);
    if (type == CHAR)
    {
        handleChar(strLiteral);
    }
    else if (type == INT)
    {
        handleInt(strLiteral);
    }
    else if (type == FLOAT)
    {
        handleFloat(strLiteral);
    }
    else if (type == DOUBLE)
    {
        handleDouble(strLiteral);
    }
    else
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return ;
    }
}