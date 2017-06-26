#include "demowidget.h"
#include <QApplication>
#include <QTimer>
#include <QSurfaceFormat>

int main(int argc, char *argv[])
{
    QSurfaceFormat glFormat;
    glFormat.setVersion(4, 1);
    glFormat.setProfile(QSurfaceFormat::CoreProfile);
    QSurfaceFormat::setDefaultFormat(glFormat);

    QApplication a(argc, argv);
    DemoWidget w;
    w.show();
    QTimer timer;
    QObject::connect(&timer, SIGNAL(timeout()), &w, SLOT(update()));
    timer.start(16);

    return a.exec();
}
