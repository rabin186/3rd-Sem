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
        Newnode->next = Newnode; 
        first = last = Newnode;
    } else {
        Newnode->next = first;
        first = Newnode;
        last->next = first; 
    }
}

void insert_pos() {
    int item, pos, i;
    node *Newnode, *temp;

    printf("Enter the item to be inserted: ");
    scanf("%d", &item);
    
    printf("Enter Position where you want to insert: ");
    scanf("%d", &pos);

    Newnode = (node*)malloc(sizeof(node));
    Newnode->data = item;

    if (pos == 1) {
        Newnode->next = first;
        first = Newnode;
        last->next = first;
        return;
    }

    temp = first;
    for (i = 1; i < pos - 1 && temp->next != first; i++) {
        temp = temp->next;
    }

    if (temp->next == first && pos > i + 1) {
        printf("Invalid position! List has fewer nodes.\n");
        free(Newnode);
        return;
    }

    Newnode->next = temp->next;
    temp->next = Newnode;

    if (temp == last) { 
        last = Newnode; 
    }
}

void insert_end() {
    int item;
    node *Newnode = (node*)malloc(sizeof(node));

    printf("Enter the item to be inserted: ");
    scanf("%d", &item);
    Newnode->data = item;

    if (first == NULL) {
        first = last = Newnode;
        last->next = first; 
    } else {
        last->next = Newnode;
        last = Newnode;
        last->next = first; 
    }
}

void delete_beg() {
    if (first == NULL) {
        printf("Void Deletion.\n");
        return;
    }

    node *temp = first;
    if (first == last) {
        first = last = NULL;
    } else {
        first = first->next;
        last->next = first; 
    }
    free(temp);
}

void delete_pos() {
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

    node *temp = first, *hold;
    for (i = 1; i < pos - 1 && temp->next != first; i++) {
        temp = temp->next;
    }

    if (temp->next == first) {
        printf("Invalid position.\n");
        return;
    }

    hold = temp->next;
    temp->next = hold->next;

    if (hold == last) { 
        last = temp; 
    }

    free(hold);
}

void delete_end() {
    if (first == NULL) {
        printf("Void Deletion.\n");
        return;
    } else if (first == last) {
        free(first);
        first = last = NULL;
        return;
    }

    node *temp = first;
    while (temp->next != last) {
        temp = temp->next;
    }

    free(last);
    last = temp;
    last->next = first; 
}

void display() {
    if (first == NULL) {
        printf("Empty Linked List.\n");
        return;
    }

    node *temp = first;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != first); 
    printf("(Back to first node)\n");
}

int main() {
    int choice;
    printf("\n*********Circular Linked List Operation*********\n");
    while (1) {
        printf("\n1.Insert at Beginning\n2.Insert at Position\n3.Insert at End\n4.Delete Beginning\n5.Delete at Position\n6.Delete at End\n7.Display\n8.Exit\n");
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



