#include "Config.h"
namespace Config{
    WordCounter::InputType inputType={WordCounter::InputType::NONE};
    FilterType filterType={FilterType::NONE};
    std::string input={""};
    std::vector<std::string> search={};
    std::optional<char> delimiter={std::nullopt};
    void setInputType(const WordCounter::InputType& t_inputType){
        inputType = t_inputType;
    }
    void setFilterType(const FilterType& t_filterType){
        filterType=t_filterType;
    }
    void setInput(const std::string& t_input){
        input=t_input;
    }
    void setSearch(const std::vector<std::string>& t_search){
        search=t_search;
    }
    void setDelimiter(const std::optional<char>& t_delimiter){
        delimiter=t_delimiter;
    }
}