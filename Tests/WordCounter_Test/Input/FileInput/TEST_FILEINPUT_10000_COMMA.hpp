namespace Test{
    TEST(FileInputTest,FileInputTest_10000_Comma){
        std::vector<std::string> keys = {":)",":-)",":-D"};
        WordCounterPtr wordCounter = WordCounter::create()
                                                    .input()
                                                        .filename(std::string(RESOURCES_DIR)+"/Words10000_Comma.txt")
                                                    .settings()
                                                        .search(keys)
                                                        .filter(FilterType::ALL)
                                                        .delimiter(',');

        wordCounter->detect();        
        const auto& topten = wordCounter->getTopTen();
        EXPECT_EQ(topten.size(),std::size_t{10});
        EXPECT_EQ(topten[0].first,"DEAL");
        EXPECT_EQ(topten[1].first,"LITTLE");
        EXPECT_EQ(topten[2].first,"like");
        EXPECT_EQ(topten[3].first,"Mother");
        EXPECT_EQ(topten[4].first,"Show");
        EXPECT_EQ(topten[5].first,"Possible");
        EXPECT_EQ(topten[6].first,"OUT");
        EXPECT_EQ(topten[7].first,"population");
        EXPECT_EQ(topten[8].first,"photo");
        EXPECT_EQ(topten[9].first,"OVER");

        EXPECT_EQ(topten[0].second,std::size_t{4});
        EXPECT_EQ(topten[1].second,std::size_t{4});
        EXPECT_EQ(topten[2].second,std::size_t{3});
        EXPECT_EQ(topten[3].second,std::size_t{3});
        EXPECT_EQ(topten[4].second,std::size_t{3});
        EXPECT_EQ(topten[5].second,std::size_t{3});
        EXPECT_EQ(topten[6].second,std::size_t{3});
        EXPECT_EQ(topten[7].second,std::size_t{3});
        EXPECT_EQ(topten[8].second,std::size_t{3});
        EXPECT_EQ(topten[9].second,std::size_t{3});

        const auto& searched = wordCounter->getSearched();

        EXPECT_EQ(searched[0].first,":-D");
        EXPECT_EQ(searched[1].first,":-)");
        EXPECT_EQ(searched[2].first,":)");
        EXPECT_EQ(searched[0].second,std::size_t{4});
        EXPECT_EQ(searched[1].second,std::size_t{4});
        EXPECT_EQ(searched[2].second,std::size_t{4});
    }
}