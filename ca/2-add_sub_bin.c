#include <stdio.h>

int addition(int a, int b) {
  int result = 0, rem = 0;
  int place = 1;

  while (a > 0 || b > 0 || rem > 0) {
    int temp_a = a % 10;
    int temp_b = b % 10;

    int temp_sum = (temp_a + temp_b + rem) % 2;
    rem = (temp_a + temp_b + rem) / 2;
    result += (temp_sum * place);

    place *= 10;
    a /= 10;
    b /= 10;
  }
  return result;
}

int subtract(int a, int b) {
  int result = 0, borrow = 0;
  int place = 1;

  while (a > 0 || b > 0) {
    int temp_a = a % 10;
    int temp_b = b % 10;

    int temp_sub = temp_a - temp_b - borrow;

    if (temp_sub < 0) {
      temp_sub += 2;
      borrow = 1;
    } else {
      borrow = 0;
    }

    result += (temp_sub * place);
    place *= 10;

    a /= 10;
    b /= 10;
  }

  return result;
}

int main() {
  int op, add_result, sub_result, b1, b2;
  printf("Enter first binary number: ");
  scanf("%d", &b1);
  printf("Enter second binary number: ");
  scanf("%d", &b2);
  add_result = addition(b1, b2);
  printf("Binary Addition Result: %d\n", add_result);
  sub_result = subtract(b1, b2);
  printf("Binary Subtraction Result: %d\n", sub_result);
  printf("\n------------------------------\n");
  printf("Programmed By Rabin Acharya.\n");
}
