#include "WordCounterText.h"
WordCounterText::WordCounterText(const std::string& inputText,const std::vector<std::string>& search, const std::optional<char>& delimiter,const FilterType& filterType):BaseWordCounter{search,delimiter,filterType,std::make_unique<std::stringstream>(inputText)}{
}
void WordCounterText::throwBufferError(){
    throw std::invalid_argument("Input file couldn't open");
}
void WordCounterText::throwBufferEmpty(){
    throw std::invalid_argument("Input Text empty");
}