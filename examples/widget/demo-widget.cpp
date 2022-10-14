#include <QGridLayout>
#include <QtImGui.h>
#include <imgui.h>
#include <QApplication>
#include <QTimer>
#include <QSurfaceFormat>
#include <QOpenGLWidget>
#include <QOpenGLExtraFunctions>
#include <implot.h>

class DemoWidget : public QOpenGLWidget, private QOpenGLExtraFunctions
{

protected:
    void initializeGL() override
    {
        initializeOpenGLFunctions();
        ref = QtImGui::initialize(this,false);
        // Update at 60 fps
        QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(update()));
        timer.start(16);
        im_context = ImPlot::CreateContext();
    }


    void paintGL() override
    {
        QtImGui::newFrame(ref);
        //ImGui::GetIO().BackendFlags = ImGui::GetIO().BackendFlags | ImGuiBackendFlags_RendererHasVtxOffset;
        //auto test =(ImGui::GetIO().BackendFlags & ImGuiBackendFlags_RendererHasVtxOffset);

        // 1. Show a simple window
        // Tip: if we don't call ImGui::Begin()/ImGui::End() the widgets appears in a window automatically called "Debug"
        {
            static float f = 0.0f;
            ImGui::Text("Hello, world!");
            ImGui::SliderFloat("float", &f, 0.0f, 1.0f);
            ImGui::ColorEdit3("clear color", (float*)&clear_color);
            if (ImGui::Button("ImGui Demo")) show_imgui_demo_window ^= 1;
            if (ImGui::Button("ImPlot Demo")) show_implot_demo_window ^= 1;
            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        }

        // 2. Show another simple window, this time using an explicit Begin/End pair
        if (show_imgui_demo_window)
        {
            ImGui::SetNextWindowSize(ImVec2(200,100), ImGuiCond_FirstUseEver);
            ImGui::ShowDemoWindow(&show_imgui_demo_window);
        }

        // 3. Show the ImGui test window. Most of the sample code is in ImGui::ShowTestWindow()
        if (show_implot_demo_window)
        {
            ImGui::SetNextWindowPos(ImVec2(650, 20), ImGuiCond_FirstUseEver);
            ImPlot::SetCurrentContext(im_context);
            ImPlot::ShowDemoWindow(&show_implot_demo_window);
        }

        // Do render before ImGui UI is rendered
        glViewport(0, 0, width(), height());
        glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui::Render();
        QtImGui::render(ref);
    }

private:
    bool show_imgui_demo_window = true;
    bool show_implot_demo_window = false;
    ImVec4 clear_color = ImColor(114, 144, 154);
    ImPlotContext * im_context;
    QtImGui::RenderRef ref         = nullptr;
    QTimer  timer{this};

};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Use OpenGL 3 Core Profile, when available
    QSurfaceFormat glFormat;
    if (QOpenGLContext::openGLModuleType() == QOpenGLContext::LibGL) {
        glFormat.setVersion(3, 3);
        glFormat.setProfile(QSurfaceFormat::CoreProfile);
    }
    QSurfaceFormat::setDefaultFormat(glFormat);

    // Show window
    DemoWidget *widget=new DemoWidget();
    widget->setWindowTitle("QtImGui widget example");
    QWidget* window=new QWidget();
    auto* l = new QGridLayout();
    window->setLayout(l);
    l->addWidget(widget, 0, 0);
    window->resize(1280, 720);
    window->show();
    // Update at 60 fps
    QTimer timer;
    QObject::connect(&timer, SIGNAL(timeout()), widget, SLOT(update()));
    timer.start(16);

    return a.exec();
}
