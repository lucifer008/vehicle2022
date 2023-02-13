project(video)
add_library(video SHARED
    videotools.h
    videotools.cpp
    formembed.h formembed.cpp formembed.ui
    formvideo.h formvideo.cpp formvideo.ui
    ffmpeghead.h
    ffmpeg.cpp
    ffmpeg.h
    videoffmpeg.h videoffmpeg.cpp videoffmpeg.ui
)

# 设置ffmpeg依赖库及头文件所在目录，并存进指定变量
set(ffmpeg_libs_DIR ${CMAKE_CURRENT_SOURCE_DIR}/ffmpeg/ffmpeg4/winlib64)
set(ffmpeg_headers_DIR ${CMAKE_CURRENT_SOURCE_DIR}/ffmpeg/ffmpeg4/include64)
file(GLOB ffmpeg_dylibs ${ffmpeg_libs_DIR}/*.lib)

include_directories(${ffmpeg_headers_DIR})
# 引入自定义头部文件/提升控件时必须引入
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
)
link_directories(${ffmpeg_libs_DIR})
target_link_libraries(video PRIVATE Qt6::Core Qt6::Widgets ${ffmpeg_dylibs})
target_include_directories(video INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
