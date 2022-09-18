
if(NOT CMAKE_BUILD_TYPE)
set(CMAKE_BUILD_TYPE Release)
endif()
cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(Wordy LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -O3")


add_definitions(-D_FILE_OFFSET_BITS=64)
add_definitions(-DWXUSINGDLL)
add_definitions(-D__WXGTK__)

if (UNIX)
    set(THIRD_PARTY_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../3rd_Party/Linux")    
    set (wxWidgets_INCLUDE_DIR ${THIRD_PARTY_PATH}/wxWidgets-3.2.1/include/wx-3.2)
    set (wxWidgetsGt_INCLUDE_DIR ${THIRD_PARTY_PATH}/wxWidgets-3.2.1/lib/wx/include/gtk3-unicode-3.2/)
    set (wxWidgets_LIBS_DIRS ${THIRD_PARTY_PATH}/wxWidgets-3.2.1/lib)
    set (wxWidgets_LIBS pthread wx_gtk3u_xrc-3.2 wx_gtk3u_html-3.2 wx_gtk3u_qa-3.2 wx_gtk3u_core-3.2 wx_baseu_xml-3.2 wx_baseu_net-3.2 wx_baseu-3.2)
else()
    message( FATAL_ERROR "Only support Linux." )
endif (UNIX)

add_subdirectory(../WordCounter WordCounter_Build)

link_directories(${wxWidgets_LIBS_DIRS})
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include" ${wxWidgets_INCLUDE_DIR} ${wxWidgetsGt_INCLUDE_DIR})
link_libraries(${wxWidgets_LIBRARIES})

file(GLOB SOURCES main.cpp src/*cpp src/wxWidgets/*cpp)

macro(add_runtime name)
add_executable(${name} ${SOURCES})
target_link_libraries(${name} WordCounter ${wxWidgets_LIBS})

endmacro()

add_runtime(Wordy)

