#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QSet>
#include <QStack>
#include <cmath>
#include <QRegularExpression>
#include <QTimer>
#include <QSettings>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    friend class CalculatorTests;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void lightTheme();
    void darkTheme();
    bool isLightTheme();

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    Ui::MainWindow *ui;

    QVector<QString> symbols; //null, digit, action, coma, o_paren, c_paren, factorial, ln, sqr
    QVector<bool> can_set_coma;

    int o_paren_count = 0;
    bool error = false;
    bool light_theme = true;

    const QSet<QString> types_for_digit = {"action", "digit", "o_paren", "coma"};
    const QSet<QString> types_for_action = {"digit", "c_paren", "factorial", "o_paren"};
    const QSet<QString> types_for_coma = {"digit"};
    const QSet<QString> types_for_o_paren = {"digit", "action", "o_paren", "c_paren", "factorial", "ln", "sqr"};
    const QSet<QString> types_for_c_paren = {"digit", "c_paren", "factorial"};
    const QSet<QString> types_for_factorial = {"digit", "c_paren"};
    const QSet<QString> types_for_change_sign = {"digit", "action"};
    const QSet<QString> types_for_calculate = {"digit", "c_paren", "factorial"};
    const QSet<QString> types_for_ln = {"digit", "action", "o_paren", "c_paren", "factorial"};
    const QSet<QString> types_for_sqr = {"digit", "action", "o_paren", "c_paren", "factorial"};
    const QSet<QString> types_for_set_multiply = {"digit", "c_paren", "factorial"};
    const QSet<QString> types_what_change_coma = {"action", "o_paren", "c_paren", "factorial", "coma"};
    const QSet<QString> standart_operators = {"+", "-", "*", "/"};

    QString getText();
    void clearErrorMessage();
    void insertBlock(int pos);
    void deleteBlock(int pos);
    int symbolPriority(QChar& symbol);
    QVector<QString> convertToIPR(QString& text);
    double calculateIPR(QVector<QString> symbols);

private slots:
    void insertDigit(QString digit);
    void insertAction(QString action);
    void insertComa();
    void insertFactorial();
    void insertLN();
    void toSqr();
    void changeSign();
    void openParen();
    void closeParen();
    void deleteSymbol();
    void deleteAll();
    void calculateResult();
    void changeTheme();
};
#endif // MAINWINDOW_H
