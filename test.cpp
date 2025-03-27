#include "calculator.h"
#include <iostream>

using namespace std;

int main() {
    Calculator calc;
    
    cout << "Addition of 5 and 3: " << calc.add(5, 3) << endl;
    cout << "Subtraction of 10-4: " << calc.subtract(10, 4) << endl;
    cout << "Multiplication 6 and 7: " << calc.multiply(6, 7) << endl;
    cout << "Division of 20 divided by 5: " << calc.divide(20, 5) << endl;
    cout << "Factorial of 5: " << calc.factorial(5) << endl;
    cout << "GCD of 48 and 18: " << calc.gcd(48, 18) << endl;
    cout << "LCM 4 and 6: " << calc.lcm(4, 6) << endl;
    cout << "Random: " << calc.generateRandom(1, 10) << endl;
    
    string expression = "3 + 4 * (2 - 1) / 5";
    cout << "Evaluated Expression (" << expression << "): " << calc.evaluateExpression(expression) << endl;
return 0;
}