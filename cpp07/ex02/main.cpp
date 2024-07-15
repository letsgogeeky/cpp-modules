#include <iostream>
#include "Array.hpp"
#include <cstdlib>

#define MAX_VAL 750

void test_empty_array()
{
	Array<int> numbers = Array<int>();
	std::cout << "Array size: " << numbers.size() << std::endl;
	try
	{
		numbers[0] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
int main(int, char**)
{
	std::cout << "Test empty array" << std::endl;
	test_empty_array();
	std::cout << "Done!!" << std::endl;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand() % 5000;
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
	// Print array
	std::cout << "Array:: ->>>>>" << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		std::cout << numbers[i] << std::endl;
	}
	std::cout << "Done!!" << std::endl;
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}