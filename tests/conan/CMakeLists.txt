cmake_minimum_required(VERSION 3.24.1)

#include("${CMAKE_BINARY_DIR}/conanbuildinfo.cmake")
#conan_basic_setup()


#set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/conan_toolchain.cmake)
set(CMAKE_MODULE_PATH "${CMAKE_BINARY_DIR}/")
#set(CMAKE_BUILD_TYPE "Debug")
project(sfml-test)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED TRUE)


find_package(SFML REQUIRED)

add_executable(TEST main.cpp)
#target_include_directories(TEST PRIVATE ${SFML_INCLUDE_DIRS})
target_link_libraries(TEST PRIVATE sfml-graphics)