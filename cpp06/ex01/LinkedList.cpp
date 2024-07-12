#include "LinkedList.hpp"
#include <iostream>

LinkedList::LinkedList() {}
LinkedList::LinkedList(int data) : data(data), next(NULL), prev(NULL)
{
}

LinkedList::LinkedList(const LinkedList &linkedList)
{
    *this = linkedList;
}

LinkedList &LinkedList::operator=(const LinkedList &linkedList)
{
    data = linkedList.data;
    next = linkedList.next;
    return *this;
}

LinkedList::~LinkedList()
{
}
