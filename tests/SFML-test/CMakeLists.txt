cmake_minimum_required(VERSION 3.24.1)

project(sfml-test)





#set(CMAKE_OSX_ARCHITECTURES "arm64" )
set(BUILD_SHARED_LIBS OFF)

set(CMAKE_CXX_STANDARD_REQUIRED TRUE)


add_executable(TEST main.cpp)

find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)

target_link_libraries(TEST PRIVATE  
    sfml-graphics sfml-audio
)
