#ifndef DEMOWIDGET_H
#define DEMOWIDGET_H

#include "imguiwidget.h"
#include <QOpenGLExtraFunctions>

class DemoWidget : public ImGuiWidget
{
    Q_OBJECT
public:
    explicit DemoWidget(QWidget *parent = nullptr);

signals:

public slots:

protected:
    void renderUI() override;

private:
    bool show_test_window = true;
    bool show_another_window = false;
    ImVec4 clear_color = ImColor(114, 144, 154);
};

#endif // DEMOWIDGET_H
