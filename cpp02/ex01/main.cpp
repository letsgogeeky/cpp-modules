#include "Fixed.hpp"
#include <iostream>

void subjectTest()
{
    Fixed a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );
    a = Fixed( 1234.4321f );
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
}

void print_if_shiftable(Fixed &f)
{
    if (f.isShiftable(f.getRawBits()))
        std::cout << f << " is shiftable and here is the int version anyways: " << f.toInt() << std::endl;
    else
        std::cout << f << " is not shiftable" << " use int: " << f.toInt() << std::endl;
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
        std::cout << "You entered: " << f << std::endl;
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
    Fixed d(0b101010011111);
    Fixed e(255.23512512f);
    print_if_shiftable(a);
    print_if_shiftable(b);
    print_if_shiftable(c);
    print_if_shiftable(d);
    print_if_shiftable(e);

    std::cout << "======Interactive test======" << std::endl;
    interactive_boom();
    return 0;
}
