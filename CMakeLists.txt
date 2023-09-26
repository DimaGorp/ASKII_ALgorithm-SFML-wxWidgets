cmake_minimum_required(VERSION 3.0)

project(ASKII)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_subdirectory("ext/")
add_subdirectory("src/")

include(FetchContent)
FetchContent_MakeAvailable(wxWidgets)
list(APPEND LIBS wx::net wx::core wx::base)
list(APPEND LIBS sfml-graphics sfml-audio)
list(APPEND LIBS Window)
list(APPEND LIBS askii_lib)
list(APPEND DIRS ${CMAKE_CURRENT_SOURCE_DIR}/src/)


add_executable(ASKII main.cpp)


target_include_directories(ASKII PUBLIC ${DIRS})
target_link_libraries(ASKII PRIVATE ${LIBS})