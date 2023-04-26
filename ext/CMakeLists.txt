include(FetchContent)

FetchContent_Declare(wxWidgets
    GIT_REPOSITORY https://github.com/wxWidgets/wxWidgets.git
    GIT_TAG v3.2.2.1
)

FetchContent_MakeAvailable(wxWidgets)
