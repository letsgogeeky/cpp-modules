#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

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

void createSignExecuteForm(Intern &i, Bureaucrat &b, std::string name, std::string target)
{
    AForm *f = NULL;
    try {
        f = i.makeForm(name, target);
        tryToSign(b, *f);
        tryToExecute(b, *f);
        delete f;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

int main()
{
    Bureaucrat b1("b1", 1);
    Intern i1;
    createSignExecuteForm(i1, b1, "random", "sooooup");
    createSignExecuteForm(i1, b1, "shrubbery creation", "giantTree");
    createSignExecuteForm(i1, b1, "robotomy request", "robotic");
    createSignExecuteForm(i1, b1, "presidential pardon", "Presidential");
    
    return (0);
}