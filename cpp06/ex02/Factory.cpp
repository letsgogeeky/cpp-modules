#include "Factory.hpp"

Base *Factory::generate(void)
{
	int i = rand() % 3;
	if (i == 0)
		return new A;
	else if (i == 1)
		return new B;
	else
		return new C;
}

void Factory::identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "By Pointer: A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "By Pointer: B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "By PointeR: C" << std::endl;
}

void Factory::identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "By Reference: A" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Conversion to type A failed: " << e.what() << std::endl;
	}
	try
	{
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "By Reference: B" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Conversion to type B failed: " << e.what() << std::endl;
	}
	try
	{
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "By Reference: C" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Conversion to type C failed: " << e.what() << std::endl;
	}
}