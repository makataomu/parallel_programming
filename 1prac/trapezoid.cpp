#include<stdio.h>
#include<assert.h>
#include<math.h>

// Define the type for a function that takes a float and returns a float
typedef float (*func_ptr)(float);

float func2(float x)
{
    return 1/(1+x*x);
}

float func1(float x)
{
    return x*x*x + 1;
}

// Trapezoidal num method to approximate definite integrals
float trapezoidal(float a, float b, float n, func_ptr func)
{
    /*
    a - lower bound
    b - upper bound
    n - number of отрезков
    formula - h/2 (f(x0) + 2 f1(x1) + ... + 2 f1(xn-1) + f(xn))
    */
    float step = (b-a)/n; // delta x - step

    // Computing sum of first and last terms
    // in above formula
    float sum = func(a) + func(b);

    // Adding middle terms in above formula
    for (int index = 1; index < n; index++)
        sum += 2 * func(a + index*step);

    return (step/2)*sum;
}

void testTrapezoidal() {
    // Test case 1: Integral of 1/(1 + x^2) from 0 to 1 (arctan(1) = pi/4)
    float result = trapezoidal(0, 1, 6, func2);  // Using 6 intervals
    float expected = M_PI / 4;            // Analytical value of the integral
    assert(fabs(result - expected) < 1e-2);  // Allowing small error
    printf("testTrapezoidal (n=6) passed!\n");

    // Test case 2: Increase intervals for better precision
    result = trapezoidal(0, 1, 1000, func2);     // Using 1000 intervals
    assert(fabs(result - expected) < 1e-6);  // Expect much better accuracy
    printf("testTrapezoidal (n=1000) passed!\n");

    // Test case 3: Testing with different range (0 to 2)
    result = trapezoidal(0, 2, 1000, func2);     // Approximate arctan(2)
    expected = atan(2);                   // Analytical value of arctan(2)
    assert(fabs(result - expected) < 1e-6);  // Should be accurate
    printf("testTrapezoidal (0 to 2) passed!\n");
}

int main()
{
    testTrapezoidal();

    // Range of definite integral
    float x0 = 0;
    float xn = 4;

    int n = 4;

    printf("Value of integral is %6.4f\n",
                  trapezoidal(x0, xn, n, func2));
    return 0;
}