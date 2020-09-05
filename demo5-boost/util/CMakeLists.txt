#引入boost的各个模块
find_package(Boost COMPONENTS system filesystem thread REQUIRED)

aux_source_directory(./ UTIL_SRC)

add_library(util SHARED ${UTIL_SRC})

#引入boost后的link
target_link_libraries(util ${Boost_LIBRARIES})