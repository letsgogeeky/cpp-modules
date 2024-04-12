#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

void subjectTest()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	delete j;
	delete i;
	delete meta;
}
void withArrayOfAnimals()
{
	const int n = 10;
	Animal* animals[n];
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for (int i = 0; i < n; i++)
	{
		animals[i]->makeSound();
		delete animals[i];
	}
}

int main()
{
	std::cout << "!!!!!!!!!Subject test!!!!!!!!!!!!" << std::endl;
	subjectTest();
	std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
	std::cout << "!!!!!!!!!!!My test!!!!!!!!!!!!!!" << std::endl;
	withArrayOfAnimals();
	std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
	return 0;
}