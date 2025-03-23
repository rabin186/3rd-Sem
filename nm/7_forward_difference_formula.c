#include <stdio.h>

#define MAX 10

int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

int main() {
    int n;
    float xp;
    float x[MAX], fx[MAX], fd[MAX];

    printf("Enter the number of data points: ");
    scanf("%d", &n);
    printf("Enter the value at which derivative is needed: ");
    scanf("%f", &xp);

    for (int i = 0; i < n; i++) 
    {
        printf("Enter the value of x and f(x) at i = %d:\n", i);
        scanf("%f%f", &x[i], &fx[i]);
        fd[i] = fx[i];
    }

    float h = x[1] - x[0];
    float s = (xp - x[0]) / h;

    for (int i = 1; i < n; i++) {
        for (int j = n - 1; j >= i; j--) 
        {
            fd[j] = fd[j] - fd[j - 1];
        }
    }

    float val = fd[1] / h;
    float product = 1.0;

    for (int i = 2; i < n; i++) {
        product *= (s - (i - 1));
        val += (fd[i] * product) / (factorial(i) * h);
    }

    printf("The first derivative is: %.6f\n", val);
    printf("/n---------------------------------------/n");
    printf("Programmed by Rabin Acharya.");
    return 0;
}

