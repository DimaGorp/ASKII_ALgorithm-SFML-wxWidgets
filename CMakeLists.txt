cmake_minimum_required(VERSION 3.20)

project(ASKII)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CONFIGURATION_TYPES "Release" CACHE STRING "" FORCE) 
include(${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake)


find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED GLOBAL)

find_package(wxWidgets CONFIG REQUIRED)



add_subdirectory("src/")
list(APPEND wxLIBS wx::core wx::base wx::stc)
list(APPEND sfmlLIBS sfml-graphics sfml-audio)
list(APPEND LIBS Window)
list(APPEND LIBS askii_lib)
list(APPEND DIRS ${CMAKE_CURRENT_SOURCE_DIR}/src/)

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

target_link_libraries(Window PRIVATE ${wxLIBS})
target_link_libraries(SrcImage PRIVATE ${wxLIBS})

add_executable(ASKII ${EXECUTABLE_TYPE} main.cpp)

target_include_directories(ASKII PUBLIC ${DIRS})
target_link_libraries(ASKII PRIVATE ${wxLIBS} ${sfmlLIBS} ${LIBS})