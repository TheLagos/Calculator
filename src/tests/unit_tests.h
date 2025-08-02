#ifndef UNIT_TESTS_H
#define UNIT_TESTS_H

class CalculatorTests {
private:
    bool testAddition();
    bool testFactorial();
    bool testComplexExpression();
    bool testDivisionByZero();
    bool testNestedParentheses();
    bool testLnOfExpression();
    bool testSquareOfSum();
    bool testFactorialZero();
    bool testFloatingPointPrecision();
    bool testMultipleOperations();
    bool testComplexExpression2();

public:
    void runAllTests();
};
#endif // UNIT_TESTS_H
