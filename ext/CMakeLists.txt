project(ASKII)

include(FetchContent)

FetchContent_Declare(
    wxWidgets
    GIT_REPOSITORY https://github.com/wxWidgets/wxWidgets.git
    GIT_TAG        v3.1.4
)
FetchContent_MakeAvailable(wxWidgets)

set(CMAKE_MODULE_PATH "${CMAKE_BINARY_DIR}/")

find_package(SFML REQUIRED GLOBAL)


