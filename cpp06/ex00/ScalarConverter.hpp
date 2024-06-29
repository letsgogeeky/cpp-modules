#include <iostream>

class ScalarConverter
{
private:
    static void showAsChar(const std::string input);
    static void showAsInt(const std::string input);
    static void showAsFloat(const std::string input);
    static void showAsDouble(const std::string input);

public:

    static void convert(const std::string input);
};