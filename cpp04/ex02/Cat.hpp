#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "AbstractAnimal.hpp"
#include "Brain.hpp"

class Cat : public AbstractAnimal
{
private:
	Brain *brain;

public:
	Cat();
	Cat(const Cat &copy);
	~Cat();
	Cat &operator=(const Cat &assign);
	void makeSound();
};

#endif