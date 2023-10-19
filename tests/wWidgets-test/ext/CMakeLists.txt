
project(test)
include(${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake)
#file(GLOB_RECURSE WX_FILE "${CMAKE_BINARY_DIR}/wxWidgetsConfig.cmake")
#get_filename_component(WX_PATH ${WX_FILE} DIRECTORY)
set(wxWidgets_DIR "${wxWidgets_ROOT_DIR}" CACHE PATH "" FORCE)

#file(GLOB_RECURSE NANO_FILE "${CMAKE_BINARY_DIR}/NanoSVGConfig.cmake")
#get_filename_component(NANO_PATH ${NANO_FILE} DIRECTORY)
#set(NanoSVG_DIR "${NANO_PATH}" CACHE PATH "" FORCE)