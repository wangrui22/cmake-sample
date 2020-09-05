include_directories(${PROJECT_SOURCE_DIR}/util)

add_executable(demo5 ./demo5.cpp)

target_link_libraries(demo5 util)