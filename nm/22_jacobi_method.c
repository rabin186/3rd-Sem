#include <stdio.h>
#include <math.h>

#define MAX_SIZE 10
#define TOLERANCE 0.0001
#define MAX_ITER 100

int main() {
    int i, j, k, n;
    float a[MAX_SIZE][MAX_SIZE], x[MAX_SIZE], x_new[MAX_SIZE], sum;
    
    // Input: Number of unknowns
    printf("Enter the dimension of system of equations: ");
    scanf("%d", &n);

    // Input: Augmented matrix
    printf("Enter %d x %d elements for the augmented matrix:\n", n, n + 1);
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            scanf("%f", &a[i][j]);
        }
        x[i] = 0.0;
    }
    printf("\nThe Solution Process is:\n");
    printf("x1(k+1)\tx2(k+1)\tx3(k+1)\n");
    printf("------------------------\n");

    for (k = 1; k <= MAX_ITER; k++) {
        for (i = 0; i < n; i++) {
            sum = 0.0;
            for (j = 0; j < n; j++) {
                if (i != j) {
                    sum += a[i][j] * x[j];
                }
            }
            x_new[i] = (a[i][n] - sum) / a[i][i]; // Update new value
            printf("%.3f\t", x_new[i]);
        }
        printf("\n");

        // Check for convergence
        int converged = 1;
        for (i = 0; i < n; i++) {
            if (fabs(x_new[i] - x[i]) > TOLERANCE) {
                converged = 0;
                break;
            }
        }

        // Update solution vector
        for (i = 0; i < n; i++) {
            x[i] = x_new[i];
        }

        // Stop if converged
        if (converged) {
            break;
        }
    }

    // Output results
    if (k > MAX_ITER) {
        printf("Maximum number of iterations exceeded.\n");
    } else {
        printf("\nThe solution set using Jacobi's Iterative Method is:\n");
        for (i = 0; i < n; i++) {
            printf("x[%d] = %.3f\n", i + 1, x[i]);
        }
        printf("\nThe number of iterations: %d\n", k);
    }
    printf("\n-----------------------------\n");
    printf("Programmed By Rabin Acharya\n");
    return 0;
}
