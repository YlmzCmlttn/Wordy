#include "BaseWordCounter.h"
#include <algorithm>
BaseWordCounter::BaseWordCounter(const std::vector<std::string>& search, const std::optional<char>& delimiter,const FilterType& filterType,std::unique_ptr<std::istream> stream):mSearch{std::move(search)},mWordFilter{std::make_unique<WordFilter>()},mSpecification{std::make_unique<MultSpecification<char>>()},mStatus{0.0},mIstream{std::move(stream)}{
    if(delimiter.has_value()){
        mDelimiter = delimiter.value();
    }else{
        mDelimiter = '\n';
    }
    if(filterType & FilterType::ALL){
        mSpecification->push(std::make_unique<WordAllSpecification>());
    }
    if(filterType & FilterType::ALPHA){
        mSpecification->push(std::make_unique<WordAlphaSpecification>());
    }
    if(filterType & FilterType::NUMERIC){
        mSpecification->push(std::make_unique<WordNumericSpecification>());
    }
    if(filterType & FilterType::LOWERCASE){
        mSpecification->push(std::make_unique<WordLowerCaseSpecification>());
    }
    if(filterType & FilterType::UPPERCASE){
        mSpecification->push(std::make_unique<WordUpperCaseSpecification>());
    }
    if(filterType & FilterType::SPACE){
        mSpecification->push(std::make_unique<WordSpaceSpecification>());
    }
}

void BaseWordCounter::detect(){
    if(!(*mIstream))throwBufferError();
    const auto nOfChar = findNumberOfChar();
    if(nOfChar==0)throwBufferEmpty();
    postSearch(search(nOfChar));
}
void BaseWordCounter::streamClear()const{
    mIstream->clear();
    mIstream->seekg(0);
}
std::size_t BaseWordCounter::findNumberOfChar()const{
    mIstream->seekg(0, std::ios::end);
    std::size_t ret = mIstream->tellg();
    streamClear();
    return std::move(ret);
}

std::pair<std::unordered_map<std::string,std::size_t>,
          std::unordered_map<std::string,std::size_t>> BaseWordCounter::search(const std::size_t& numberOfWord){
    std::string word("");
    std::unordered_map<std::string,size_t> mapAll;
    std::unordered_map<std::string,size_t> mapSearch;

    std::for_each(std::istreambuf_iterator<char>(*mIstream),
                    std::istreambuf_iterator<char>(),
                    [&numberOfWord,&word,&mapAll,&mapSearch,this](const char& c){
                        if(c==mDelimiter){
                            pushWord(word,mapAll,mapSearch);
                            word.clear();
                        }else{
                            word += c;
                        }
                        mStatus = double(mIstream->tellg())/double(numberOfWord);
                    });
    mStatus = 1.0;
    if(!(word.empty())){
        pushWord(word,mapAll,mapSearch);
        word.clear();
    }
    streamClear();
    return std::move(std::make_pair(std::move(mapAll),std::move(mapSearch)));
}
void BaseWordCounter::pushToMap(const std::string& word,std::unordered_map<std::string,size_t>& map)const{
    if(map.count(word)>0){
        map[word] += 1;
    }else{
        map[word] = 1;                    
    }
}
void BaseWordCounter::pushWord(const std::string& word,std::unordered_map<std::string,size_t>& mapAll,std::unordered_map<std::string,size_t>& mapSearch)const{
    if(mWordFilter->filter(word,mSpecification)){
        pushToMap(word,mapAll);
        for(const auto& f : mSearch){
            std::string word_{word};
            size_t pos{0};
            while ((pos = word_.find(f)) != std::string::npos) {
                pushToMap(f,mapSearch);
                word_.erase(0, pos + f.length());
            }
        }      
    }
}
void BaseWordCounter::postSearch(const std::pair<std::unordered_map<std::string,std::size_t>,std::unordered_map<std::string,std::size_t>>& result){
    mSearched.clear();
    mTopTen.clear();
    std::vector<std::pair<std::string,std::size_t>> sorted(result.first.begin(), result.first.end());
    std::sort(sorted.begin(), sorted.end(), [](const std::pair<std::string,std::size_t>& a,const std::pair<std::string,std::size_t>& b){
        return a.second>b.second;
    });
    mSearched = std::vector<std::pair<std::string,std::size_t>>(result.second.begin(),result.second.end());
    std::sort(mSearched.begin(), mSearched.end(), [](const std::pair<std::string,std::size_t>& a,const std::pair<std::string,std::size_t>& b){
        return a.second>b.second;
    });
    for(const auto& s : sorted){
        if(mTopTen.size()<10){
            mTopTen.push_back(s);
        }else{
            break;
        }
    }
}
std::vector<std::pair<std::string,std::size_t>> BaseWordCounter::getTopTen()const{
    return mTopTen;
}
std::vector<std::pair<std::string,std::size_t>> BaseWordCounter::getSearched()const{
    return mSearched;
}
double BaseWordCounter::getStatus()const{
    return mStatus;
}