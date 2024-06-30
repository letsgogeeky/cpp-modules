#include "Bureaucrat.hpp"

void initBureaucrat(const std::string name, int grade)
{
    try
    {
        Bureaucrat b(name, grade);
        std::cout << b << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

int main()
{
    Bureaucrat b1("b1", 1);
    Bureaucrat b2("b2", 150);
    // should raise exceptions
    initBureaucrat("b3", 151);
    initBureaucrat("b4", 0);

    Bureaucrat b5("b5", 2);
    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    std::cout << b5 << std::endl;

    initBureaucrat("b6", 162);
    initBureaucrat("b7", -1);

    try
    {
        Bureaucrat b8("b8", 3);
        b8.incrementGrade();
        std::cout << b8 << std::endl;
        b8.incrementGrade();
        std::cout << b8 << std::endl;
        b8.incrementGrade();
        std::cout << b8 << std::endl;
        b8.incrementGrade();
        std::cout << b8 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b9("b9", 148);
        b9.decrementGrade();
        std::cout << b9 << std::endl;
        b9.decrementGrade();
        std::cout << b9 << std::endl;
        b9.decrementGrade();
        std::cout << b9 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return (0);
}