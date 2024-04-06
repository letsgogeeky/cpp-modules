#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

#include <limits>
#include <iostream>
#include <cmath>

class Fixed
{
private:
    int _value;
    static const int _fractionalBits = 8;

public:
    Fixed();
    Fixed(const Fixed& fixed);
    Fixed(const int value);
    Fixed(const float value);
    ~Fixed();
    Fixed& operator=(const Fixed& fixed);
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;

    bool isShiftable(int value);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif