QT       += core gui opengl
TARGET = demo-window
TEMPLATE = app

DEFINES += _AMD64_

include(../../qtimgui.pri)
include(../../glad/glad.pri)

SOURCES += \
    demo-window.cpp

LIBS += \
	-lopengl32
