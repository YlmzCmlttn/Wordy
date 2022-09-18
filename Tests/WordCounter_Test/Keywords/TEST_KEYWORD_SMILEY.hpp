namespace Test{
    TEST(KeywordTest,KeywordTest_Smiley){
        std::vector<std::string> keys = {":-)",":)",":-D"};
        std::string inputStr = "1,:-), ,A,a,Aa,:-),:),:-D,:-D,:-D";
        WordCounterPtr wordCounter = WordCounter::create()
                                                    .input()
                                                        .text(inputStr)
                                                    .settings()
                                                        .search(keys)
                                                        .filter(FilterType::ALL)
                                                        .delimiter(',');

        wordCounter->detect();
        const auto& searched = wordCounter->getSearched();

        EXPECT_EQ(searched[0].first,":-D");
        EXPECT_EQ(searched[1].first,":-)");
        EXPECT_EQ(searched[2].first,":)");
        EXPECT_EQ(searched[0].second,std::size_t{3});
        EXPECT_EQ(searched[1].second,std::size_t{2});
        EXPECT_EQ(searched[2].second,std::size_t{1});      
    }
}