cmake_minimum_required(VERSION 3.2.1)

project(test)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

configure_file("${CMAKE_CURRENT_SOURCE_DIR}/src/help.h.in" "${CMAKE_CURRENT_SOURCE_DIR}/src/help.h")

add_subdirectory(src)
list(APPEND EXTRA_LIBS wxbase wxcore wxnet)
list(APPEND EXTRA_INCLUDES ${wxWindgets_USE_FILE})

option(USE_MATH "Math library" ON)
if(USE_MATH)
    add_subdirectory(src/math/)
    list(APPEND EXTRA_LIBS math)
endif()


add_library(compiled_flags INTERFACE)
target_compile_features(compiled_flags INTERFACE cxx_std_11)

add_executable(RUN src/main.cpp)

target_link_libraries(RUN PUBLIC ${EXTRA_LIBS})

