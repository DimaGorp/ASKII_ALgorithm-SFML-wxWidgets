cmake_minimum_required(VERSION 3.0)

project(ASKII)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_subdirectory(ext/)
find_package(wxWidgets REQUIRED gl core base OPTIONAL_COMPONENTS net)
include(${wxWidgets_USE_FILE})

list(APPEND LIBS ${wxWidgets_LIBRARIES})
list(APPEND LIBS Window)
list(APPEND DIRS ${CMAKE_CURRENT_SOURCE_DIR}/src/)
list(APPEND DIRS ${wxWidgets_USE_FILE})

add_subdirectory(src/)


add_executable(ASKII main.cpp)


target_include_directories(ASKII PUBLIC ${DIRS})
target_link_libraries(ASKII PUBLIC ${LIBS})