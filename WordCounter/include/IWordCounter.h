#pragma once
#include <vector>
#include <string>
class IWordCounter
{
public:
    virtual std::vector<std::pair<std::string,std::size_t>> getTopTen()const = 0;
    virtual std::vector<std::pair<std::string,std::size_t>> getSearched()const = 0;
    virtual void detect() = 0;
    virtual double getStatus()const = 0;
};