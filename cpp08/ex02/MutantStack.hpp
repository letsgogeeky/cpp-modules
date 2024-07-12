#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack() : std::stack<T>() {}
    MutantStack(const MutantStack &mutantStack) : std::stack<T>(mutantStack) {}
    MutantStack &operator=(const MutantStack &mutantStack)
    {
        std::stack<T>::operator=(mutantStack);
        return *this;
    }
    ~MutantStack() {}

    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin()
    {
        return std::stack<T>::c.begin();
    }

    iterator end()
    {
        return std::stack<T>::c.end();
    }

};