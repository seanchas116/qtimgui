
# Add Dear ImGui sources (QtImGui depends on it)
SOURCES += \
    $$PWD/modules/imgui/imgui_draw.cpp \
    $$PWD/modules/imgui/imgui.cpp \
    $$PWD/modules/imgui/imgui_demo.cpp \
    $$PWD/modules/imgui/imgui_widgets.cpp \
    $$PWD/modules/imgui/imgui_tables.cpp \
    $$PWD/modules/implot/implot.cpp \
    $$PWD/modules/implot/implot_demo.cpp \
    $$PWD/modules/implot/implot_items.cpp

INCLUDEPATH += \
    $$PWD/modules/imgui \
    $$PWD/modules/implot \
    $$PWD/src

HEADERS += \
    $$PWD/src/ImGuiRenderer.h \
    $$PWD/src/QtImGui.h

SOURCES += \
    $$PWD/src/ImGuiRenderer.cpp \
    $$PWD/src/QtImGui.cpp
