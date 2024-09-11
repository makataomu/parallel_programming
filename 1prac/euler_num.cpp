#include <iostream>
#include <cmath>
#include <iomanip>
#include <cassert>  // For testing

using namespace std;

double Factorial(int n) {    // Max n = 170
    if(n == 0) return 1;     // Add case for 0! = 1
    if(n == 1) return 1;
    else return n * Factorial(n - 1);
}

double GetEuler(int n) {
    // 1 + 1/1! + 1/2! + 1/3! ....
    if(n == 0) return 1;
    else return (1 / Factorial(n) + GetEuler(n - 1));
}

void testGetEuler() {
    const double known_e = 2.718281828459045;  // Known value of e
    double e_approx_10 = GetEuler(10);
    double e_approx_20 = GetEuler(20);

    assert(fabs(e_approx_10 - known_e) < 1e-3);
    assert(fabs(e_approx_20 - known_e) < 1e-6);
    cout << "testGetEuler passed!" << endl;
}

int main() {
    // Running tests
    testGetEuler();

    // Running the main program
    double e = GetEuler(170);  // 170 terms should be very accurate
    cout << setprecision(15) << e << endl;  // Should print accurate Euler's number

    return 0;
}

/*
not defined by geometry. related to growth.
(1+1/n)^n n to inf = e
11 2 11 4 11 6
*/