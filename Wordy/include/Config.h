#pragma once
#include "WordCounter.h"
#include <string>
#include <vector>
#include <optional>
namespace Config{
    extern WordCounter::InputType inputType;
    extern FilterType filterType;
    extern std::string input;
    extern std::vector<std::string> search;
    extern std::optional<char> delimiter;
    void setInputType(const WordCounter::InputType& t_inputType);
    void setFilterType(const FilterType&);
    void setInput(const std::string&);
    void setSearch(const std::vector<std::string>&);
    void setDelimiter(const std::optional<char>&);
}