cmake_minimum_required(VERSION 3.5)

project(vehicle2022 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets WebChannel)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets WebChannel)
#find_package(QT Qt6 REQUIRED COMPONENTS WebEngineWidgets)
set(PROJECT_SOURCES
        main.cpp
        home.cpp
        home.h
        widget.ui
        test.h test.cpp
        formtest.h formtest.cpp formtest.ui
        ResourceFile.qrc
)
# 类库定义和类库cmakeLists.txt文件呼应
add_subdirectory(video)
#include_directories(./video)
add_subdirectory(map)
#include_directories(./map)

# 设置ffmpeg依赖库及头文件所在目录，并存进指定变量
# 兼容路径问题 begin 原因待接?,强指定代替 include_directories(./map)，估计和cmake环境有问题，用include_directories引入会找不到头文件错误
set(ffmpeg_libs_DIR ${CMAKE_CURRENT_SOURCE_DIR}/video/ffmpeg/ffmpeg4/winlib64)
set(ffmpeg_headers_DIR ${CMAKE_CURRENT_SOURCE_DIR}/video/ffmpeg/ffmpeg4/include64)
file(GLOB ffmpeg_dylibs ${ffmpeg_libs_DIR}/*.lib)
include_directories(${ffmpeg_headers_DIR})
# 兼容路径问题 end

#资源文件设置
#qt_add_resources(vehicle2022 "ResourceFile"
#    PREFIX "/img"
#    FILES
#        /images/btn_close.png
#        /images/btn_ok.png
#)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(vehicle2022
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        ResourceFile.qrc
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET vehicle2022 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(vehicle2022 SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(vehicle2022
            ${PROJECT_SOURCES}
        )
    endif()
endif()

#引用库及自定义库设置
target_link_libraries(vehicle2022 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets video map Qt6::WebChannel)

set_target_properties(vehicle2022 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)


install(TARGETS vehicle2022
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(vehicle2022)
endif()
