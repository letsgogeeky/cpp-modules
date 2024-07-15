#include "MutantStack.hpp"
#include <iostream>
#include <list>

template <typename T>
void test_with_container(T &container)
{
    typename T::iterator it = container.begin();
    typename T::iterator ite = container.end();

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
	std::cout << "Using for loop iterator" << std::endl;
	for (typename T::iterator it = container.begin(); it != container.end(); it++)
	{
		std::cout << *it << std::endl;
	}
}
MutantStack<int> get_mutant_stack()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    return mstack;
}

std::list<int> get_list()
{
    std::list<int> lst;

    lst.push_back(5);
    lst.push_back(17);
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    return lst;
}

void test_mutant_operations()
{
	MutantStack<int> mstack = get_mutant_stack();

	std::cout << "Popping: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Popping: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Popping: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Popping: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Popping: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Popping: " << mstack.top() << std::endl;
	mstack.pop();
	mstack.push(42);
	std::cout << "Pushed: " << mstack.top() << std::endl;
	mstack.push(2521);
	std::cout << "Pushed: " << mstack.top() << std::endl;
	mstack.push(400);
	std::cout << "Pushed: " << mstack.top() << std::endl;
	mstack.push(-4231);
	std::cout << "Pushed: " << mstack.top() << std::endl;
}


int main()
{
    MutantStack<int> mstack = get_mutant_stack();
    std::list<int> lst = get_list();

    std::cout << "MutantStack:" << std::endl;
    test_with_container(mstack);

    std::cout << "List:" << std::endl;
    test_with_container(lst);

	std::cout << "Testing MutantStack operations" << std::endl;
	test_mutant_operations();

    return 0;
}
