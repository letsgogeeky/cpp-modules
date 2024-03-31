#pragma once
#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>
namespace zombie
{
class Zombie
{
    private:
        std::string name;
    
    public:
        Zombie();
        ~Zombie();
        void announce(void);
        void setName(std::string name);
};
Zombie* newZombie(std::string name);
void randomChump(std::string name);
}

#endif