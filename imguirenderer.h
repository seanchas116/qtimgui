#pragma once

#include <QOpenGLExtraFunctions>
#include <QObject>
#include <imgui.h>

class QMouseEvent;
class QWheelEvent;
class QKeyEvent;

namespace QtImGui {

class ImGuiRenderer : public QObject, QOpenGLExtraFunctions {
    Q_OBJECT
public:
    void initialize(QWidget *window);
    void newFrame();

    QWidget *window() const { return m_window; }

    bool eventFilter(QObject *watched, QEvent *event);

    static ImGuiRenderer *instance();

private:
    ImGuiRenderer() {}

    void onMousePressedChange(QMouseEvent *event);
    void onWheel(QWheelEvent *event);
    void onKeyPressRelease(QKeyEvent *event);

    void renderDrawList(ImDrawData *draw_data);
    bool createFontsTexture();
    bool createDeviceObjects();

    QWidget *m_window;
    double       g_Time = 0.0f;
    bool         g_MousePressed[3] = { false, false, false };
    float        g_MouseWheel = 0.0f;
    GLuint       g_FontTexture = 0;
    int          g_ShaderHandle = 0, g_VertHandle = 0, g_FragHandle = 0;
    int          g_AttribLocationTex = 0, g_AttribLocationProjMtx = 0;
    int          g_AttribLocationPosition = 0, g_AttribLocationUV = 0, g_AttribLocationColor = 0;
    unsigned int g_VboHandle = 0, g_VaoHandle = 0, g_ElementsHandle = 0;
};

void initialize(QWidget *window);
void newFrame();

}
