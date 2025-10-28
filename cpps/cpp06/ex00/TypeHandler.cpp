#include "TypeHandler.hpp"

void handleChar(std::string &l)
{
    char c = l[0];
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

//check  - akram
void handleInt(std::string &l)
{
    char *endptr = 0;
    errno = 0;

    long val = std::strtol(l.c_str(), &endptr, 10);

    // Check for conversion errors:
    if (endptr == l.c_str() || *endptr != '\0' || errno == ERANGE ||
        val > INT_MAX || val < INT_MIN)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    int i = static_cast<int>(val);

    if (std::isprint(static_cast<unsigned char>(i)))
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

//check  - akram
void handleDouble(std::string &l)
{
    char *endptr = 0;
    errno = 0;

    double d = std::strtod(l.c_str(), &endptr);

    // check for errors
    if (endptr == l.c_str() || *endptr != '\0' || errno == ERANGE)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    // handle char and int conversions
    if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        int i = static_cast<int>(d);
        if (std::isprint(static_cast<unsigned char>(i)))
            std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;

        std::cout << "int: " << i << std::endl;
    }

    // float output
    float f = static_cast<float>(d);
    if (f - static_cast<int>(f) == 0)
        std::cout << "float: " << f << ".0f" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;

    // double output
    if (d - static_cast<int>(d) == 0)
        std::cout << "double: " << d << ".0" << std::endl;
    else
        std::cout << "double: " << d << std::endl;
}

//check  - akram
void handleFloat(std::string &l)
{
    // remove trailing 'f'
    std::string floatStr = l.substr(0, l.size() - 1);

    char *endptr = 0;
    errno = 0;

    double temp = std::strtod(floatStr.c_str(), &endptr);

    // validate parsing
    if (endptr == floatStr.c_str() || *endptr != '\0' || errno == ERANGE)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    float f = static_cast<float>(temp);

    if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        int i = static_cast<int>(f);
        if (std::isprint(static_cast<unsigned char>(i)))
            std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;

        std::cout << "int: " << i << std::endl;
    }

    // float output
    if (f - static_cast<int>(f) == 0)
        std::cout << "float: " << f << ".0f" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;

    // double output
    double d = static_cast<double>(f);
    if (d - static_cast<int>(d) == 0)
        std::cout << "double: " << d << ".0" << std::endl;
    else
        std::cout << "double: " << d << std::endl;
}