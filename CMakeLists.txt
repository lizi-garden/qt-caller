cmake_minimum_required(VERSION 3.10)

project(qt-caller)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(qtCaller main.cpp widget.cpp widget.h)

target_link_libraries(qtCaller PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
