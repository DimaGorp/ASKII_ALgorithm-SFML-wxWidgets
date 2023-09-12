project(ASKII)
add_library(askii ASKII.hpp ASKII.cpp)

find_package(SFML 2.6 COMPONENTS graphics audio system REQUIRED)

target_link_libraries(askii PUBLIC 
                    sfml-graphics sfml-audio)
target_include_directories(askii PUBLIC "${CMAKE_SOURCE_DIR}/src/")