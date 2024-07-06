#include <iostream>
#include <vector>
#include <list>
#include <deque>

class PmergeMe
{
private:
	PmergeMe();
	std::vector<std::vector<int> > _vec;
	std::deque<std::deque<int> > _deq;
	std::list<int> _data;
	std::list<int> _jacobs;
	int _length;
	void _computeJacobs();
	// void _fillVectorPairs();
	// void _sortVectorPairs();
public:
	PmergeMe(std::list<int> &data);
	// PmergeMe(const PmergeMe &pmergeme);
	// PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();
	std::vector<int> sortWithVector();
	// std::deque<int> sortWithDeque(std::deque<int> data);
};
