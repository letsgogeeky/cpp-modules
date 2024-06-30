#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void tryToSign(Bureaucrat &b, AForm &f)
{
    try
    {
        f.beSigned(b);
    }
    catch (std::exception &e)
    {
        std::cerr << b.getName() << " " << e.what() << " to sign!" << std::endl;
    }
}

void tryToExecute(Bureaucrat &b, AForm &f)
{
    try
    {
        b.executeAForm(f);
    }
    catch (std::exception &e)
    {
        std::cerr << b.getName() << " " << e.what() << " to execute!"  << std::endl;
    }
}

int main()
{
    Bureaucrat b1("b1", 50);
    Bureaucrat b2("b2", 1);
    ShrubberyCreationForm f1("form1", "sooooup"); // Static tree
    ShrubberyCreationForm f2("form2", "giantTree", 100); // Dynamic tree
    RobotomyRequestForm f3("form3", "robotic");
    Bureaucrat b3("b3", 14);
    PresidentialPardonForm f4("f4", "Presidential");
    tryToSign(b3, f4);
    tryToExecute(b3, f4);
    tryToExecute(b2, f4);
    tryToSign(b1, f1);
    tryToSign(b1, f2);
    tryToSign(b2, f1);
    tryToSign(b2, f2);
    tryToSign(b1, f3);
    tryToExecute(b1, f1);
    tryToExecute(b1, f2);
    tryToExecute(b2, f1);
    tryToExecute(b2, f2);
    tryToExecute(b1, f3);
    tryToExecute(b2, f3);
    return (0);
}