#include "easyfind.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>

void test_with_list()
{
	std::list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);

	// My easyfind
	std::list<int>::iterator it = easyfind(l, 3);
	if (it != l.end())
		std::cout << "Found: " << *it << std::endl;
	else
		std::cout << "Not found" << std::endl;
	
	// std::find
	std::list<int>::iterator it2 = std::find(l.begin(), l.end(), 3);
	if (it2 != l.end())
		std::cout << "Found: " << *it2 << std::endl;
	else
		std::cout << "Not found" << std::endl;

	// My easyfind
	std::list<int>::iterator it3 = easyfind(l, 7);
	if (it3 != l.end())
		std::cout << "Found: " << *it3 << std::endl;
	else
		std::cout << "Not found" << std::endl;
	
	// std::find
	std::list<int>::iterator it4 = std::find(l.begin(), l.end(), 7);
	if (it4 != l.end())
		std::cout << "Found: " << *it4 << std::endl;
	else
		std::cout << "Not found" << std::endl;

}

void test_with_vectors()
{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	// My easyfind
	std::cout << "easyfind exists" << std::endl;
	std::vector<int>::iterator it = easyfind(v, 3);
	if (it != v.end())
		std::cout << "Found: " << *it << std::endl;
	else
		std::cout << "Not found" << std::endl;
	
	// std::find
	std::cout << "std::find exists" << std::endl;
	std::vector<int>::iterator it2 = std::find(v.begin(), v.end(), 3);
	if (it2 != v.end())
		std::cout << "Found: " << *it2 << std::endl;
	else
		std::cout << "Not found" << std::endl;

	// My easyfind
	std::cout << "easyfind not exists" << std::endl;
	std::vector<int>::iterator it3 = easyfind(v, 7);
	if (it3 != v.end())
		std::cout << "Found: " << *it3 << std::endl;
	else
		std::cout << "Not found" << std::endl;
	
	// std::find
	std::cout << "std::find not exists" << std::endl;
	std::vector<int>::iterator it4 = std::find(v.begin(), v.end(), 7);
	if (it4 != v.end())
		std::cout << "Found: " << *it4 << std::endl;
	else
		std::cout << "Not found" << std::endl;

}

int main()
{
	// Test with vectors
	std::cout << "Test with vectors" << std::endl;
	test_with_vectors();
	// Test with list
	std::cout << "Test with list" << std::endl;
	test_with_list();
	return 0;
}