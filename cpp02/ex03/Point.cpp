#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(const Fixed &x, const Fixed &y) : x(x), y(y)
{
}

Point::Point(const Point &point) : x(point.x), y(point.y)
{
}

Point::~Point()
{
}

Point &Point::operator=(const Point &point)
{
    (void)point;
    return *this;
}

Fixed Point::getX() const
{
    return x;
}

Fixed Point::getY() const
{
    return y;
}
