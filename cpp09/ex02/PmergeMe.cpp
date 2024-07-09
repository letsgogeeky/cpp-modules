#include "PmergeMe.hpp"
#include <algorithm>
#include <iostream>

PmergeMe::PmergeMe(std::list<int> &data) 
{
	_data = data;
	_length = data.size();
	_computeJacobs();
}

PmergeMe::~PmergeMe() {}

void PmergeMe::_computeJacobs()
{
	int lastJacobs = -1;
	for (int i = 3; lastJacobs <= _length - 1; i++)
	{
		lastJacobs = (pow(2, i) - pow(-1, i)) / 3;
		_jacobs.push_back(lastJacobs);
	}
	for (std::list<int>::iterator it = _jacobs.begin(); it != _jacobs.end(); it++)
		std::cout << "This Jacob is huge: " << *it << std::endl;
}

void PmergeMe::_sortVectorPairs(std::vector< std::vector<int> > &vec)
{
	if (vec.size() == 1)
		return;
	
	size_t mid = vec.size() / 2;
	std::vector< std::vector<int> > left(vec.begin(), vec.begin() + mid);
	std::vector< std::vector<int> > right(vec.begin() + mid, vec.end());
	_sortVectorPairs(left);
	_sortVectorPairs(right);
	
	std::merge(left.begin(), left.end(), right.begin(), right.end(), vec.begin());
}

std::vector<int> PmergeMe::sortWithVector()
{
	int strangler = -1;
	std::vector<int> seq;
	std::vector<int> pend;
	if (_length % 2 != 0)
	{
		strangler = _data.back();
		_data.pop_back();
	}
	// convert data to vector;
	for (std::list<int>::iterator it = _data.begin(); it != _data.end(); it++)
	{
		std::vector<int> pair;
		pair.push_back(*it);
		it++;
		pair.push_back(*it);
		_vec.push_back(pair);
	}
	int idx = 0;
	for (std::vector< std::vector<int> >::iterator it = _vec.begin(); it != _vec.end(); it++)
	{
		std::cout << "Pair starting idx: " << idx << std::endl;
		std::cout << "Before sorting pair: [" << (*it).at(0) << ", " << (*it).at(1) << "]" << std::endl;
		// sort pairs asc
		if ((*it).at(0) > (*it).at(1))
		{
			int tmp = (*it).at(0);
			(*it)[0] = (*it).at(1);
			(*it)[1] = tmp;
		}
		std::cout << "After sorting asc pair: [" << (*it).at(0) << ", " << (*it).at(1) << "]" << std::endl;

		// sort pairs desc >> REMEMBER REMEMBER THE 5TH OF NEVEMBER!! TO REMOVE IT.
		if ((*it).at(0) < (*it).at(1))
		{
			int tmp = (*it).at(0);
			(*it)[0] = (*it).at(1);
			(*it)[1] = tmp;
		}
		std::cout << "After sorting desc pair: [" << (*it).at(0) << ", " << (*it).at(1) << "]" << std::endl;
	}
	_sortVectorPairs(_vec);
	for (std::vector< std::vector<int> >::iterator it = _vec.begin(); it != _vec.end(); it++)
	{
		seq.push_back((*it).at(0));
		pend.push_back((*it).at(1));
	}
	if (strangler != -1)
		pend.push_back(strangler);
	for (std::vector<int>::iterator it = seq.begin(); it != seq.end(); it++)
		std::cout << "Seq: " << *it << std::endl;

	for (std::vector<int>::iterator it = pend.begin(); it != pend.end(); it++)
		std::cout << "Pend: " << *it << std::endl;

	// seq.insert(seq.begin(), pend.at(0));
	// pend.erase(pend.begin());
	int prevJacobs = -1;
	bool jacobPassedUpperBound = false;
	int skip = 1;
	for (std::list<int>::iterator it = _jacobs.begin(); it != _jacobs.end(); it++)
	{
		int idx = *it;
		if (idx > static_cast<int>(pend.size() - 1))
		{
			if (jacobPassedUpperBound)
				break;
			jacobPassedUpperBound = true;
			idx = pend.size() - 1;
		}
		std::cout << "Jacob idx: " << idx << std::endl;
		while (prevJacobs < idx)
		{
			int item = pend.at(idx);
			std::vector<int>::iterator it = std::lower_bound(seq.begin(), seq.begin() + idx + skip, item);
			seq.insert(it, item);
			skip++;
			idx--;
		}
		prevJacobs = *it;
	}

	for (std::vector<int>::iterator it = seq.begin(); it != seq.end(); it++)
		std::cout << "Seq: " << *it << std::endl;

	std::cout << "Sorted: " << _checkSorted(seq) << std::endl;
	return _vec[0];
}

bool PmergeMe::_checkSorted(std::vector<int> &vec)
{
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end() - 1; it++)
	{
		if (*it > *(it + 1))
			return false;
	}
	return true;
}