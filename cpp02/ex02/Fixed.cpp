#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    if (isShiftable(value))
        _value = value << _fractionalBits;
    else
        std::cout << "Value is not shiftable" << std::endl;
}

Fixed::Fixed(const float value)
{
    if (isShiftable(value))
        _value = static_cast<int>(roundf(value * (1 << _fractionalBits)));
    else
        std::cout << "Value is not shiftable" << std::endl;
    std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    _value = fixed._value;
    return *this;
}

Fixed Fixed::operator+(const Fixed& fixed) const
{
    Fixed result;

    result.setRawBits(_value + fixed._value);
    return result;
}

Fixed Fixed::operator-(const Fixed& fixed) const
{
    Fixed result;

    result.setRawBits(_value - fixed._value);
    return result;
}

Fixed Fixed::operator*(const Fixed& fixed) const
{
    Fixed result;

    result.setRawBits((_value * fixed._value) >> _fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed& fixed) const
{
    Fixed result;

    result.setRawBits((_value << _fractionalBits) / fixed._value);
    return result;
}

Fixed& Fixed::operator++()
{
    _value++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    operator++();
    return tmp;
}

Fixed& Fixed::operator--()
{
    _value--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    operator--();
    return tmp;
}

bool Fixed::operator>(const Fixed& fixed) const
{
    return _value > fixed._value;
}

bool Fixed::operator<(const Fixed& fixed) const
{
    return _value < fixed._value;
}

bool Fixed::operator>=(const Fixed& fixed) const
{
    return _value >= fixed._value;
}

bool Fixed::operator<=(const Fixed& fixed) const
{
    return _value <= fixed._value;
}

bool Fixed::operator==(const Fixed& fixed) const
{
    return _value == fixed._value;
}

bool Fixed::operator!=(const Fixed& fixed) const
{
    return _value != fixed._value;
}


int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _value;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    _value = raw;
}

float Fixed::toFloat(void) const
{
    return (static_cast<float>(_value) / static_cast<float>(1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
    return _value >> _fractionalBits;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return a < b ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return a < b ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return a > b ? a : b;
}


const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return a > b ? a : b;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}
