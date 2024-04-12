#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
	std::string type;

public:
	Animal();
	Animal(std::string type);
	Animal(const Animal &copy);
	virtual ~Animal();
	Animal &operator=(const Animal &assign);
	std::string getType() const;
	virtual void makeSound() const;
};

#endif