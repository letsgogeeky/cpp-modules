#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap default constructor" << std::endl;
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap constructor" << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragTrap)
{
    *this = fragTrap;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &fragTrap)
{
    name = fragTrap.name;
    hitPoints = fragTrap.hitPoints;
    energyPoints = fragTrap.energyPoints;
    attackDamage = fragTrap.attackDamage;
    return *this;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << name << " requests a high five!" << std::endl;
}