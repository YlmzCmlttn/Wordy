#pragma once
#include "BaseWordCounter.h"
#include <fstream>
class WordCounterFile : public BaseWordCounter
{
private:
    void throwBufferError()override;
    void throwBufferEmpty()override;
    WordCounterFile(const std::string& fileName,const std::vector<std::string>& search, const std::optional<char>& delimiter,const FilterType& filterType);
    friend class WordCounterFactory;
};
