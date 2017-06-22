#include "demowidget.h"
#include <QApplication>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DemoWidget w;
    w.show();
    QTimer timer;
    QObject::connect(&timer, SIGNAL(timeout()), &w, SLOT(update()));
    timer.start();

    return a.exec();
}
