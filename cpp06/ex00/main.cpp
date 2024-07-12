#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: invalid number of arguments" << std::endl;
		std::cerr << "Usage: ./convert [NUMBER/INPUT]" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}