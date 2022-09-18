#pragma once
#include "WordCounterBuilder.h"
#include <string>
#include <optional>

class WordCounterSettingsBuilder : public AbstractWordCounterBuilder
{
public:
    explicit WordCounterSettingsBuilder(WordCounter &wordCounter);
    WordCounterSettingsBuilder& search(const std::vector<std::string> &search);
    WordCounterSettingsBuilder& filter(const FilterType& filter);
    WordCounterSettingsBuilder& delimiter(const char& delimiter);
    WordCounterSettingsBuilder& delimiter(const std::optional<char>& delimiter);
};