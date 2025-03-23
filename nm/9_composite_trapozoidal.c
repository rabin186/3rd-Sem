#include<stdio.h>
#include<math.h>
#define MAX 10
double f(double x)
{
  return (pow(x,3)+1);
}

int main()
{
    int i,n;
    float a,b,y[MAX],h,sum=0,Ig;
    printf("Enter the initial and final value of x: ");
    scanf("%f%f",&a,&b);
    printf("Enter the no. of segments: ");
    scanf("%d",&n);
    h=(b-a)/n;
    for(i=0;i<=n;i++)
    {
        y[i]=f(a+i*h);
    }
    for(i=1;i<=n-1;i++)
        sum+=y[i];
    Ig=h/2*(y[0]+y[n]+2*sum);
    printf("\nThe integration is %f",Ig);
    printf("\n---------------------------\n");
    printf("Programmed By Rabin Acharya.\n");
    return 0;
}
