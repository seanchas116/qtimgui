QT       += core gui widgets
TARGET = demo-window
TEMPLATE = app

SOURCES += \
    ../imgui/imgui_draw.cpp \
    ../imgui/imgui.cpp \
    ../imgui/imgui_demo.cpp \
    ../ImGuiRenderer.cpp \
    ../QtImGui.cpp \
    demo-window.cpp

INCLUDEPATH += ../imgui ..

HEADERS += \
    ../ImGuiRenderer.h \
    ../QtImGui.h
