project(ASKII)

add_subdirectory("SFML/")
set(image ${CMAKE_SOURCE_DIR}/refs/)
set(textfile ${CMAKE_SOURCE_DIR}/refs/)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Directories.h.in ${CMAKE_CURRENT_SOURCE_DIR}/DIRS.h)

add_library(Window ${CMAKE_CURRENT_SOURCE_DIR}/Window/Window.hpp ${CMAKE_CURRENT_SOURCE_DIR}/Window/Window.cpp)
add_library(SrcImage ${CMAKE_CURRENT_SOURCE_DIR}/Components/Scroll_Image.hpp ${CMAKE_CURRENT_SOURCE_DIR}/Components/Scroll_Image.cpp)
target_link_libraries(Window PRIVATE
                        sfml-graphics sfml-system)
target_link_libraries(Window PUBLIC askii_lib SrcImage)

target_include_directories(Window PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Window/ 
                                            ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(SrcImage PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Components/
                                            ${CMAKE_CURRENT_SOURCE_DIR})