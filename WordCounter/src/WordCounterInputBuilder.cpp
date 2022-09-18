#include "WordCounterInputBuilder.h"
#include "Assert.h"
WordCounterInputBuilder::WordCounterInputBuilder(WordCounter &wordCounter):AbstractWordCounterBuilder{wordCounter}{
    mWordCounter.inputType = WordCounter::InputType::NONE;
}
WordCounterInputBuilder& WordCounterInputBuilder::filename(const std::string &filename){    
    my_assert(!(mWordCounter.inputType==WordCounter::InputType::TEXT), "You can not assign both filename and text at same time");
    mWordCounter.inputType = WordCounter::InputType::FILE;
    mWordCounter.input = filename;    
    return *this;
}
WordCounterInputBuilder& WordCounterInputBuilder::text(const std::string &text){
    my_assert(!(mWordCounter.inputType==WordCounter::InputType::FILE), "You can not assign both filename and text at same time");
    mWordCounter.inputType = WordCounter::InputType::TEXT;
    mWordCounter.input = text;
    return *this;
}
WordCounterInputBuilder& WordCounterInputBuilder::input(const std::string &input,const WordCounter::InputType& inputType){
    mWordCounter.inputType = inputType;            
    mWordCounter.input = input;
    return *this;
}