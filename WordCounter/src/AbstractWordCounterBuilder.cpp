#include "AbstractWordCounterBuilder.h"
#include "WordCounterBuilder.h"
#include "WordCounterInputBuilder.h"
#include "WordCounterSettingsBuilder.h"
WordCounterInputBuilder AbstractWordCounterBuilder::input()const{
    return WordCounterInputBuilder{mWordCounter};
};
WordCounterSettingsBuilder AbstractWordCounterBuilder::settings()const{
    return WordCounterSettingsBuilder{mWordCounter};
};