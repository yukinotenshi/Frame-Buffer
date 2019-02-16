cmake_minimum_required(VERSION 3.5.1)
project(Frame_Buffer)

set(CMAKE_CXX_STANDARD 14)

add_executable(Frame_Buffer
        main.cpp
        core/canvas.cpp
        core/point.cpp
        drawable/line.cpp
        drawable/drawable.h
        core/color.cpp
        drawable/polygon.cpp
        drawable/circle.cpp
        factory/line_factory.cpp
        factory/base_factory.h
        factory/circle_factory.cpp
        factory/polygon_factory.cpp
        core/view.cpp
        drawable/rectangle.h
        factory/rectangle_factory.cpp)