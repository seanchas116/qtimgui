include(${CMAKE_CURRENT_SOURCE_DIR}/../cmake/qtimgui_android.cmake)
# do not put "-" in android application names (the first arg of add_imgui_app)
add_imgui_app(demo_runner demo-runner.cpp)
