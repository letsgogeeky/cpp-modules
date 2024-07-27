#include "PmergeMe.hpp"

template <typename T, typename Container>
PmergeMe<T, Container>::PmergeMe(std::list<int> &data)
{
	_data = data;
	_length = data.size();
	_computeJacobs();
}

template <typename T, typename Container>
PmergeMe<T, Container>::~PmergeMe() {
	paired.clear();
	_data.clear();
	_jacobs.clear();
}

template <typename T, typename Container>
void PmergeMe<T, Container>::_computeJacobs()
{
	int lastJacobs = -1;
	for (int i = 3; lastJacobs <= _length - 1; i++)
	{
		lastJacobs = (pow(2, i) - pow(-1, i)) / 3;
		_jacobs.push_back(lastJacobs);
	}
}
template <typename T, typename Container>
void PmergeMe<T, Container>::_sortPairs(Container &data)
{
	if (data.size() == 1)
		return;
	
	size_t mid = data.size() / 2;
	Container left(data.begin(), data.begin() + mid);
	Container right(data.begin() + mid, data.end());
	_sortPairs(left);
	_sortPairs(right);
	
	std::merge(left.begin(), left.end(), right.begin(), right.end(), data.begin());
}
template <typename T, typename Container>
void PmergeMe<T, Container>::_fillPairs()
{
	for (std::list<int>::iterator it = _data.begin(); it != _data.end(); it++)
	{
		T pair;
		pair.push_back(*it);
		it++;
		pair.push_back(*it);
		paired.push_back(pair);
	}
}

template <typename T, typename Container>
void PmergeMe<T, Container>::_adjustPairs()
{
	for (typename Container::iterator it = paired.begin(); it != paired.end(); it++)
	{
		if ((*it).at(0) < (*it).at(1))
		{
			int tmp = (*it).at(0);
			(*it)[0] = (*it).at(1);
			(*it)[1] = tmp;
		}
	}
}

template <typename T, typename Container>
T PmergeMe<T, Container>::sort()
{
	int strangler = -1;

	_start = clock();
	if (_length % 2 != 0)
	{
		strangler = _data.back();
		_data.pop_back();
	}
	_fillPairs();
	_adjustPairs();
	try {
		_sortPairs(paired);
	} catch (std::exception &e) {
		throw PmergeMe::StackOverflowException();
	}
	for (typename Container::iterator it = paired.begin(); it != paired.end(); it++)
	{
		seq.push_back((*it).at(0));
		pend.push_back((*it).at(1));
	}
	if (strangler != -1)
		pend.push_back(strangler);
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
		while (prevJacobs < idx)
		{
			int item = pend.at(idx);
			typename T::iterator it = std::lower_bound(seq.begin(), seq.begin() + idx + skip, item);
			// IMPORTANT: item was a strangler and it happens to be the largest element in the sequence
			if (it == seq.begin() + idx + skip)
				seq.push_back(item);
			else
				seq.insert(it, item);
			skip++;
			idx--;
		}
		prevJacobs = *it;
	}
	if (!_checkSorted(seq))
		throw PmergeMe::StackOverflowException();
	_end = clock();
	_elapsed = (static_cast<double>(_end - _start) / CLOCKS_PER_SEC) * 1000000;
	return seq;
}

template <typename T, typename Container>
bool PmergeMe<T, Container>::_checkSorted(T &vec)
{
	for (typename T::iterator it = vec.begin(); it != vec.end() - 1; it++)
	{
		if (*it > *(it + 1))
			return false;
	}
	return true;
}

template <typename T, typename Container>
std::string PmergeMe<T, Container>::getElapsedString() const {
	std::string elapsed = std::to_string(_elapsed);
	elapsed += " us";
	return elapsed;
}

template <typename T, typename Container>
PmergeMe<T, Container>::PmergeMe(const PmergeMe &pmergeme)
{
	_data = pmergeme._data;
	_jacobs = pmergeme._jacobs;
	_length = pmergeme._length;
	_start = pmergeme._start;
	_end = pmergeme._end;
	_elapsed = pmergeme._elapsed;
	seq = pmergeme.seq;
	pend = pmergeme.pend;
	paired = pmergeme.paired;
}

template <typename T, typename Container>
PmergeMe<T, Container> &PmergeMe<T, Container>::operator=(const PmergeMe &other)
{
	if (this == &other)
		return *this;
	_data = other._data;
	_jacobs = other._jacobs;
	_length = other._length;
	_start = other._start;
	_end = other._end;
	_elapsed = other._elapsed;
	seq = other.seq;
	pend = other.pend;
	paired = other.paired;
	return *this;
}
