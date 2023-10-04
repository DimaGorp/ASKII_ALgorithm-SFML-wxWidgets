project(test)


include(${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake)

find_package(OpenGL GLOBAL)
find_package(wxWidgets CONFIG REQUIRED GLOBAL)

include_directories(${wxWidgets_USE_FILE})