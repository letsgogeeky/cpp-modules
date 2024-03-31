#include "Harl.hpp"
#include <iostream>

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout << "Error: Invalid number of arguments" << std::endl;
        std::cout << "Usage: ./ex06 [complaint level]" << std::endl;
        std::cout << "Complaint levels: DEBUG, INFO, WARNING, ERROR" << std::endl;
        return 1;
    }
    std::string level = argv[1];
    Harl harl = Harl();
    harl.setMinLevel(level);
    if (harl.getMinLevel() == -1)
    {
        std::cout << "Error: Invalid complaint level" << std::endl;
        std::cout << "Complaint levels: DEBUG, INFO, WARNING, ERROR" << std::endl;
        return 1;
    }
    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");
    return 0;
}
