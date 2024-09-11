#include <iostream>
#include <cmath>

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

int main()
{
    printf("%0.20f\n", calcPiAcos()); 
    printf("%0.20f\n", calcPiTaylor(1000000)); 

    return 0; 
}
