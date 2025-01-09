cmake_minimum_required(VERSION 3.5)
project(hw1)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
find_package(fmt REQUIRED)

add_executable(pascal hw1.cpp)
target_link_libraries(pascal fmt::fmt)