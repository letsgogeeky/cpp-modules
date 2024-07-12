#include <iostream>
#include "LinkedList.hpp"

class Serializer
{
private:
	Serializer();
	~Serializer();
public:
    static uintptr_t serialize(const LinkedList *list);
    static LinkedList *deserialize(uintptr_t raw);
};