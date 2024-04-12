#include "Cat.hpp"
#include "Dog.hpp"
#include "AbstractAnimal.hpp"

#include <iostream>
#include <string>

void withArrayOfAbstractAnimals()
{
	const int n = 10;
	AbstractAnimal* AbstractAnimals[n];
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			AbstractAnimals[i] = new Dog();
		else
			AbstractAnimals[i] = new Cat();
	}
	for (int i = 0; i < n; i++)
	{
		std::cout << "AbstractAnimals[" << i << "]: ";
		AbstractAnimals[i]->makeSound();
		delete AbstractAnimals[i];
	}
}

int main()
{
	std::cout << "!!!!!!!!!!!My test!!!!!!!!!!!!!!" << std::endl;
	withArrayOfAbstractAnimals();
	std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
	return 0;
}