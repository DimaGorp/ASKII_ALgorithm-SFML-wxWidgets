project(ASKII)
add_library(askii ASKII.hpp ASKII.cpp)
set(CMAKE_MODULE_PATH "${CMAKE_BINARY_DIR}/")

find_package(SFML REQUIRED)

target_link_libraries(askii PUBLIC 
                    sfml-graphics sfml-audio)
target_include_directories(askii PUBLIC "${CMAKE_SOURCE_DIR}/src/")