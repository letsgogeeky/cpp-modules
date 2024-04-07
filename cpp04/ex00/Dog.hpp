#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>

#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog();
	Dog(const Dog &copy);
	~Dog();
	Dog &operator=(const Dog &assign);
	void makeSound() const;
};

#endif