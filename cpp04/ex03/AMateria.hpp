#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "interfaces/ICharacter.hpp"

class AMateria
{
    protected:
        std::string type;

    public:
        AMateria();
        AMateria(std::string const &type);
        AMateria(const AMateria &aMateria);
        virtual ~AMateria();
        AMateria &operator=(const AMateria &aMateria);
        std::string const &getType() const;
        virtual AMateria *clone() const = 0;
        virtual void use(ICharacter &target);
};

#endif