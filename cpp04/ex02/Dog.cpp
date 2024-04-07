#include "Dog.hpp"

Dog::Dog() : AbstractAnimal("Dog")
{
	std::cout << "Dog constructor called" << std::endl;
	brain = new Brain();
}

Dog::Dog(const Dog &copy) : AbstractAnimal(copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

Dog &Dog::operator=(const Dog &assign)
{
	if (this == &assign)
		return (*this);
	AbstractAnimal::operator=(assign);
	return (*this);
}

void Dog::makeSound()
{
	std::cout << "Woof Woof" << std::endl;
}