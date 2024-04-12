#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(const Ice &ice) : AMateria(ice)
{
}

Ice::~Ice()
{
}

Ice &Ice::operator=(const Ice &ice)
{
    if (this == &ice)
        return (*this);
    AMateria::operator=(ice);
    return (*this);
}

AMateria *Ice::clone() const
{
    return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
