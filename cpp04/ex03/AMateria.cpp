#include "AMateria.hpp"

AMateria::AMateria() : type("default")
{
}

AMateria::AMateria(const std::string &type) : type(type)
{
}

AMateria::AMateria(const AMateria &aMateria) : type(aMateria.type)
{
}

AMateria::~AMateria()
{
}

AMateria &AMateria::operator=(const AMateria &aMateria)
{
    if (this == &aMateria)
        return (*this);
    return (*this);
}

const std::string &AMateria::getType() const
{
    return (type);
}

void AMateria::use(ICharacter &target)
{
    std::cout << "* uses some materia on " << target.getName() << " *" << std::endl;
}
