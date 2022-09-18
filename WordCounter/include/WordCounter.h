#pragma once
#include <string>
#include <vector>
#include <optional>
#include "Filter.h"
class WordCounterBuilder;
class WordCounter
{
public:
    friend class WordCounterBuilder;
    friend class WordCounterInputBuilder;
    friend class WordCounterSettingsBuilder;
    friend class AbstractWordCounterBuilder;
    static WordCounterBuilder create();
    enum class InputType{
        NONE,
        FILE,
        TEXT
    };
private:
    WordCounter()=default;
    InputType inputType;
    std::string input;
    std::vector<std::string> search;
    FilterType filterType;
    std::optional<char> delimiter;
};