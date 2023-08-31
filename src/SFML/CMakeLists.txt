set(CMAKE_OSX_ARCHITECTURES "x86_64" CACHE STRING "Architecture" FORCE)
add_library(ASKII_alg ASKII/ASKII2.hpp ASKII/ASKII2.cpp)
                                                                                                            
target_link_libraries(ASKII_alg PUBLIC ${CMAKE_SOURCE_DIR}/ext/SFML2/lib/libsfml-audio.2.6.0.dylib
                                        ${CMAKE_SOURCE_DIR}/ext/SFML2/lib/libsfml-graphics.2.6.0.dylib
                                        ${CMAKE_SOURCE_DIR}/ext/SFML2/lib/libsfml-system.2.6.0.dylib
                                        ${CMAKE_SOURCE_DIR}/ext/SFML2/lib/libsfml-window.2.6.0.dylib)
#target_compile_features(ASKII_alg PUBLIC cxx_std_17)
target_include_directories(ASKII_alg PUBLIC ${CMAKE_SOURCE_DIR}/ext/SFML2/include/
                                            ${CMAKE_SOURCE_DIR}/src/SFML    
                                            ${CMAKE_SOURCE_DIR}/src/) 