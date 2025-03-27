#include "calculator.h"
#include <stdexcept>
#include <cstdlib>
#include <cctype>
#include <sstream>
#include <iostream>
#include <cmath>

using namespace std;

double Calculator::add(double a, double b) { return a + b; }
double Calculator::subtract(double a, double b) { return a - b; }
double Calculator::multiply(double a, double b) { return a * b; }
double Calculator::divide(double a, double b) {
    if (b == 0) throw runtime_error("Division by zero");
    return a / b;
}
int Calculator::factorial(int n) {
    if (n < 0) throw runtime_error("Negative factorial not allowed");
    return (n == 0) ? 1 : n * factorial(n - 1);
}
int Calculator::gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }
int Calculator::lcm(int a, int b) { return (a / gcd(a, b)) * b; }
int Calculator::generateRandom(int min, int max) { return rand() % (max - min + 1) + min; }
int Calculator::operatorType(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}
double Calculator::applyOperation(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) throw runtime_error("Division by zero");
            return a / b;
        default: throw runtime_error("Invalid operator");
    }
}

// Function to evaluate mathematical expressions using the Shunting-Yard Algorithm
double Calculator::evaluateExpression(const string& expr) {
    stack<double> values;
    stack<char> operators;
    stringstream ss(expr);
    char token;

    while (ss >> token) {
        if (isdigit(token)) {
            ss.putback(token);
            double num;
            ss >> num;
            values.push(num);
        } else if (token == '(') {
            operators.push(token);
        } else if (token == ')') {
            while (!operators.empty() && operators.top() != '(') {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char op = operators.top(); operators.pop();
                values.push(applyOperation(a, b, op));
            }
            operators.pop();  // Remove '('
        } else if (operatorType(token) > 0) {
            while (!operators.empty() && operatorType(operators.top()) >= operatorType(token)) {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char op = operators.top(); operators.pop();
                values.push(applyOperation(a, b, op));
            }
            operators.push(token);
        }
    }

    while (!operators.empty()) {
        double b = values.top(); values.pop();
        double a = values.top(); values.pop();
        char op = operators.top(); operators.pop();
        values.push(applyOperation(a, b, op));
    } return values.top();
}