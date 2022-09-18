namespace Test{
    TEST(TextInputTest,TextInputTest_Comma){
        std::vector<std::string> keys = {"10","9","8"};
        WordCounterPtr wordCounter = WordCounter::create()
                                                    .input()
                                                        .text(generateTextString(','))
                                                    .settings()
                                                        .search(keys)
                                                        .filter(FilterType::ALL)
                                                        .delimiter(',');

        wordCounter->detect();
        const auto& topten = wordCounter->getTopTen();
        EXPECT_EQ(topten.size(),std::size_t{10});
        for(uint i =0;i<10;i++){
            EXPECT_EQ(topten[i].first,std::to_string(10-i));
            EXPECT_EQ(topten[i].second,(10-i));
        }
        EXPECT_EQ(std::accumulate(topten.begin(),topten.end(),0,[](size_t lhs, const std::pair<std::string,std::size_t>& p){
            return lhs+p.second;
        }),55);

        const auto& searched = wordCounter->getSearched();
        EXPECT_EQ(searched.size(),std::size_t{3});
        EXPECT_EQ(std::accumulate(searched.begin(),searched.end(),0,[](size_t lhs, const std::pair<std::string,std::size_t>& p){
            return lhs+p.second;
        }),27);
    }
}