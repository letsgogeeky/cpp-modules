#ifndef LinkedList_HPP
#define LinkedList_HPP

class LinkedList
{
public:
    int data;
    LinkedList *next;
    LinkedList *prev;
    LinkedList();
    LinkedList(int data);
    LinkedList(const LinkedList &linkedList);
    LinkedList &operator=(const LinkedList &linkedList);
    ~LinkedList();

};

#endif