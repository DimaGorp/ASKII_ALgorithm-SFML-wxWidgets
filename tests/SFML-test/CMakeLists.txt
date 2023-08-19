cmake_minimum_required(VERSION 3.24.1)

project(sfml-test)





#set(CMAKE_OSX_ARCHITECTURES "arm64" )
set(BUILD_SHARED_LIBS OFF)

set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable(TEST main.cpp)

target_include_directories(TEST PRIVATE /opt/homebrew/Cellar/sfml/2.6.0/include/)

target_link_libraries(TEST PRIVATE  
    /opt/homebrew/Cellar/sfml/2.6.0/lib/libsfml-graphics.2.6.0.dylib
    /opt/homebrew/Cellar/sfml/2.6.0/lib/libsfml-system.2.6.0.dylib
    /opt/homebrew/Cellar/sfml/2.6.0/lib/libsfml-window.2.6.0.dylib
)
