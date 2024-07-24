#include "BitcoinExchange.hpp"
#include <cstdlib>

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
    std::ifstream file;
	file.open(path.c_str(), std::ios::in);
    if (!file.is_open())
        throw std::invalid_argument("File not found");
    
    std::string line;
    std::getline(file, line);
	if (line != "date,exchange_rate")
		throw std::invalid_argument("Invalid file format, expected 'date,exchange_rate' as a header.");
    while (std::getline(file, line))
    {
        _db.insert(
            std::pair<std::string, double>(line.substr(0, line.find(',')),
            std::atof(line.substr(line.find(',') + 1).c_str()))
        );
    }
}

void BitcoinExchange::processInput(std::string path) const
{
    std::ifstream file;
	file.open(path.c_str(), std::ios::in);
    if (!file.is_open())
        throw std::invalid_argument("File not found");

    std::string line;
    std::getline(file, line);
	if (line != "date | value")
		throw std::invalid_argument("Invalid file format, expected 'date | value' as a header.");
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
        date = line.substr(0, line.find('|') - 1);
        amount = _convertToDouble(line.substr(line.find('|') + 1));
        double rate = getRate(date);
		if (rate == -1)
		{
			std::cerr << "Error: No exchange rate found for: " << date << std::endl;
			continue;
		}
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
	try
	{
		if (date.length() != 10) return false;
    	if (date[4] != '-' || date[7] != '-') return false;
		int year = std::atoi(date.substr(0, 4).c_str());
		int month = std::atoi(date.substr(5, 2).c_str());
		int day = std::atoi(date.substr(8, 2).c_str());
		int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		if (isLeapYear(year))
			daysInMonth[1] = 29;
		if (month < 1 || month > 12)
			return false;
		if (day < 1 || day > daysInMonth[month - 1])
			return false;
		return true;
	}
	catch (const std::exception &e)
	{
		return false;
	}
}

double BitcoinExchange::getRate(std::string date) const
{
    double rate;
    if (_db.find(date) != _db.end())
       rate = _db.at(date);
    // find closest date
    else
    {
		// std::map<std::string, double>::const_iterator it = _db.lower_bound(date);
		// rate = it->second;
        std::string closestDate;
        double closestRate = -1;
        for (std::map<std::string, double>::const_iterator it = _db.begin(); it != _db.end(); ++it)
        {
			int date_timestamp = _dateToTimestamp(date);
			int it_timestamp = _dateToTimestamp(it->first);
			int closest_timestamp = _dateToTimestamp(closestDate);
			bool isClosest = std::abs(date_timestamp - it_timestamp) < std::abs(date_timestamp - closest_timestamp);
			if (it_timestamp > date_timestamp)
				break;
            if (closestDate.empty() || isClosest)
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
    if (!_isDateValid(record.substr(0, 10)))
        return InvalidDate;
    if (record.find('|') + 2 >= record.length())
        return InvalidRecordFormat;
    if (record.substr(0, record.find('|')).length() > 12)
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
    if (_convertToDouble(rate) < 0)
        return NegativeRate;

    if (_convertToDouble(rate) > 1000)
        return TooLargeRate;

    return NoError;
}

void BitcoinExchange::_parseRecord(std::string record)
{
    std::string date = record.substr(0, record.find(','));
    double rate = _convertToDouble(record.substr(record.find(',') + 1));
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
        std::cerr << "Error: Invalid date => " << record << std::endl;
        break;
    case NegativeRate:
        std::cerr << "Error: Negative rate => " << record << std::endl;
        break;
    case TooLargeRate:
        std::cerr << "Error: Rate too large => " << record << std::endl;
        break;
    case InvalidRecordFormat:
        std::cerr << "Error: Invalid record format => " << record << std::endl;
        break;
    default:
        break;
    }
    std::cout << "\033[0m";
}

double BitcoinExchange::_convertToDouble(std::string str) const
{
	std::stringstream ss(str);
	double result;
	ss >> result;
	result = static_cast<double>(result);
	return result;
}

int BitcoinExchange::_dateToTimestamp(std::string date) const
{
	if (date.length() != 10)
		return -1;
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	int timestamp = 0;
	for (int i = 1970; i < year; i++)
	{
		if (isLeapYear(i))
			timestamp += 366;
		else
			timestamp += 365;
	}
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (isLeapYear(year))
		daysInMonth[1] = 29;
	for (int i = 0; i < month - 1; i++)
		timestamp += daysInMonth[i];
	timestamp += day;
	return timestamp;
}
