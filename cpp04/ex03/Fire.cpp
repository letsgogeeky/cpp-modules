#include "Fire.hpp"

Fire::Fire() : AMateria("fire")
{
}

Fire::Fire(const Fire &copy) : AMateria(copy)
{
}

Fire::~Fire()
{
}

Fire &Fire::operator=(const Fire &assign)
{
	if (this == &assign)
		return (*this);
	AMateria::operator=(assign);
	return (*this);
}

AMateria *Fire::clone() const
{
	return (new Fire(*this));
}

void Fire::use(ICharacter &target)
{
	std::cout << "* shoots a fireball at " << target.getName() << " *" << std::endl;
}
