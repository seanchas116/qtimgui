QT       += core gui widgets
TARGET = demo-widget
TEMPLATE = app

include(../../qtimgui.pri)

SOURCES += \
    ../../modules/implot/implot.cpp \
    ../../modules/implot/implot_demo.cpp \
    ../../modules/implot/implot_items.cpp \
    demo-widget.cpp
