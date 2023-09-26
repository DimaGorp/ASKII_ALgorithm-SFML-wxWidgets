project(ASKII)

add_subdirectory("SFML/")

set(image ${CMAKE_SOURCE_DIR}/refs/)
set(textfile ${CMAKE_SOURCE_DIR}/refs/)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Directories.h.in ${CMAKE_CURRENT_SOURCE_DIR}/DIRS.h)

add_library(Window ${CMAKE_CURRENT_SOURCE_DIR}/Window/Window.hpp ${CMAKE_CURRENT_SOURCE_DIR}/Window/Window.cpp)

target_link_libraries(Window PUBLIC wx::net wx::core wx::base wx::stc
                        sfml-graphics sfml-system)
target_include_directories(Window PUBLIC ${wxWidgets_SOURCE_DIR}/include)
target_link_libraries(Window PUBLIC askii_lib)

target_include_directories(Window PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
