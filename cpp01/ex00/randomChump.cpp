#include "Zombie.hpp"
#include <string>
namespace zombie
{
void randomChump(std::string name)
{
    Zombie zombie;
    zombie.setName(name);
    zombie.announce();
}
}
