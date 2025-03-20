#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10

typedef struct node {
  int key;
  int value;
} NODE;

NODE *hashTable;

int hashFunction(int key) {
  return key % TABLE_SIZE;
}

void insert() {
  NODE new_node;
  printf("\nEnter key: ");
  scanf("%d", &new_node.key);
  printf("Enter value: ");
  scanf("%d", &new_node.value);
  
  int index = hashFunction(new_node.key), startIndex = index;
  while (hashTable[index].key != 0) {
    index = (index + 1) % TABLE_SIZE;
    if (index == startIndex) {
      printf("\nHash table is full! Cannot insert (%d, %d)\n", new_node.key, new_node.value);
      return;
    }
  }
  hashTable[index] = new_node;
  printf("\nInserted key %d with value %d at index %d\n", new_node.key, new_node.value, index);
}

void search() {
  int key;
  printf("\nEnter key to search: ");
  scanf("%d", &key);
  
  int index = hashFunction(key), startIndex = index;
  while (hashTable[index].key != 0) {
    if (hashTable[index].key == key) {
      printf("\n Found key %d with value %d at index %d\n", key, hashTable[index].value, index);
      return;
    }
    index = (index + 1) % TABLE_SIZE;
    if (index == startIndex) break;
  }
  printf("\nKey %d not found.\n", key);
}

void deleteKey() {
  int key;
  printf("\nEnter key to delete: ");
  scanf("%d", &key);
  
  int index = hashFunction(key), startIndex = index;
  while (hashTable[index].key != 0) 
  {
    if (hashTable[index].key == key) 
    {
      hashTable[index].key = 0;
      printf("\nDeleted key %d from index %d\n", key, index);
      return;
    }
    index = (index + 1) % TABLE_SIZE;
    if (index == startIndex) break;
  }
  printf("\nKey %d not found. Cannot delete.\n", key);
}

void display() {
  printf("\nHash Table:\n");
  for (int i = 0; i < TABLE_SIZE; i++) {
    if (hashTable[i].key == 0)
    {
      printf("  Index %d: EMPTY\n", i);
    }
    else 
    {
      printf("  Index %d: (%d, %d)\n", i, hashTable[i].key, hashTable[i].value);
    }
  }
}

int main() {
  hashTable = (NODE*)malloc(TABLE_SIZE * sizeof(NODE));
  if (!hashTable) 
  {
    printf("\nMemory allocation failed!\n");
    return 1;
  }
  
  for (int i = 0; i < TABLE_SIZE; i++) 
  {
    hashTable[i].key = 0;
    hashTable[i].value = 0;
  }
  
  int choice = 0;
  printf("\n============================\n");
  printf("   HASHING TECHNIQUES MENU   \n");
  printf("============================\n");
  printf(" 1. Insert\n 2. Search\n 3. Delete\n 4. Display\n 5. Exit\n");
  printf("============================\n");
  
  while (choice != 5) {
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
      case 1: 
        insert(); 
        break;
      case 2: 
        search(); 
        break;
      case 3: 
        deleteKey(); 
        break;
      case 4: 
        display(); 
        break;
      case 5: 
        printf("\nExiting...\n"); 
        break;
      default: 
        printf("\nInvalid Choice! Please enter a valid option.\n");
    }
  }
  
  free(hashTable);
  return 0;
}

