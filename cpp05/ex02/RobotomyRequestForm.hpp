#include "AForm.hpp"
#include <iostream>

class AForm;

class RobotomyRequestForm : public AForm
{

private:
    std::string _target;

public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string name, const std::string target);
    RobotomyRequestForm(const RobotomyRequestForm &robotomyRequestForm);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &robotomyRequestForm);
    ~RobotomyRequestForm();

    void execute(const Bureaucrat &executor) const;
    std::string getTarget() const;
};