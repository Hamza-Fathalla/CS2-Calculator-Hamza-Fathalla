
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include <stack>

using namespace std;

class Calculator {
public:
    Calculator() {}
    double add(double a, double b);
    double subtract(double a, double b);
    double multiply(double a, double b);
    double divide(double a, double b);
    int factorial(int n);
    int gcd(int a, int b);
    int lcm(int a, int b);
    int generateRandom(int min, int max);
    double evaluateExpression(const string& expr);

private:
    int operatorType(char op);
    double applyOperation(double a, double b, char op);
    double applyFunction(const string& func, double val);
};

#endif