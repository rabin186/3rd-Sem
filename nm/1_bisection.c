#include <math.h>
#include <stdio.h>
#define MAX 100
#define E 0.00001
#define f(x) (3 * x * x - 6 * x + 2)

int main() {
  int count = 0;
  float x1, x2, x0;
  printf("Enter the initial guess values x1 and x2\n");
  scanf("%f%f", &x1, &x2);

  if (f(x1) * f(x2) > 0)
    printf("The guess values don't bracket root. Change the guess values.\n");
  else {
    while (count < MAX) {
      x0 = (x1 + x2) / 2;
      if (fabs(f(x0)) < E) {
        printf("\nThe root is %.6f", x0);
        printf("\nNo. of iterations is %d\n", count);
        break;
      } else {
        if (f(x0) > 0)
          x2 = x0;
        else
          x1 = x0;

        count++;
      }
    }

    if (count == MAX)
      printf("\nThe process doesn't converge within the maximum iterations.\n");
  }

  printf("\n--------------------------\n");
  printf("Programmed By Rabin Acharya.\n");
  return 0;
}
