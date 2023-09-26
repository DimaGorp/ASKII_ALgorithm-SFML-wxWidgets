project(ASKII)
add_library(askii_lib ASKII.hpp ASKII.cpp)

target_link_libraries(askii_lib PUBLIC 
                    sfml-graphics sfml-audio)
target_include_directories(askii_lib PUBLIC "${CMAKE_SOURCE_DIR}/src/")