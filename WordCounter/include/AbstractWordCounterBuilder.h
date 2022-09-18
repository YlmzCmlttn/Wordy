#pragma once
#include "WordCounter.h"
#include <memory>
#include "WordCounterFactory.h"
class WordCounterInputBuilder;
class WordCounterSettingsBuilder;
class AbstractWordCounterBuilder
{
protected:
    WordCounter& mWordCounter;
    inline explicit AbstractWordCounterBuilder(WordCounter& wordCounter):mWordCounter{wordCounter}{}
public:
    inline operator std::unique_ptr<IWordCounter>()const{
        return WordCounterFactory::create(mWordCounter.inputType,mWordCounter.input,mWordCounter.search,mWordCounter.delimiter,mWordCounter.filterType);
    };
    WordCounterInputBuilder input()const;
    WordCounterSettingsBuilder settings()const;
};