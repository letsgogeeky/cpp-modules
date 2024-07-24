#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <fstream>
#include <exception>

enum Error
{
    NoError,
    InvalidDate,
    NegativeRate,
    TooLargeRate,
    InvalidRecordFormat
};

class BitcoinExchange
{
private:
    std::map<std::string, double> _db;
    void    _loadDb(std::string path);
    bool    _isDateValid(std::string date) const;
    double  getRate(std::string date) const;
    Error    _isValidRecord(std::string record) const;
    void    _parseRecord(std::string record);
    void    logError(Error error, std::string record) const;
	double	_convertToDouble(std::string str) const;
	int     _dateToTimestamp(std::string date) const;

public:
    BitcoinExchange(std::string path);
    BitcoinExchange(const BitcoinExchange &bitcoinExchange);
    BitcoinExchange &operator=(const BitcoinExchange &bitcoinExchange);
    ~BitcoinExchange();

    void    processInput(std::string path) const;
    void    printDb() const;
};
