#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() : name("default")
{
    for (int i = 0; i < 4; i++)
        materias[i] = NULL;
}

Character::Character(std::string name) : name(name)
{
    for (int i = 0; i < 4; i++)
        materias[i] = NULL;
}

Character::Character(const Character &character)
{
    *this = character;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (materias[i])
            delete materias[i];
    }
}

Character &Character::operator=(const Character &character)
{
    if (this == &character)
        return (*this);
    name = character.name;
    for (int i = 0; i < 4; i++)
    {
        if (materias[i])
            delete materias[i];
        materias[i] = character.materias[i]->clone();
    }
    return (*this);
}

std::string const &Character::getName() const
{
    return (name);
}

void Character::equip(AMateria *materia)
{
    for (int i = 0; i < 4; i++)
    {
        if (!materias[i])
        {
            materias[i] = materia;
            return;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4 || !materias[idx])
        return;
    materias[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx >= 4 || !materias[idx])
        return;
    materias[idx]->use(target);
}