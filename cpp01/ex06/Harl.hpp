#pragma once
#ifndef HARL_H
# define HARL_H

#include <string>
#include <array>

class Harl
{
    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);

        std::array<void (Harl::*)(void), 4> functions;
        std::array<std::string, 4> levels;

        int min_level;

    public:
        Harl();
        ~Harl();
        void complain(std::string level);
        void setMinLevel(std::string level);
        int getMinLevel(void);
        
};

#endif