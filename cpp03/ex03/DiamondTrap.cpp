#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() 
    : ClapTrap(), ScavTrap(), FragTrap(), name(ClapTrap::name + "_clap_name")
{
    std::cout << "DiamondTrap default constructor" << std::endl;
    hitPoints = FragTrap::hitPoints;
    energyPoints = ScavTrap::energyPoints;
    attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(std::string name) 
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name)
{
    std::cout << "DiamondTrap constructor" << std::endl;
    hitPoints = FragTrap::hitPoints;
    energyPoints = ScavTrap::energyPoints;
    attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap)
{
    *this = diamondTrap;
}

DiamondTrap::~DiamondTrap() 
{
    std::cout << "DiamondTrap destructor" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondTrap)
{
    name = diamondTrap.name;
    hitPoints = diamondTrap.hitPoints;
    energyPoints = diamondTrap.energyPoints;
    attackDamage = diamondTrap.attackDamage;
    return *this;
}

void DiamondTrap::attack(std::string const &target)
{
    ScavTrap::attack(target);    
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << name << std::endl;
    std::cout << "ClapTrap name: " << ClapTrap::name << std::endl;
}
