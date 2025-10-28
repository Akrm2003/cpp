#pragma once
# include "DetectType.hpp"
# include "TypeHandler.hpp"
# include <iomanip>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();
    public:
        static void convert(char *literal);
};
