#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() 
{
    std::cout << "ClapTrap default constructor" << std::endl;
    hitPoints = 10;
    energyPoints = 10;
    attackDamage = 0;
}

ClapTrap::ClapTrap(const std::string name) : name(name) 
{
    std::cout << "ClapTrap constructor" << std::endl;
    hitPoints = 10;
    energyPoints = 10;
    attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap)
{
    *this = clapTrap;
}

ClapTrap::~ClapTrap() 
{
    std::cout << "ClapTrap destructor" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& clapTrap)
{
    name = clapTrap.name;
    hitPoints = clapTrap.hitPoints;
    energyPoints = clapTrap.energyPoints;
    attackDamage = clapTrap.attackDamage;
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if (hitPoints == 0)
    {
        std::cout << "ClapTrap " << name << " has no hit points! Cannot attack!" << std::endl;
        return;
    }
    if (energyPoints == 0)
    {
        std::cout << "ClapTrap " << name << " has no energy points!" << std::endl;
        return;
    }
    energyPoints -= 1;
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " has no hit points! cannot take damage anymore." << std::endl;
        return;
    }
    if (amount > hitPoints)
        amount = hitPoints;
    hitPoints -= amount;
    std::cout << "current hit points: " << hitPoints << std::endl;
    std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints == 0)
    {
        std::cout << "ClapTrap " << name << " has no hit points!" << std::endl;
        return;
    }
    if (energyPoints == 0)
    {
        std::cout << "ClapTrap " << name << " has no energy points!" << std::endl;
        return;
    }
    energyPoints -= 1;
    if (amount + hitPoints > 2000)
    {
        std::cout << "Cannot repair more than 2000 hit points!" << std::endl;
        return;
    }    
    hitPoints += amount;
    std::cout << "ClapTrap " << name << " is repaired for " << amount << " points!" << std::endl;
}
