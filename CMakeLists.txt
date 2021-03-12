# minimum require
cmake_minimum_required (VERSION 3.8.1)

# global solution
project(qtimgui_sln)

# goto subs
add_subdirectory(examples)
add_subdirectory(modules)
add_subdirectory(src)

# global
# set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTORCC ON)
# set(CMAKE_AUTOUIC ON)
# find_package(Qt5 COMPONENTS Core Quick Gui Widgets Svg REQUIRED)
