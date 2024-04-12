#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>

#include "interfaces/ICharacter.hpp"

class Character: public ICharacter
{
    private:
        std::string name;
        AMateria *materias[4];
    public:
        Character();
        Character(std::string name);
        Character(const Character &character);
        ~Character();
        Character &operator=(const Character &character);
        std::string const &getName() const;
        void equip(AMateria *materia);
        void unequip(int idx);
        void use(int idx, ICharacter &target);
};

#endif