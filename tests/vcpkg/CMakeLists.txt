cmake_minimum_required(VERSION 3.24.1)


set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
  CACHE STRING "Vcpkg toolchain file")
set(CMAKE_BUILD_TYPE "Release")
project(sfml-test)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED TRUE)


find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)

add_executable(TEST main.cpp)
#target_include_directories(TEST PRIVATE ${SFML_INCLUDE_DIRS})
target_link_libraries(TEST PRIVATE sfml-graphics)