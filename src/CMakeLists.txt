project(ASKII)

add_subdirectory(SFML/)


set(image ${CMAKE_SOURCE_DIR}/refs/)
set(textfile ${CMAKE_SOURCE_DIR}/refs/)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Directories.h.in ${CMAKE_CURRENT_SOURCE_DIR}/DIRS.h)

add_library(Window ${CMAKE_CURRENT_SOURCE_DIR}/Window/Window.hpp ${CMAKE_CURRENT_SOURCE_DIR}/Window/Window.cpp)

add_library(ScrImage ${CMAKE_CURRENT_SOURCE_DIR}/Window/Components/ScrolledImage.hpp ${CMAKE_CURRENT_SOURCE_DIR}/Window/Components/ScrolledImage.cpp)

target_link_libraries(Window PUBLIC wx::net wx::core wx::base wx::stc)
target_link_libraries(Window PUBLIC askii)

target_link_libraries(ScrImage PUBLIC wx::net wx::core wx::base)

target_link_libraries(Window PUBLIC ScrImage)

target_include_directories(Window PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(ScrImage PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Window/)
