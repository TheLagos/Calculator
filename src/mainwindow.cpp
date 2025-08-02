#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);

    symbols.push_back("digit"); //початкові параметри
    can_set_coma.push_back(true);

    connect(ui->zero,  &QPushButton::clicked, this, [=](){ insertDigit("0"); });
    connect(ui->one,   &QPushButton::clicked, this, [=](){ insertDigit("1"); });
    connect(ui->two,   &QPushButton::clicked, this, [=](){ insertDigit("2"); });
    connect(ui->three, &QPushButton::clicked, this, [=](){ insertDigit("3"); });
    connect(ui->four,  &QPushButton::clicked, this, [=](){ insertDigit("4"); });
    connect(ui->five, &QPushButton::clicked, this, [=](){ insertDigit("5"); });
    connect(ui->six,   &QPushButton::clicked, this, [=](){ insertDigit("6"); });
    connect(ui->seven, &QPushButton::clicked, this, [=](){ insertDigit("7"); });
    connect(ui->eight, &QPushButton::clicked, this, [=](){ insertDigit("8"); });
    connect(ui->nine,  &QPushButton::clicked, this, [=](){ insertDigit("9"); });

    connect(ui->plus,    &QPushButton::clicked, this, [=](){ insertAction("+"); });
    connect(ui->minus,   &QPushButton::clicked, this, [=](){ insertAction("-"); });
    connect(ui->multiply,&QPushButton::clicked, this, [=](){ insertAction("*"); });
    connect(ui->devide,  &QPushButton::clicked, this, [=](){ insertAction("/"); });

    connect(ui->open_paren,  &QPushButton::clicked, this, [=](){ openParen(); });
    connect(ui->close_paren, &QPushButton::clicked, this, [=](){ closeParen(); });

    connect(ui->point, &QPushButton::clicked, this, [=](){ insertComa(); });
    connect(ui->ln,  &QPushButton::clicked, this, [=](){ insertLN(); });
    connect(ui->square,  &QPushButton::clicked, this, [=](){ toSqr(); });
    connect(ui->factorial, &QPushButton::clicked, this, [=](){ insertFactorial(); });
    connect(ui->sign_change, &QPushButton::clicked, this, [=](){ changeSign(); });

    connect(ui->result, &QPushButton::clicked, this, [=](){ calculateResult(); });

    connect(ui->backspace, &QPushButton::clicked, this, [=](){ deleteSymbol(); });
    connect(ui->clear,  &QPushButton::clicked, this, [=](){ deleteAll(); });
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::getText() { return ui->result_line->text(); }

void MainWindow::clearErrorMessage() {
    if(error) {
        ui->error_line->setText("");
        error = false;
    }
}

void MainWindow::insertDigit(QString digit) {
    QString text = getText();
    QString symbol_type = symbols.back();

    clearErrorMessage();

    if (text.size() == 1 && text == "0") {
        text = digit;
        symbols.clear();
    } else if (types_for_digit.contains(symbol_type)) {
        text.append(digit);
        can_set_coma.push_back(can_set_coma.back());
    } else { return; }

    symbols.push_back("digit");
    ui->result_line->setText(text);
}

void MainWindow::insertAction(QString action) {
    QString text = getText();
    QString symbol_type = symbols.back();

    clearErrorMessage();

    if (symbol_type == "action" && symbols.at(symbols.size() - 2) != "o_paren") {
        text.chop(1);
    } else if (types_for_action.contains(symbol_type)) {
        if (symbol_type == "o_paren" && action != "-") {
            return;
        }
        symbols.push_back("action");
        can_set_coma.push_back(true);
    } else { return; }

    text.append(action);

    ui->result_line->setText(text);
}

void MainWindow::insertComa() {
    if (can_set_coma.last()) {
        QString text = getText();
        QString symbol_type = symbols.back();

        clearErrorMessage();

        if (!types_for_coma.contains(symbol_type)) {
            return;
        }

        symbols.push_back("coma");
        text.append(",");
        can_set_coma.push_back(false);

        ui->result_line->setText(text);
    }
}

void MainWindow::insertFactorial() {
    QString text = getText();
    QString symbol_type = symbols.back();

    clearErrorMessage();

    if (!types_for_factorial.contains(symbol_type)) {
        return;
    }

    symbols.push_back("factorial");
    text.append("!");
    can_set_coma.push_back(true);

    ui->result_line->setText(text);
}

void MainWindow::insertLN() {
    QString text = getText();
    QString symbol_type = symbols.back();

    clearErrorMessage();

    if (!types_for_ln.contains(symbol_type)) {
        return;
    }

    if (types_for_set_multiply.contains(symbol_type)) {
        if (text == "0") {
            text.clear();
            symbols.clear();
            can_set_coma.pop_back();
        } else {
            insertAction("*");
            text = getText();
        }
    }

    text.append("ln");
    symbols.append({" ", "ln"});
    can_set_coma.insert(can_set_coma.end(), 2, false);

    ui->result_line->setText(text);
    openParen();
}

void MainWindow::toSqr() {
    QString text = getText();
    QString symbol_type = symbols.back();

    clearErrorMessage();

    if (!types_for_ln.contains(symbol_type)) {
        return;
    }

    if (types_for_set_multiply.contains(symbol_type)) {
        if (text == "0") {
            text.clear();
            symbols.clear();
            can_set_coma.pop_back();
        } else {
            insertAction("*");
            text = getText();
        }
    }

    text.append("sqr");
    symbols.append({" ", " ", "sqr"});
    can_set_coma.insert(can_set_coma.end(), 3, false);

    ui->result_line->setText(text);
    openParen();
}

void MainWindow::insertBlock(int pos) {
    QString text = getText();
    ++o_paren_count;

    text.insert(pos, "(-");
    symbols.insert(symbols.begin() + pos, "o_paren");
    symbols.insert(symbols.begin() + pos + 1, "action");
    can_set_coma.insert(can_set_coma.begin() + pos, 2, true);

    ui->result_line->setText(text);
}

void MainWindow::deleteBlock(int pos) {
    QString text = getText();
    --o_paren_count;

    text.remove(pos, 2);
    symbols.erase(symbols.begin() + pos, symbols.begin() + pos + 2);
    can_set_coma.erase(can_set_coma.begin() + pos, can_set_coma.begin() + pos + 2);

    ui->result_line->setText(text);
}

void MainWindow::changeSign() {
    QString text = getText();
    QString symbol_type = symbols.back();

    clearErrorMessage();

    if (!types_for_change_sign.contains(symbol_type)) {
        return;
    }

    if (text.size() == 1 && text == "0") { // якщо початок
        openParen();
        insertAction("-");
    } else  {
        for (auto iter = symbols.rbegin(); iter != symbols.rend(); ++iter) { // ітерація по виразу з кінця
            int pos = 0;
            auto last_digit = iter.base();

            if (*iter == "action") { // знайдено дію
                if (*next(iter) == "o_paren") { // є (-
                    pos = std::distance(symbols.begin(), last_digit) - 2;
                    deleteBlock(pos);
                } else { // немає (-
                    pos = std::distance(symbols.begin(), last_digit);
                    insertBlock(pos);
                }
                break;
            } else if (*iter == "o_paren") { // знайдено відкриту дужку
                if (next(iter) == symbols.rend()) { pos = 1; } // дужка на початку
                else { pos = std::distance(symbols.begin(), last_digit); } // дужка десь в виразі

                insertBlock(pos);
                break;
            }  else if (*iter == "digit" && next(iter) == symbols.rend()) { // знайдено останнє число
                insertBlock(0);
                break;
            }
        }
    }

    text = getText();

    if (text.isEmpty()) { // перевірка на пустоту
        text = "0";
        symbols.push_back("digit");
        can_set_coma.push_back(true);
    }

    ui->result_line->setText(text);
}

void MainWindow::openParen() {
    QString text = getText();
    QString symbol_type = symbols.back();

    clearErrorMessage();

    if (!types_for_o_paren.contains(symbol_type)) {
        return;
    }

    if (types_for_set_multiply.contains(symbol_type)) {
        if (text == "0") {
            text.clear();
            symbols.pop_back();
            can_set_coma.pop_back();
        } else {
            insertAction("*");
            text = getText();
        }
    }

    text.append("(");
    symbols.push_back("o_paren");

    ++o_paren_count;
    can_set_coma.push_back(true);

    ui->result_line->setText(text);
}

void MainWindow::closeParen() {
    if (o_paren_count > 0) {
        QString text = getText();
        QString symbol_type = symbols.back();

        if (!types_for_c_paren.contains(symbol_type)) {
            return;
        }

        text.append(")");
        symbols.push_back("c_paren");
        --o_paren_count;
        can_set_coma.push_back(true);

        ui->result_line->setText(text);
    }
}

void MainWindow::deleteSymbol() {
    QString text = getText();

    clearErrorMessage();

    if (!symbols.isEmpty() && !text.isEmpty() && text != "0") {
        QString symbol_type = symbols.back();

        if (symbol_type == "c_paren") {
            ++o_paren_count;
        } else if (symbol_type == "o_paren") {
            --o_paren_count;
        } else if (symbol_type == "ln") {
            symbols.resize(symbols.size() - 1);
            text.chop(1);
            can_set_coma.pop_back();
        } else if (symbol_type == "sqr") {
            symbols.resize(symbols.size() - 2);
            text.chop(2);
            can_set_coma.resize(can_set_coma.size() - 2);
        }
        symbols.pop_back();
        text.chop(1);
        can_set_coma.pop_back();

        if (text.isEmpty()) {
            text = "0";
            symbols.push_back("digit");
            can_set_coma.push_back(true);
        }

        ui->result_line->setText(text);
    }
}

void MainWindow::deleteAll() {
    clearErrorMessage();

    if (!getText().isEmpty()) {
        ui->result_line->setText("0");

        symbols.clear();
        symbols.push_back("digit");

        o_paren_count = 0;

        can_set_coma.clear();
        can_set_coma.push_back(true);
    }
}

int MainWindow::symbolPriority(QChar& symbol) {
    if (symbol == '!' || symbol == 'n' || symbol == 'q') { return 4; }
    else if (symbol == '*' || symbol == '/') { return 3; }
    else if (symbol == '+' || symbol == '-') { return 2; }
    else { return 1; }
}

QVector<QString> MainWindow::convertToIPR(QString& text) {
    QStack<QChar> actions;
    QVector<QString> output;
    QString number;

    for (int i = 0; i < text.size(); ++i) {
        QString symbol_type = symbols[i];
        QChar symbol = text[i];

        if (symbol_type == "digit" || symbol_type == "coma" || (symbol_type == "action" && symbols[i - 1] == "o_paren")) {
            number += symbol;
        } else {
            if (!number.isEmpty()) {
                output.push_back(number);
                number.clear();
            }

            if (symbol_type == "action" || symbol_type == "ln" || symbol_type == "sqr") {
                if (symbol_type == "ln") { symbol = 'n'; }
                else if (symbol_type == "sqr") { symbol = 'q'; }

                while (!actions.isEmpty() && symbolPriority(actions.top()) >= symbolPriority(symbol)) {
                    output.push_back(actions.pop());
                }
                actions.push(symbol);
            } else if (symbol_type == "o_paren") {
                actions.push(symbol);
            } else if (symbol_type == "factorial") {
                output.push_back(symbol);
            } else if (symbol_type == "c_paren") {
                while (!actions.isEmpty() && actions.top() != '(') {
                    output.push_back(actions.pop());
                }
                actions.pop();
            }
        }
    }

    if (!number.isEmpty()) {
        output.push_back(number);
        number.clear();
    }

    while (!actions.isEmpty()) {
        output.push_back(actions.pop());
    }

    return output;
}

double MainWindow::calculateIPR(QVector<QString> symbols) {
    QStack<double> result;

    bool isDigit;
    for (QString& symbol : symbols) {
        double value = symbol.toDouble(&isDigit);
        if (isDigit) {
            result.push(value);
        } else if (standart_operators.contains(symbol)) {
            double b = result.top(); result.pop();
            double a = result.top(); result.pop();

            if (symbol == "+") {result.push(a + b); }
            else if (symbol == "-") { result.push(a - b); }
            else if (symbol == "*") { result.push(a * b); }
            else if (symbol == "/") {
                if (b == 0) {
                    ui->error_line->setText("На нуль ділити не можна!");
                    error = true;
                    return 0;
                }
                result.push(a / b);
            }
        }  else {
            value = result.pop();
            if (symbol == "!") {
                if (value < 0) {
                    ui->error_line->setText("Неприпустиме значення факторіалу!");
                    error = true;
                    return 0;
                }
                result.push(std::tgamma(value + 1));
            } else if (symbol == "n") {
                if (value <= 0) {
                    ui->error_line->setText("Неприпустиме значення логарифму!");
                    error = true;
                    return 0;
                }
                result.push(std::log(value));
            } else if (symbol == "q") {
                result.push(std::pow((value), 2));
            }
        }
    }

    return result.top();
}

void MainWindow::calculateResult() {
    QString text = getText();
    QString symbol_type = symbols.back();

    clearErrorMessage();

    if (!types_for_calculate.contains(symbol_type)) {
        return;
    }

    text.replace(",", ".");
    for (int i = 0; i < o_paren_count; ++i) {
        text.append(")");
        symbols.push_back("c_paren");
    }
    o_paren_count = 0;

    double value = calculateIPR(convertToIPR(text));

    QString result = QString::number(value, 'f', 16);

    static const QRegularExpression trailingZeros("0+$");
    static const QRegularExpression trailingDot("\\.$");

    result = result.remove(trailingZeros); // прибирає зайві нулі
    result = result.remove(trailingDot); //прибирає зайву крапку

    result.replace(".", ",");

    ui->result_line->setText(result);

    symbols.clear();

    for (QChar& ch : result) {
        if (ch.isDigit()) {
            symbols.push_back("digit");
        } else if (ch == ',') {
            symbols.push_back("coma");
        } else if (ch == '-') {
            symbols.push_back("action");
        }
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
switch(event->key()) {
    case Qt::Key_1:
        ui->one->animateClick();
        break;
    case Qt::Key_2:
        ui->two->animateClick();
        break;
    case Qt::Key_3:
        ui->three->animateClick();
        break;
    case Qt::Key_4:
        ui->four->animateClick();
        break;
    case Qt::Key_5:
        ui->five->animateClick();
        break;
    case Qt::Key_6:
        ui->six->animateClick();
        break;
    case Qt::Key_7:
        ui->seven->animateClick();
        break;
    case Qt::Key_8:
        ui->eight->animateClick();
        break;
    case Qt::Key_9:
        ui->nine->animateClick();
        break;
    case Qt::Key_0:
        ui->zero->animateClick();
        break;
    }

    switch(event->key()) {
    case Qt::Key_Plus:
        ui->plus->animateClick();
        break;
    case Qt::Key_Minus:
        ui->minus->animateClick();
        break;
    case Qt::Key_Asterisk:
        ui->multiply->animateClick();
        break;
    case Qt::Key_Slash:
        ui->devide->animateClick();
        break;
    }

    switch(event->key()) {
    case Qt::Key_ParenLeft:
        ui->open_paren->animateClick();
        break;
    case Qt::Key_ParenRight:
        ui->close_paren->animateClick();
        break;
    }

    switch(event->key()) {
    case Qt::Key_Comma:
        ui->point->animateClick();
        break;
    }

    switch(event->key()) {
    case Qt::Key_Exclam:
        ui->factorial->animateClick();
        break;
    }

    switch(event->key()) {
    case Qt::Key_C:
        ui->sign_change->animateClick();
        break;
    case Qt::Key_N:
        ui->ln->animateClick();
        break;
    case Qt::Key_Q:
        ui->square->animateClick();
        break;
    }

    switch(event->key()) {
    case Qt::Key_Backspace:
        ui->backspace->animateClick();
        break;
    case Qt::Key_Delete:
        ui->clear->animateClick();
        break;
    case Qt::Key_Enter:
    case Qt::Key_Return:
    case Qt::Key_Equal:
        ui->result->animateClick();
        break;
    }
}
