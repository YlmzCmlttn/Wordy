namespace Test{
    TEST(KeywordTest,KeywordTest_Word){
        std::vector<std::string> keys = {"Word","word","WORD"};
        std::string inputStr = "1,:-), ,A,a,Aa,Word,word,word,WORD,WORD,WORD";
        WordCounterPtr wordCounter = WordCounter::create()
                                                    .input()
                                                        .text(inputStr)
                                                    .settings()
                                                        .search(keys)
                                                        .filter(FilterType::ALL)
                                                        .delimiter(',');

        wordCounter->detect();
        const auto& searched = wordCounter->getSearched();

        EXPECT_EQ(searched[0].first,"WORD");
        EXPECT_EQ(searched[1].first,"word");
        EXPECT_EQ(searched[2].first,"Word");
        EXPECT_EQ(searched[0].second,std::size_t{3});
        EXPECT_EQ(searched[1].second,std::size_t{2});
        EXPECT_EQ(searched[2].second,std::size_t{1});        
    }
}