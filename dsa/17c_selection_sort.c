#include<stdio.h>
#define MAX 100
void selection_sort(int a[], int n)
{
  int i,k,temp,index,least;
  for(i=0;i<n;i++)
  {
    least=a[i];
    index=i;
    for(k=i+1;k<n;k++)
    {
      if(a[k]<least)
      {
        least=a[k];
        index=k;
      }
    }
    if(i!=index)
    {
      temp=a[i];
      a[i]=a[index];
      a[index]=temp;
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
  selection_sort(a,n);
  printf("\nThe data items after sorting: \n");
  for(i=0;i<n;i++)
  {
    printf("%d\t",a[i]);
  }
  printf("\n---------------------\n");
  printf("Programmed By Rabin Acharya.\n");
  return 0;
}
