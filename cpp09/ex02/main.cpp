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

bool isAllPositive(std::list<int> &v)
{
	for (std::list<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		if (*it < 0)
			return false;
	}
	return true;
}

bool checkSorted(std::list<int> &v)
{
	std::list<int>::iterator it = v.begin();
	int prev = *it;
	it++;
	while (it != v.end())
	{
		if (*it < prev)
			return false;
		prev = *it;
		it++;
	}
	return true;
}

bool hasDuplicates(std::list<int> &v)
{
	std::list<int> sorted(v);
	sorted.sort();
	std::list<int>::iterator it = sorted.begin();
	int prev = *it;
	it++;
	while (it != sorted.end())
	{
		if (*it == prev)
			return true;
		prev = *it;
		it++;
	}
	return false;
}

template <typename T1, typename T2>
bool areEqual(T1 &v1, T2 &v2)
{
	if (v1.size() != v2.size())
		return false;
	for (size_t i = 0; i < v1.size(); i++)
	{
		if (v1[i] != v2[i])
			return false;
	}
	return true;
}

template <typename T>
void cleanup(T &v)
{
	while (!v.empty())
		v.pop_back();
}

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
	if (!isAllPositive(v))
	{
		std::cerr << "Error: invalid input, please make sure all numbers are positive." << std::endl;
		std::cerr << usage << std::endl;
		return 1;
	}
	if (v.size() < 2)
	{
		std::cerr << "Error: invalid input, please make sure there are at least two numbers." << std::endl;
		return 1;
	}
	if (checkSorted(v)) {
		std::cerr << "Error: input is already sorted!" << std::endl;
		return 1;
	}
	if (hasDuplicates(v)) {
		std::cerr << "Error: input contains duplicates!" << std::endl;
		return 1;
	}
	std::cout << "Input: ";
	for (std::list<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	PmergeMe<std::vector<int>, std::vector< std::vector<int> > > sorter_v(v);
	std::vector<int> vec_result = sorter_v.sort();
	PmergeMe<std::deque<int>, std::deque< std::deque<int> > > sorter_d(v);
	std::deque<int> deq_result = sorter_d.sort();
	std::cout << "Output: ";
	for (std::vector<int>::iterator it = vec_result.begin(); it != vec_result.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	// Uncomment to verify that the results are the same
	// if (areEqual(vec_result, deq_result))
	// 	std::cout << "Results are the same." << std::endl;
	// else
	// 	std::cout << "Results are different." << std::endl;
	std::cout << "Vector Elapsed time to sort " << v.size() << " is: " << sorter_v.getElapsedString() << std::endl;
	std::cout << "Deque Elapsed time: to sort " << v.size() << " is: " << sorter_d.getElapsedString() << std::endl;
	cleanup(vec_result);
	cleanup(deq_result);
	return 0;
}
