#include "WordCounter.h"
#include "WordCounterBuilder.h"
WordCounterBuilder WordCounter::create(){
    return WordCounterBuilder{};
}