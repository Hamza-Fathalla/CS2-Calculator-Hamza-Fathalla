#include <iostream>
#include "calculator.h"
using namespace std;
int main() {

    int a = 10, b = 5;
    cout << "Addition: " << add(a, b) << endl;

    cout << "Subtraction: " << subtract(a, b) << endl;

    cout << "Multiplication: " << multiply(a, b) << endl;

    cout << "Division: " << divide(a, b) << endl;
    cout << "Division by Zero: " << divide(a, 0) << endl;

    int n = 5;
    cout << "Factorial of " << n << ": " << factorial(n) << endl;
    
    int num1 = 48, num2 = 18;
    cout << "GCD of " << num1 << " and " << num2 << ": " << gcd(num1, num2) << endl;

    cout << "LCM of " << num1 << " and " << num2 << ": " << lcm(num1, num2) << endl;

    int min = 1, max = 100;
    cout << "Random number between " << min << " and " << max << ": " << random_number(min, max) << endl;

    return 0;
}
