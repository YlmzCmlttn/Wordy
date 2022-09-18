#pragma once
#include <string>
#include "WordCounterBuilder.h"

class WordCounterInputBuilder : public AbstractWordCounterBuilder
{
public:
    explicit WordCounterInputBuilder(WordCounter &wordCounter);
    WordCounterInputBuilder& filename(const std::string &fileName);
    WordCounterInputBuilder& text(const std::string &text);
    WordCounterInputBuilder& input(const std::string &input,const WordCounter::InputType& inputType);
};