#include <stdio.h>

#define MAX 10

int main() {
  int i, j, n;
  float x[MAX], f[MAX], sum = 0, pro, xp, fp;

  printf("Enter the number of data points (max %d): ", MAX);
  scanf("%d", &n);

  if (n > MAX) {
    printf("Error: Maximum number of data points exceeded!\n");
    return 1;
  }

  for (i = 0; i < n; i++) {
    printf("\nInput the data points for x[%d] & f[%d]:\n", i, i);
    printf("x[%d] = ", i);
    scanf("%f", &x[i]);
    printf("f[%d] = ", i);
    scanf("%f", &f[i]);
  }

  printf("\nInput the specified value of x: ");
  scanf("%f", &xp);

  for (i = 0; i < n; i++) {
    pro = 1.0;
    for (j = 0; j < n; j++) {
      if (i != j) {
        pro *= (xp - x[j]) / (x[i] - x[j]);
      }
    }
    sum += pro * f[i];
  }

  fp = sum;
  printf("\nThe required functional value at %.6f = %.6f\n", xp, fp);
  printf("--------------------------------------\n");
  printf("Programmed By Rabin Acharya");
  return 0;
}
