#include <stdio.h>
#define MAX 100

void heapify(int a[], int n, int i) {
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  
  if (l < n && a[l] > a[largest]) {
    largest = l;
  }
  
  if (r < n && a[r] > a[largest]) {
    largest = r;
  }
  
  if (largest != i) {
    int temp = a[i];
    a[i] = a[largest];
    a[largest] = temp;
    
    heapify(a, n, largest);
  }
}

void heap_sort(int a[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(a, n, i);
  }
  
  for (int i = n - 1; i > 0; i--) {
    int temp = a[0];
    a[0] = a[i];
    a[i] = temp;
    
    heapify(a, i, 0);
  }
}

int main() {
  int n, i, a[MAX];
  
  printf("Enter the no. of data items: ");
  scanf("%d", &n);
  
  printf("Enter %d data items: ", n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  
  printf("The data items before sorting:\n");
  for (i = 0; i < n; i++) {
    printf("%d\t", a[i]);
  }
  
  heap_sort(a, n);
  
  printf("\nThe data items after sorting:\n");
  for (i = 0; i < n; i++) {
    printf("%d\t", a[i]);
  }
  
  printf("\n---------------------\n");
  printf("Programmed By Rabin Acharya.\n");
  
  return 0;
}

