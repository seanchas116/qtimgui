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
    void paintGL() override;
    virtual void renderImGui() = 0;

private:
    static ImGuiWidget *m_instance;
    ImGuiRenderer *m_renderer;
};

}
