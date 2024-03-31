#include "Harl.hpp"

int main()
{
    Harl harl = Harl();
    harl.complain("debug");
    harl.complain("info");
    harl.complain("warning");
    harl.complain("error");
    return 0;
}