#pragma once
#include "IWordCounter.h"
#include "Filter.h"
#include <optional>
#include <vector>
#include <unordered_map>
#include <atomic>
#include <istream>
class BaseWordCounter : public IWordCounter
{
private:
    virtual void throwBufferError()=0;
    virtual void throwBufferEmpty()=0;
    std::size_t findNumberOfChar()const;
    std::pair<std::unordered_map<std::string,std::size_t>,
                            std::unordered_map<std::string,std::size_t>> search(const std::size_t& numberOfWord);
    void postSearch(const std::pair<std::unordered_map<std::string,std::size_t>,std::unordered_map<std::string,std::size_t>>& result);
    void streamClear()const;
    void pushWord(const std::string& word,std::unordered_map<std::string,size_t>& mapAll,std::unordered_map<std::string,size_t>& mapSearch)const;
    void pushToMap(const std::string& word,std::unordered_map<std::string,size_t>& map)const;
protected:   
    char mDelimiter;
    std::vector<std::pair<std::string,std::size_t>> mTopTen;
    std::vector<std::pair<std::string,std::size_t>> mSearched;
    std::vector<std::string> mSearch;
    std::unique_ptr<WordFilter> mWordFilter;
    std::unique_ptr<MultSpecification<char>> mSpecification;
    std::atomic<double> mStatus;
    std::unique_ptr<std::istream> mIstream;
    BaseWordCounter(const std::vector<std::string>& search, const std::optional<char>& delimiter,const FilterType& filterType,std::unique_ptr<std::istream> stream);
public:
    void detect()override;
    std::vector<std::pair<std::string,std::size_t>> getTopTen()const override;
    std::vector<std::pair<std::string,std::size_t>> getSearched()const override;
    double getStatus()const override;
};
