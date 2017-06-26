# qt-opengl-imgui

Qt (QOpenGLWidget) backend for [ImGui](https://github.com/ocornut/imgui)

## How to use

* Add `qtimgui.cpp` and `qtimgui.h` to your project
* Add ImGui to your project
* Subclass `QOpenGLWidget` and:

```cpp
class DemoWindow : public QOpenGLWidget
{
protected:
    void initializeGL() override
    {
        QtImGui::initialize(this);
    }
    void paintGL() override
    {
        QtImGui::newFrame();
        ImGui::Text("Hello");
        ImGui::Render();
    }
};
```
