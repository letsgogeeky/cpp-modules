#ifndef AbstractAnimal_HPP
#define AbstractAnimal_HPP

#include <iostream>

class AbstractAnimal
{
protected:
	std::string type;

public:
	AbstractAnimal();
	AbstractAnimal(std::string type);
	AbstractAnimal(const AbstractAnimal &copy);
	virtual ~AbstractAnimal();
	AbstractAnimal &operator=(const AbstractAnimal &assign);
	std::string getType() const;
	virtual void makeSound() = 0;
};

#endif