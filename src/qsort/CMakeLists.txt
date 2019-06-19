cmake_minimum_required(VERSION 2.8)

project(QSort)

set(SOURCES QSort.cpp)

set(HEADERS QSort.h)


add_library(QSort SHARED ${SOURCES} ${HEADERS})

add_custom_command(TARGET QSort POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different "${PROJECT_SOURCE_DIR}/Debug/QSort.dll"
        ../../api)