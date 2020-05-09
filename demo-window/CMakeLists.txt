add_executable(
  qt_imgui_demo_window
  demo-window.cpp
)
target_link_libraries(qt_imgui_demo_window 
  PRIVATE 
  qt_imgui_quick
)
