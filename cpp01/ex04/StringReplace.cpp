#include "StringReplace.hpp"

StringReplace::StringReplace()
{
}

StringReplace::~StringReplace()
{
}

const std::string StringReplace::replace(std::string str, std::string s1, std::string s2)
{
     size_t pos = 0;
    while ((pos = str.find(s1, pos)) != std::string::npos)
    {
        str.erase(pos, std::string(s1).length());
        str.insert(pos, s2);
        pos += std::string(s2).length();
    }
    return str;
}