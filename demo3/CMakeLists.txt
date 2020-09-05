cmake_minimum_required(VERSION 3.10.0)

project(demo3)

add_subdirectory(./mylib)

add_executable(demo3 demo3.cpp)

target_link_libraries(demo3 mylib)