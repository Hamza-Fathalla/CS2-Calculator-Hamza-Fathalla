#include <iostream>
#include "calculator.h"

int main() {

    cout << "Addition: 3 + 4 = " << add(3, 4) << endl;
    cout << "Subtraction: 10 - 2 = " << subtract(10, 2) << endl;
    cout << "Multiplication: 3 * 7 = " << multiply(3, 7) << endl;
    cout << "Division: 10 / 2 = " << divide(10, 2) << endl;

   cout << "Division by zero: 10 / 0 = " << divide(10, 0) << endl;

    int num = 5;
    cout << "Factorial of " << num << " = " << factorial(num) << endl;

    int a = 56, b = 98;
    cout << "GCD of " << a << " and " << b << " = " << gcd(a, b) << endl;

    cout << "LCM of " << a << " and " << b << " = " << lcm(a, b) << endl;

    cout << "Random number between 1 and 10: " << generateRandomNumber(1, 10) << endl;

    
    string expression1 = "3 + 4 * (2 - 1) / 5";
    cout << "Result: " << expression1 << "' = " << evaluateExpression(expression1) << endl;

    string expression2 = "(3 + 5) * (2 - 1)";
    cout << "Result: " << expression2 << "' = " << evaluateExpression(expression2) << endl;

    string expression3 = "3 + 4 * 2 / (1 - 5) ^ 2 ^ 3";
    cout << "Result: " << expression3 << "' = " << evaluateExpression(expression3) << endl;

    return 0;
}

