#include <string>
#include <iostream>
#include <fstream>
#include "StringReplace.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Error: Invalid number of arguments" << std::endl;
        std::cout << "Usage: ./ex04 [file] [s1] [s2 (to replace s1)]" << std::endl;
        return 1;
    }
    std::string replaced = argv[1];
    replaced += ".replace";
    std::ifstream file(argv[1]);
    std::fstream file_replaced;
    if (!file || !file.is_open())
    {
        std::cout << "Error: Could not open file" << std::endl;
        return 1;
    }
    file_replaced.open(replaced.c_str(), std::ios::out | std::ios::trunc);
    if (!file_replaced.is_open())
    {
        file.close();
        std::cout << "Error: Could not open file" << std::endl;
        return 1;
    }
    std::string line;
    StringReplace sr = StringReplace();
    while (std::getline(file, line))
    {
        file_replaced << sr.replace(line, argv[2], argv[3]) << std::endl;
    }
    file.close();
    file_replaced.close();
    return 0;
}