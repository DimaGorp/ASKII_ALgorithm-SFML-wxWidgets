cmake_minimum_required(VERSION 3.24.1)

project(sfml-test LANGUAGES CXX)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(BUILD_SHARED_LIBS OFF)
set(CMAKE_OSX_DEPLOYMENT_TARGET 11.0)
include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

#find_package(SFML COMPONENTS graphics window system CONFIG REQUIRED)

add_executable(TEST main.cpp)

target_link_libraries(TEST PRIVATE sfml-graphics)
target_compile_features(TEST PRIVATE cxx_std_17)
