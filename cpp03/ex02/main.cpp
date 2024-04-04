#include "FragTrap.hpp"

int main()
{
    FragTrap fragTrap("fragTrap");

    fragTrap.attack("Madara");
    fragTrap.takeDamage(10);
    fragTrap.beRepaired(5);
    fragTrap.attack("Naruto");
    fragTrap.beRepaired(400);
    fragTrap.takeDamage(350);
    fragTrap.attack("Sasuke");
    fragTrap.takeDamage(100);
    fragTrap.highFivesGuys();
    fragTrap.attack("Kakashi");
    fragTrap.takeDamage(100);
    return 0;
}

