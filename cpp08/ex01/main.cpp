#include "Span.hpp"
#include <iostream>

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

	// testing with 50k
	std::cout << "Testing with 50k" << std::endl;
	test_optimized(50000);
	test_slow_as_hell(50000);

	/*
	// testing with 300k
	std::cout << "Testing with 300k" << std::endl;
	test_optimized(300000);
	test_slow_as_hell(300000);
	*/

	std::cout << "---------------------" << std::endl;
	std::cout << "Testing advanced addNumber" << std::endl;
	int arr[] = {1, 2, 3, 4, 5};
	Span sp = Span(5);
	sp.addNumber(arr, 5);
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}
