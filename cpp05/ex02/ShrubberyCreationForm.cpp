#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationDefaultForm", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name, const std::string target) 
    : AForm(name, 145, 137), _target(target), _levels(-1)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name, const std::string target, int levels) 
    : AForm(name, 145, 137), _target(target), _levels(levels)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ShrubberyCreationForm)
    : AForm(ShrubberyCreationForm.getName(),
            ShrubberyCreationForm.getGradeToSign(),
            ShrubberyCreationForm.getGradeToExecute())
{
    _target = ShrubberyCreationForm._target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &ShrubberyCreationForm)
{
    _target = ShrubberyCreationForm._target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    try
    {
        if (!AForm::canExecute(executor))
            return ;
        if (_levels > 0)
            writeDynamicTree(_target + "_shrubbery", _levels);
        else
            writeStaticTree(_target + "_shrubbery");
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return;
    }    
}

void ShrubberyCreationForm::writeStaticTree(const std::string filename) const
{
    std::ofstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file " << filename << std::endl;
        return;
    }

    file << "      /\\      " << std::endl;
    file << "     /\\*\\     " << std::endl;
    file << "    /\\O\\*\\    " << std::endl;
    file << "   /*/\\/\\/\\   " << std::endl;
    file << "  /\\O\\/\\*\\/\\  " << std::endl;
    file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
    file << "/\\O\\/\\/*/\\/O/\\" << std::endl;
    file << "      |||      " << std::endl;
    file << "      |||     " << std::endl;
    file << "      |||     " << std::endl;
    file.close();
}

void ShrubberyCreationForm::writeDynamicTree(const std::string filename, int levels) const
{
    std::ofstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file " << filename << std::endl;
        return;
    }
    for (int i = 0; i < levels; i++)
    {
        for (int j = 0; j < levels - i; j++)
            file << " ";
        for (int j = 0; j < i * 2 + 1; j++)
            file << "*";
        file << std::endl;
    }
    int stems = levels / 2;
    int stemWidth = levels / 5;
    for (int i = 0; i < stems; i++)
    {
        for (int j = 0; j < levels - (stemWidth / 2); j++)
            file << " ";
        for (int s = 0; s < stemWidth; s++)
            file << "|";
        file << std::endl;
    }
}
