if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()
cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(WordCounter VERSION 1.0.1 DESCRIPTION "WordCounter")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
file(GLOB_RECURSE SOURCES src/*.cpp)

add_library(
    WordCounter STATIC
    ${SOURCES}
)
target_include_directories(WordCounter PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
