#include "LinkedList.hpp"
#include "Serializer.hpp"

int main()
{
    LinkedList *list = new LinkedList(42);
    std::cout << "Original Pointer: " << list << std::endl;
    std::cout << "Head Data : " << list->data << std::endl;
    uintptr_t raw = Serializer::serialize(list);
    std::cout << "Serialized Pointer: " << raw << std::endl;
    LinkedList *list2 = Serializer::deserialize(raw);
    std::cout << "Deserialized Pointer: " << list2 << std::endl;
    std::cout << "Head Data : " << list2->data << std::endl;
    delete list;
    return 0;
}