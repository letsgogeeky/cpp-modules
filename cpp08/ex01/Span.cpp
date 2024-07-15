#include "Span.hpp"

Span::Span(unsigned int n) : _n(n), _size(0), _array(new int[n])
{
}

Span::Span(const Span &other) : _n(other._n), _size(other._size), _array(new int[other._n])
{
	for (unsigned int i = 0; i < _size; i++)
	{
		_array[i] = other._array[i];
	}
}

Span::~Span()
{
	delete[] _array;
}

Span &Span::operator=(const Span &other)
{
	if (this == &other)
		return *this;
	delete[] _array;
	_n = other._n;
	_size = other._size;
	_array = new int[other._n];
	for (unsigned int i = 0; i < _size; i++)
	{
		_array[i] = other._array[i];
	}
	return *this;
}

void Span::addNumber(int number)
{
	if (_size >= _n)
		throw std::exception();
	_array[_size] = number;
	_size++;
}

void Span::addNumber(int* numbers, unsigned int size)
{
	if (_size + size > _n)
		throw std::exception();
	for (unsigned int i = 0; i < size; i++)
	{
		_array[_size] = numbers[i];
		_size++;
	}
}

int Span::shortestSpan()
{
	if (_size <= 1)
		throw std::exception();
	std::sort(_array, _array + _size);
	int min = _array[1] - _array[0];
	for (unsigned int i = 1; i < _size; i++)
	{
		int diff = _array[i] - _array[i - 1];
		if (diff < min)
			min = diff;
	}
	return min;
}

int Span::longestSpan()
{
	if (_size <= 1)
		throw std::exception();
	std::sort(_array, _array + _size);
	return _array[_size - 1] - _array[0];
}

int Span::shortestSpanSlowAsHell()
{
	if (_size <= 1)
		throw std::exception();
	int min = std::numeric_limits<int>::max();
	for (unsigned int i = 0; i < _size; i++)
	{
		for (unsigned int j = i + 1; j < _size; j++)
		{
			int diff = std::abs(_array[i] - _array[j]);
			if (diff < min)
				min = diff;
		}
	}
	return min;
}

int Span::longestSpanSlowAsHell()
{
	if (_size <= 1)
		throw std::exception();
	int max = 0;
	for (unsigned int i = 0; i < _size; i++)
	{
		for (unsigned int j = i + 1; j < _size; j++)
		{
			int diff = std::abs(_array[i] - _array[j]);
			if (diff > max)
				max = diff;
		}
	}
	return max;
}
