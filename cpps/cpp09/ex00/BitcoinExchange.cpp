#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : data() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : data(other.data) {}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        data = other.data;
    }
    return *this;
}
BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 1000 || year > 9999 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;

    if (month == 2)
    {
        bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > (isLeapYear ? 29 : 28))
            return false;
    }

    return true;
}

bool BitcoinExchange::isValidValue(const std::string &valueStr, double &value) const
{
    try
    {
        size_t pos;
        value = std::stod(valueStr, &pos);
        if (pos != valueStr.size())
            return false;
        if (value < 0)
            return false;
    }
    catch (const std::exception &)
    {
        return false;
    }
    return true;
}

bool BitcoinExchange::isValidDataLine(const std::string &line) const
{
    size_t commaPos = line.find(',');
    if (commaPos == std::string::npos || line.find(',', commaPos + 1) != std::string::npos)
        return false; // Ensure exactly one comma

    std::string date = line.substr(0, commaPos);
    std::string valueStr = line.substr(commaPos + 1);

    // Validate the date and value
    double value;
    return isValidDate(date) && isValidValue(valueStr, value);
}

bool BitcoinExchange::isValidInputLine(const std::string &line) const
{
    size_t pipePos = line.find('|');
    if (pipePos == std::string::npos || line.find('|', pipePos + 1) != std::string::npos)
        return false; // Ensure exactly one '|'

    std::string date = line.substr(0, pipePos);
    std::string valueStr = line.substr(pipePos + 1);

    // Trim whitespace around the date and value
    date.erase(0, date.find_first_not_of(" \t"));
    date.erase(date.find_last_not_of(" \t") + 1);
    valueStr.erase(0, valueStr.find_first_not_of(" \t"));
    valueStr.erase(valueStr.find_last_not_of(" \t") + 1);

    // Validate the date and value
    double value;
    return isValidDate(date) && isValidValue(valueStr, value);
}

double BitcoinExchange::getExchangeRate(const std::string &date) const
{
}

void BitcoinExchange::loadData(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw FileError();
    std::string line;
    std::getline(file, line); // Skip header
    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string date;
        std::string valueStr;
        if (!std::getline(ss, date, ',') || !std::getline(ss, valueStr))
            throw DataError();

        double value = std::atof(valueStr.c_str());
        data[date] = value;
        std::cout << "Loaded: " << date << " => " << value << std::endl;
    }
    file.close();
}

void BitcoinExchange::processInputFile(const std::string &filename)
{
    (void)filename;
    // include full path to avoid unused parameter warning
}