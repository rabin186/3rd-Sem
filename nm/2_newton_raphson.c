#include <stdio.h>
#include <math.h>

#define E 0.00001  // Convergence tolerance
#define H 0.00001  // Step size for numerical differentiation

// Function whose root we need to find
double f(double x) {
    return x * x + 4 * x - 9;  // Function: x^2 - 4x - 10
}

// Numerical derivative using central difference method
double df(double x) {
    return (f(x + H) - f(x - H)) / (2 * H);
}

int main() {
    int count = 0;
    double x0, x1;

    // Get initial guess from user
    printf("Please Enter the initial guess: ");
    scanf("%lf", &x0);

    while (1) {
        double fx = f(x0);
        double dfx = df(x0);

        if (fabs(dfx) < E) {  // Prevent division by zero
            printf("Mathematical error: derivative too small.\n");
            return 1;  // Exit the program
        }

        x1 = x0 - fx / dfx;
        printf("Iteration %d: x = %.6f\n", count, x1);

        if (fabs(x1 - x0) < E) {  // Convergence check
            break;
        }

        x0 = x1;
        count++;
    }

    printf("The root is: %.6f\n", x1);
    printf("\n-----------------------\n");
    printf("Programmed By Rabin Acharya.\n");
    return 0;
}

