#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>

#include "AbstractAnimal.hpp"
#include "Brain.hpp"

class Dog : public AbstractAnimal
{
private:
	Brain *brain;
	
public:
	Dog();
	Dog(const Dog &copy);
	~Dog();
	Dog &operator=(const Dog &assign);
	void makeSound();
};

#endif