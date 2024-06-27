#include <iostream>
#include <string>
#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
private:
    std::string _target;

public:
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string name, const std::string target);
    PresidentialPardonForm(const PresidentialPardonForm &presidentialPardonForm);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &presidentialPardonForm);
    ~PresidentialPardonForm();

    void execute(const Bureaucrat &executor) const;
    std::string getTarget() const;
};