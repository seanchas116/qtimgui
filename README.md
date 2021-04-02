# QtImGui

Qt (QOpenGLWidget / QOpenGLWindow) backend for [ImGui](https://github.com/ocornut/imgui)

It enables ImGui to run in QOpenGLWidget / QOpenGLWindow.

[![https://gyazo.com/eb68699c96b9147cca3d5ea9fadfc263](https://i.gyazo.com/eb68699c96b9147cca3d5ea9fadfc263.gif)](https://gyazo.com/eb68699c96b9147cca3d5ea9fadfc263)

## How to use

* Add QtImGui sources and headers to your project
  * If you are using git submodule, run `git submodule update --init --recursive` to ensure that the inner submodule is initialized as well.
* CMake:
  * Add `add_subdirectory(path/to/qtimgui)` to your `CMakeLists.txt` file
  * Link `qt_imgui_quick` (for Qt Quick apps or apps that don't use QOpenGLWidget) or `qt_imgui_widget` (for apps using QOpenGLWidget)
* qmake:
  * Add `include(path/to/qtimgui/qtimgui.pri)` to your `.pro` file
* Subclass `QOpenGLWindow` or `QOpenGLWidget` and:

```cpp
class DemoWindow : public QOpenGLWindow
{
protected:
    void initializeGL() override
    {
        QtImGui::initialize(this);
    }
    void paintGL() override
    {
        // you can do custom GL rendering as well in paintGL

        QtImGui::newFrame();

        ImGui::Text("Hello");
        // more widgets...

        ImGui::Render();
        QtImGui::render();
    }
};
```

See [QOpenGLWidget example](examples/widget) and [QOpenGLWindow example](examples/window) for details.

## Specific notes for Android, when using cmake

Two projects are provided: `qtimgui.pro` and `CMakeLists.txt`.

When using CMake under Android, this project will uses [qt-android-cmake](https://github.com/LaurentGomila/qt-android-cmake), which is a CMake utility for building and deploying Qt based applications on Android without Qt Creator.

*In order to successfuly deploy the app to a device, the cmake variable `ANDROID_NATIVE_API_LEVEL` should elevated to 21 or 26 (depending on the native levels installed in your android sdk)
 You will need to set it via the CMake command line, or inside Qt Creator (in the project view).*

