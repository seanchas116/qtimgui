#pragma once

#include <QOpenGLExtraFunctions>
#include <QObject>
#include <QPoint>
#include <imgui.h>

#ifdef IMGUI_VERSION_NUM
    #if IMGUI_VERSION_NUM < 18700
       #error only ImGUI v1.87 or higer is supported see https://github.com/ocornut/imgui/releases/tag/v1.87
    #endif
#else
    #error Unknow version of ImGUI
#endif

#include <memory>

class QMouseEvent;
class QWheelEvent;
class QKeyEvent;

namespace QtImGui {

class WindowWrapper {
public:
    virtual ~WindowWrapper() {}
    virtual void installEventFilter(QObject *object) = 0;
    virtual QSize size() const = 0;
    virtual qreal devicePixelRatio() const = 0;
    virtual bool isActive() const = 0;
    virtual QPoint mapFromGlobal(const QPoint &p) const = 0;
    virtual QPointF mapToGlobal(const QPointF& pos) const = 0;
    virtual QObject* object() = 0;    
    virtual void setCursorShape(Qt::CursorShape shape) = 0;
    virtual void setCursorPos(const QPoint& local_pos) = 0;   
    virtual WId nativeHandle() const = 0;
    virtual void setMouseTracking(bool on) = 0;
};

class ImGuiRenderer : public QObject, QOpenGLExtraFunctions {
    Q_OBJECT
public:
    void initialize(WindowWrapper *window);
    void newFrame();
    void render();
    bool eventFilter(QObject *watched, QEvent *event);

    static ImGuiRenderer *instance();

public:
    ImGuiRenderer();
    ~ImGuiRenderer();

private:
    void onMouseMove(QMouseEvent* event);
    void onMouseLeave();
    void onMousePressed(QMouseEvent* event);
    void onMouseReleased(QMouseEvent* event);
    void onWheel(QWheelEvent *event);
    void onKeyPressRelease(QKeyEvent *event);    
    void updateCursorShape(const ImGuiIO &io);   
    void renderDrawList(ImDrawData *draw_data);
    bool createFontsTexture();
    bool createDeviceObjects();
    int  mouseEventToImGuiMouseButton(QMouseEvent *event);

    std::unique_ptr<WindowWrapper> m_window;
    double       g_Time = 0.0f;
    GLuint       g_FontTexture = 0;
    int          g_ShaderHandle = 0, g_VertHandle = 0, g_FragHandle = 0;
    int          g_AttribLocationTex = 0, g_AttribLocationProjMtx = 0;
    int          g_AttribLocationPosition = 0, g_AttribLocationUV = 0, g_AttribLocationColor = 0;
    unsigned int g_VboHandle = 0, g_VaoHandle = 0, g_ElementsHandle = 0;    

    // Members to track mouse events to be pushed to ImGUI (pretty much like win32 backend data)
    bool MouseTracked{ false };
    // Mouse position, in pixels. Set to ImVec2(-FLT_MAX, -FLT_MAX) if mouse is unavailable (on another screen, etc.)
    ImVec2           MousePos{ -FLT_MAX, -FLT_MAX };
    ImGuiMouseCursor LastMouseCursor = ImGuiMouseCursor_COUNT;
    // Mouse buttons: 0=left, 1=right, 2=middle + extras (ImGuiMouseButton_COUNT == 5).
    // Dear ImGui mostly uses left and right buttons. Others buttons allows us to track if the mouse is being used by your application + available to user as a convenience via IsMouse** API.
    ImGuiMouseButton LastMouseButton = 0;
    bool             MouseDown { false};

    ImGuiContext*    g_ctx = nullptr;
};

} // namespace QtImGui
