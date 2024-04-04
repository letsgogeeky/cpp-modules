#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap default constructor" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap constructor" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap)
{
    *this = scavTrap;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap)
{
    name = scavTrap.name;
    hitPoints = scavTrap.hitPoints;
    energyPoints = scavTrap.energyPoints;
    attackDamage = scavTrap.attackDamage;
    return *this;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " has entered in Gate keeper mode" << std::endl;
}
