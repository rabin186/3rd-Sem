#include<stdio.h>
int binary_search(int a[100],int l,int r,int key)
{
  int m;
  int flag=0;
  if(l<=r)
  {
    m=(l+r)/2;
    if(key==a[m])
    {
      flag=m;
    }
    else if(key<a[m])
    {
      return binary_search(a,l,m-1,key);
    }
    else
    {
      return binary_search(a,m+1,r,key);
    }
  }
  else
  {
    return flag;
  }
}
int main()
{
  int a[100],n,i,key,flag;
  printf("Enter no. of data items: \n");
  scanf("%d",&n);
  printf("Enter %d data items in sorted form: \n",n);
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  printf("Enter the data to be searched: ");
  scanf("%d",&key);
  flag=binary_search(a,0,n-1,key);
  if(flag==0)
  {
    printf("Search Un-succesful.");
  }
  else 
  {
    printf("Search Succesful and found ot location %d.",flag+1);
  }
  printf("\n---------------------------\n");
  printf("Programmed By Rabin Acharya.\n");
  return 0;
}
