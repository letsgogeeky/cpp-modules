#include "Zombie.hpp"
#include <string>

namespace zombie
{
Zombie* newZombie(std::string name)
{
    Zombie* zombie = new Zombie();
    zombie->setName(name);
    return zombie;
}
}
