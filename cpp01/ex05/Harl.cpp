#include "Harl.hpp"
#include <iostream>

Harl::Harl() 
{
    this->levels[0] = "debug";
    this->levels[1] = "info";
    this->levels[2] = "warning";
    this->levels[3] = "error";
    this->functions[0] = &Harl::debug;
    this->functions[1] = &Harl::info;
    this->functions[2] = &Harl::warning;
    this->functions[3] = &Harl::error;
}

Harl::~Harl() {}

void Harl::complain(std::string level)
{
    for (int i = 0; i < 4; i++)
    {
        if (level == this->levels[i])
        {
            (this->*functions[i])();
            return;
        }
    }
}

void Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable. I want to speak to the manager now." << std::endl;
}