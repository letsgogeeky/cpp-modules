#include "Point.hpp"
#include <iostream>

bool bsp( Point const a, Point const b, Point const c, Point const point )
{
    Fixed const x1 = a.getX();
    Fixed const y1 = a.getY();
    Fixed const x2 = b.getX();
    Fixed const y2 = b.getY();
    Fixed const x3 = c.getX();
    Fixed const y3 = c.getY();
    Fixed const a1 = (point.getX() - x1) * (y2 - y1) - (x2 - x1) * (point.getY() - y1);
    std::cout << "a1: " << a1 << std::endl;
    Fixed const a2 = (point.getX() - x2) * (y3 - y2) - (x3 - x2) * (point.getY() - y2);
    std::cout << "a2: " << a2 << std::endl;
    Fixed const a3 = (point.getX() - x3) * (y1 - y3) - (x1 - x3) * (point.getY() - y3);
    std::cout << "a3: " << a3 << std::endl;
    return (a1 >= 0 && a2 >= 0 && a3 >= 0) || (a1 <= 0 && a2 <= 0 && a3 <= 0);
}
