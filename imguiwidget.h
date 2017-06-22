#ifndef IMGUIWIDGET_H
#define IMGUIWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLExtraFunctions>

class ImGuiWidget : public QOpenGLWidget, QOpenGLExtraFunctions
{
public:
    ImGuiWidget(QWidget *parent = nullptr);

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
};

#endif // IMGUIWIDGET_H
