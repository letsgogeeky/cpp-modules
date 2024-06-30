#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): _name("default"), 
    _signed(false), _gradeToSign(150), _gradeToExecute(150)
{

}

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute): 
    _name(name), _signed(false),
    _gradeToSign(gradeToSign),
    _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &aForm): 
    _name(aForm._name),
    _signed(aForm._signed),
    _gradeToSign(aForm._gradeToSign),
    _gradeToExecute(aForm._gradeToExecute)
{

}

AForm &AForm::operator=(const AForm &AForm)
{
    _signed = AForm._signed;
    return *this;
}

AForm::~AForm()
{

}

const std::string AForm::getName() const
{
    return _name;
}

bool AForm::isSigned() const
{
    return _signed;
}

int AForm::getGradeToSign() const
{
    return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw AForm::GradeTooLowException();
    _signed = true;
    std::cout << bureaucrat.getName() << " signs " << _name << " successfully!" << std::endl;
}

bool AForm::canExecute(const Bureaucrat &executor) const
{
    if (!isSigned())
        throw AForm::SignatureRequiredException();
    if (executor.getGrade() > _gradeToExecute)
        throw AForm::GradeTooLowException();
    return true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

const char *AForm::AFormAlreadySignedException::what() const throw()
{
    return "AForm is already signed";
}

const char *AForm::SignatureRequiredException::what() const throw()
{
    return "Signature is required";
}

std::ostream &operator<<(std::ostream &out, const AForm &AForm)
{
    out << AForm.getName() << " AForm is ";
    if (AForm.isSigned())
        out << "signed";
    else
        out << "not signed";
    out << " and requires grade " << AForm.getGradeToSign() << " to sign and grade " << AForm.getGradeToExecute() << " to execute";
    return out;
}
