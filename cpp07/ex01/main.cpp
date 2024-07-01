#include <iostream>
#include "iter.hpp"

int main()
{
	int arr[] = {4, 5, 6, 7, 8, 9};
	iter(arr, 6, print);
	iter(arr, 6, addOne);
	std::cout << "After adding one to each element:\n";
	iter(arr, 6, print);
}