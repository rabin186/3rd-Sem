#include<stdio.h>
int fibonacci(int n){
  if (n == 0){
    return 0;
  }
  if (n == 1 || n == 2){
    return 1;
  }
  else{
    return fibonacci(n-1)+fibonacci(n-2);
  }
}

int main(){
  int n,i;
  printf("Enter a number upto which you want to find fibonacci series: ");
  scanf("%d",&n);
  printf("%dth fibonacci term is: %d\n",n,fibonacci(n-1));
  printf("The fibonacci No. upto %d is: \n",n);
  for(i=0;i<n;i++){
    printf("%d\t",fibonacci(i));
  }
  printf("\n");
  printf("\n-----------------------------------\n");
  printf("Programmed By Rabin Acharya.\n");
  return 0;  
}
