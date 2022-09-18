#pragma once
#include "IWordCounter.h"
#include "WordCounter.h"
#include "WordCounterFile.h"
#include "WordCounterText.h"
#include <memory>

template<typename T>
using Scope = std::unique_ptr<T>;
typedef Scope<IWordCounter> WordCounterPtr;

class WordCounterFactory
{
public:
    static WordCounterPtr create(const WordCounter::InputType& type,const std::string& input, const std::vector<std::string>& search, const std::optional<char>& delimiter,const FilterType& filterType);
};
