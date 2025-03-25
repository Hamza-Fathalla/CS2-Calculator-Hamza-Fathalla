#include "calculator.h"
#include <iostream>
#include <sstream>
#include <stack>
#include <cctype>
#include <cmath>
#include <unordered_map>
#include <stdexcept>

using namespace std;

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        cout<<"error, cannot divide by 0"<<endl;
    }
    return a /(double)b;
}

long long factorial(int n) {
    if (n <= 1) return 1;
    long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int generateRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

int typeofoperator(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}


double useoperator(double a, double b, char op) {
    switch (op) {
        case '+': return add(a, b);
        case '-': return subtract(a, b);
        case '*': return multiply(a, b);
        case '/': return divide(a, b);
        default: cout<<"Invalid operator"<<endl;
    }
}

double evaluateExpression(const string& expression) {
    stack<double> values; 
    stack<char> operators; 
    unordered_map<char, int> operatortype = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

    for (size_t i = 0; i < expression.size(); ++i) {
        char current = expression[i];

        if (isspace(current)) {
            continue; // Ignore spaces
        }

        if (isdigit(current) || current == '.') {
            stringstream ss;
            ss << current;
            // Handle multi-digit numbers or decimal numbers
            while (i + 1 < expression.size() && (isdigit(expression[i + 1]) || expression[i + 1] == '.')) {
                ss << expression[++i];
            }
            double num;
            ss >> num;
            values.push(num);
        }
        else if (current == '(') {
            operators.push(current); // Push '(' onto the operator stack
        }
        else if (current == ')') {
            while (!operators.empty() && operators.top() != '(') {
                double val2 = values.top();
                values.pop();
                double val1 = values.top();
                values.pop();
                char op = operators.top();
                operators.pop();
                values.push(applyOperator(val1, val2, op));
            }
            operators.pop(); // Pop the '('
        }
        else if (operatortype.find(current) != operatortype.end()) {
            while (!operators.empty() && precedence(operators.top()) >= precedence(current)) {
                double val2 = values.top();
                values.pop();
                double val1 = values.top();
                values.pop();
                char op = operators.top();
                operators.pop();
                values.push(applyOperator(val1, val2, op));
            }
            operators.push(current);
        }
    }

    while (!operators.empty()) {
        double val2 = values.top();
        values.pop();
        double val1 = values.top();
        values.pop();
        char op = operators.top();
        operators.pop();
        values.push(applyOperator(val1, val2, op));
    }

    return values.top();
}
