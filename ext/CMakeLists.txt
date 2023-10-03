project(ASKII)
include("${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake")

#set(SFML_DIR "${CMAKE_SOURCE_DIR}/vcpkg_installed/")
find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED GLOBAL )#PATHS "${CMAKE_SOURCE_DIR}/vcpkg/packages/")

#set(CMAKE_PREFIX_PATH "${wxwidgets_path}")
find_package(wxWidgets CONFIG REQUIRED GLOBAL)#PATHS "${CMAKE_SOURCE_DIR}/vcpkg/packages/")


