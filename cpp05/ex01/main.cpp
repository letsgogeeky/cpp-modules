#include "Bureaucrat.hpp"
#include "Form.hpp"

void tryToSign(Bureaucrat &b, Form &f)
{
    try
    {
        f.beSigned(b);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

int main()
{
    Bureaucrat b1("b1", 13);
    Form f1("form1", 1, 1);
    Form f2("form2", 150, 150);
    Form f3("form3", 2, 2);
    Form f4("form4", 149, 149);

    std::cout << b1 << std::endl;
    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;
    std::cout << f3 << std::endl;
    std::cout << f4 << std::endl;

    tryToSign(b1, f1);
    tryToSign(b1, f2);
    tryToSign(b1, f3);
    tryToSign(b1, f4);

    try
    {
        b1.signForm(f1);
        b1.signForm(f2);
        b1.signForm(f3);
        b1.signForm(f4);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}