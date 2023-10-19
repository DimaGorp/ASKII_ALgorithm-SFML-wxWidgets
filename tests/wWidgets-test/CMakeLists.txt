cmake_minimum_required(VERSION 3.12)

project(test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/help.h.in ${CMAKE_CURRENT_SOURCE_DIR}/src/help.h)
set(CMAKE_CONFIGURATION_TYPES "Release" CACHE STRING "" FORCE) 
include(${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake)

find_package(wxWidgets CONFIG REQUIRED)

if(WIN32)
	set(EXECUTABLE_TYPE WIN32)
endif(WIN32)
if(APPLE)
	set(MACOSX_BUNDLE YES)
	set(EXECUTABLE_TYPE MACOSX_BUNDLE)
endif(APPLE)
if(LINUX)
	set(EXECUTABLE_TYPE "")
endif(LINUX)

add_executable(test ${EXECUTABLE_TYPE} src/main.cpp)
target_link_libraries(test PRIVATE wx::core wx::base )






