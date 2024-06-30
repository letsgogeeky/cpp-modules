#include "ScalarConverter.hpp"

void ScalarConverter::showAsChar(const std::string input)
{
    try
    {
        char c = std::stoi(input);
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
        int i = std::stoi(input);
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
        float f = std::stof(input);
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
        double d = std::stod(input);
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
