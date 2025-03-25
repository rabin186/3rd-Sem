#include <stdio.h>

int main() {
  int n,i,j,k;
  printf("Enter the size of the square matrix (n): ");
  scanf("%d", &n);
  float A[n][n], L[n][n], U[n][n];
  printf("Enter the elements of the matrix A:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%f", &A[i][j]);
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      L[i][j] = 0;
      U[i][j] = 0;
    }
  }
  for (i = 0; i < n; i++) 
  {
    for (k = i; k < n; k++) 
    {
      float sum = 0;
      for (j = 0; j < i; j++) 
      {
        sum += L[i][j] * U[j][k];
      }
      U[i][k] = A[i][k] - sum;
    }
    for (k = i; k < n; k++) {
      if (i == k) {
        L[i][i] = 1; // Diagonal elements of L are 1
      } else {
        float sum = 0;
        for (j = 0; j < i; j++) {
          sum += L[k][j] * U[j][i];
        }
        L[k][i] = (A[k][i] - sum) / U[i][i];
      }
    }
  }
  printf("\nLower Triangular Matrix (L):\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%.4f\t", L[i][j]);
    }
    printf("\n");
  }

  printf("\nUpper Triangular Matrix (U):\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%.4f\t", U[i][j]);
    }
    printf("\n");
  }
  printf("\n----------------------------\n");
  printf("Programmed By Rabin Acharya.\n");
  return 0;
}
