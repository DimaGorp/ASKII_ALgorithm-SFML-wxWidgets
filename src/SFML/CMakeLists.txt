#set(CMAKE_OSX_ARCHITECTURES "x86_64;arm64" CACHE STRING "Architecture" FORCE)
find_package(SFML 2.5.1 COMPONENTS graphics window system REQUIRED)
add_library(ASKII_alg ASKII/ASKII.hpp ASKII/ASKII.cpp)
#add_library(include INTERFACE includes.h)



#target_link_libraries(include INTERFACE "sfml-graphics")

#target_compile_features(include INTERFACE cxx_std_17)


                                                                                                            
target_link_libraries(ASKII_alg PUBLIC "sfml-graphics")
target_compile_features(ASKII_alg PUBLIC cxx_std_17)
target_include_directories(ASKII_alg PUBLIC ${CMAKE_SOURCE_DIR}/src/SFML) 