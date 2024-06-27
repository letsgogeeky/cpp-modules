#include <iostream>
#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class AForm;

class ShrubberyCreationForm : public AForm
{
private:
    std::string _target;
    int _levels;
    void    writeStaticTree(std::string filename) const;
    void    writeDynamicTree(std::string filename, int levels) const;

public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string name, const std::string target);
    ShrubberyCreationForm(const std::string name, const std::string target, int levels);
    ShrubberyCreationForm(const ShrubberyCreationForm &shrubberyCreationForm);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &shrubberyCreationForm);
    ~ShrubberyCreationForm();

    void execute(const Bureaucrat &executor) const;
};