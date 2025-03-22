#include <stdio.h>
#define MAX 100

void swap(int *a, int *b) 
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int a[], int low, int high) 
{
  int pivot = a[high], i = low - 1, j;
  for (j = low; j < high; j++) 
  {
    if (a[j] < pivot) 
    {
      i++;
      swap(&a[i], &a[j]);
    }
  }
  swap(&a[i + 1], &a[high]);
  return i + 1;
}

void quick_sort(int a[], int low, int high) 
{
  if (low < high) 
  {
    int pi = partition(a, low, high);
    quick_sort(a, low, pi - 1);
    quick_sort(a, pi + 1, high);
  }
}

int main() {
  int n, i, a[MAX];
  printf("Enter the no. of data items: ");
  scanf("%d", &n);
  printf("Enter %d data items: ", n);
  for (i = 0; i < n; i++) 
  {
    scanf("%d", &a[i]);
  }
  printf("The data items before sorting:\n");
  for (i = 0; i < n; i++) 
  {
    printf("%d\t", a[i]);
  }
  quick_sort(a, 0, n - 1);
  printf("\nThe data items after sorting:\n");
  for (i = 0; i < n; i++) 
  {
    printf("%d\t", a[i]);
  }
  printf("\n---------------------\n");
  printf("Programmed By Rabin Acharya.\n");
  return 0;
}

