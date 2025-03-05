#include<stdio.h>
#include<string.h>
void TOH(int n, char S, char D, char temp){
  if (n>0){
    TOH(n-1,S,temp,D);
    printf("Move disk %d from %c to %c\n",n,S,D);
    TOH(n-1,temp,D,S);
  }
}
int main(){
  int n;
  printf("Enter the no. of disks: ");
  scanf("%d",&n);
  TOH(n,'S','D','T');
  printf("Note: S=Source, D=Destination, T=Temporary \n");
  printf("\n-----------------------------------\n");
  printf("Programmed By Rabin Acharya.\n");
  return 0;
}
