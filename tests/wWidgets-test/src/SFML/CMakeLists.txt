project(test)
add_library(ASKII ASKII.hpp ASKII.cpp)

find_package(SFML 2.6 COMPONENTS graphics audio system REQUIRED)

target_link_libraries(ASKII PUBLIC 
                    sfml-graphics sfml-audio)
target_include_directories(ASKII PUBLIC "${CMAKE_SOURCE_DIR}/src/")