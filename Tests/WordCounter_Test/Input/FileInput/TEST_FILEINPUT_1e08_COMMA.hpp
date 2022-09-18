namespace Test{
    TEST(FileInputTest,FileInputTest_1e08_Comma){
        std::vector<std::string> keys = {":)",":-)",":-D"};
        WordCounterPtr wordCounter = WordCounter::create()
                                                    .input()
                                                        .filename(std::string(RESOURCES_DIR)+"/Words1e+08_Comma.txt")
                                                    .settings()
                                                        .search(keys)
                                                        .filter(FilterType::ALL)
                                                        .delimiter(',');

        wordCounter->detect();
        const auto& topten = wordCounter->getTopTen();
        EXPECT_EQ(topten.size(),std::size_t{10});
        EXPECT_EQ(std::accumulate(topten.begin(),topten.end(),0,[](size_t lhs, const std::pair<std::string,std::size_t>& p){
            return lhs+p.second;
        }),109160);

        const auto& searched = wordCounter->getSearched();
        EXPECT_EQ(searched.size(),std::size_t{3});
        EXPECT_EQ(std::accumulate(searched.begin(),searched.end(),0,[](size_t lhs, const std::pair<std::string,std::size_t>& p){
            return lhs+p.second;
        }),98519);
    }
}