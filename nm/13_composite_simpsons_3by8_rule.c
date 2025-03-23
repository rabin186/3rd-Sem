#include <stdio.h>
#include <math.h>

double f(double x) {
    return pow(x, 3) + 3 * pow(x, 2);
}

int main() {
    int i, n;
    float x0, xn, h, Ig, term = 0;

    printf("Enter the lower and upper limit: ");
    scanf("%f%f", &x0, &xn);
    printf("Enter the number of Segments (multiple of 3): ");
    scanf("%d", &n);

    if (n % 3 != 0) {
        printf("Error: Simpson's 3/8 rule requires the number of segments to be a multiple of 3.\n");
        return 1;
    }

    h = (xn - x0) / n;

    term = f(x0) + f(xn);

    for (i = 1; i < n; i++) {
        double a = x0 + i * h;

        if (i % 3 == 0) {
            term += 2 * f(a);
        } 
        else {
            term += 3 * f(a);
        }
    }

    Ig = (3.0 / 8.0) * h * term;

    printf("\nThe integration is %f.\n", Ig);
    printf("\n-----------------------------\n");
    printf("Programmed By Rabin Acharya.\n");

    return 0;
}

