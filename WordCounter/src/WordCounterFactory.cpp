#include "WordCounterFactory.h"
#include "Assert.h"
std::unique_ptr<IWordCounter> WordCounterFactory::create(const WordCounter::InputType& type,const std::string& input, const std::vector<std::string>& search, const std::optional<char>& delimiter,const FilterType& filterType){
    my_assert(!(type==WordCounter::InputType::NONE),"Factory need Input Type");
    if(type==WordCounter::InputType::FILE){
        return std::unique_ptr<WordCounterFile>(new WordCounterFile(input,search,delimiter,filterType));
    }else if(type==WordCounter::InputType::TEXT){
        return std::unique_ptr<WordCounterText>(new WordCounterText(input,search,delimiter,filterType));
    }else{
        throw std::invalid_argument("Factory need Input Type");
        return std::unique_ptr<IWordCounter>(nullptr);
    }
}