#ifndef STRINGREPLACE_H
# define STRINGREPLACE_H

#include <string>
class StringReplace
{
    public:
        StringReplace();
        ~StringReplace();
        const std::string replace(std::string str, std::string s1, std::string s2);
};

#endif