#pragma once
#include "BaseWordCounter.h"
#include <sstream>
class WordCounterText : public BaseWordCounter
{
private:
    void throwBufferError()override;
    void throwBufferEmpty()override;
    WordCounterText(const std::string& inputText,const std::vector<std::string>& search, const std::optional<char>& delimiter,const FilterType& filterType);
    friend class WordCounterFactory;
};
