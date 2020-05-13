# QtImGui

Qt (QOpenGLWidget / QOpenGLWindow) backend for [ImGui](https://github.com/ocornut/imgui)

It enables ImGui to run in QOpenGLWidget / QOpenGLWindow.

[![https://gyazo.com/eb68699c96b9147cca3d5ea9fadfc263](https://i.gyazo.com/eb68699c96b9147cca3d5ea9fadfc263.gif)](https://gyazo.com/eb68699c96b9147cca3d5ea9fadfc263)

## How to use

### By subclassing QOpenGLWindow or QOpenGlWidget
* Add QtImGui sources and headers to your project
    * If you are using git submodule, run `git submodule update --init --recursive` to ensure that the inner submodules are initialized as well.
* Add `include(path/to/qtimgui.pri)` to youre `.pro` file
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
    }
};
```

See [QOpenGLWidget example](demo-widget/demo-widget.cpp) and [QOpenGLWindow example](/demo-window/demo-window.cpp) for details.

### By using QtImGuiRunner (and cmake) 

QtImGuiRunner enables you to write an app with *very few* lines of code, by simply registering 
a gui loop function or lambda: 
![aa](https://i.gyazo.com/95a925b8c3c8e4e96a7c8a092097bd2e.gif)

To use it:
1. Adapt this [CMakeLists](demo-runner/CMakeLists.txt) to your needs
2. Create a gui loop function and [pass it to QtImGuiRunner::Run()](demo-runner-minimal/demo-runner-minimal.cpp)

See [demo-runner](demo-runner) and [demo-runner-minimal](demo-runner-minimal) for more details.

## Specific notes for Android, when using cmake

Two projects are provided: `qtimgui.pro` and `CMakaLists.txt`.

When using cmake under Android, this project will uses [qt-android-cmake](https://github.com/LaurentGomila/qt-android-cmake), which is a CMake utility for building and deploying Qt based applications on Android without QtCreator.

*In order to successfuly deploy the app to a device, the cmake variable ANDROID_NATIVE_API_LEVEL should be >= 26.
 You will need to set it via the cmake command line, or inside Qt Creator (in the project view).*

