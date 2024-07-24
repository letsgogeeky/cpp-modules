#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <ctime>

class PmergeMe
{
private:
	PmergeMe();
	std::vector<std::vector<int> > _vec;
	std::deque<std::deque<int> > _deq;
	std::list<int> _data;
	std::list<int> _jacobs;
	int _length;
	unsigned long _start;
	unsigned long _end;
	unsigned long _elapsed;
	void _computeJacobs();
	// void _fillVectorPairs();
	void _sortVectorPairs(std::vector< std::vector<int> > &vec);
	bool _checkSorted(std::vector<int> &vec);
public:
	PmergeMe(std::list<int> &data);
	// PmergeMe(const PmergeMe &pmergeme);
	// PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();
	std::vector<int> sortWithVector();
	std::string getElapsedString() const;
	// std::deque<int> sortWithDeque(std::deque<int> data);
};
