cmake_minimum_required(VERSION 3.10.2)

project(demo2 VERSION 0.1.0)

aux_source_directory( ./src DIR_SRC)
add_executable(demo2 ${DIR_SRC})

