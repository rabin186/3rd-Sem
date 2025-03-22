#include<stdio.h>
#define MAX 100
void insertion_sort(int a[], int n)
{
  int i,k,temp;
  for(i=0;i<n;i++)
  {
    temp = a[i];
    k = i-1;
    while(k>=0&&a[k]>temp)
    {
      a[k+1]=a[k];
      k = k-1;
    }
    a[k+1] = temp;
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
  insertion_sort(a,n);
  printf("\nThe data items after sorting: \n");
  for(i=0;i<n;i++)
  {
    printf("%d\t",a[i]);
  }
  printf("\n---------------------\n");
  printf("Programmed By Rabin Acharya.\n");
  return 0;
}
