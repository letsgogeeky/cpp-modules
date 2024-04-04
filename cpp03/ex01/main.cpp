#include "ScavTrap.hpp"

int main()
{
    ScavTrap scavTrap("scavTrap");

    scavTrap.attack("Madara");
    scavTrap.takeDamage(10);
    scavTrap.beRepaired(5);
    scavTrap.attack("Naruto");
    scavTrap.beRepaired(400);
    scavTrap.takeDamage(350);
    scavTrap.guardGate();
    return 0;
}

