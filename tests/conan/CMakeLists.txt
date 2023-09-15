cmake_minimum_required(VERSION 3.24.1)

#set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_BINARY_DIR}/conan_toolchain.cmake"
# CACHE STRING "Conan toolchain file")


project(sfml-test)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)


find_package(SFML 2.6.0 COMPONENTS system window graphics CONFIG REQUIRED)

add_executable(TEST main.cpp)

target_link_libraries(TEST PRIVATE sfml-system sfml-network sfml-graphics sfml-window)