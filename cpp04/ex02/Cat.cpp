#include "Cat.hpp"

Cat::Cat() : AbstractAnimal("Cat")
{
	std::cout << "Cat constructor called" << std::endl;
	brain = new Brain();
}

Cat::Cat(const Cat &copy) : AbstractAnimal(copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

Cat &Cat::operator=(const Cat &assign)
{
	if (this == &assign)
		return (*this);
	AbstractAnimal::operator=(assign);
	return (*this);
}

void Cat::makeSound()
{
	std::cout << "Meow Meow" << std::endl;
}
