#include <stdio.h>
int gcd(int x, int y) 
{
    if (x == 0) 
    {
        return y;
    }
    return gcd(y % x, x); 
}
int main() 
{
    int x, y, g;
    printf("Please enter two numbers whose GCD you want to calculate: ");
    scanf("%d %d", &x, &y);
    g = gcd(x, y);
    printf("The GCD of %d and %d is: %d\n", x, y, g);
    printf("\n-----------------------------\n");  
    printf("Programmed By Rabin Acharya.\n");
    return 0;
}

