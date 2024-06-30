#include "RobotomyRequestForm.hpp"
#include <random>
#include <cstdlib>
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("default", 72, 45), _target("defaultTarget")
{
    srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const std::string name, const std::string target)
    : AForm(name, 72, 45), _target(target)
{
    srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &robotomyRequestForm): AForm(robotomyRequestForm)
{
    srand(time(NULL));
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &robotomyRequestForm)
{
    AForm::operator=(robotomyRequestForm);
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

std::string RobotomyRequestForm::getTarget() const
{
    return _target;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    try
    {
        if (!AForm::canExecute(executor))
            return ;
        std::cout << "*drilling noises*" << std::endl;
        // afplay can be replaced with aplay on linux
        system("afplay -t 5 assets/power-drill.mp3");
        if (rand() % 2)
            std::cout << _target << " has been robotomized successfully!" << std::endl;
        else
            std::cout << _target << " failed to be robotomized!" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }   
}
