#include<stdio.h>
float f(float x,float y)
{
  return 2*y/x;
}
int main()
{
  float x0,y0,xp,h;
  printf("Enter the initial values: ");
  scanf("%f%f",&x0,&y0);
  printf("Enter the value at which functional value is required: ");
  scanf("%f",&xp);
  printf("Enter the step size: ");
  scanf("%f",&h);
  float y=y0, x=x0;
  for(x=x0;x<xp;x=x+h)
  {
    y=y+f(x,y)*h;
  }
  printf("Functional Value at x=%f is %f\n",xp,y);
  printf("\n-------------------------\n");
  printf("Programmed By Rabin Acharya.\n");
  return 0;
}
