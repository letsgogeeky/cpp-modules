#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

void subjectTest()
{
	const Animal* a = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << a->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	a->makeSound();
	delete j;
	delete i;
	delete a;
}

int main()
{
	std::cout << "!!!!!!!!!Subject test!!!!!!!!!!!!" << std::endl;
	subjectTest();
	std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
	WrongAnimal *wrongAnimal = new WrongCat();
	std::cout << wrongAnimal->getType() << " " << std::endl;
	wrongAnimal->makeSound();
	delete wrongAnimal;
	// Instantiations without pointers
	Cat cat = Cat();
	std::cout << cat.getType() << " " << std::endl;
	cat.makeSound();
	Dog dog = Dog();
	std::cout << dog.getType() << " " << std::endl;
	dog.makeSound();
	return 0;
}