cmake_minimum_required(VERSION 3.10.0)

project(demo6)

find_package(Qt5 COMPONENTS Core Widgets Gui REQUIRED)

set(SRC 
    ${PROJECT_SOURCE_DIR}/mainwindow.h
    ${PROJECT_SOURCE_DIR}/mainwindow.cpp
    ${PROJECT_SOURCE_DIR}/mainwindow.ui
    ${PROJECT_SOURCE_DIR}/main.cpp)

add_executable(demo6 ${SRC})

target_link_libraries(demo6 Qt5::Widgets Qt5::Core Qt5::Gui)

set_target_properties(demo6 PROPERTIES AUTOMOC ON)
set_target_properties(demo6 PROPERTIES AUTOUIC ON)