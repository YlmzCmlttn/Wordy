#include "WordCounterSettingsBuilder.h"

WordCounterSettingsBuilder::WordCounterSettingsBuilder(WordCounter &wordCounter):AbstractWordCounterBuilder{wordCounter}{}

WordCounterSettingsBuilder& WordCounterSettingsBuilder::search(const std::vector<std::string>& search){
    mWordCounter.search=search;
    return *this;
}
WordCounterSettingsBuilder& WordCounterSettingsBuilder::filter(const FilterType& filterType){
    mWordCounter.filterType=filterType;
    return *this;
}
WordCounterSettingsBuilder& WordCounterSettingsBuilder::delimiter(const char& delimiter){
    mWordCounter.delimiter=std::optional<char>(delimiter);
    return *this;
}
WordCounterSettingsBuilder& WordCounterSettingsBuilder::delimiter(const std::optional<char>& delimiter){
    mWordCounter.delimiter= delimiter;
    return *this;
}