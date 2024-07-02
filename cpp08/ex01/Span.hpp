#include <iostream>

class Span
{
private:
	unsigned int _n;
	unsigned int _size;
	int* _array;

public:
	Span(unsigned int n);
	Span(const Span &other);
	~Span();
	Span &operator=(const Span &other);

	void addNumber(int number);
	int shortestSpan();
	int longestSpan();
	int shortestSpanSlowAsHell();
	int longestSpanSlowAsHell();
};