cmake_minimum_required(VERSION 3.5.1)
project(Frame_Buffer)

set(CMAKE_CXX_STANDARD 14)
SET(GCC_COVERAGE_COMPILE_FLAGS "-std=c++11 -pthread")

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

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
        factory/rectangle_factory.cpp drawable/dot.cpp factory/dot_factory.cpp factory/dot_factory.h drawable/group_object.cpp drawable/group_object.h factory/group_factory.cpp factory/group_factory.h scene/base_scene.h event/base_event.h scene/menu_scene.cpp scene/menu_scene.h event/keyboard_event.h event_dispatcher/base_dispatcher.h controller/main_controller.h event_dispatcher/keyboard_dispatcher.cpp event_dispatcher/keyboard_dispatcher.h 
        scene/first_scene.cpp scene/first_scene.h 
        scene/second_scene.cpp scene/second_scene.h
        scene/third_scene.cpp scene/third_scene.h
        scene/fourth_scene.cpp scene/fourth_scene.h
        scene/seventh_scene.cpp scene/seventh_scene.h
        )

target_link_libraries(Frame_Buffer ${CURSES_LIBRARIES})