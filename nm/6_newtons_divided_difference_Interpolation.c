#include <stdio.h>
#define MAX 100
int main()
{
    int n;
    float x_val;
    printf("Enter the number of points: ");
    scanf("%d", &n);
    printf("Enter the value at which interpolated value is needed (x): ");
    scanf("%f", &x_val);

    float x[MAX], fx[MAX], dd[MAX];
    for (int i=0;i<n;i++) 
    {
        printf("Enter the value of x and f(x) at i = %d:\n", i);
        scanf("%f %f",&x[i],&fx[i]);
        dd[i] = fx[i];
    }

    // Calculating divided differences
    for(int i=1;i<n;i++)
    {
        for(int j=n-1;j>=i;j--) 
        {
            dd[j]=(dd[j]-dd[j-1])/(x[j]-x[j-i]);
        }
    }

    float v=dd[0];
    float p=1;

    for (int i = 1; i < n; i++) 
    {
        p *= (x_val - x[i - 1]);
        v += dd[i] * p;
    }
    
    printf("The Interpolation Value is: %f\n", v);

    return 0;
}

