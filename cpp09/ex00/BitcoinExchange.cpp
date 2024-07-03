#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string path)
{
    _loadDb(path);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &bitcoinExchange)
{
    *this = bitcoinExchange;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &bitcoinExchange)
{
    if (this != &bitcoinExchange)
    {
        _db = bitcoinExchange._db;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
    _db.clear();
}

void BitcoinExchange::_loadDb(std::string path)
{
    _db = std::map<std::string, double>();
    std::ifstream file(path);
    if (!file.is_open())
        throw std::invalid_argument("File not found");
    
    std::string line;
    std::getline(file, line); // skip header (date,rate)
    while (std::getline(file, line))
    {
        _db.insert(
            std::pair<std::string, double>(line.substr(0, line.find(',')),
            std::stod(line.substr(line.find(',') + 1)))
        );
    }
}

void BitcoinExchange::processInput(std::string path) const
{
    std::ifstream file(path);
    if (!file.is_open())
        throw std::invalid_argument("File not found");

    std::string line;
    std::getline(file, line); // skip header (date,amount)
    while (std::getline(file, line))
    {
        Error error = _isValidRecord(line);
        if (error != NoError)
        {
            logError(error, line);
            continue;
        }
        std::string date;
        double amount;
        date = line.substr(0, line.find(','));
        amount = std::stod(line.substr(line.find(',') + 1));
        double rate = getRate(date);
        std::cout << date << " => " << amount << " = " << amount * rate << std::endl;
    }
}

bool isLeapYear(int year)
{
    if (year % 4 != 0)
        return false;
    if (year % 100 != 0)
        return true;
    if (year % 400 != 0)
        return false;
    return true;
}

bool BitcoinExchange::_isDateValid(std::string date) const
{
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;

    int year = std::stoi(date.substr(0, 4));
    int month = std::stoi(date.substr(5, 2));
    int day = std::stoi(date.substr(8, 2));
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(year))
        daysInMonth[1] = 29;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > daysInMonth[month - 1])
        return false;
    return true;

}

double BitcoinExchange::getRate(std::string date) const
{
    double rate;
    if (_db.find(date) != _db.end())
       rate = _db.at(date);
    // find closest date
    else
    {
        std::string closestDate;
        double closestRate;
        for (std::map<std::string, double>::const_iterator it = _db.begin(); it != _db.end(); ++it)
        {
            if (closestDate.empty() || std::abs(std::stod(date) - std::stod(it->first)) < std::abs(std::stod(date) - std::stod(closestDate)))
            {
                closestDate = it->first;
                closestRate = it->second;
            }
        }
        rate = closestRate;
    }
    return rate;
}

Error BitcoinExchange::_isValidRecord(std::string record) const
{
    if (record.find('|') == std::string::npos)
        return InvalidRecordFormat;
    if (!_isDateValid(record.substr(0, record.find('|') - 1)))
        return InvalidDate;
    
    if (record.find('|') + 2 >= record.length())
        return InvalidRecordFormat;
    
    int pipeCount = 0;
    for (size_t i = 0; i < record.length(); i++)
    {
        if (record[i] == '|')
            pipeCount++;
    }
    if (pipeCount != 1)
        return InvalidRecordFormat;

    std::string rate = record.substr(record.find('|') + 2);
    if (rate[0] == '-')
        return NegativeRate;
    for (size_t i = 0; i < rate.length(); i++)
    {
        if (!std::isdigit(rate[i]) && rate[i] != '.')
            return InvalidRecordFormat;
    }

    if (std::stod(rate) < 0)
        return NegativeRate;

    if (std::stod(rate) > 1000)
        return TooLargeRate;

    return NoError;
}

void BitcoinExchange::_parseRecord(std::string record)
{
    std::string date = record.substr(0, record.find(','));
    double rate = std::stod(record.substr(record.find(',') + 1));
    _db.insert(std::pair<std::string, double>(date, rate));
}

void BitcoinExchange::printDb() const
{
    for (std::map<std::string, double>::const_iterator it = _db.begin(); it != _db.end(); ++it)
        std::cout << it->first << " " << it->second << std::endl;
}

void BitcoinExchange::logError(Error error, std::string record) const
{
    std::cout << "\033[31m";
    switch (error)
    {
    case InvalidDate:
        std::cout << "Error: Invalid date => " << record << std::endl;
        break;
    case NegativeRate:
        std::cout << "Error: Negative rate => " << record << std::endl;
        break;
    case TooLargeRate:
        std::cout << "Error: Rate too large => " << record << std::endl;
        break;
    case InvalidRecordFormat:
        std::cout << "Error: Invalid record format => " << record << std::endl;
        break;
    default:
        break;
    }
    std::cout << "\033[0m";
}