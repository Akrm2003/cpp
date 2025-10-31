#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

class BitcoinExchange
{
private:
    std::map<std::string, double> data;

    bool    isValidDate(const std::string &date) const;
    bool    isValidValue(const std::string &valueStr, double &value) const;
	bool	isValidDataValue(const std::string &valueStr, double &value) const;
    double  getExchangeRate(const std::string &date) const;
    bool    isValidDataLine(const std::string &line) const;
    bool    isValidInputLine(const std::string &line) const;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();
    void loadData(const std::string &filename);
    void processInputFile(const std::string &filename);
    class FileError : public std::exception
    {
    public:
        const char *what() const throw()
        {
            return "File could not be opened.";
        }
    };
    class DataError : public std::exception
    {
    public:
        const char *what() const throw()
        {
            return "Data format is incorrect.";
        }
    };
    class InputError : public std::exception
    {
    public:
        const char *what() const throw()
        {
            return "Input format is incorrect.";
        }
    };
};
