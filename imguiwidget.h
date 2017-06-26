#pragma once

#include <QOpenGLWidget>

namespace QtImGui {

class ImGuiRenderer;

class ImGuiWidget : public QOpenGLWidget
{
public:
    ImGuiWidget(QWidget *parent = nullptr);
    static ImGuiWidget *instance() { return m_instance; }

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
    virtual void renderUI() = 0;

private:
    static ImGuiWidget *m_instance;
    ImGuiRenderer *m_renderer;
};

}
