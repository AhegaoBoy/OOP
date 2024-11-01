cmake_minimum_required(VERSION 3.21)
project(lab_3)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

FetchContent_Declare(googletest
                            URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip)
FetchContent_MakeAvailable(googletest)



set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)

include_directories(${INCLUDE_DIR})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES false ${SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false ${TEST_DIR}/*.cpp)

add_library(${CMAKE_PROJECT_NAME}_lib ${SOURCES}
        include/Figure.h
        include/Rectangle.h
        include/Square.h
        include/Point.h
        include/Trapezoid.h)
add_executable(${CMAKE_PROJECT_NAME}_exe main.cpp
        src/Point.cpp
        src/Trapezoid.cpp)

add_executable(lab_3 main.cpp)

target_link_libraries(lab_3
        PRIVATE
        gtest_main)
##############