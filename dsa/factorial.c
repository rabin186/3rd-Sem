#include<stdio.h>
int factorial(int n){
  if (n==1){
    return 1;
  }
  else{
    return n*factorial(n-1);
  }
}
int main(){
  int a,fact;
  printf("Please Enter a number: ");
  scanf("%d",&a);
  fact=factorial(a);
  printf("The factorial of %d is %d\n",a,fact);
  printf("\n-----------------------------------\n");
  printf("Programmed By Rabin Acharya.\n");
  return 0;
}
