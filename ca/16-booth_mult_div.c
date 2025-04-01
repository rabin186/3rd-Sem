#include <stdio.h>
#include <stdlib.h>

void booth_multiplication(int m, int q, int n) {
  int m_neg = ~m + 1;
  int q1 = 0;
  int accumulator = 0;
  int q_copy = q;

  for (int i = 0; i < n; i++) {
    printf("Step %d: A=%d Q=%d Q1=%d\n", i + 1, accumulator, q_copy, q1);

    if ((q_copy & 1) == 1 && q1 == 0) {
      accumulator += m_neg; // Subtract M
    } else if ((q_copy & 1) == 0 && q1 == 1) {
      accumulator += m; // Add M
    }

    int q0 = q_copy & 1;

    // Arithmetic right shift (preserves sign bit)
    int sign = accumulator & (1 << (n - 1));
    q_copy = (accumulator & 1) << (n - 1) | (q_copy >> 1);
    accumulator = (accumulator >> 1) | sign;

    q1 = q0;
  }

  printf("Final Result: A = %d, Q = %d\n", accumulator, q_copy);
}

void binary_division(int dividend, int divisor, int n) {
  int accumulator = 0; // Remainder (initially 0)
  int quotient = dividend;

  printf("\nDivision\n");

  for (int i = 0; i < n; i++) {
    // Shift left A and Q
    accumulator = (accumulator << 1) | ((quotient >> (n - 1)) & 1);
    quotient = (quotient << 1) & ((1 << n) - 1); // Keep only n bits

    printf("Step %d: A=%d Q=%d\n", i + 1, accumulator, quotient);

    // Subtract divisor
    accumulator -= divisor;

    if (accumulator < 0) {
      accumulator += divisor; // Restore A
    } else {
      quotient |= 1; // Set Q0 = 1
    }
  }

  printf("Final Quotient: %d, Remainder: %d\n", quotient, accumulator);
}

int main() {
  int m, q, n;
  printf("Enter the number of bits: ");
  scanf("%d", &n);
  printf("\n=============================\n");
  printf("Booth Multiplication\n");
  printf("Enter the multiplicand: ");
  scanf("%d", &m);
  printf("Enter the multiplier: ");
  scanf("%d", &q);
  booth_multiplication(m, q, n);
  printf("\n=============================\n");
  printf("Booth Division\n");
  printf("Enter the dividend: ");
  scanf("%d", &m);
  printf("Enter the divisor: ");
  scanf("%d", &q);
  binary_division(m, q, n);
  printf("\n--------------------------\n");
  printf("Programmed By Rabin Acharya.\n");
  return 0;
}
