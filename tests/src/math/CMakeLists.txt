add_library(math INTERFACE math.hpp)

target_link_libraries(math INTERFACE compiled_flags)

target_include_directories(math INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})