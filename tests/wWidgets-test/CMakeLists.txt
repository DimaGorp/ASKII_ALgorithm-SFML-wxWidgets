cmake_minimum_required(VERSION 3.12)

project(test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/help.h.in ${CMAKE_CURRENT_SOURCE_DIR}/src/help.h)
add_subdirectory("ext/")


add_executable(test src/main.cpp)


target_link_libraries(test PRIVATE wx::wxcore wx::wxbase wx::wxgl)#${wxWidgets_LIBRARIES})
#target_include_directories(test PRIVATE ${wxWidgets_INCLUDE_DIRS})


