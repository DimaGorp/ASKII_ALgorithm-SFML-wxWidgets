cmake_minimum_required(VERSION 3.24.2)

project(test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(file "${CMAKE_CURRENT_SOURCE_DIR}/src/ref/")

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/help.h.in ${CMAKE_CURRENT_SOURCE_DIR}/src/help.h)
add_subdirectory("ext/")
add_subdirectory("src/SFML")


add_executable(test src/main.cpp)

target_link_libraries(test PRIVATE wx::net wx::core wx::base ASKII)


