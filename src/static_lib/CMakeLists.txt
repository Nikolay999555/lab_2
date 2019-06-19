cmake_minimum_required(VERSION 2.8)


project(static_lib)


set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MTd")

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")


set(SOURCES StaticLib.cpp)
set(HEADERS StaticLib.h)


add_library(StaticLib STATIC ${SOURCES} ${HEADERS})
