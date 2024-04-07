#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &assign)
{
	if (this == &assign)
		return (*this);
	WrongAnimal::operator=(assign);
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "Super Wrong Meow Meow" << std::endl;
}
