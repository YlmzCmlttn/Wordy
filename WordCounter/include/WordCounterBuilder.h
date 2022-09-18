#pragma once
#include "WordCounter.h"
#include "AbstractWordCounterBuilder.h"
class WordCounterBuilder : public AbstractWordCounterBuilder
{
    WordCounter mWordCounter;
public:
    WordCounterBuilder();
};