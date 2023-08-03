#find_package(wxWidgets REQUIRED gl core base OPTIONAL_COMPONENTS net)
#find_package(SFML 2.5.1 COMPONENTS graphics window system REQUIRED)
#include(${wxWidgets_USE_FILE})

add_subdirectory(SFML)



set(image ${CMAKE_CURRENT_SOURCE_DIR})
set(textfile ${CMAKE_CURRENT_SOURCE_DIR}/SFML/ASKII)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Directories.h.in ${CMAKE_CURRENT_SOURCE_DIR}/DIRS.h)

add_library(Window ${CMAKE_CURRENT_SOURCE_DIR}/Window/Window.hpp ${CMAKE_CURRENT_SOURCE_DIR}/Window/Window.cpp)

add_library(Settings ${CMAKE_CURRENT_SOURCE_DIR}/Window/Settings/Settings.hpp ${CMAKE_CURRENT_SOURCE_DIR}/Window/Settings/Settings.cpp)

target_link_libraries(Window PUBLIC wx::net wx::core wx::base)
target_link_libraries(Window PUBLIC ASKII_alg)

target_link_libraries(Settings PUBLIC wx::net wx::core wx::base)

target_link_libraries(Window PUBLIC Settings)

target_include_directories(Window PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(Settings PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Window/)
