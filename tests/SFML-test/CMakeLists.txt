cmake_minimum_required(VERSION 3.24.1)

project(sfml-test)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)

add_executable(TEST main.cpp)

target_link_libraries(TEST PRIVATE sfml-graphics sfml-window sfml-system)

target_compile_options(TEST PRIVATE -Wall -Werror)