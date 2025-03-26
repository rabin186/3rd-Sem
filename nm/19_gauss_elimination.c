#include <stdio.h>

void gaussElimination(int n, float a[n][n + 1]) {
  int i, j, k;
  float factor;
  for (i = 0; i < n; i++) {
    if (a[i][i] == 0) {
      printf("Error: Division by zero detected.\n");
      return;
    }
    for (j = i + 1; j < n; j++) {
      factor = a[j][i] / a[i][i];
      for (k = i; k <= n; k++) {
        a[j][k] -= factor * a[i][k];
      }
    }
  }
  float x[n];
  for (i = n - 1; i >= 0; i--) {
    x[i] = a[i][n];
    for (j = i + 1; j < n; j++) {
      x[i] -= a[i][j] * x[j];
    }
    x[i] /= a[i][i];
  }
  printf("\nSolution:\n");
  for (i = 0; i < n; i++) {
    printf("x[%d] = %.4f\n", i + 1, x[i]);
  }
}

int main() {
  int n, i, j;
  printf("Enter number of equations: ");
  scanf("%d", &n);
  float a[n][n + 1];
  printf("Enter the augmented matrix:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j <= n; j++) {
      scanf("%f", &a[i][j]);
    }
  }
  gaussElimination(n, a);
  printf("\n----------------------------\n");
  printf("Programmed By Rabin Acharya.\n");
  return 0;
}
