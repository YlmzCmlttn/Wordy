namespace Test{
    TEST(FilterTest,FilterTest_UPPERCASE){
        std::vector<std::string> keys = {"1","9","8"};
        std::string inputStr = "1,:-), ,A,a,Aa";
        WordCounterPtr wordCounter = WordCounter::create()
                                                    .input()
                                                        .text(inputStr)
                                                    .settings()
                                                        .search(keys)
                                                        .filter(FilterType::UPPERCASE)
                                                        .delimiter(',');

        wordCounter->detect();
        const auto& topten = wordCounter->getTopTen();
        EXPECT_EQ(topten.size(),std::size_t{1});        
    }
}