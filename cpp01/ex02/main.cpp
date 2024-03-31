#include <iostream>
#include <string>

int main()
{
    std::string brain = "HI THIS IS BRAIN";
    std::string* brainPTR = &brain;
    std::string& brainREF = brain;

    std::cout << "Address of brain: " << &brain << std::endl;
    std::cout << "Address of brainPTR: " << brainPTR << std::endl;
    std::cout << "Address of brainREF: " << &brainREF << std::endl;

    std::cout << "Value of brain: " << brain << std::endl;
    std::cout << "Value of brainPTR: " << *brainPTR << std::endl;
    std::cout << "Value of brainREF: " << brainREF << std::endl;
}
