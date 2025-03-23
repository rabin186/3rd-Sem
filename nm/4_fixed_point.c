#include <stdio.h>
#include <math.h>

#define E 0.00001  // Convergence criteria
#define MAX_ITER 1000  // Maximum iterations

// We define the function g(x) such that x = g(x)
double g(double x) {
    return (9 - x * x) / 4;  // For x^2 + 4x - 9 = 0
}

int main() {
    double x0, x1;
    int count = 0;
    printf("Enter initial guess: ");
    scanf("%lf", &x0);

    printf("\nIteration\t x\n");

    while (1) {
        x1 = g(x0);
        printf("%d\t\t %.6f\n", count, x1);

        if (fabs(x1 - x0) < E)
        {
            break;
        }

        x0 = x1;
        count++;

        if (count > MAX_ITER) {
            printf("Method did not converge.\n");
            return 1;
        }
    }

    printf("\nThe root is: %.6f\n", x1);
    return 0;
}

