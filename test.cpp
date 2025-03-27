#include "calculator.h"
#include <iostream>

using namespace std;

int main() {
    Calculator calc;
    
    cout << "Addition: " << calc.add(5, 3) << endl;
    cout << "Subtraction: " << calc.subtract(10, 4) << endl;
    cout << "Multiplication: " << calc.multiply(6, 7) << endl;
    cout << "Division: " << calc.divide(20, 5) << endl;
    cout << "Factorial: " << calc.factorial(5) << endl;
    cout << "GCD: " << calc.gcd(48, 18) << endl;
    cout << "LCM: " << calc.lcm(4, 6) << endl;
    cout << "Random: " << calc.generateRandom(1, 10) << endl;
    
    string expression = "3 + 4 * (2 - 1) / 5";
    cout << "Evaluated Expression (" << expression << "): " << calc.evaluateExpression(expression) << endl;
return 0;
}