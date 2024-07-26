#ifndef __PMERGEME_HPP
#define __PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <ctime>
#include <algorithm>

template <typename T, typename Container>
class PmergeMe
{
private:
	PmergeMe() {};
	Container paired;
	T seq;
	T pend;
	std::list<int> _data;
	std::list<int> _jacobs;
	int _length;
	unsigned long _start;
	unsigned long _end;
	unsigned long _elapsed;
	void _computeJacobs();
	void _fillPairs();
	void _adjustPairs();
	void _sortPairs(Container &data);
	bool _checkSorted(T &data);
public:
	PmergeMe(std::list<int> &data);
	PmergeMe(const PmergeMe &pmergeme);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();
	T sort();
	std::string getElapsedString() const;
	class StackOverflowException : public std::exception
	{
		virtual const char *what() const throw()
		{
			return "Stack overflow exception";
		}
	};
};

#include "PmergeMe.cpp"

#endif