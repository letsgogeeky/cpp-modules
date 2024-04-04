#include "ClapTrap.hpp"

int main()
{
    ClapTrap clapTrap("ClapTrap");

    clapTrap.attack("Madara");
    clapTrap.takeDamage(10);
    clapTrap.beRepaired(5);
    clapTrap.attack("Naruto");
    clapTrap.beRepaired(400);
    clapTrap.takeDamage(350);
    clapTrap.attack("Sasuke");
    clapTrap.takeDamage(100);
    clapTrap.attack("Kakashi");
    clapTrap.takeDamage(100);
    clapTrap.beRepaired(100);
    clapTrap.attack("Itachi");
    clapTrap.takeDamage(100);
    clapTrap.attack("Rick");
    clapTrap.takeDamage(100);
    return 0;
}
