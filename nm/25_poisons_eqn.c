#include <math.h>
#include <stdio.h>

#define g(x, y) (2.0 * (x) * (x) * (y) * (y)) // Poisson Source Function

int main() {
  int n, i, j, k;
  float sum, error, E[100], a[100][100], b[100], new_x[100], old_x[100];
  float tl, tr, tu, tb, h;

  // Input parameters
  printf("Enter Dimension of plate: ");
  scanf("%d", &n);
  h = 1.0 / (n + 1); // Grid spacing for a unit square

  printf("Enter temperatures at Left, Right, Bottom & Top:\n");
  scanf("%f %f %f %f", &tl, &tr, &tb, &tu);

  // Initialize coefficient matrix (Laplace Operator)
  for (i = 0; i < n * n; i++) {
    for (j = 0; j < n * n; j++) {
      a[i][j] = 0; // Initialize to 0
    }
    a[i][i] = -4; // Diagonal elements
  }

  for (i = 0; i < n * n; i++) {
    if (i % n != 0) // Left neighbor
      a[i][i - 1] = 1;
    if ((i + 1) % n != 0) // Right neighbor
      a[i][i + 1] = 1;
    if (i >= n) // Bottom neighbor
      a[i][i - n] = 1;
    if (i < n * (n - 1)) // Top neighbor
      a[i][i + n] = 1;
  }

  // Construct RHS vector b
  k = 0;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      b[k] = h * h * g(i * h, j * h); // Apply source function

      // Apply boundary conditions
      if (i == 1)
        b[k] -= tl; // Left
      if (i == n)
        b[k] -= tr; // Right
      if (j == 1)
        b[k] -= tb; // Bottom
      if (j == n)
        b[k] -= tu; // Top

      k++;
    }
  }

  printf("Enter Accuracy Limit: ");
  scanf("%f", &error);

  // Initialize solution
  for (i = 0; i < n * n; i++) {
    new_x[i] = 0;
  }

  // Gauss-Seidel Iteration
  while (1) {
    for (i = 0; i < n * n; i++) {
      sum = b[i];
      for (j = 0; j < n * n; j++) {
        if (i != j) {
          sum -= a[i][j] * new_x[j];
        }
      }
      old_x[i] = new_x[i];
      new_x[i] = sum / a[i][i];
      E[i] = fabs(new_x[i] - old_x[i]) / fabs(new_x[i]);
    }

    // Check for convergence
    for (i = 0; i < n * n; i++) {
      if (E[i] > error)
        break;
    }
    if (i == n * n)
      break;
  }

  // Print the solution in the required format
  printf("\nSolution:\n");
  for (i = 0; i < n * n; i++) {
    printf("x%d = %.2f\n", i + 1, new_x[i]); // Prints x1, x2, x3, ...
  }
  printf("\n--------------------------\m");
  printf("Programmed By Rabin Acharya.\n");
  return 0;
}
