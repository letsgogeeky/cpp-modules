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
	for (std::vector< std::vector<int> >::iterator it = _vec.begin(); it != _vec.end(); it++)
	{
		seq.push_back((*it).at(1));
		pend.push_back((*it).at(0));
	}
	seq.insert(seq.begin(), pend.at(0));
	for (int i = 0; i < pend.size(); i++)
	{
		
	}
	std::cout << "Strangler: " << strangler << std::endl;
	return _vec[0];
}