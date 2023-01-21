project(video)
add_library(video SHARED
    videotools.h
    videotools.cpp
)
target_link_libraries(video PRIVATE Qt6::Core)
target_include_directories(video INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
