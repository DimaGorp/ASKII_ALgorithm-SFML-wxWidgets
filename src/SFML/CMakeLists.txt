include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_library(ASKII src/ASKII/ASKII.hpp src/ASKII/ASKII.cpp)
add_library(include INTERFACE src/includes.h)



target_link_libraries(include INTERFACE sfml-graphics)

target_compile_features(include INTERFACE cxx_std_17)
target_compile_features(ASKII PUBLIC cxx_std_17)


target_include_directories(ASKII PUBLIC 
                                        "src/") 
                                                                                                            
target_link_libraries(ASKII PUBLIC include)