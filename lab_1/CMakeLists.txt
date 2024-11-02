cmake_minimum_required(VERSION 3.21)
project(lab_1)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare( googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip)

#set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(
        googletest)


add_executable(lab_1
                main.cpp
        solution.cpp)

target_link_libraries(
        lab_1
        PRIVATE
        gtest_main)




