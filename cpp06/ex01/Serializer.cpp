#include "Serializer.hpp"

uintptr_t Serializer::serialize(const LinkedList *list)
{
    return reinterpret_cast<uintptr_t>(list);
}

LinkedList *Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<LinkedList *>(raw);
}

