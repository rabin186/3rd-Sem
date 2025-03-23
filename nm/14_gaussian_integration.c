#include <stdio.h>
#include <math.h>

double f(double x) {
    return pow(x, 2)+4;
}

int main() {
    int i, n = 3;
    float a, b, c, x[3], z[3], w[3], Ig = 0;

    printf("Enter the lower and upper limit of x: ");
    scanf("%f%f",&a,&b);

    z[0] = -0.77460;
    z[1] = 0;
    z[2] = 0.77460;
    
    w[0] = w[2] = 0.55556;
    w[1] = 0.88889;

    c = (b - a) / 2;
    for (i = 0; i < n; i++) {
        x[i] = c * z[i] + (b + a) / 2;
    }
    for (i = 0; i < n; i++) {
        Ig += w[i] * f(x[i]);
    }
    Ig *= c;
    printf("\nThe integration is %f\n", Ig);
    printf("\n-----------------------------\n");
    printf("Programmed By Rabin Acharya.\n");

    return 0;
}

