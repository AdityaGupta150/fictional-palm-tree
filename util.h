#pragma once

#include<string>
#include<exception>

class InvalidQueryException : public std::exception{};

namespace util
{
    void trimZeroes(std::string &s);
    bool validator(std::string&);
    std::string evaluate(std::string&);   //The std::string will be empty | double... only
    bool replace_all(const std::string&, const std::string&, std::string&); //instead of it, use boost::algorithm::replace_all later
} // namespace util
