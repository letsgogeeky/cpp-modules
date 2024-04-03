#include "Point.hpp"
#include <iostream>


int main( void )
{
    Point const a(Fixed(0), Fixed(0));
    Point const b(Fixed(0), Fixed(2));
    Point const c(Fixed(2), Fixed(4));

    // should be inside
    Point const point(Fixed(0.2f), Fixed(0.5f));

    // should be outside
    Point const point(Fixed(0.5f), Fixed(0.5f));
    std::cout << bsp(a, b, c, point) << std::endl;
    return 0;
}
