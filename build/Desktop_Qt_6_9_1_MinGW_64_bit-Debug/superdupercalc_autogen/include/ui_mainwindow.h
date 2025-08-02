/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *result_line;
    QWidget *gridLayoutWidget;
    QGridLayout *buttons_grid;
    QPushButton *open_paren;
    QPushButton *result;
    QPushButton *ln;
    QPushButton *plus;
    QPushButton *one;
    QPushButton *seven;
    QPushButton *four;
    QPushButton *zero;
    QPushButton *nine;
    QPushButton *multiply;
    QPushButton *factorial;
    QPushButton *minus;
    QPushButton *eight;
    QPushButton *six;
    QPushButton *point;
    QPushButton *devide;
    QPushButton *two;
    QPushButton *sign_change;
    QPushButton *close_paren;
    QPushButton *square;
    QPushButton *five;
    QPushButton *backspace;
    QPushButton *three;
    QPushButton *clear;
    QLabel *error_line;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(245, 355);
        MainWindow->setMinimumSize(QSize(245, 355));
        MainWindow->setMaximumSize(QSize(245, 355));
        QFont font;
        font.setFamilies({QString::fromUtf8("System")});
        font.setPointSize(12);
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/window_icon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        result_line = new QLabel(centralwidget);
        result_line->setObjectName("result_line");
        result_line->setGeometry(QRect(20, 30, 201, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("System")});
        font1.setPointSize(12);
        font1.setBold(true);
        result_line->setFont(font1);
        result_line->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(10, 50, 228, 290));
        buttons_grid = new QGridLayout(gridLayoutWidget);
        buttons_grid->setSpacing(0);
        buttons_grid->setObjectName("buttons_grid");
        buttons_grid->setContentsMargins(5, 5, 5, 5);
        open_paren = new QPushButton(gridLayoutWidget);
        open_paren->setObjectName("open_paren");
        open_paren->setMinimumSize(QSize(50, 40));
        open_paren->setMaximumSize(QSize(50, 30));
        open_paren->setFont(font);

        buttons_grid->addWidget(open_paren, 2, 0, 1, 1);

        result = new QPushButton(gridLayoutWidget);
        result->setObjectName("result");
        result->setMinimumSize(QSize(50, 40));
        result->setMaximumSize(QSize(50, 30));
        result->setFont(font);

        buttons_grid->addWidget(result, 6, 3, 1, 1);

        ln = new QPushButton(gridLayoutWidget);
        ln->setObjectName("ln");
        ln->setMinimumSize(QSize(50, 40));
        ln->setMaximumSize(QSize(50, 30));
        ln->setFont(font);

        buttons_grid->addWidget(ln, 0, 0, 1, 1);

        plus = new QPushButton(gridLayoutWidget);
        plus->setObjectName("plus");
        plus->setMinimumSize(QSize(50, 40));
        plus->setMaximumSize(QSize(50, 30));
        plus->setFont(font);

        buttons_grid->addWidget(plus, 4, 3, 1, 1);

        one = new QPushButton(gridLayoutWidget);
        one->setObjectName("one");
        one->setMinimumSize(QSize(50, 40));
        one->setMaximumSize(QSize(50, 30));
        one->setFont(font);

        buttons_grid->addWidget(one, 5, 0, 1, 1);

        seven = new QPushButton(gridLayoutWidget);
        seven->setObjectName("seven");
        seven->setMinimumSize(QSize(50, 40));
        seven->setMaximumSize(QSize(50, 30));
        seven->setFont(font);

        buttons_grid->addWidget(seven, 3, 0, 1, 1);

        four = new QPushButton(gridLayoutWidget);
        four->setObjectName("four");
        four->setMinimumSize(QSize(50, 40));
        four->setMaximumSize(QSize(50, 30));
        four->setFont(font);

        buttons_grid->addWidget(four, 4, 0, 1, 1);

        zero = new QPushButton(gridLayoutWidget);
        zero->setObjectName("zero");
        zero->setMinimumSize(QSize(50, 40));
        zero->setMaximumSize(QSize(50, 30));
        zero->setFont(font);

        buttons_grid->addWidget(zero, 6, 1, 1, 1);

        nine = new QPushButton(gridLayoutWidget);
        nine->setObjectName("nine");
        nine->setMinimumSize(QSize(50, 40));
        nine->setMaximumSize(QSize(50, 30));
        nine->setFont(font);

        buttons_grid->addWidget(nine, 3, 2, 1, 1);

        multiply = new QPushButton(gridLayoutWidget);
        multiply->setObjectName("multiply");
        multiply->setMinimumSize(QSize(50, 40));
        multiply->setMaximumSize(QSize(50, 30));
        multiply->setFont(font);

        buttons_grid->addWidget(multiply, 2, 3, 1, 1);

        factorial = new QPushButton(gridLayoutWidget);
        factorial->setObjectName("factorial");
        factorial->setMinimumSize(QSize(50, 40));
        factorial->setMaximumSize(QSize(50, 30));
        factorial->setFont(font);

        buttons_grid->addWidget(factorial, 2, 2, 1, 1);

        minus = new QPushButton(gridLayoutWidget);
        minus->setObjectName("minus");
        minus->setMinimumSize(QSize(50, 40));
        minus->setMaximumSize(QSize(50, 30));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("System")});
        font2.setPointSize(12);
        font2.setBold(false);
        minus->setFont(font2);

        buttons_grid->addWidget(minus, 5, 3, 1, 1);

        eight = new QPushButton(gridLayoutWidget);
        eight->setObjectName("eight");
        eight->setMinimumSize(QSize(50, 40));
        eight->setMaximumSize(QSize(50, 30));
        eight->setFont(font);

        buttons_grid->addWidget(eight, 3, 1, 1, 1);

        six = new QPushButton(gridLayoutWidget);
        six->setObjectName("six");
        six->setMinimumSize(QSize(50, 40));
        six->setMaximumSize(QSize(50, 30));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("System")});
        font3.setPointSize(12);
        font3.setKerning(false);
        six->setFont(font3);

        buttons_grid->addWidget(six, 4, 2, 1, 1);

        point = new QPushButton(gridLayoutWidget);
        point->setObjectName("point");
        point->setMinimumSize(QSize(50, 40));
        point->setMaximumSize(QSize(50, 30));
        point->setFont(font);

        buttons_grid->addWidget(point, 6, 2, 1, 1);

        devide = new QPushButton(gridLayoutWidget);
        devide->setObjectName("devide");
        devide->setMinimumSize(QSize(50, 40));
        devide->setMaximumSize(QSize(50, 30));
        devide->setFont(font);

        buttons_grid->addWidget(devide, 3, 3, 1, 1);

        two = new QPushButton(gridLayoutWidget);
        two->setObjectName("two");
        two->setMinimumSize(QSize(50, 40));
        two->setMaximumSize(QSize(50, 30));
        two->setFont(font);

        buttons_grid->addWidget(two, 5, 1, 1, 1);

        sign_change = new QPushButton(gridLayoutWidget);
        sign_change->setObjectName("sign_change");
        sign_change->setMinimumSize(QSize(50, 40));
        sign_change->setMaximumSize(QSize(50, 30));
        sign_change->setFont(font);

        buttons_grid->addWidget(sign_change, 6, 0, 1, 1);

        close_paren = new QPushButton(gridLayoutWidget);
        close_paren->setObjectName("close_paren");
        close_paren->setMinimumSize(QSize(50, 40));
        close_paren->setMaximumSize(QSize(50, 30));
        close_paren->setFont(font);

        buttons_grid->addWidget(close_paren, 2, 1, 1, 1);

        square = new QPushButton(gridLayoutWidget);
        square->setObjectName("square");
        square->setMinimumSize(QSize(50, 40));
        square->setMaximumSize(QSize(50, 30));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("System")});
        font4.setPointSize(12);
        font4.setKerning(true);
        square->setFont(font4);
        square->setLocale(QLocale(QLocale::Ukrainian, QLocale::Ukraine));
        square->setText(QString::fromUtf8("sqr"));

        buttons_grid->addWidget(square, 0, 1, 1, 1);

        five = new QPushButton(gridLayoutWidget);
        five->setObjectName("five");
        five->setMinimumSize(QSize(50, 40));
        five->setMaximumSize(QSize(50, 30));
        five->setFont(font);

        buttons_grid->addWidget(five, 4, 1, 1, 1);

        backspace = new QPushButton(gridLayoutWidget);
        backspace->setObjectName("backspace");
        backspace->setMinimumSize(QSize(50, 40));
        backspace->setMaximumSize(QSize(50, 30));
        backspace->setFont(font);

        buttons_grid->addWidget(backspace, 0, 3, 1, 1);

        three = new QPushButton(gridLayoutWidget);
        three->setObjectName("three");
        three->setMinimumSize(QSize(50, 40));
        three->setMaximumSize(QSize(50, 30));
        three->setFont(font);

        buttons_grid->addWidget(three, 5, 2, 1, 1);

        clear = new QPushButton(gridLayoutWidget);
        clear->setObjectName("clear");
        clear->setMinimumSize(QSize(50, 40));
        clear->setMaximumSize(QSize(50, 30));
        clear->setFont(font);

        buttons_grid->addWidget(clear, 0, 2, 1, 1);

        error_line = new QLabel(centralwidget);
        error_line->setObjectName("error_line");
        error_line->setGeometry(QRect(20, 10, 201, 20));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("System")});
        font5.setPointSize(9);
        error_line->setFont(font5);
        error_line->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 245, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200", nullptr));
        result_line->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        open_paren->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        result->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        ln->setText(QCoreApplication::translate("MainWindow", "ln", nullptr));
        plus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        one->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        seven->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        four->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        zero->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        nine->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        multiply->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        factorial->setText(QCoreApplication::translate("MainWindow", "n!", nullptr));
        minus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        eight->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        six->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        point->setText(QCoreApplication::translate("MainWindow", ",", nullptr));
        devide->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        two->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        sign_change->setText(QCoreApplication::translate("MainWindow", "+/-", nullptr));
        close_paren->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        five->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        backspace->setText(QCoreApplication::translate("MainWindow", "\342\214\253", nullptr));
        three->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        clear->setText(QCoreApplication::translate("MainWindow", "\320\241", nullptr));
        error_line->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
