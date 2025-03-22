#include<stdio.h>
#define MAX 100
void bubble_sort(int a[], int n)
{
  int i,k,temp;
  for(i=0;i<n;i++)
  {
    for(k=0;k<n-i-1;k++)
    {
      if(a[k]>a[k+1])
      {
        temp=a[k];
        a[k]=a[k+1];
        a[k+1]=temp;
      }
    }
  }
}
int main()
{
  int n,i,a[MAX];
  printf("Enter the no. of data items: ");
  scanf("%d",&n);
  printf("Enter %d data items: ",n);
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  printf("The data items before sorting: \n");
  for(i=0;i<n;i++)
  {
    printf("%d\t",a[i]);
  }
  bubble_sort(a,n);
  printf("\nThe data items after sorting: \n");
  for(i=0;i<n;i++)
  {
    printf("%d\t",a[i]);
  }
  printf("\n---------------------\n");
  printf("Programmed By Rabin Acharya.\n");
  return 0;
}
