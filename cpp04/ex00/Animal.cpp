#include "Animal.hpp"

Animal::Animal() : type("Animal") {}

Animal::Animal(std::string type) : type(type) {}

Animal::Animal(const Animal &copy) : type(copy.type) {}

Animal::~Animal() {}

Animal &Animal::operator=(const Animal &assign)
{
	if (this == &assign)
		return (*this);
	type = assign.type;
	return (*this);
}

std::string Animal::getType() const
{
	return (type);
}

void Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}
