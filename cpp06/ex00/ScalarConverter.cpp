#include "ScalarConverter.hpp"
#include <sstream>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::showAsChar(const std::string input)
{
    try
    {
		std::istringstream ss(input);
		double implicit_cast;
		ss >> implicit_cast;
        char c = static_cast<char>(implicit_cast);
        if (c < 32 || c > 126)
            throw std::exception();
        std::cout << "char: '" << c << "'" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "char: Non displayable. Supported displayable range is from ASCII 32 to 126" << std::endl;
    }
}

void ScalarConverter::showAsInt(const std::string input)
{
    try
    {
		std::istringstream ss(input);
		double implicit_cast;
		ss >> implicit_cast;
        int i = static_cast<int>(implicit_cast);
        std::cout << "int: " << i << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "int: impossible" << std::endl;
    }
}

void ScalarConverter::showAsFloat(const std::string input)
{
    try
    {
		if (_countChars(input, '.') > 1 || !_isAllNumeric(input))
			throw std::exception();
		std::istringstream ss(input);
		double implicit_cast;
		ss >> implicit_cast;
        float f = static_cast<float>(implicit_cast);
		// std::cout.precision(10);
        std::cout << "float: " << f << "f" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "float: impossible" << std::endl;
    }
}

void ScalarConverter::showAsDouble(const std::string input)
{
    try
    {
		if (_countChars(input, '.') > 1 || !_isAllNumeric(input))
			throw std::exception();
		std::istringstream ss(input);
		double implicit_cast;
		ss >> implicit_cast;
        double d = static_cast<double>(implicit_cast);
        std::cout << "double: " << d << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "double: impossible" << std::endl;
    }
}

void ScalarConverter::convert(const std::string input)
{
    ScalarConverter::showAsChar(input);
    ScalarConverter::showAsInt(input);
    ScalarConverter::showAsFloat(input);
    ScalarConverter::showAsDouble(input);
}

size_t ScalarConverter::_countChars(const std::string input, char c)
{
	size_t count = 0;
	for (size_t i = 0; i < input.length(); i++)
	{
		if (input[i] == c)
			count++;
	}
	return count;
}

bool ScalarConverter::_isAllNumeric(const std::string input)
{
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!std::isdigit(input[i]) && input[i] != '.' && input[i] != '-')
			return false;
	}
	return true;
}
