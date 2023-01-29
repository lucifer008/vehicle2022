project(map)
add_library(map SHARED
    map.h
    map.cpp
)

# 设置ffmpeg依赖库及头文件所在目录，并存进指定变量
#set(ffmpeg_libs_DIR ${CMAKE_CURRENT_SOURCE_DIR}/ffmpeg/ffmpeg4/winlib64)
#set(ffmpeg_headers_DIR ${CMAKE_CURRENT_SOURCE_DIR}/ffmpeg/ffmpeg4/include64)
#file(GLOB ffmpeg_dylibs ${ffmpeg_libs_DIR}/*.lib)

#include_directories(${ffmpeg_headers_DIR})
#link_directories(${ffmpeg_libs_DIR})
#target_link_libraries(video PRIVATE Qt6::Core Qt6::Widgets ${ffmpeg_dylibs})
target_link_libraries(map PRIVATE Qt6::Core Qt6::Widgets)
target_include_directories(map INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
