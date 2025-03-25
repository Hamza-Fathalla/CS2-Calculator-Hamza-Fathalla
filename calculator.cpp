#include "calculator.h"
#include <cstdlib>
#include <ctime>
#include <iostream>  
using namespace std; 

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

double divide(int a, int b) {
    if (b == 0) {
        cout << "Error, you cannot divide by 0" <<endl;
        return 0;      }
    return a/(double)b;
}

int factorial(int n) {
    if (n == 0 || n == 1) return 1;
    int result = 1;
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

int random_number(int min, int max) {
    srand(time(0));
    return rand() % (max - min + 1) + min;
}
