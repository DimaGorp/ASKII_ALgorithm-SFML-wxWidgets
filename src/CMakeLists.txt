project(ASKII)

add_subdirectory(SFML/)


set(image ${CMAKE_SOURCE_DIR}/refs/)
set(textfile ${CMAKE_SOURCE_DIR}/refs/)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Directories.h.in ${CMAKE_CURRENT_SOURCE_DIR}/DIRS.h)

add_library(Window ${CMAKE_CURRENT_SOURCE_DIR}/Window/Window.hpp ${CMAKE_CURRENT_SOURCE_DIR}/Window/Window.cpp)

#add_library(Settings ${CMAKE_CURRENT_SOURCE_DIR}/Window/Settings/Settings.hpp ${CMAKE_CURRENT_SOURCE_DIR}/Window/Settings/Settings.cpp)

target_link_libraries(Window PUBLIC wx::net wx::core wx::base)
target_link_libraries(Window PUBLIC askii)

#target_link_libraries(Settings PUBLIC wx::net wx::core wx::base)

#target_link_libraries(Window PUBLIC Settings)

target_include_directories(Window PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
#target_include_directories(Settings PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Window/)
