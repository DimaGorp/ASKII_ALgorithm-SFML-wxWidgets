cmake_minimum_required(VERSION 3.0)

project(ASKII)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

#find_package(wxWidgets REQUIRED gl core base OPTIONAL_COMPONENTS net)

#include(${wxWidgets_USE_FILE})

#find_package(SFML 2.5.1 COMPONENTS graphics window system REQUIRED)
add_subdirectory("ext/wxWidgets")
add_subdirectory("src/")


list(APPEND LIBS wx::net wx::core wx::base)
list(APPEND LIBS ${CMAKE_SOURCE_DIR}/ext/SFML2/lib/libsfml-audio.2.6.0.dylib)
list(APPEND LIBS ${CMAKE_SOURCE_DIR}/ext/SFML2/lib/libsfml-graphics.2.6.0.dylib)
list(APPEND LIBS ${CMAKE_SOURCE_DIR}/ext/SFML2/lib/libsfml-system.2.6.0.dylib)
list(APPEND LIBS ${CMAKE_SOURCE_DIR}/ext/SFML2/lib/libsfml-window.2.6.0.dylib)
list(APPEND LIBS Window)
list(APPEND LIBS Settings)
list(APPEND DIRS ${CMAKE_CURRENT_SOURCE_DIR}/src/)




add_executable(ASKII main.cpp)


target_include_directories(ASKII PUBLIC ${DIRS})
target_link_libraries(ASKII PUBLIC ${LIBS})