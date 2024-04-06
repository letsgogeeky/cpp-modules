#include "Point.hpp"
#include <iostream>


int main( void )
{
    Point const a(Fixed(0), Fixed(0));
    Point const b(Fixed(0), Fixed(2));
    Point const c(Fixed(2), Fixed(4));

    // should be inside
    Point const inside(Fixed(0.2f), Fixed(0.5f));

    // should be outside
    Point const vertex(Fixed(0), Fixed(0));

	// should be outside
	Point const edge(Fixed(0), Fixed(1));
    std::cout << bsp(a, b, c, inside) << std::endl;
	std::cout << bsp(a, b, c, vertex) << std::endl;
	std::cout << bsp(a, b, c, edge) << std::endl;
    return 0;
}
