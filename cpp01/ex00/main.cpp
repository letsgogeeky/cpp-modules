#include "Zombie.hpp"

int main(void)
{
    zombie::Zombie* heap = zombie::newZombie("Zombie1LivesInHeap");
    heap->announce();
    delete heap;
    zombie::randomChump("Zombie2LivesInStack");
    return 0;
}