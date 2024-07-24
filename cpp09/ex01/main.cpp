#include <iostream>
#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Number of arguments is: " << argc << std::endl;
		std::cerr << "Usage: ./RPN \"EXPRESSION HERE\"" << std::endl;
		return 1;
	}
	try
	{
		RPN rpn = RPN(argv[1]);
		std::cout << rpn.compute(argv[1]) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
