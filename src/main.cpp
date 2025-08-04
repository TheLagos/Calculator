#include "mainwindow.h"
#include "unit_tests.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    CalculatorTests t;
    t.runAllTests();

    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, &w, [&]() {
        bool current = w.isLightTheme();
        if (current != w.get_theme()) {
            w.set_theme(current);
        }
    });
    timer.start(2000);

    return a.exec();
}
