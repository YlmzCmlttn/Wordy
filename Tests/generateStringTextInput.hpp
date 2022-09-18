#pragma once
#include <sstream>
std::string generateTextString(const char& delimeter){
    std::stringstream ret;
    for(uint i=0;i<11;i++){
        for(uint j=0;j<i;j++){
            ret<<i<<delimeter;
        }
    }
    return ret.str();
}