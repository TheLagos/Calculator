#include "unit_tests.h"
#include "mainwindow.h"

#include <iostream>
#include <cmath>

bool CalculatorTests::testAddition() {
    MainWindow w;
    QString expr = "2+3";
    w.symbols = {"digit","action","digit"};
    double result = w.calculateIPR(w.convertToIPR(expr));
    return std::abs(result - 5.0) < 1e-12;
}

bool CalculatorTests::testFactorial() {
    MainWindow w;
    QString expr = "5!";
    w.symbols = {"digit","factorial"};
    double result = w.calculateIPR(w.convertToIPR(expr));
    return std::abs(result - 120.0) < 1e-12;
}

bool CalculatorTests::testComplexExpression() {
    MainWindow w;
    // Expression: (2+3)! / 2 = 120/2 = 60
    QString expr = "(2+3)!/2";
    w.symbols = {"o_paren","digit","action","digit","c_paren","factorial","action","digit"};
    double result = w.calculateIPR(w.convertToIPR(expr));
    return std::abs(result - 60.0) < 1e-12;
}

bool CalculatorTests::testDivisionByZero() {
    MainWindow w;
    QString expr = "5/0";
    w.symbols = {"digit","action","digit"};
    double result = w.calculateIPR(w.convertToIPR(expr));
    return w.error && result == 0.0;
}

bool CalculatorTests::testNestedParentheses() {
    MainWindow w;
    // ((2+3)*2)^2 = 10^2 = 100
    QString expr = "((2+3)*2)sqr";
    w.symbols = {
        "o_paren", "o_paren", "digit", "action", "digit", "c_paren",
        "action", "digit", "c_paren", " ", " ", "sqr"
    };
    double result = w.calculateIPR(w.convertToIPR(expr));
    return std::abs(result - 100.0) < 1e-12;
}

bool CalculatorTests::testLnOfExpression() {
    MainWindow w;
    // ln(4) = ln(2*2)
    QString expr = "(2*2)ln";
    w.symbols = {"o_paren","digit","action","digit","c_paren", " ", "ln"};
    double expected = std::log(4.0);
    double result = w.calculateIPR(w.convertToIPR(expr));
    return std::abs(result - expected) < 1e-12;
}

bool CalculatorTests::testSquareOfSum() {
    MainWindow w;
    // (3+2)^2 = 25
    QString expr = "(3+2)sqr";
    w.symbols = {"o_paren","digit","action","digit","c_paren", " ", " ", "sqr"};
    double result = w.calculateIPR(w.convertToIPR(expr));
    return std::abs(result - 25.0) < 1e-12;
}

bool CalculatorTests::testFactorialZero() {
    MainWindow w;
    // 0! = 1
    QString expr = "0!";
    w.symbols = {"digit","factorial"};
    double result = w.calculateIPR(w.convertToIPR(expr));
    return std::abs(result - 1.0) < 1e-12;
}

bool CalculatorTests::testFloatingPointPrecision() {
    MainWindow w;
    // 2.5 * 4 = 10
    QString expr = "2,5*4"; // your calculator uses comma for decimal
    expr.replace(",", ".");
    w.symbols = {"digit","coma","digit","action","digit"};
    double result = w.calculateIPR(w.convertToIPR(expr));
    return std::abs(result - 10.0) < 1e-12;
}

bool CalculatorTests::testMultipleOperations() {
    MainWindow w;
    // 2 + 3 * 4 = 14 (test operator precedence)
    QString expr = "2+3*4";
    w.symbols = {"digit","action","digit","action","digit"};
    double result = w.calculateIPR(w.convertToIPR(expr));
    return std::abs(result - 14.0) < 1e-12;
}

bool CalculatorTests::testComplexExpression2() {
    MainWindow w;
    // (2+3)! / (4 - 2) = 120 / 2 = 60
    QString expr = "(2+3)!/(4-2)";
    w.symbols = {
        "o_paren","digit","action","digit","c_paren",
        "factorial","action",
        "o_paren","digit","action","digit","c_paren"
    };
    double result = w.calculateIPR(w.convertToIPR(expr));
    return std::abs(result - 60.0) < 1e-12;
}

void CalculatorTests::runAllTests() {
    struct Test {
        const char* name;
        std::function<bool()> func;
    };

    std::vector<Test> tests = {
        {"Addition",                 [this]() { return testAddition(); }},
        {"Factorial",                [this]() { return testFactorial(); }},
        {"Complex Expression 1",     [this]() { return testComplexExpression(); }},
        {"Division by Zero",         [this]() { return testDivisionByZero(); }},
        {"Nested Parentheses",       [this]() { return testNestedParentheses(); }},
        {"Ln of Expression",         [this]() { return testLnOfExpression(); }},
        {"Square of Sum",            [this]() { return testSquareOfSum(); }},
        {"Factorial Zero",           [this]() { return testFactorialZero(); }},
        {"Floating Point Precision", [this]() { return testFloatingPointPrecision(); }},
        {"Multiple Operations",      [this]() { return testMultipleOperations(); }},
        {"Complex Expression 2",     [this]() { return testComplexExpression(); }}
    };

    int passed = 0;
    int total = static_cast<int>(tests.size());

    std::cout << "Running Calculator Tests...\n";

    for (auto &t : tests) {
        bool result = t.func();
        if (result) {
            std::cout << "[PASS] " << t.name << "\n";
            ++passed;
        } else {
            std::cout << "[FAIL] " << t.name << "\n";
        }
    }

    std::cout << "Summary: " << passed << "/" << total << " tests passed.\n";
}
