#include "Factory.hpp"
#include <typeinfo>
#include <iostream>

void generate()
{
	Base *base = Factory::generate();
	std::cout << typeid(*base).hash_code() << " | Name: " << typeid(*base).name() << std::endl;
	Factory::identify(base);
	Factory::identify(*base);
	delete base;
}

int main()
{
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
		generate();
	return 0;
}