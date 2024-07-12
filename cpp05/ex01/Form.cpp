#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{

}

Form::Form(const std::string name, int gradeToSign, int gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &form): _name(form._name), _signed(form._signed), _gradeToSign(form._gradeToSign), _gradeToExecute(form._gradeToExecute)
{

}

Form &Form::operator=(const Form &form)
{
    _signed = form._signed;
    return *this;
}

Form::~Form()
{

}

const std::string Form::getName() const
{
    return _name;
}

bool Form::isSigned() const
{
    return _signed;
}

int Form::getGradeToSign() const
{
    return _gradeToSign;
}

int Form::getGradeToExecute() const
{
    return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw Form::GradeTooLowException();
    _signed = true;
    std::cout << bureaucrat.getName() << " signs " << _name << " successfully!" << std::endl;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "EXCEPTION:: Form Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "EXCEPTION:: Form Grade is too low";
}

const char *Form::FormAlreadySignedException::what() const throw()
{
    return "EXCEPTION:: Form is already signed";
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << form.getName() << " form is ";
    if (form.isSigned())
        out << "signed";
    else
        out << "not signed";
    out << " and requires grade " << form.getGradeToSign();
	out << " to sign and grade " << form.getGradeToExecute() << " to execute.";
    return out;
}
