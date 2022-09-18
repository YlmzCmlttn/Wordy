#include "WordCounterFile.h"
WordCounterFile::WordCounterFile(const std::string& fileName,const std::vector<std::string>& search, const std::optional<char>& delimiter,const FilterType& filterType):BaseWordCounter{search,delimiter,filterType,std::make_unique<std::ifstream>(fileName)}{    
}
void WordCounterFile::throwBufferError(){
    throw std::invalid_argument("Input file couldn't open");
}
void WordCounterFile::throwBufferEmpty(){
    throw std::invalid_argument("Input file empty");
}