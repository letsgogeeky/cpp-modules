#include <iostream>
#include <string>
#include <cstdlib>

class ScalarConverter
{
private:
	ScalarConverter();
	~ScalarConverter();
    static void showAsChar(const std::string input);
    static void showAsInt(const std::string input);
    static void showAsFloat(const std::string input);
    static void showAsDouble(const std::string input);
	static size_t _countChars(const std::string input, char c);
	static bool _isAllNumeric(const std::string input);

public:

    static void convert(const std::string input);
};