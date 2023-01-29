project(video)
add_library(video SHARED
    videotools.h
    videotools.cpp
    formvideo.h formvideo.cpp formvideo.ui
)
target_link_libraries(video PRIVATE Qt6::Core Qt6::Widgets)
target_include_directories(video INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
