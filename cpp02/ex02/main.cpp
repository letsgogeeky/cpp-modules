#include "Fixed.hpp"
#include <iostream>

void subjectTest()
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
}

void print_if_shiftable(Fixed &f)
{
    if (f.isShiftable(f.getRawBits()))
        std::cout << f << " is shiftable and here is the int version anyways: " << f.toInt() << std::endl;
    else
        std::cout << f << " is not shiftable" << " use int: " << f.toInt() << std::endl;
}

void test_all_operators(Fixed &a, Fixed &b)
{
    std::cout << "a: " << a << " b: " << b << std::endl;
    std::cout << "a + b: " << a + b << std::endl;
    std::cout << "a - b: " << a - b << std::endl;
    std::cout << "a * b: " << a * b << std::endl;
    std::cout << "a / b: " << a / b << std::endl;
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a >= b: " << (a >= b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;
}

void test_min_max(Fixed &a, Fixed &b)
{
    std::cout << "a: " << a << " b: " << b << std::endl;
    std::cout << "min(a, b): " << Fixed::min(a, b) << std::endl;
    std::cout << "max(a, b): " << Fixed::max(a, b) << std::endl;
}

void test_increment_decrement(Fixed &a)
{
    std::cout << "a: " << a << std::endl;
    std::cout << "++a: " << ++a << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "a++: " << a++ << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "--a: " << --a << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "a--: " << a-- << std::endl;
    std::cout << "a: " << a << std::endl;
}

void interactive_boom()
{
    Fixed f;
    while (1)
    {
        std::string input;
        float number;
        if (std::cin.eof())
            break;
        
        std::cout << "Enter a number: ";
        std::cin >> input;
        if (input == "exit")
            break;
        try {
            number = std::stof(input);
        } catch (std::exception &e) {
            std::cout << "Invalid input" << std::endl;
            continue;
        }
        f = Fixed(number);
        test_increment_decrement(f);
    }
}

int main( void )
{
    std::cout << "======Subject test======" << std::endl;
    subjectTest();
    std::cout << "======My test===========" << std::endl;
    Fixed a;
    Fixed b(1000);
    Fixed c(13234.2134f);
    a.setRawBits(1010);

    std::cout << "======Test min max======" << std::endl;
    test_min_max(a, b);
    test_min_max(a, c);
    test_min_max(b, c);

    std::cout << "======Test all operators======" << std::endl;
    std::cout << "Test a and b" << std::endl;
    test_all_operators(a, b);
    std::cout << "Test a and c" << std::endl;
    test_all_operators(a, c);
    std::cout << "Test b and c" << std::endl;
    test_all_operators(b, c);
    std::cout << "======Interactive test======" << std::endl;
    interactive_boom();
    return 0;
}
