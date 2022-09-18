
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()
cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(Test LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -O3")
set(THIRD_PARTY_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../3rd_Party")

add_definitions(-D_FILE_OFFSET_BITS=64)
add_definitions(-DWXUSINGDLL)
add_definitions(-D__WXGTK__)

if (UNIX)
    set(THIRD_PARTY_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../3rd_Party/Linux")

    set (GTEST_INCLUDE_DIRS ${THIRD_PARTY_PATH}/Google_Test/include)
    set (GTEST_LIBS_DIR ${THIRD_PARTY_PATH}/Google_Test/lib)
    set (GTEST_LIBRARIES gmock gmock_main gtest gtest_main)
else()
    message( FATAL_ERROR "Only support Linux." )
endif (UNIX)

add_subdirectory(../WordCounter WordCounter_Build)
file(GLOB SOURCES main.cpp src/*cpp)

include_directories(${GTEST_INCLUDE_DIRS} ${wxWidgets_INCLUDE_DIR} ${wxWidgetsGt_INCLUDE_DIR})
link_directories(${GTEST_LIBS_DIR} ${wxWidgets_LIBS_DIRS})

macro(add_test_all name)
add_executable(${name}_all ${name}.cpp)
target_link_libraries(${name}_all ${GTEST_LIBRARIES} ${wxWidgets_LIBRARIES} pthread WordCounter)
endmacro()

add_test_all(Test)