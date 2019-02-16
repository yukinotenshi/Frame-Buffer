cmake_minimum_required(VERSION 3.13)
project(Frame_Buffer)

set(CMAKE_CXX_STANDARD 14)

add_executable(Frame_Buffer main.cpp core/canvas.cpp core/point.cpp drawable/line.cpp drawable/drawable.h core/color.cpp)