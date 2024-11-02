cmake_minimum_required(VERSION 3.21)
project(lab_4)
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(
        googletest
)




add_executable(lab_4 main.cpp
        vector.h
        figure.h
        hexagon.h
        pentagon.h
        point.h
        rhomb.h
)


target_link_libraries(
        lab_4
        PRIVATE
        gtest_main
)
