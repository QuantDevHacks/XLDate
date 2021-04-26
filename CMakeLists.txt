cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_STANDARD 14)
include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v2.13.1)
include_directories(Dates)

project(XLDate)
add_library(XLDate OBJECT
        Dates/date.h
        Dates/DayCount.cpp
        Dates/DayCount.h
        Dates/XLDate.h
        Dates/XLDate.cpp)

FetchContent_MakeAvailable(Catch2)
add_executable(XLDateTests
        DateTests/Tests_Dates.cpp
        DateTests/Tests_Daycounts.cpp
        DateTests/TestMain.cpp)
target_link_libraries(XLDateTests PRIVATE
        XLDate
        Catch2::Catch2)

add_executable(XLDateMain Main01.cpp)
target_link_libraries(XLDateMain XLDate)