#ifndef IMGUIWIDGET_H
#define IMGUIWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLExtraFunctions>

class ImGuiWidget : public QOpenGLWidget, QOpenGLExtraFunctions
{
public:
    ImGuiWidget(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
};

#endif // IMGUIWIDGET_H
