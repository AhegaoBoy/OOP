cmake_minimum_required(VERSION 3.27)
project(lab_6)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab_6 main.cpp
        bear.cpp
        bear.h
        npc.cpp
        npc.h
        robber.cpp
        robber.h
        wolf.cpp
        wolf.h)
