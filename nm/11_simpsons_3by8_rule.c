#include <math.h>
#include <stdio.h>

double f(double x) { return (pow(x, 3) + 1); }

int main() {
  int i, n = 3;
  float a, b, y[4], h, Ig;
  printf("Enter the initial and final value of x: ");
  scanf("%f%f", &a, &b);
  h = (b - a) / n;

  for (i = 0; i <= n; i++)
    y[i] = f(a + i * h);

  Ig = (3 * h / 8) * (y[0] + y[n] + 3 * (y[1] + y[2]));
  printf("\nThe integration is %.3f", Ig);
  printf("\n---------------------------\n");
  printf("Programmed By Rabin Acharya.\n");
  return 0;
}
