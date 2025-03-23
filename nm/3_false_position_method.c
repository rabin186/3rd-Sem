#include <stdio.h>
#include <math.h>

#define E 0.00001  
#define H 0.00001  

double f(double x) {
    return x * x + 4 * x - 9;  
}

int main() {
    double a, b;
    printf("Enter the interval [a, b]: ");
    scanf("%lf %lf", &a, &b);
    if (f(a) * f(b) >= 0) {
        printf("Invalid interval: f(a) and f(b) must have opposite signs.\n");
        return 1;
    }

    double c;
    int count = 0;
    
    while (1) {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        printf("Iteration %d: c = %.6f\n", count, c);
        
        if (fabs(f(c)) < E) {
            break;
        }
        
        if (f(c) * f(a) < 0) {
            b = c;
        } else {
            a = c;
        }
        
        count++;
    }
    
    printf("The root is: %.6f\n", c);
    return 0;
}
