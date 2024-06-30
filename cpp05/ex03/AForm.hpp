#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
protected:
    const std::string _name;
    bool _signed;
    const int _gradeToSign;
    const int _gradeToExecute;

public:
    AForm();
    AForm(const std::string name, int gradeToSign, int gradeToExecute);
    AForm(const AForm &AForm);
    AForm &operator=(const AForm &aForm);
    virtual ~AForm();

    const std::string getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void beSigned(const Bureaucrat &bureaucrat);
    bool canExecute(const Bureaucrat &executor) const;
    virtual void execute(const Bureaucrat &executor) const = 0;

    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class AFormAlreadySignedException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class SignatureRequiredException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const AForm &aForm);

#endif