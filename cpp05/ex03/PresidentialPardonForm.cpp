#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("default", 25, 5)
{
    _target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string name, const std::string target): AForm(name, 25, 5)
{
    _target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &presidentialPardonForm)
    : AForm(presidentialPardonForm)
{
    _target = presidentialPardonForm._target;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &presidentialPardonForm)
{
    _target = presidentialPardonForm._target;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

std::string PresidentialPardonForm::getTarget() const
{
    return _target;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    try
    {
        if (!AForm::canExecute(executor))
            return ;
        std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}