#include <stdio.h>
#define MAX 100

void merge(int a[], int l, int m, int r) 
{
  int n1 = m - l + 1, n2 = r - m;
  int L[n1], R[n2], i, j, k;
  for (i = 0; i < n1; i++)
  {
    L[i] = a[l + i];
  }
  for (j = 0; j < n2; j++)
  {
    R[j] = a[m + 1 + j];
  }
  i = j = 0, k = l;
  while (i < n1 && j < n2)
  {
    a[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
  }
  while (i < n1)
  {
    a[k++] = L[i++];
  }
  while (j < n2) 
  {
    a[k++] = R[j++];
  }
}

void merge_sort(int a[], int l, int r) {
  if (l < r) 
  {
    int m = l + (r - l) / 2;
    merge_sort(a, l, m);
    merge_sort(a, m + 1, r);
    merge(a, l, m, r);
  }
}

int main() {
  int n, i, a[MAX];
  printf("Enter the no. of data items: ");
  scanf("%d", &n);
  printf("Enter %d data items: ", n);
  for (i = 0; i < n; i++) 
    scanf("%d", &a[i]);
  printf("The data items before sorting:\n");
  for (i = 0; i < n; i++) 
    printf("%d\t", a[i]);
  merge_sort(a, 0, n - 1);
  printf("\nThe data items after sorting:\n");
  for (i = 0; i < n; i++) 
    printf("%d\t", a[i]);
  printf("\n---------------------\n");
  printf("Programmed By Rabin Acharya.\n");
  return 0;
}

