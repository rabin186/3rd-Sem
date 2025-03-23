#include<stdio.h>
#include<math.h>
double f(double x)
{
  return (pow(x,3)+1);
}

int main()
{
    int i,n;
    float a,x0,xn,h,Ig,term;
    printf("Enter the lower and upper limit: ");
    scanf("%f%f",&x0,&xn);
    printf("Enter the number of Segments: ");
    scanf("%d",&n);
    h=(xn-x0)/n;
    term=f(x0)+f(xn);
    for(i=0;i<n;i+=2)
    {
      a=x0+i*h;
      term=term+4*(f(a));
    }
    for(i=2;i<n-1;i+=2)
    {
      a=x0+i*h;
      term=term+2*(f(a));

    }
    Ig=h/3*term;
    printf("\nThe integration is %f.\n",Ig);
    printf("\n-----------------------------\n");
    printf("Programmed By Rabin Acharya.\n");
    return 0;
}
