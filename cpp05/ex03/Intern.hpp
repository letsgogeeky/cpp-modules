#include <iostream>
#include <string>

#include "AForm.hpp"

class Bureaucrat;

class Intern
{

private:
    static const std::string _formNames[3];
    static AForm *(*_formCreators[3])(const std::string, const std::string);
    static AForm *createShrubberyCreationForm(const std::string name, const std::string target);
    static AForm *createRobotomyRequestForm(const std::string name, const std::string target);
    static AForm *createPresidentialPardonForm(const std::string name, const std::string target);

public:
    Intern();
    Intern(const Intern &intern);
    Intern &operator=(const Intern &intern);
    ~Intern();

    AForm *makeForm(const std::string formName, const std::string target);

    class FormNotFoundException: public std::exception
    {
        virtual const char* what() const throw();
    };

};