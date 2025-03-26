#include <math.h>
#include <stdio.h>

double f(double x) { return 1.0 / x; }

int main() {
  int i, j, k, p, q;
  double x0, xn, h, T[10][10], sm;

  printf("Enter the lower and upper limit of x: ");
  scanf("%lf %lf", &x0, &xn);
  printf("Enter p & q of required T(p,q): ");
  scanf("%d %d", &p, &q);

  h = (xn - x0);
  T[0][0] = (h / 2) * (f(x0) + f(xn));

  for (i = 1; i <= p; i++) {
    h /= 2.0;
    sm = 0.0;
    for (k = 1; k <= pow(2, i - 1); k++) {
      sm += f(x0 + (2 * k - 1) * h);
    }
    T[i][0] = 0.5 * T[i - 1][0] + sm * h;
    for (j = 1; j <= i && j <= q; j++) {
      T[i][j] = (pow(4, j) * T[i][j - 1] - T[i - 1][j - 1]) / (pow(4, j) - 1);
    }
  }

  printf("\nThe Romberg Estimate of integration is: %.6f\n", T[p][q]);
  printf("\n---------------------------\n");
  printf("Programmed By Rabin Acharya.\n");

  return 0;
}
