#include <stdio.h>

double f(double x) {
  return x * x + 4 * x - 9; // Function: x^2 - 4x - 10
}

int main() {
  float x0, x1;
  float fx0, fx1, h;
  printf("Enter the lower and upper limit: ");
  scanf("%f%f", &x0, &x1);
  fx0 = f(x0);
  fx1 = f(x1);
  h = x1 - x0;
  float integration = (h / 2) * (fx0 + fx1);
  printf("The value of integration is: %f\n", integration);
  printf("\n---------------------------\n");
  printf("Programmed By Rabin Acharya.\n");
  return 0;
}
