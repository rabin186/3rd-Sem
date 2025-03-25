#include <stdio.h>

void gaussJordan(int n, float a[n][n + 1]) {
  int i, j, k;
  float factor;
  for (i = 0; i < n; i++) {
    if (a[i][i] == 0) {
      int swapRow = -1;
      for (j = i + 1; j < n; j++) {
        if (a[j][i] != 0) {
          swapRow = j;
          break;
        }
      }
      if (swapRow == -1) {
        printf("Error: Division by zero detected. No unique solution exists.\n");
        return;
      }
      for (k = 0; k <= n; k++) {
        float temp = a[i][k];
        a[i][k] = a[swapRow][k];
        a[swapRow][k] = temp;
      }
    }
    float pivot = a[i][i];
    for (j = i; j <= n; j++) {
      a[i][j] /= pivot;
    }
    for (j = 0; j < n; j++) {
      if (j != i) {
        factor = a[j][i];
        for (k = i; k <= n; k++) {
          a[j][k] -= factor * a[i][k];
        }
      }
    }
  }
  printf("\nSolution:\n");
  for (i = 0; i < n; i++) {
    printf("x[%d] = %.4f\n", i + 1, a[i][n]);
  }
}

int main() {
  int n, i, j;
  printf("Enter number of equations: ");
  scanf("%d", &n);

  float a[n][n + 1];
  printf("Enter the augmented matrix (coefficients + constants):\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j <= n; j++) {
      scanf("%f", &a[i][j]);
    }
  }

  gaussJordan(n, a);
  printf("\n-------------------------\n");
  printf("Programmed By Rabin Acharya.\n");
  return 0;
}
