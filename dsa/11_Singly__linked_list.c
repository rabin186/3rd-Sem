#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

typedef struct Node node;
node *first = NULL, *last = NULL;

void insert_beg() {
  int item;
  node *Newnode = (node*)malloc(sizeof(node));
  printf("Enter the item to be inserted: ");
  scanf("%d", &item);
  Newnode->data = item;

  if (first == NULL) {
    Newnode->next = NULL;
    first = last = Newnode;
  } else {
    Newnode->next = first;
    first = Newnode;
  }
}

void insert_pos() {
    int item, pos, i;
    node *Newnode, *temp;

    printf("Enter the item to be inserted: ");
    scanf("%d", &item);
    
    printf("Enter Position of a node where you want to insert: ");
    scanf("%d", &pos);

    Newnode = (node*)malloc(sizeof(node)); // Allocate memory
    Newnode->data = item;
    Newnode->next = NULL;

    if (pos == 1) {  // Insert at the beginning
        Newnode->next = first;
        first = Newnode;
        return;
    }

    temp = first;
    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) { // If position is invalid
        printf("Invalid position! List has fewer nodes.\n");
        free(Newnode);
        return;
    }

    Newnode->next = temp->next;
    temp->next = Newnode;

    if (Newnode->next == NULL) { // Update last pointer if inserted at the end
        last = Newnode;
    }
}


void insert_end() {
  int item;
  node *Newnode = (node*)malloc(sizeof(node));

  printf("Enter the item to be inserted: ");
  scanf("%d", &item);
  Newnode->data = item;
  Newnode->next = NULL;

  if (first == NULL) {
    first = last = Newnode;
  } else {
    last->next = Newnode;
    last = Newnode;
  }
}

void delete_beg() {
  node *temp;
  if (first == NULL) {
    printf("Void Deletion.\n");
    return;
  }
  temp = first;
  first = first->next;
  free(temp);
}

void delete_pos() {
  node *hold, *temp;
  int pos, i;
  if (first == NULL) {
    printf("Void Deletion.\n");
    return;
  }
  
  printf("Enter the position of node to be deleted: ");
  scanf("%d", &pos);

  if (pos == 1) {
    delete_beg();
    return;
  }

  temp = first;
  for (i = 1; i < pos - 1 && temp->next != NULL; i++) {
    temp = temp->next;
  }

  if (temp->next == NULL) {
    printf("Invalid position.\n");
    return;
  }

  hold = temp->next;
  temp->next = hold->next;
  free(hold);
}

void delete_end() {
  node *temp, *hold;
  if (first == NULL) {
    printf("Void Deletion.\n");
    return;
  } else if (first->next == NULL) {
    hold = first;
    first = NULL;
    free(hold);
    return;
  }

  temp = first;
  while (temp->next->next != NULL) {
    temp = temp->next;
  }

  hold = temp->next;
  temp->next = NULL;
  last = temp;
  free(hold);
}

void display() {
  node *temp = first;
  if (first == NULL) {
    printf("Empty Linked List.\n");
    return;
  }

  while (temp != NULL) 
  {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

int main() {
  int choice;
  printf("\n*********Linked List Operation*********\n");
  while (1) 
  {
    printf("1.Insert at Beginning\n2.Insert at Position\n3.Insert at End\n4.Delete Beginning\n5.Delete at Position\n6.Delete at End\n7.Display\n8.Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1: 
        insert_beg(); 
        break;
      case 2: 
        insert_pos(); 
        break;
      case 3: 
        insert_end(); 
        break;
      case 4: 
        delete_beg(); 
        break;
      case 5: 
        delete_pos(); 
        break;
      case 6: 
        delete_end(); 
        break;
      case 7: 
        display(); 
        break;
      case 8: 
        printf("Exiting....\n");
        return 0;
      default: 
        printf("Invalid choice.\n");
    }
  }
  printf("\n-----------------------------\n");
  printf("Programmed By Rabin Acharya.\n");
  return 0;
}

