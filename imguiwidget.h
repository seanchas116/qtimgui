#ifndef IMGUIWIDGET_H
#define IMGUIWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLExtraFunctions>
#include <imgui.h>

class ImGuiWidget : public QOpenGLWidget, QOpenGLExtraFunctions
{
public:
    ImGuiWidget(QWidget *parent = nullptr);
    static ImGuiWidget *instance() { return m_instance; }

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
    virtual void renderUI() = 0;

private:
    double       g_Time = 0.0f;
    float        g_MousePosition[2] = { 0.0, 0.0 };
    bool         g_MousePressed[3] = { false, false, false };
    float        g_MouseWheel = 0.0f;
    GLuint       g_FontTexture = 0;
    int          g_ShaderHandle = 0, g_VertHandle = 0, g_FragHandle = 0;
    int          g_AttribLocationTex = 0, g_AttribLocationProjMtx = 0;
    int          g_AttribLocationPosition = 0, g_AttribLocationUV = 0, g_AttribLocationColor = 0;
    unsigned int g_VboHandle = 0, g_VaoHandle = 0, g_ElementsHandle = 0;

    static ImGuiWidget *m_instance;

    void renderDrawList(ImDrawData *draw_data);
    bool createFontsTexture();
    bool createDeviceObjects();
    void newFrame();
};

#endif // IMGUIWIDGET_H
