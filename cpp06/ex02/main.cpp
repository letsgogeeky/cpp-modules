#include "Factory.hpp"
#include <iostream>

void generate()
{
	Base *base = Factory::generate();
	Factory::identify(base);
	Factory::identify(*base);
	delete base;
	std::cout << "----------------" << std::endl;
}

int main()
{
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
		generate();
	return 0;
}