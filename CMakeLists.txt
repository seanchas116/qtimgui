# minimum require
cmake_minimum_required (VERSION 3.8.1)

# build option in msvc
if (CMAKE_GENERATOR MATCHES "Visual Studio")
    option(QTIMGUI_LINK_MD "if link type is MD/MDd" ON)
    message(STATUS "Using Visual Studio compiler.")
    if (NOT QTIMGUI_LINK_MD)
        set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
        set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
        message(STATUS "Link type is set to MT/MTd")
    else()
        set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD")
        set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MDd")
        message(STATUS "Link type is set to MD/MDd")
    endif()
endif()

# global solution
project(qtimgui_sln)

# goto subs
add_subdirectory(examples)
add_subdirectory(modules)
add_subdirectory(src)
