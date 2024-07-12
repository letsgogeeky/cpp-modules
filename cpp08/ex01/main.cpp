#include "Span.hpp"
#include <iostream>
#include <random>

void test_optimized(unsigned int n)
{
	Span sp = Span(n);
	for (unsigned int i = 0; i < n; i++)
	{
		sp.addNumber(rand());
	}
	time_t start = time(NULL);
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	time_t end = time(NULL);
	std::cout << "Optimized Time taken: " << end - start << " seconds" << std::endl;
}

void test_slow_as_hell(unsigned int n)
{
	Span sp = Span(n);
	for (unsigned int i = 0; i < n; i++)
	{
		sp.addNumber(rand());
	}
	time_t start = time(NULL);
	std::cout << "Shortest span: " << sp.shortestSpanSlowAsHell() << std::endl;
	std::cout << "Longest span: " << sp.longestSpanSlowAsHell() << std::endl;
	time_t end = time(NULL);
	std::cout << "Slow as hell Time taken: " << end - start << " seconds" << std::endl;
}

int main()
{
	// Time it and see how long it takes to run
	srand(time(NULL));
	// testing with 10k
	std::cout << "Testing with 10k" << std::endl;
	test_optimized(10000);
	test_slow_as_hell(10000);

	// testing with 100k
	std::cout << "Testing with 100k" << std::endl;
	test_optimized(100000);
	test_slow_as_hell(100000);

	// testing with 1m
	std::cout << "Testing with 1m" << std::endl;
	test_optimized(1000000);
	test_slow_as_hell(1000000);
	
}