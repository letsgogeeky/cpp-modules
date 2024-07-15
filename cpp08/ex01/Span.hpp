#include <iostream>
#include <algorithm>
#include <limits>

class Span
{
private:
	unsigned int _n;
	unsigned int _size;
	int* _array;

	Span();

public:
	Span(unsigned int n);
	Span(const Span &other);
	~Span();
	Span &operator=(const Span &other);

	void addNumber(int number);
	void addNumber(int* numbers, unsigned int size);
	int shortestSpan();
	int longestSpan();
	int shortestSpanSlowAsHell();
	int longestSpanSlowAsHell();
};
