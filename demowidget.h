#pragma once

#include "imguiwidget.h"
#include <QOpenGLExtraFunctions>
#include <imgui.h>

class DemoWidget : public QtImGui::ImGuiWidget, private QOpenGLExtraFunctions
{
    Q_OBJECT
public:
    explicit DemoWidget(QWidget *parent = nullptr);

signals:

public slots:

protected:
    void initializeGL() override;
    void paintGL() override;

private:
    bool show_test_window = true;
    bool show_another_window = false;
    ImVec4 clear_color = ImColor(114, 144, 154);
};
