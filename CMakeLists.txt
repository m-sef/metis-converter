cmake_minimum_required(VERSION 3.16)
project(metis-converter)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -g -pg -Wall -Wextra -Werror")

add_executable(
    metis
    src/main.cpp
    src/graph.tpp
    src/utility.cpp
)