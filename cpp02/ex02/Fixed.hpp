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
    Fixed operator+(const Fixed& fixed) const;
    Fixed operator-(const Fixed& fixed) const;
    Fixed operator*(const Fixed& fixed) const;
    Fixed operator/(const Fixed& fixed) const;
    Fixed& operator++();
    Fixed operator++(int);
    Fixed& operator--();
    Fixed operator--(int);


    bool operator>(const Fixed& fixed) const;
    bool operator<(const Fixed& fixed) const;
    bool operator>=(const Fixed& fixed) const;
    bool operator<=(const Fixed& fixed) const;
    bool operator==(const Fixed& fixed) const;
    bool operator!=(const Fixed& fixed) const;

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;

    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);

    static bool isShiftable(int value)
    {
        return (value <= static_cast<int>(std::numeric_limits<int>::max() >> _fractionalBits) && 
                value >= static_cast<int>(std::numeric_limits<int>::min() >> _fractionalBits));
    }
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif