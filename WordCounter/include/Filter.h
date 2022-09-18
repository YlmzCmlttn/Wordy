#pragma once
#include <cstdint>
#include <cctype>
#include <memory>
#include <vector>
enum FilterType{
    NONE = 0,
    ALPHA = std::uint8_t(1 << 0),
    NUMERIC = std::uint8_t(1 << 1),
    ALPHANUMNERIC = FilterType::ALPHA | FilterType::NUMERIC,
    LOWERCASE = std::uint8_t(1 << 2),
    UPPERCASE = std::uint8_t(1 << 3),
    SPACE = std::uint8_t(1 << 4),
    ALL = std::uint8_t(1 << 5),
};
[[maybe_unused]] static FilterType operator|(FilterType a, FilterType b)
{
    return static_cast<FilterType>(static_cast<std::uint8_t>(a) | static_cast<std::uint8_t>(b));
}
[[maybe_unused]] static FilterType operator^(FilterType a, FilterType b)
{
    return static_cast<FilterType>(static_cast<std::uint8_t>(a) ^ static_cast<std::uint8_t>(b));
}

template<typename T> class Specification{
public:
    virtual bool isSatisfied(const T& item)const=0;
};

class WordAllSpecification : public Specification<char>{
    bool isSatisfied([[maybe_unused]] const char& item)const override{
        return true;
    }
};
class WordAlphaSpecification : public Specification<char>{
    bool isSatisfied(const char& item)const override{
        return std::isalpha(item);
    }
};
class WordNumericSpecification : public Specification<char>{
    bool isSatisfied(const char& item)const override{
        return std::isdigit(item);
    }
};
class WordLowerCaseSpecification : public Specification<char>{
    bool isSatisfied(const char& item)const override{
        return std::islower(item);
    }
};
class WordUpperCaseSpecification : public Specification<char>{
    bool isSatisfied(const char& item)const override{
        return std::isupper(item);
    }
};
class WordSpaceSpecification : public Specification<char>{
    bool isSatisfied(const char& item)const override{
        return std::isspace(item);
    }
};
template <typename T> class MultSpecification : public Specification<T>{
public:
    std::vector<std::unique_ptr<Specification<T>>> m_Specifications;
    MultSpecification()=default;
    void push(std::unique_ptr<Specification<T>> specification){
        m_Specifications.push_back(std::move(specification));
    }

    bool isSatisfied(const T& item)const override{
        for(const auto& specs : m_Specifications ){
            if(specs->isSatisfied(item)){
                return true;
            }
        }
        return false;
    }
};

template <typename T1,typename T2> class Filter{
public:
    virtual bool filter(const T1& item,const std::unique_ptr<Specification<T2>>& specification)const=0;
    virtual bool filter(const T1& item,const std::unique_ptr<MultSpecification<T2>>& specification)const=0;
};

class WordFilter : Filter<std::string,char>{
public:
    bool filter(const std::string& item,const std::unique_ptr<Specification<char>>& specification)const override{        
        for(auto& p: item)
            if(!(specification->isSatisfied(p)))
                return false;                
        return true;
    }
    bool filter(const std::string& item,const std::unique_ptr<MultSpecification<char>>& specification)const override{        
        for(auto& p: item)
            if(!(specification->isSatisfied(p)))
                return false;                
        return true;
    }
};