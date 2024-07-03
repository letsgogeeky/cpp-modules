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


int main()
{
    MutantStack<int> mstack = get_mutant_stack();
    std::list<int> lst = get_list();

    std::cout << "MutantStack:" << std::endl;
    test_with_container(mstack);

    std::cout << "List:" << std::endl;
    test_with_container(lst);

    return 0;
}