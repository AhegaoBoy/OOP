cmake_minimum_required(VERSION 3.21)
project(lab_2)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

FetchContent_Declare(googletest
                    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip)

FetchContent_MakeAvailable(googletest)


add_executable(lab_2 main.cpp
        decimal.cpp
        decimal.h
)

target_link_libraries(lab_2
                        PRIVATE
                        gtest_main)
