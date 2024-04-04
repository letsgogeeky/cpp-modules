#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap diamondTrap("diamondTrap");

    diamondTrap.attack("Madara");
    diamondTrap.takeDamage(10);
    diamondTrap.beRepaired(5);
    diamondTrap.attack("Naruto");
    diamondTrap.beRepaired(400);
    diamondTrap.takeDamage(350);
    diamondTrap.attack("Sasuke");
    diamondTrap.takeDamage(100);
    diamondTrap.highFivesGuys();
    diamondTrap.attack("Kakashi");
    diamondTrap.takeDamage(100);
    diamondTrap.guardGate();
    diamondTrap.whoAmI();
    return 0;
}
