#ifndef IMGUIRENDERER_H
#define IMGUIRENDERER_H

#include <QOpenGLExtraFunctions>
#include <imgui.h>
#include "imguiwidget.h"

class ImGuiRenderer : QOpenGLExtraFunctions {
public:
    ImGuiRenderer(ImGuiWidget *w) : widget(w) {}

    ImGuiWidget *widget;
    double       g_Time = 0.0f;
    bool         g_MousePressed[3] = { false, false, false };
    float        g_MouseWheel = 0.0f;
    GLuint       g_FontTexture = 0;
    int          g_ShaderHandle = 0, g_VertHandle = 0, g_FragHandle = 0;
    int          g_AttribLocationTex = 0, g_AttribLocationProjMtx = 0;
    int          g_AttribLocationPosition = 0, g_AttribLocationUV = 0, g_AttribLocationColor = 0;
    unsigned int g_VboHandle = 0, g_VaoHandle = 0, g_ElementsHandle = 0;

    void initialize();

    void renderDrawList(ImDrawData *draw_data);
    bool createFontsTexture();
    bool createDeviceObjects();
    void newFrame();

    void updateMousePressed(QMouseEvent *event);
};


#endif // IMGUIRENDERER_H
