#include "QtImGui.h"
#include "ImGuiRenderer.h"

namespace QtImGui {

void initialize(QWidget *window) {
    ImGuiRenderer::instance()->initialize(window);
}

void newFrame() {
    ImGuiRenderer::instance()->newFrame();
}

}
