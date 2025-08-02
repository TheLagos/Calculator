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

    return a.exec();
}

//додати зміну режиму, прибрати фрейм для розпишення вікна, рев'ювнути код і пописати коментарі
