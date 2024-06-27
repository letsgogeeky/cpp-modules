#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"


const std::string Intern::_formNames[3] = {
    "robotomy request",
    "shrubbery creation",
    "presidential pardon"
};

AForm *(*Intern::_formCreators[3])(const std::string, const std::string) = {
    &Intern::createRobotomyRequestForm,
    &Intern::createShrubberyCreationForm,
    &Intern::createPresidentialPardonForm
};

Intern::Intern()
{
}

Intern::Intern(const Intern &intern)
{
    *this = intern;
}

Intern &Intern::operator=(const Intern &intern)
{
    (void)intern;
    return (*this);
}

Intern::~Intern()
{
}

AForm* Intern::createRobotomyRequestForm(const std::string name, const std::string target)
{
    return (new RobotomyRequestForm(name, target));
}

AForm* Intern::createShrubberyCreationForm(const std::string name, const std::string target)
{
    srand(time(NULL));
    int level = rand() % 95 + 5;
    return (new ShrubberyCreationForm(name, target, level));
}

AForm* Intern::createPresidentialPardonForm(const std::string name, const std::string target)
{
    return (new PresidentialPardonForm(name, target));
}

const char* Intern::FormNotFoundException::what() const throw()
{
    return ("Form not found");
}

AForm *Intern::makeForm(const std::string name, const std::string target)
{
    for (int i = 0; i < 3; i++)
    {
        if (name == _formNames[i])
        {
            return (_formCreators[i](name, target));
        }
    }
    throw Intern::FormNotFoundException();
}
