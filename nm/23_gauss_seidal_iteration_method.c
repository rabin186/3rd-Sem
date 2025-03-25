#include <math.h>
#include <stdio.h>

#define MAX_ITER 100
#define TOLERANCE 0.0001

void gaussSeidel(int n, double a[n][n], double b[n], double x[n]) {
  int i, j, iter;
  double sum, error, new_xi;

  printf("Iteration\tSolutions\t\t\tError\n");
  printf("------------------------------------------------\n");

  for (iter = 1; iter <= MAX_ITER; iter++) {
    error = 0.0;

    for (i = 0; i < n; i++) {
      sum = 0.0;
      for (j = 0; j < n; j++) {
        if (j != i) {
          sum += a[i][j] * x[j];
        }
      }

      new_xi = (b[i] - sum) / a[i][i];
      error += fabs(new_xi - x[i]);
      x[i] = new_xi;
    }

    // Print current iteration results
    printf("%d\t\t", iter);
    for (i = 0; i < n; i++) {
      printf("x[%d]=%.6f  ", i, x[i]);
    }
    printf("\t%.6f\n", error);

    // Check for convergence
    if (error < TOLERANCE) {
      printf("\nConverged after %d iterations.\n", iter);
      return;
    }
  }

  printf("\nMaximum iterations reached without convergence.\n");
}

int main() {
  int n, i, j;

  printf("Enter the number of equations: ");
  scanf("%d", &n);

  double a[n][n], b[n], x[n];

  printf("Enter the coefficients matrix (A):\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%lf", &a[i][j]);
    }
  }

  printf("Enter the right-hand side vector (B):\n");
  for (i = 0; i < n; i++) {
    scanf("%lf", &b[i]);
  }

  printf("Enter initial guesses for solutions:\n");
  for (i = 0; i < n; i++) {
    scanf("%lf", &x[i]);
  }

  gaussSeidel(n, a, b, x);

  printf("\nFinal Solution:\n");
  for (i = 0; i < n; i++) {
    printf("x[%d] = %.6f\n", i, x[i]);
  }
  printf("\n-----------------------\n");
  printf("Programmed By Rabin Acharya.\n");
  return 0;
}
