#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

double calcPiAcos() 
{ 
    // Find value of pi using 
    // acos() function 
    return 2 * acos(0.0); // 2 x pi/2
} 

double calcPiTaylor(int n) {
    /*
    Taylor expansion of arctanb = integral of 1/(1+x^2) from b to 0 
    arctan(1) = pi/4 
    */
    double sum = 0.0;
    int sign = 1;
    for (int i = 0; i < n; ++i) {         
        sum += sign/(2.0*i+1.0);
        sign *= -1;
    }
    return 4.0*sum;
}

void testCalcPiAcos() {
    const double expected_pi = 3.14159265358979323846; // Reference Pi
    double pi_from_acos = calcPiAcos();
    assert(fabs(pi_from_acos - expected_pi) < 1e-12); // Assert that the difference is very small
    cout << "testCalcPiAcos passed!\n";
}

void testCalcPiTaylor() {
    const double expected_pi = 3.14159265358979323846; // Reference Pi

    double pi_taylor_10 = calcPiTaylor(10);
    assert(fabs(pi_taylor_10 - expected_pi) > 1e-2);

    double pi_taylor_1000 = calcPiTaylor(1000);
    assert(fabs(pi_taylor_1000 - expected_pi) < 1e-3);

    double pi_taylor_1000000 = calcPiTaylor(1000000);
    assert(fabs(pi_taylor_1000000 - expected_pi) < 1e-6);

    cout << "testCalcPiTaylor passed!\n";
}

int main()
{
    testCalcPiAcos();
    testCalcPiTaylor();

    return 0; 
}
