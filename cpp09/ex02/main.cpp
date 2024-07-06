#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <sstream>
#include <string>

bool isAllDigitOrSpace(char *input)
{
	for (int i = 0; input[i]; i++)
	{
		if (!isdigit(input[i]) && !isblank(input[i]))
			return false;
	}
	return true;
}
std::list<int> splitInput(char *input, char delim = ' ')
{
	std::string s(input);
	std::list<int> v;
	std::istringstream iss(s);
	std::string token;
	while (std::getline(iss, token, delim))
	{
		if (!token.empty())
			v.push_back(atoi(token.c_str()));
	}
	return v;
}

// std::list<int> loadList(std::vector<std::string> &v)
// {
// 	std::list<int> l;
// 	for (std::vector<std::string>::iterator it = v.begin(); it != v.end(); it++)
// 		l.push_back(atoi(it->c_str()));
// 	return l;
// }

// std::vector<int> loadVector(std::list<int> &v)
// {
// 	std::vector<int> vec;
// 	for (std::list<int>::iterator it = v.begin(); it != v.end(); it++)
// 		vec.push_back(it);
// 	return vec;
// }

// void runInList(std::vector<std::string> &v)
// {
// 	std::list<int> l = loadList(v);
// 	PmergeMe lstSort = PmergeMe();
	
// }

// void runInVector(std::vector<std::string> &v)
// {
// 	std::vector<int> vec = loadVector(v);
// 	PmergeMe vecSort = PmergeMe();
// }

int main(int argc, char **argv)
{
	std::string usage = "Usage: ./PmergeMe \"[list of integers separated by spaces, and between double quotes]\"";
	if (argc != 2)
	{
		std::cerr << usage << std::endl;
		return 1;
	}
	if (!isAllDigitOrSpace(argv[1]))
	{
		std::cerr << "Error: invalid input, please make sure it doesn't contain characters or hypothetical scenarios about the universe." << std::endl;
		std::cerr << usage << std::endl;
		return 1;
	}
	std::list<int> v = splitInput(argv[1]);

	PmergeMe sorter = PmergeMe(v);
	
	std::vector<int> result = sorter.sortWithVector();

	return 0;
}
