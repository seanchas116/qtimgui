
SOURCES += \
    $$PWD/src/imgui/imgui_draw.cpp \
    $$PWD/src/imgui/imgui.cpp \
    $$PWD/src/imgui/imgui_demo.cpp \
    $$PWD/src/imgui/imgui_widgets.cpp \
    $$PWD/src/ImGuiRenderer.cpp \
    $$PWD/src/QtImGui.cpp

INCLUDEPATH += $$PWD/modules/imgui $$PWD/modules/implot $$PWD/src

HEADERS += \
    $$PWD/src/ImGuiRenderer.h \
    $$PWD/src/QtImGui.h
