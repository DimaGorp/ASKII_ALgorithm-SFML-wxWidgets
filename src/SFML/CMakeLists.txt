project(ASKII)
add_library(askii ASKII.hpp ASKII.cpp)

target_link_libraries(askii PUBLIC 
                    sfml-graphics sfml-audio)
target_include_directories(askii PUBLIC "${CMAKE_SOURCE_DIR}/src/")