include_directories(${PROJECT_SOURCE_DIR}/mylib)

aux_source_directory(./ SRCS)

add_executable(demo4 ${SRCS})

target_link_libraries(demo4 mylib)