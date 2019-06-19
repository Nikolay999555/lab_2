cmake_minimum_required(VERSION 2.8)


project(main_project)

set(SOURCES api.cpp)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MTd")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")

add_executable(main_project ${SOURCES})

target_link_libraries(main_project StaticLib)
target_link_libraries(main_project QSort)
target_link_libraries(main_project gtest)
