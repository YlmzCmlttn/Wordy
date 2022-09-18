namespace Test{
    TEST(FilterTest,FilterTest_ALPHANUM_SPACE){
        std::vector<std::string> keys = {"1","9","8"};
        std::string inputStr = "1,:-), ,A,a,Aa";
        WordCounterPtr wordCounter = WordCounter::create()
                                                    .input()
                                                        .text(inputStr)
                                                    .settings()
                                                        .search(keys)
                                                        .filter(FilterType::ALPHANUMNERIC | FilterType::SPACE)
                                                        .delimiter(',');

        wordCounter->detect();
        const auto& topten = wordCounter->getTopTen();
        EXPECT_EQ(topten.size(),std::size_t{5});        
    }
}